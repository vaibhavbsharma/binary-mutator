#include <iostream>
#include "Visitor.h"
#include "Immediate.h"
#include "BinaryFunction.h"
#include "Dereference.h"
#include "Register.h"
#include "Result.h"
#include <string>
using namespace std;

class MyVisitor: public Dyninst::InstructionAPI::Visitor {
  public :
    MyVisitor ( bool _debug=false) { 
			isImmediate = 0; 
			regUsed = Dyninst::x86_64::rip; 
			immediateValue = -1;
			debug = _debug;
		};
    ~MyVisitor () {};

		bool debug;

		int getImmediateValue() {
			assert(isImmediate==1);
			if(debug) cout<<" returning immediateValue ("<<immediateValue<<") ";
			return immediateValue; 
		}

		Dyninst::MachRegister regUsed;
		const Dyninst::MachRegister getRegUsed() {
			if(debug) cout<< " returning reg("<<regUsed.name()<<") ";
			return regUsed; 
		}

    int isImmediate, immediateValue;
    int getIsImmediate() { return isImmediate; }
    
		virtual void visit ( Dyninst::InstructionAPI::BinaryFunction * b ) {
    };

    virtual void visit ( Dyninst::InstructionAPI::Immediate * i ) {
			Dyninst::InstructionAPI::Result result = i->eval();
			if(debug) cout << " \t Immediate value = " << result.format()<<" ";
			//Dyninst::InstructionAPI::s32 ret = (Dyninst::InstructionAPI::s32) result.convert();
			//immediateValue = (int) ret;
			immediateValue = result.convert<int>();
      isImmediate = 1;
    };

    virtual void visit ( Dyninst::InstructionAPI::RegisterAST * r ) {
			regUsed = r->getID();
      if(debug) cout <<" \tVisiting register " << r -> getID ().name ()<< " " ;
			if(r -> getID() == Dyninst::x86_64::eax) {
				if(debug) cout<<" visited eax ("<<regUsed.name()<<")";
			}
    }
    
		virtual void visit ( Dyninst::InstructionAPI::Dereference * d ) {};
};
