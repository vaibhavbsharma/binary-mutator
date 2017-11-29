#include "entryIDs.h"
bool isCMOVCC(entryID e) {
	switch(e) {
    case e_cmovbe:
    case e_cmove:
    case e_cmovnae:
    case e_cmovnb:
    case e_cmovnbe:
    case e_cmovne:
    case e_cmovng:
    case e_cmovnge:
    case e_cmovnl:
    case e_cmovno:
    case e_cmovns:
    case e_cmovo:
    case e_cmovpe:
    case e_cmovpo:
    case e_cmovs:
			return true;
		default: return false;
	}
}

bool isSETCC(entryID e) {
	switch(e) {
	  case e_setb:
    case e_setbe:
    case e_setl:
    case e_setle:
    case e_setnb:
    case e_setnbe:
    case e_setnl:
    case e_setnle:
    case e_setno:
    case e_setnp:
    case e_setns:
    case e_setnz:
    case e_seto:
    case e_setp:
    case e_sets:
    case e_setz:
			return true;
		default: return false;
	}
}
