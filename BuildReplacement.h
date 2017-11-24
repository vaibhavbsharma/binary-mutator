#include "PatchMgr.h"
#include "PatchModifier.h"
#include "Point.h"
#include "Snippet.h"
// DyninstAPI
#include "BPatch.h"
#include "BPatch_basicBlock.h"
#include "BPatch_flowGraph.h"
#include "BPatch_function.h"
#include "BPatch_object.h"
#include "BPatch_point.h"
#include "BPatch_snippet.h"

using namespace Dyninst::PatchAPI;
using namespace Dyninst::InstructionAPI;
using namespace Dyninst;

//taken from https://github.com/crafthpc/craft/blob/master/src/fpinst.cpp

bool overwriteBlock(PatchBlock *block, unsigned char val) {
    ParseAPI::Block *b = block->block();
    Offset off = b->start();
    ParseAPI::SymtabCodeRegion *r = 
        dynamic_cast<ParseAPI::SymtabCodeRegion*>(b->region());
    if (r == NULL) return false;
    Offset region_off = (Offset)r->getPtrToInstruction(off) - 
                        (Offset)r->symRegion()->getPtrToRawData();
    bool success = false;
    while (off++ < b->end()) {
        success = r->symRegion()->patchData(region_off++, (void*)&val, 1);
        if (!success) return false;
    }
    return true;
}

string disassembleBlock(PatchBlock *block) {
    PatchBlock::Insns insns;
    PatchBlock::Insns::iterator j;
    Instruction::Ptr iptr;
    void *addr;
    unsigned char bytes[64];
    size_t nbytes, i;
    char buffer[64];
    string str("");

    block->getInsns(insns);
    for (j = insns.begin(); j != insns.end(); j++) {

        // get instruction bytes
        addr = (void*)((*j).first);
        iptr = (*j).second;
        nbytes = iptr->size();
        assert(nbytes <= 64);
        for (i=0; i<nbytes; i++) {
            bytes[i] = iptr->rawByte(i);
        }
        bytes[nbytes] = '\0';

        sprintf(buffer, "%08lx\t", (unsigned long)addr);
        str.append(buffer);
        str.append(iptr->format());
        str.append("\n");
    }
    return str;
}

