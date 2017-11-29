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