void buildReplacement(void *addr, Instruction *inst, Dyninst::PatchAPI::PatchBlock *block, bool patchAPI_debug, Point *point, Snippet::Ptr handler)
{
    // build Dyninst::PatchAPI::Snippet
    bool success = true;
    //Dyninst::PatchAPI::Snippet::Ptr handler = Dyninst::PatchAPI::convert(new BPatch_nullExpr());
    // Dyninst::PatchAPI::Snippet::Ptr handler = Dyninst::PatchAPI::convert(
		// 		Patch_plus, new BPatch_constExpr(42), new BPatch_registerExpr(Dyninst::x86_64::eax));

		    
		//Snippet::Ptr handler = PatchAPI::convert(new BPatch_constExpr(1));

    // CFG surgery (remove the old instruction and insert the new Dyninst::PatchAPI::Snippet)
    //
    //

    Dyninst::PatchAPI::PatchBlock *insnBlock = block;   // block with old instruction
    void *preSplitAddr = addr;
    void *postSplitAddr = (void*)((unsigned long)preSplitAddr + inst->size());

    // split before instruction
    if ((unsigned long)preSplitAddr > (unsigned long)insnBlock->start()) {
        if (patchAPI_debug) {
            printf("        splitting block [%p-%p] at %p\n",
                    (void*)insnBlock->start(), (void*)insnBlock->end(), preSplitAddr);
        }
        insnBlock = Dyninst::PatchAPI::PatchModifier::split(insnBlock, (Dyninst::Address)preSplitAddr);
        if (!insnBlock) {
            printf("ERROR: could not split block [%p-%p] at %p\n",
                    (void*)block->start(), (void*)block->end(), preSplitAddr);
            assert(0);
        }
    } else {
        // instruction is at the beginning of a block; no need to split
        // pre-block
        if (patchAPI_debug) {
            printf("        insn is at beginning of block\n");
        }
        insnBlock = block;
    }

    // split after instruction
    Dyninst::PatchAPI::PatchBlock *postBlock = NULL;
    if ((unsigned long)postSplitAddr < (unsigned long)insnBlock->end()) {
        if (patchAPI_debug) {
            printf("        splitting block [%p-%p] at %p\n",
                    (void*)insnBlock->start(), (void*)insnBlock->end(), postSplitAddr);
        }
        postBlock = Dyninst::PatchAPI::PatchModifier::split(insnBlock, (Dyninst::Address)postSplitAddr);
        if (!postBlock) {
            printf("ERROR: could not split block [%p-%p] at %p\n",
                    (void*)insnBlock->start(), (void*)block->end(), postSplitAddr);
            assert(0);
        }
    } else {
        // instruction is at the end of a block; no need to split
        // post-block
        if (patchAPI_debug) {
            printf("        insn is at end of block\n");
        }
        assert(block->targets().size() == 1);
        PatchEdge *postEdge = *(insnBlock->targets().begin());
        assert(postEdge->type() == ParseAPI::FALLTHROUGH);
        postBlock = postEdge->trg();
    }

    // insert new code
    InsertedCode::Ptr icode = Dyninst::PatchAPI::PatchModifier::insert(block->object(), handler, point);
    //InsertedCode::Ptr icode = Dyninst::PatchAPI::PatchModifier::insert(block->object(), handler, prePoint);
    //InsertedCode::Ptr icode = Dyninst::PatchAPI::PatchModifier::insert(block->object(), handler,
           //mainMgr->findPoint(Location::Block(instBlock), Point::BlockEntry, true));
    assert(icode->blocks().size() >= 1);
    Dyninst::PatchAPI::PatchBlock *newBlock = icode->entry();
    assert(newBlock != NULL);

    vector<PatchEdge*> edges;
    vector<PatchEdge*>::const_iterator i;
    vector<PatchEdge*>::iterator j;
    bool keepInsnBlock = false;

    // grab all incoming edges to insnBlock
    edges.clear();
    for (i = insnBlock->sources().begin(); i != insnBlock->sources().end(); i++) {
        edges.push_back(*i);

        if (patchAPI_debug) {
            printf("        checking incoming edge of type %s\n", ParseAPI::format((*i)->type()).c_str());
        }

        // we can only redirect these types of edges
        if (!((*i)->type() == ParseAPI::COND_TAKEN || 
              (*i)->type() == ParseAPI::COND_NOT_TAKEN ||
              (*i)->type() == ParseAPI::DIRECT ||
              (*i)->type() == ParseAPI::FALLTHROUGH ||
              (*i)->type() == ParseAPI::CALL_FT)) {
            keepInsnBlock = true;
        }
    }

    if (keepInsnBlock) {

        // overwrite insnBlock with nops
        if (patchAPI_debug) {
            printf("        overwriting block [%p-%p]\n",
                    (void*)insnBlock->start(), (void*)insnBlock->end());
        }
        success = overwriteBlock(insnBlock, 0x90);    // nop
        assert(success);

        // redirect from insnBlock to newBlock
        edges.clear();
        for (i = insnBlock->targets().begin(); i != insnBlock->targets().end(); i++) {
            edges.push_back(*i);
        }
        for (j = edges.begin(); j != edges.end(); j++) {
            if (patchAPI_debug) {
                printf("        redirecting insn outgoing edge [%p-%p] -> [%p-%p] to [%p-%p]\n",
                       (void*)((*j)->src()->start()), (void*)((*j)->src()->end()),
                       (void*)((*j)->trg()->start()), (void*)((*j)->trg()->end()),
                       (void*)(newBlock->start()), (void*)(newBlock->end()));
            }
            success = Dyninst::PatchAPI::PatchModifier::redirect(*j, newBlock);
            assert(success);
        }

    } else {

        // redirect from src/pre to newBlock (skip insnBlock)
        for (j = edges.begin(); j != edges.end(); j++) {
            if (patchAPI_debug) {
                printf("        redirecting incoming edge [%p-%p] -> [%p-%p] of type %s to [%p-%p]\n",
                       (void*)((*j)->src()->start()), (void*)((*j)->src()->end()),
                       (void*)((*j)->trg()->start()), (void*)((*j)->trg()->end()),
                       ParseAPI::format((*j)->type()).c_str(),
                       (void*)(newBlock->start()), (void*)(newBlock->end()));
            }
            success = Dyninst::PatchAPI::PatchModifier::redirect(*j, newBlock);
            assert(success);
        }
    }

    // redirect icode's exit to postBlock
    // (should only be one of them)
    assert(icode->exits().size() == 1);
    if (patchAPI_debug) {
        printf("        redirecting outgoing edge [%p-%p] -> [%p-%p] of type %s to [%p-%p]\n",
               (void*)((*icode->exits().begin())->src()->start()),
               (void*)((*icode->exits().begin())->src()->end()),
               (void*)((*icode->exits().begin())->trg()->start()),
               (void*)((*icode->exits().begin())->trg()->end()),
               ParseAPI::format((*icode->exits().begin())->type()).c_str(),
               (void*)(postBlock->start()), (void*)(postBlock->end()));
    }
    success = Dyninst::PatchAPI::PatchModifier::redirect(*icode->exits().begin(), postBlock);
    assert(success);

    // should be single entry and exit now
    Dyninst::PatchAPI::PatchBlock *newEntry = icode->entry();
    Dyninst::PatchAPI::PatchBlock *newExit = (*icode->exits().begin())->src();

    if (patchAPI_debug) {
        // debug output
        printf("    new sequence: => ");
        if ((unsigned long)preSplitAddr > (unsigned long)block->start()) {
           printf("[%p-%p] -> ", (void*)block->start(),
                                 (void*)block->end());
        } else if (keepInsnBlock) {
           printf("[%p-%p] -> ", (void*)insnBlock->start(),
                                 (void*)insnBlock->end());
        }
        printf("{ [%p-%p] ... [%p-%p] } ", 
              (void*)newEntry->start(), (void*)newEntry->end(),
              (void*)newExit->start(),  (void*)newExit->end());
        printf(" -> [%p-%p] ", (void*)postBlock->start(),
                              (void*)postBlock->end());
        printf("=> \n");
    }

    // disassemble for log
    set<Dyninst::PatchAPI::PatchBlock*>::iterator k;
    string disassembly("");
    disassembly.append(disassembleBlock(newEntry));
    disassembly.append("\n");
    for (k = icode->blocks().begin(); k != icode->blocks().end(); k++) {
        if (((*k) != newEntry) && ((*k) != newExit)) {
            disassembly.append(disassembleBlock(*k));
            disassembly.append("\n");
        }
    }
    disassembly.append(disassembleBlock(newExit));
    disassembly.append("\n");

    // debug output
    //logfile->addMessage(STATUS, 0, "Inserted " + analysis->getTag() + " replacement instrumentation.",
     //       disassembly, "", inst);
}
