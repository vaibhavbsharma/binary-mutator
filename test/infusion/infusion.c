/********
* ec2c version 0.67
* context   method = HEAP
* ext call  method = PROCEDURES
* c header file generated for node : top 
* to be used with : top.c 
********/
#ifndef _top_EC2C_H_FILE
#define _top_EC2C_H_FILE
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: top 20 5
//IN: _boolean TLM_MODE_IN_On_Start
//IN: _boolean OP_CMD_IN_Infusion_Initiate
//IN: _boolean OP_CMD_IN_Infusion_Inhibit
//IN: _boolean OP_CMD_IN_Infusion_Cancel
//IN: _boolean PATIENT_IN_Bolus_Request
//IN: _integer CONFIG_IN_Flow_Rate_Basal
//IN: _integer CONFIG_IN_Flow_Rate_Intermittent_Bolus
//IN: _integer CONFIG_IN_Intermittent_Bolus_Duration
//IN: _integer CONFIG_IN_Flow_Rate_Patient_Bolus
//IN: _integer CONFIG_IN_Patient_Bolus_Duration
//IN: _integer CONFIG_IN_Lock_Out_Duration
//IN: _integer CONFIG_IN_Max_Patient_Bolus
//IN: _integer CONFIG_IN_Interval_Intermittent_Bolus
//IN: _integer CONFIG_IN_Duration_Total
//IN: _integer CONFIG_IN_VTBI_Total
//IN: _integer CONFIG_IN_Configured
//IN: _integer CONFIG_IN_Flow_Rate_KVO
//IN: _integer ALARM_IN_Highest_Level_Alarm
//IN: _boolean SYS_STAT_IN_Reservoir_Empty
//IN: _integer SYS_STAT_Volume_Infused
//OUT: _integer IM_OUT_Flow_Rate_Commanded
//OUT: _integer IM_OUT_Current_System_Mode
//OUT: _boolean IM_OUT_New_Infusion
//OUT: _integer IM_OUT_Log_Message_ID
//OUT: _integer IM_OUT_Actual_Infusion_Duration
#endif
/********
* ec2c version 0.67
* c file generated for node : top 
* context   method = HEAP
* ext call  method = PROCEDURES
********/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _top_EC2C_SRC_FILE
/*--------
Internal structure for the call
--------*/

typedef struct top_ctx {
   void* client_data;
   //INPUTS
   _boolean _TLM_MODE_IN_On_Start;
   _boolean _OP_CMD_IN_Infusion_Initiate;
   _boolean _OP_CMD_IN_Infusion_Inhibit;
   _boolean _OP_CMD_IN_Infusion_Cancel;
   _boolean _PATIENT_IN_Bolus_Request;
   _integer _CONFIG_IN_Flow_Rate_Basal;
   _integer _CONFIG_IN_Flow_Rate_Intermittent_Bolus;
   _integer _CONFIG_IN_Intermittent_Bolus_Duration;
   _integer _CONFIG_IN_Flow_Rate_Patient_Bolus;
   _integer _CONFIG_IN_Patient_Bolus_Duration;
   _integer _CONFIG_IN_Lock_Out_Duration;
   _integer _CONFIG_IN_Max_Patient_Bolus;
   _integer _CONFIG_IN_Interval_Intermittent_Bolus;
   _integer _CONFIG_IN_Duration_Total;
   _integer _CONFIG_IN_VTBI_Total;
   _integer _CONFIG_IN_Configured;
   _integer _CONFIG_IN_Flow_Rate_KVO;
   _integer _ALARM_IN_Highest_Level_Alarm;
   _boolean _SYS_STAT_IN_Reservoir_Empty;
   _integer _SYS_STAT_Volume_Infused;
   //OUTPUTS
   _integer _IM_OUT_Flow_Rate_Commanded;
   _integer _IM_OUT_Current_System_Mode;
   _boolean _IM_OUT_New_Infusion;
   _integer _IM_OUT_Log_Message_ID;
   _integer _IM_OUT_Actual_Infusion_Duration;
   //REGISTERS
   _integer M638;
   _boolean M638_nil;
   _boolean M626;
   _boolean M626_nil;
   _integer M604;
   _boolean M604_nil;
   _integer M567;
   _boolean M567_nil;
   _integer M496;
   _boolean M496_nil;
   _integer M526;
   _boolean M526_nil;
   _integer M48;
   _boolean M48_nil;
   _integer M71;
   _boolean M71_nil;
   _integer M123;
   _boolean M123_nil;
   _boolean M345;
   _boolean M345_nil;
   _integer M378;
   _boolean M378_nil;
   _integer M406;
   _boolean M406_nil;
   _integer M319;
   _boolean M319_nil;
   _boolean M144;
   _boolean M144_nil;
   _integer M166;
   _boolean M166_nil;
   _integer M192;
   _boolean M192_nil;
   _integer M251;
   _boolean M251_nil;
   _integer M224;
   _boolean M224_nil;
   _integer M84;
   _boolean M84_nil;
   _integer M30;
   _boolean M30_nil;
   _boolean M25;
} top_ctx;
/*--------
Internal reset input procedure
--------*/
static void top_reset_input(top_ctx* ctx){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void top_reset(top_ctx* ctx){
   ctx->M638_nil = _true;
   ctx->M626_nil = _true;
   ctx->M604_nil = _true;
   ctx->M567_nil = _true;
   ctx->M496_nil = _true;
   ctx->M526_nil = _true;
   ctx->M48_nil = _true;
   ctx->M71_nil = _true;
   ctx->M123_nil = _true;
   ctx->M345_nil = _true;
   ctx->M378_nil = _true;
   ctx->M406_nil = _true;
   ctx->M319_nil = _true;
   ctx->M144_nil = _true;
   ctx->M166_nil = _true;
   ctx->M192_nil = _true;
   ctx->M251_nil = _true;
   ctx->M224_nil = _true;
   ctx->M84_nil = _true;
   ctx->M30_nil = _true;
   ctx->M25 = _true;
   top_reset_input(ctx);
}
/*--------
Copy the value of an internal structure
--------*/
void top_copy_ctx(top_ctx* dest, top_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(top_ctx));
}
/*--------
Dynamic allocation of an internal structure
--------*/
top_ctx* top_new_ctx(void* cdata){
   top_ctx* ctx = (top_ctx*)calloc(1, sizeof(top_ctx));
   ctx->client_data = cdata;
   top_reset(ctx);
   return ctx;
}
/*--------
Step procedure
--------*/

void top_step(top_ctx* ctx){
    //LOCAL VARIABLES
    _boolean L24;
    _integer L29;
    _integer L23;
    _boolean L22;
    _boolean L21;
    _boolean L33;
    _boolean L36;
    _integer L47;
    _integer L46;
    _boolean L45;
    _boolean L59;
    _boolean L60;
    _boolean L58;
    _boolean L57;
    _boolean L64;
    _boolean L63;
    _boolean L65;
    _boolean L62;
    _boolean L97;
    _boolean L96;
    _integer L485;
    _boolean L484;
    _boolean L486;
    _boolean L483;
    _integer L482;
    _boolean L142;
    _boolean L143;
    _boolean L141;
    _integer L140;
    _boolean L139;
    _integer L488;
    _integer L481;
    _integer L70;
    _integer L69;
    _integer L472;
    _boolean L68;
    _boolean L473;
    _boolean L67;
    _integer L83;
    _integer L82;
    _boolean L81;
    _boolean L104;
    _boolean L103;
    _boolean L105;
    _boolean L102;
    _integer L495;
    _integer L494;
    _boolean L493;
    _integer L525;
    _integer L524;
    _boolean L523;
    _integer L547;
    _boolean L549;
    _integer L550;
    _integer L548;
    _integer L522;
    _boolean L521;
    _boolean L520;
    _integer L562;
    _boolean L554;
    _boolean L556;
    _integer L566;
    _integer L565;
    _integer L564;
    _integer L563;
    _integer L492;
    _integer L491;
    _boolean L107;
    _integer L122;
    _integer L121;
    _boolean L120;
    _integer L165;
    _integer L164;
    _boolean L163;
    _integer L191;
    _integer L190;
    _integer L283;
    _boolean L189;
    _boolean L284;
    _boolean L188;
    _integer L187;
    _boolean L216;
    _boolean L220;
    _boolean L219;
    _integer L223;
    _integer L222;
    _boolean L221;
    _boolean L218;
    _integer L286;
    _boolean L246;
    _integer L250;
    _integer L249;
    _integer L277;
    _boolean L248;
    _integer L288;
    _integer L287;
    _integer L285;
    _integer L186;
    _boolean L312;
    _integer L318;
    _integer L317;
    _boolean L316;
    _boolean L344;
    _boolean L343;
    _boolean L342;
    _integer L341;
    _boolean L400;
    _integer L405;
    _integer L404;
    _integer L434;
    _boolean L403;
    _boolean L402;
    _integer L455;
    _integer L454;
    _integer L315;
    _boolean L314;
    _integer L572;
    _integer L571;
    _boolean L457;
    _boolean L459;
    _integer L574;
    _integer L573;
    _integer L570;
    _integer L569;
    _integer L568;
    _integer L490;
    _integer L489;
    _integer L480;
    _integer L479;
    _boolean L110;
    _boolean L112;
    _boolean L116;
    _boolean L115;
    _boolean L114;
    _integer L578;
    _integer L577;
    _integer L576;
    _integer L575;
    _integer L44;
    _integer L43;
    _boolean L39;
    _integer L579;
    _integer L42;
    _integer L20;
    _boolean L514;
    _boolean L513;
    _integer L590;
    _integer L588;
    _integer L593;
    _integer L587;
    _boolean L552;
    _integer L599;
    _integer L598;
    _integer L603;
    _integer L602;
    _integer L601;
    _integer L600;
    _integer L597;
    _integer L596;
    _integer L609;
    _integer L608;
    _integer L611;
    _integer L610;
    _integer L607;
    _integer L606;
    _integer L605;
    _integer L595;
    _integer L594;
    _integer L586;
    _integer L585;
    _integer L615;
    _integer L614;
    _integer L613;
    _integer L612;
    _integer L584;
    _integer L583;
    _integer L617;
    _integer L616;
    _integer L582;
    _integer L581;
    _boolean L623;
    _boolean L625;
    _boolean L624;
    _boolean L622;
    _boolean L630;
    _boolean L629;
    _boolean L628;
    _boolean L627;
    _boolean L621;
    _boolean L620;
    _boolean L619;
    _integer L54;
    _boolean L53;
    _integer L637;
    _integer L636;
    _integer L635;
    _integer L642;
    _integer L641;
    _integer L640;
    _integer L645;
    _integer L644;
    _integer L643;
    _integer L639;
    _integer L634;
    _integer L647;
    _integer L646;
    _integer L633;
    _integer L632;
    _integer L75;
    _integer L464;
    _integer L466;
    _integer L465;
    _integer L119;
    _integer L118;
    _integer L117;
    _integer L80;
    _integer L79;
    _integer L78;
    _integer L77;
    _integer L469;
    _integer L468;
    _integer L467;
    _integer L76;
    _integer L74;
    _integer L471;
    _integer L470;
    _integer L73;
    _integer L72;
    _integer T638;
    _boolean T626;
    _integer T604;
    _integer T567;
    _integer L506;
    _boolean L505;
    _integer L504;
    _boolean L503;
    _integer L502;
    _integer L501;
    _integer L500;
    _integer L512;
    _integer L511;
    _integer L510;
    _integer L551;
    _integer L519;
    _integer L555;
    _integer L553;
    _integer L518;
    _integer L517;
    _integer L558;
    _integer L557;
    _integer L516;
    _integer L515;
    _integer L509;
    _integer L508;
    _integer L561;
    _integer L560;
    _integer L559;
    _integer L507;
    _integer L499;
    _integer L498;
    _integer L497;
    _integer T496;
    _integer L534;
    _boolean L533;
    _integer L532;
    _integer L531;
    _integer L530;
    _integer L538;
    _integer L541;
    _integer L543;
    _integer L542;
    _integer L540;
    _integer L539;
    _integer L537;
    _integer L536;
    _integer L546;
    _integer L545;
    _integer L544;
    _integer L535;
    _integer L529;
    _integer L528;
    _integer L527;
    _integer T526;
    _integer L52;
    _integer L66;
    _integer L61;
    _integer L56;
    _integer L476;
    _integer L475;
    _integer L474;
    _integer L55;
    _integer L51;
    _integer L478;
    _integer L477;
    _integer L50;
    _integer L49;
    _integer T48;
    _integer T71;
    _integer L91;
    _boolean L90;
    _integer L133;
    _boolean L132;
    _integer L131;
    _boolean L130;
    _integer L129;
    _integer L128;
    _integer L127;
    _integer L138;
    _integer L137;
    _integer L307;
    _integer L313;
    _integer L311;
    _integer L458;
    _integer L456;
    _integer L310;
    _integer L309;
    _integer L308;
    _integer L306;
    _integer L305;
    _integer L136;
    _integer L135;
    _integer L463;
    _integer L462;
    _integer L461;
    _integer L460;
    _integer L134;
    _integer L126;
    _integer L125;
    _integer L124;
    _integer T123;
    _integer L327;
    _boolean L326;
    _boolean L352;
    _boolean L351;
    _boolean L350;
    _boolean L349;
    _boolean L361;
    _boolean L364;
    _integer L363;
    _boolean L362;
    _boolean L360;
    _boolean L366;
    _integer L365;
    _integer L359;
    _boolean L358;
    _boolean L357;
    _boolean L356;
    _integer L377;
    _integer L376;
    _integer L375;
    _boolean L374;
    _boolean L442;
    _integer L441;
    _boolean L440;
    _boolean L373;
    _boolean L394;
    _integer L443;
    _integer L372;
    _boolean L371;
    _boolean L370;
    _boolean L369;
    _boolean L447;
    _boolean L449;
    _boolean L448;
    _boolean L446;
    _boolean L445;
    _boolean L444;
    _boolean L368;
    _boolean L367;
    _boolean L355;
    _boolean L354;
    _boolean L453;
    _boolean L452;
    _boolean L451;
    _boolean L450;
    _boolean L353;
    _boolean L348;
    _boolean L347;
    _boolean L346;
    _boolean T345;
    _integer L382;
    _integer L388;
    _integer L387;
    _integer L386;
    _integer L393;
    _integer L392;
    _integer L391;
    _integer L398;
    _integer L401;
    _integer L399;
    _integer L397;
    _integer L396;
    _integer L395;
    _integer L390;
    _integer L389;
    _integer L385;
    _integer L384;
    _integer L437;
    _integer L436;
    _integer L435;
    _integer L383;
    _integer L381;
    _integer L439;
    _integer L438;
    _integer L380;
    _integer L379;
    _integer T378;
    _integer L414;
    _integer L413;
    _integer L412;
    _integer L411;
    _integer L410;
    _integer L420;
    _integer L419;
    _integer L418;
    _integer L423;
    _integer L428;
    _integer L427;
    _integer L426;
    _integer L425;
    _integer L424;
    _integer L422;
    _integer L421;
    _integer L417;
    _integer L416;
    _integer L431;
    _integer L430;
    _integer L429;
    _integer L415;
    _integer L409;
    _integer L433;
    _integer L432;
    _integer L408;
    _integer L407;
    _integer T406;
    _integer L325;
    _integer L324;
    _integer L323;
    _integer L331;
    _integer L334;
    _integer L336;
    _integer L335;
    _integer L333;
    _integer L332;
    _integer L330;
    _integer L329;
    _integer L340;
    _integer L339;
    _integer L338;
    _integer L337;
    _integer L328;
    _integer L322;
    _integer L321;
    _integer L320;
    _integer T319;
    _boolean L149;
    _boolean L148;
    _boolean L152;
    _boolean L155;
    _boolean L154;
    _boolean L157;
    _boolean L159;
    _boolean L294;
    _boolean L297;
    _boolean L296;
    _boolean L295;
    _boolean L293;
    _boolean L162;
    _boolean L161;
    _boolean L160;
    _boolean L158;
    _boolean L156;
    _boolean L153;
    _boolean L151;
    _boolean L300;
    _boolean L302;
    _boolean L301;
    _boolean L299;
    _boolean L298;
    _boolean L150;
    _boolean L147;
    _boolean L304;
    _boolean L303;
    _boolean L146;
    _boolean L145;
    _boolean T144;
    _integer L176;
    _boolean L175;
    _integer L174;
    _boolean L173;
    _integer L172;
    _integer L171;
    _integer L170;
    _integer L180;
    _integer L183;
    _integer L185;
    _integer L184;
    _integer L182;
    _integer L181;
    _integer L179;
    _integer L178;
    _integer L292;
    _integer L291;
    _integer L290;
    _integer L289;
    _integer L177;
    _integer L169;
    _integer L168;
    _integer L167;
    _integer T166;
    _integer L200;
    _integer L199;
    _integer L198;
    _integer L197;
    _integer L196;
    _integer L206;
    _integer L205;
    _integer L207;
    _integer L204;
    _integer L211;
    _integer L210;
    _integer L217;
    _integer L247;
    _integer L245;
    _integer L215;
    _integer L214;
    _integer L213;
    _integer L212;
    _integer L209;
    _integer L208;
    _integer L203;
    _integer L202;
    _integer L280;
    _integer L279;
    _integer L278;
    _integer L201;
    _integer L195;
    _integer L282;
    _integer L281;
    _integer L194;
    _integer L193;
    _integer T192;
    _integer L255;
    _integer L261;
    _integer L260;
    _integer L259;
    _integer L264;
    _integer L268;
    _integer L271;
    _integer L270;
    _integer L269;
    _integer L267;
    _integer L266;
    _integer L265;
    _integer L263;
    _integer L262;
    _integer L258;
    _integer L257;
    _integer L274;
    _integer L273;
    _integer L272;
    _integer L256;
    _integer L254;
    _integer L276;
    _integer L275;
    _integer L253;
    _integer L252;
    _integer T251;
    _integer L228;
    _integer L239;
    _integer L238;
    _integer L237;
    _integer L236;
    _integer L235;
    _integer L234;
    _integer L233;
    _integer L232;
    _integer L231;
    _integer L230;
    _integer L242;
    _integer L241;
    _integer L240;
    _integer L229;
    _integer L227;
    _integer L244;
    _integer L243;
    _integer L226;
    _integer L225;
    _integer T224;
    _integer L89;
    _integer L88;
    _integer L95;
    _integer L101;
    _integer L108;
    _integer L106;
    _integer L100;
    _integer L99;
    _integer L94;
    _integer L93;
    _integer L113;
    _integer L111;
    _integer L109;
    _integer L92;
    _integer L87;
    _integer L86;
    _integer L85;
    _integer T84;
    _integer L35;
    _integer L40;
    _integer L38;
    _integer L32;
    _integer L41;
    _integer L31;
    _integer T30;
    //CODE
    if (ctx->M25) {
        L24 = _true;
    } else {
        L24 = _false;
    }
    if (ctx->M25) {
        L29 = 0;
    } else {
        L29 = ctx->M30;
    }
    if (L24) {
        L23 = 0;
    } else {
        L23 = L29;
    }
    L22 = (L23 == 0);
    L21 = (! L22);
    L33 = (L23 == 1);
    L36 = (! ctx->_TLM_MODE_IN_On_Start);
    if (ctx->M25) {
        L47 = 0;
    } else {
        L47 = ctx->M48;
    }
    if (L24) {
        L46 = 0;
    } else {
        L46 = L47;
    }
    L45 = (L46 == 1);
    L59 = (ctx->_OP_CMD_IN_Infusion_Initiate && ctx->_SYS_STAT_IN_Reservoir_Empty);
    L60 = (ctx->_CONFIG_IN_Configured < 1);
    L58 = (L59 || L60);
    L57 = (L58 || ctx->_OP_CMD_IN_Infusion_Cancel);
    L64 = (ctx->_CONFIG_IN_Configured == 1);
    L63 = (ctx->_OP_CMD_IN_Infusion_Initiate && L64);
    L65 = (! ctx->_SYS_STAT_IN_Reservoir_Empty);
    L62 = (L63 && L65);
    L97 = (ctx->_ALARM_IN_Highest_Level_Alarm >= 3);
    L96 = (ctx->_OP_CMD_IN_Infusion_Inhibit || L97);
    if (L97) {
        L485 = 2;
    } else {
        L485 = 1;
    }
    L484 = (L485 == 2);
    L486 = (ctx->_ALARM_IN_Highest_Level_Alarm == 4);
    L483 = (L484 && L486);
    if (L483) {
        L482 = 0;
    } else {
        L482 = ctx->_CONFIG_IN_Flow_Rate_KVO;
    }
    L142 = (! L24);
    if (ctx->M25) {
        L143 = _false;
    } else {
        L143 = ctx->M144;
    }
    L141 = (L142 && L143);
    if (L141) {
        L140 = 3;
    } else {
        L140 = 2;
    }
    L139 = (L140 == 1);
    if (L139) {
        L488 = ctx->_CONFIG_IN_Flow_Rate_Patient_Bolus;
    } else {
        L488 = ctx->_CONFIG_IN_Flow_Rate_Basal;
    }
    if (L96) {
        L481 = L482;
    } else {
        L481 = L488;
    }
    if (ctx->M25) {
        L70 = 0;
    } else {
        L70 = ctx->M71;
    }
    if (L24) {
        L69 = 0;
    } else {
        L69 = L70;
    }
    L472 = (ctx->_CONFIG_IN_Duration_Total - 1);
    L68 = (L69 >= L472);
    L473 = (ctx->_SYS_STAT_Volume_Infused >= ctx->_CONFIG_IN_VTBI_Total);
    L67 = (L68 || L473);
    if (ctx->M25) {
        L83 = 0;
    } else {
        L83 = ctx->M84;
    }
    if (L24) {
        L82 = 0;
    } else {
        L82 = L83;
    }
    L81 = (L82 == 1);
    L104 = (ctx->_ALARM_IN_Highest_Level_Alarm < 3);
    L103 = (ctx->_OP_CMD_IN_Infusion_Initiate && L104);
    L105 = (! ctx->_OP_CMD_IN_Infusion_Inhibit);
    L102 = (L103 && L105);
    if (ctx->M25) {
        L495 = 0;
    } else {
        L495 = ctx->M496;
    }
    if (L24) {
        L494 = 0;
    } else {
        L494 = L495;
    }
    L493 = (L494 == 1);
    if (ctx->M25) {
        L525 = 0;
    } else {
        L525 = ctx->M526;
    }
    if (L24) {
        L524 = 0;
    } else {
        L524 = L525;
    }
    L523 = (L524 == 1);
    if (L97) {
        L547 = 2;
    } else {
        L547 = L524;
    }
    L549 = (L524 == 2);
    if (L103) {
        L550 = 1;
    } else {
        L550 = L524;
    }
    if (L549) {
        L548 = L550;
    } else {
        L548 = L524;
    }
    if (L523) {
        L522 = L547;
    } else {
        L522 = L548;
    }
    L521 = (L522 == 2);
    L520 = (L521 && L486);
    if (L520) {
        L562 = 0;
    } else {
        L562 = ctx->_CONFIG_IN_Flow_Rate_KVO;
    }
    L554 = (L494 == 2);
    L556 = (L494 == 3);
    if (ctx->M25) {
        L566 = 0;
    } else {
        L566 = ctx->M567;
    }
    if (L24) {
        L565 = 0;
    } else {
        L565 = L566;
    }
    if (L556) {
        L564 = L562;
    } else {
        L564 = L565;
    }
    if (L554) {
        L563 = L562;
    } else {
        L563 = L564;
    }
    if (L493) {
        L492 = L562;
    } else {
        L492 = L563;
    }
    if (L102) {
        L491 = L488;
    } else {
        L491 = L492;
    }
    L107 = (L82 == 2);
    if (ctx->M25) {
        L122 = 0;
    } else {
        L122 = ctx->M123;
    }
    if (L24) {
        L121 = 0;
    } else {
        L121 = L122;
    }
    L120 = (L121 == 1);
    if (ctx->M25) {
        L165 = 0;
    } else {
        L165 = ctx->M166;
    }
    if (L24) {
        L164 = 0;
    } else {
        L164 = L165;
    }
    L163 = (L164 == 1);
    if (ctx->M25) {
        L191 = 0;
    } else {
        L191 = ctx->M192;
    }
    if (L24) {
        L190 = 0;
    } else {
        L190 = L191;
    }
    L283 = (ctx->_CONFIG_IN_Patient_Bolus_Duration - 1);
    L189 = (L190 >= L283);
    L284 = (ctx->_ALARM_IN_Highest_Level_Alarm == 2);
    L188 = (L189 || L284);
    if (L188) {
        L187 = 3;
    } else {
        L187 = L164;
    }
    L216 = (L164 == 2);
    L220 = (ctx->_ALARM_IN_Highest_Level_Alarm < 2);
    L219 = (ctx->_PATIENT_IN_Bolus_Request && L220);
    if (ctx->M25) {
        L223 = 0;
    } else {
        L223 = ctx->M224;
    }
    if (L24) {
        L222 = 0;
    } else {
        L222 = L223;
    }
    L221 = (L222 < ctx->_CONFIG_IN_Max_Patient_Bolus);
    L218 = (L219 && L221);
    if (L218) {
        L286 = 1;
    } else {
        L286 = L164;
    }
    L246 = (L164 == 3);
    if (ctx->M25) {
        L250 = 0;
    } else {
        L250 = ctx->M251;
    }
    if (L24) {
        L249 = 0;
    } else {
        L249 = L250;
    }
    L277 = (ctx->_CONFIG_IN_Lock_Out_Duration - 1);
    L248 = (L249 >= L277);
    if (L248) {
        L288 = 2;
    } else {
        L288 = L164;
    }
    if (L246) {
        L287 = L288;
    } else {
        L287 = L164;
    }
    if (L216) {
        L285 = L286;
    } else {
        L285 = L287;
    }
    if (L163) {
        L186 = L187;
    } else {
        L186 = L285;
    }
    L312 = (L186 == 1);
    if (ctx->M25) {
        L318 = 0;
    } else {
        L318 = ctx->M319;
    }
    if (L24) {
        L317 = 0;
    } else {
        L317 = L318;
    }
    L316 = (L317 == 1);
    if (ctx->M25) {
        L344 = _false;
    } else {
        L344 = ctx->M345;
    }
    L343 = (L142 && L344);
    L342 = (L343 && L220);
    if (L342) {
        L341 = 2;
    } else {
        L341 = L317;
    }
    L400 = (L317 == 2);
    if (ctx->M25) {
        L405 = 0;
    } else {
        L405 = ctx->M406;
    }
    if (L24) {
        L404 = 0;
    } else {
        L404 = L405;
    }
    L434 = (ctx->_CONFIG_IN_Intermittent_Bolus_Duration - 1);
    L403 = (L404 >= L434);
    L402 = (L403 || L284);
    if (L402) {
        L455 = 1;
    } else {
        L455 = L317;
    }
    if (L400) {
        L454 = L455;
    } else {
        L454 = L317;
    }
    if (L316) {
        L315 = L341;
    } else {
        L315 = L454;
    }
    L314 = (L315 == 2);
    if (L314) {
        L572 = ctx->_CONFIG_IN_Flow_Rate_Intermittent_Bolus;
    } else {
        L572 = ctx->_CONFIG_IN_Flow_Rate_Basal;
    }
    if (L312) {
        L571 = ctx->_CONFIG_IN_Flow_Rate_Patient_Bolus;
    } else {
        L571 = L572;
    }
    L457 = (L121 == 2);
    L459 = (L121 == 3);
    if (L459) {
        L574 = L571;
    } else {
        L574 = L565;
    }
    if (L457) {
        L573 = L571;
    } else {
        L573 = L574;
    }
    if (L120) {
        L570 = L571;
    } else {
        L570 = L573;
    }
    if (L96) {
        L569 = L482;
    } else {
        L569 = L570;
    }
    if (L107) {
        L568 = L569;
    } else {
        L568 = L565;
    }
    if (L81) {
        L490 = L491;
    } else {
        L490 = L568;
    }
    if (L67) {
        L489 = 0;
    } else {
        L489 = L490;
    }
    if (L62) {
        L480 = L481;
    } else {
        L480 = L489;
    }
    if (L57) {
        L479 = 0;
    } else {
        L479 = L480;
    }
    L110 = (L46 == 2);
    L112 = (ctx->_OP_CMD_IN_Infusion_Cancel || ctx->_OP_CMD_IN_Infusion_Inhibit);
    L116 = (ctx->_CONFIG_IN_Configured > 0);
    L115 = (ctx->_OP_CMD_IN_Infusion_Initiate && L116);
    L114 = (L115 && L65);
    if (L96) {
        L578 = L482;
    } else {
        L578 = ctx->_CONFIG_IN_Flow_Rate_Basal;
    }
    if (L114) {
        L577 = L578;
    } else {
        L577 = 0;
    }
    if (L112) {
        L576 = 0;
    } else {
        L576 = L577;
    }
    if (L110) {
        L575 = L576;
    } else {
        L575 = L565;
    }
    if (L45) {
        L44 = L479;
    } else {
        L44 = L575;
    }
    if (L36) {
        L43 = 0;
    } else {
        L43 = L44;
    }
    L39 = (L23 == 2);
    if (L39) {
        L579 = 0;
    } else {
        L579 = L565;
    }
    if (L33) {
        L42 = L43;
    } else {
        L42 = L579;
    }
    if (L21) {
        L20 = L42;
    } else {
        L20 = 0;
    }
    //top_O_IM_OUT_Flow_Rate_Commanded(ctx->client_data, L20);
    ctx->_IM_OUT_Flow_Rate_Commanded = L20;
    L514 = (ctx->_ALARM_IN_Highest_Level_Alarm == 3);
    L513 = (L484 && L514);
    if (L513) {
        L590 = 7;
    } else {
        L590 = 8;
    }
    if (L483) {
        L588 = 6;
    } else {
        L588 = L590;
    }
    if (L139) {
        L593 = 4;
    } else {
        L593 = 2;
    }
    if (L96) {
        L587 = L588;
    } else {
        L587 = L593;
    }
    L552 = (L521 && L514);
    if (L552) {
        L599 = 7;
    } else {
        L599 = 8;
    }
    if (L520) {
        L598 = 6;
    } else {
        L598 = L599;
    }
    if (ctx->M25) {
        L603 = 0;
    } else {
        L603 = ctx->M604;
    }
    if (L24) {
        L602 = 0;
    } else {
        L602 = L603;
    }
    if (L556) {
        L601 = L598;
    } else {
        L601 = L602;
    }
    if (L554) {
        L600 = L598;
    } else {
        L600 = L601;
    }
    if (L493) {
        L597 = L598;
    } else {
        L597 = L600;
    }
    if (L102) {
        L596 = L593;
    } else {
        L596 = L597;
    }
    if (L314) {
        L609 = 3;
    } else {
        L609 = 2;
    }
    if (L312) {
        L608 = 4;
    } else {
        L608 = L609;
    }
    if (L459) {
        L611 = L608;
    } else {
        L611 = L602;
    }
    if (L457) {
        L610 = L608;
    } else {
        L610 = L611;
    }
    if (L120) {
        L607 = L608;
    } else {
        L607 = L610;
    }
    if (L96) {
        L606 = L588;
    } else {
        L606 = L607;
    }
    if (L107) {
        L605 = L606;
    } else {
        L605 = L602;
    }
    if (L81) {
        L595 = L596;
    } else {
        L595 = L605;
    }
    if (L67) {
        L594 = 1;
    } else {
        L594 = L595;
    }
    if (L62) {
        L586 = L587;
    } else {
        L586 = L594;
    }
    if (L57) {
        L585 = 1;
    } else {
        L585 = L586;
    }
    if (L96) {
        L615 = L588;
    } else {
        L615 = 2;
    }
    if (L114) {
        L614 = L615;
    } else {
        L614 = 1;
    }
    if (L112) {
        L613 = 1;
    } else {
        L613 = L614;
    }
    if (L110) {
        L612 = L613;
    } else {
        L612 = L602;
    }
    if (L45) {
        L584 = L585;
    } else {
        L584 = L612;
    }
    if (L36) {
        L583 = 0;
    } else {
        L583 = L584;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L617 = 1;
    } else {
        L617 = 0;
    }
    if (L39) {
        L616 = L617;
    } else {
        L616 = L602;
    }
    if (L33) {
        L582 = L583;
    } else {
        L582 = L616;
    }
    if (L21) {
        L581 = L582;
    } else {
        L581 = L617;
    }
    // top_O_IM_OUT_Current_System_Mode(ctx->client_data, L581);
    ctx->_IM_OUT_Current_System_Mode = L581;
    L623 = (! L45);
    if (ctx->M25) {
        L625 = _false;
    } else {
        L625 = ctx->M626;
    }
    L624 = (L142 && L625);
    L622 = (L623 && L624);
    L630 = (L114 || L624);
    if (L112) {
        L629 = L624;
    } else {
        L629 = L630;
    }
    if (L110) {
        L628 = L629;
    } else {
        L628 = L624;
    }
    L627 = (L623 && L628);
    if (L36) {
        L621 = L622;
    } else {
        L621 = L627;
    }
    if (L33) {
        L620 = L621;
    } else {
        L620 = L624;
    }
    if (L21) {
        L619 = L620;
    } else {
        L619 = L624;
    }
    // top_O_IM_OUT_New_Infusion(ctx->client_data, L619);
    ctx->_IM_OUT_New_Infusion = L619;
    if (L45) {
        L54 = 0;
    } else {
        L54 = L46;
    }
    L53 = (L54 == 2);
    if (ctx->M25) {
        L637 = 0;
    } else {
        L637 = ctx->M638;
    }
    if (L24) {
        L636 = 0;
    } else {
        L636 = L637;
    }
    if (L53) {
        L635 = 1;
    } else {
        L635 = L636;
    }
    if (L67) {
        L642 = 1;
    } else {
        L642 = L636;
    }
    if (L62) {
        L641 = 1;
    } else {
        L641 = L642;
    }
    if (L57) {
        L640 = 1;
    } else {
        L640 = L641;
    }
    if (L114) {
        L645 = 1;
    } else {
        L645 = L636;
    }
    if (L112) {
        L644 = 1;
    } else {
        L644 = L645;
    }
    if (L110) {
        L643 = L644;
    } else {
        L643 = L636;
    }
    if (L45) {
        L639 = L640;
    } else {
        L639 = L643;
    }
    if (L36) {
        L634 = L635;
    } else {
        L634 = L639;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L647 = 1;
    } else {
        L647 = L636;
    }
    if (L39) {
        L646 = L647;
    } else {
        L646 = L636;
    }
    if (L33) {
        L633 = L634;
    } else {
        L633 = L646;
    }
    if (L21) {
        L632 = L633;
    } else {
        L632 = L647;
    }
    // top_O_IM_OUT_Log_Message_ID(ctx->client_data, L632);
    ctx->_IM_OUT_Log_Message_ID = L632;
    if (L53) {
        L75 = 0;
    } else {
        L75 = L69;
    }
    L464 = (L69 + 1);
    if (L459) {
        L466 = L464;
    } else {
        L466 = L69;
    }
    if (L457) {
        L465 = L464;
    } else {
        L465 = L466;
    }
    if (L120) {
        L119 = L464;
    } else {
        L119 = L465;
    }
    if (L96) {
        L118 = L69;
    } else {
        L118 = L119;
    }
    if (L107) {
        L117 = L118;
    } else {
        L117 = L69;
    }
    if (L81) {
        L80 = L69;
    } else {
        L80 = L117;
    }
    if (L67) {
        L79 = 0;
    } else {
        L79 = L80;
    }
    if (L62) {
        L78 = 0;
    } else {
        L78 = L79;
    }
    if (L57) {
        L77 = 0;
    } else {
        L77 = L78;
    }
    if (L114) {
        L469 = 0;
    } else {
        L469 = L69;
    }
    if (L112) {
        L468 = 0;
    } else {
        L468 = L469;
    }
    if (L110) {
        L467 = L468;
    } else {
        L467 = L69;
    }
    if (L45) {
        L76 = L77;
    } else {
        L76 = L467;
    }
    if (L36) {
        L74 = L75;
    } else {
        L74 = L76;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L471 = 0;
    } else {
        L471 = L69;
    }
    if (L39) {
        L470 = L471;
    } else {
        L470 = L69;
    }
    if (L33) {
        L73 = L74;
    } else {
        L73 = L470;
    }
    if (L21) {
        L72 = L73;
    } else {
        L72 = L471;
    }
    // top_O_IM_OUT_Actual_Infusion_Duration(ctx->client_data, L72);
    ctx->_IM_OUT_Actual_Infusion_Duration = L72;
    T638 = L632;
    T626 = L619;
    T604 = L581;
    T567 = L20;
    if (L493) {
        L506 = 0;
    } else {
        L506 = L494;
    }
    L505 = (L506 == 2);
    if (L505) {
        L504 = 0;
    } else {
        L504 = L506;
    }
    L503 = (L504 == 3);
    if (L503) {
        L502 = 0;
    } else {
        L502 = L504;
    }
    if (L81) {
        L501 = L502;
    } else {
        L501 = L494;
    }
    if (L45) {
        L500 = L501;
    } else {
        L500 = L494;
    }
    if (L513) {
        L512 = 2;
    } else {
        L512 = 3;
    }
    if (L483) {
        L511 = 1;
    } else {
        L511 = L512;
    }
    if (L96) {
        L510 = L511;
    } else {
        L510 = L501;
    }
    if (L552) {
        L551 = 2;
    } else {
        L551 = 3;
    }
    if (L520) {
        L519 = 1;
    } else {
        L519 = L551;
    }
    if (L556) {
        L555 = L519;
    } else {
        L555 = L494;
    }
    if (L554) {
        L553 = L519;
    } else {
        L553 = L555;
    }
    if (L493) {
        L518 = L519;
    } else {
        L518 = L553;
    }
    if (L102) {
        L517 = L502;
    } else {
        L517 = L518;
    }
    if (L96) {
        L558 = L511;
    } else {
        L558 = L494;
    }
    if (L107) {
        L557 = L558;
    } else {
        L557 = L494;
    }
    if (L81) {
        L516 = L517;
    } else {
        L516 = L557;
    }
    if (L67) {
        L515 = L501;
    } else {
        L515 = L516;
    }
    if (L62) {
        L509 = L510;
    } else {
        L509 = L515;
    }
    if (L57) {
        L508 = L501;
    } else {
        L508 = L509;
    }
    if (L114) {
        L561 = L558;
    } else {
        L561 = L494;
    }
    if (L112) {
        L560 = L494;
    } else {
        L560 = L561;
    }
    if (L110) {
        L559 = L560;
    } else {
        L559 = L494;
    }
    if (L45) {
        L507 = L508;
    } else {
        L507 = L559;
    }
    if (L36) {
        L499 = L500;
    } else {
        L499 = L507;
    }
    if (L33) {
        L498 = L499;
    } else {
        L498 = L494;
    }
    if (L21) {
        L497 = L498;
    } else {
        L497 = L494;
    }
    T496 = L497;
    if (L523) {
        L534 = 0;
    } else {
        L534 = L524;
    }
    L533 = (L534 == 2);
    if (L533) {
        L532 = 0;
    } else {
        L532 = L534;
    }
    if (L81) {
        L531 = L532;
    } else {
        L531 = L524;
    }
    if (L45) {
        L530 = L531;
    } else {
        L530 = L524;
    }
    if (L96) {
        L538 = L485;
    } else {
        L538 = L531;
    }
    if (L102) {
        L541 = L532;
    } else {
        L541 = L522;
    }
    if (L96) {
        L543 = L485;
    } else {
        L543 = L524;
    }
    if (L107) {
        L542 = L543;
    } else {
        L542 = L524;
    }
    if (L81) {
        L540 = L541;
    } else {
        L540 = L542;
    }
    if (L67) {
        L539 = L531;
    } else {
        L539 = L540;
    }
    if (L62) {
        L537 = L538;
    } else {
        L537 = L539;
    }
    if (L57) {
        L536 = L531;
    } else {
        L536 = L537;
    }
    if (L114) {
        L546 = L543;
    } else {
        L546 = L524;
    }
    if (L112) {
        L545 = L524;
    } else {
        L545 = L546;
    }
    if (L110) {
        L544 = L545;
    } else {
        L544 = L524;
    }
    if (L45) {
        L535 = L536;
    } else {
        L535 = L544;
    }
    if (L36) {
        L529 = L530;
    } else {
        L529 = L535;
    }
    if (L33) {
        L528 = L529;
    } else {
        L528 = L524;
    }
    if (L21) {
        L527 = L528;
    } else {
        L527 = L524;
    }
    T526 = L527;
    if (L53) {
        L52 = 0;
    } else {
        L52 = L54;
    }
    if (L67) {
        L66 = 2;
    } else {
        L66 = L46;
    }
    if (L62) {
        L61 = 1;
    } else {
        L61 = L66;
    }
    if (L57) {
        L56 = 2;
    } else {
        L56 = L61;
    }
    if (L114) {
        L476 = 1;
    } else {
        L476 = L46;
    }
    if (L112) {
        L475 = 2;
    } else {
        L475 = L476;
    }
    if (L110) {
        L474 = L475;
    } else {
        L474 = L46;
    }
    if (L45) {
        L55 = L56;
    } else {
        L55 = L474;
    }
    if (L36) {
        L51 = L52;
    } else {
        L51 = L55;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L478 = 2;
    } else {
        L478 = L46;
    }
    if (L39) {
        L477 = L478;
    } else {
        L477 = L46;
    }
    if (L33) {
        L50 = L51;
    } else {
        L50 = L477;
    }
    if (L21) {
        L49 = L50;
    } else {
        L49 = L478;
    }
    T48 = L49;
    T71 = L72;
    if (L81) {
        L91 = 0;
    } else {
        L91 = L82;
    }
    L90 = (L91 == 2);
    if (L120) {
        L133 = 0;
    } else {
        L133 = L121;
    }
    L132 = (L133 == 2);
    if (L132) {
        L131 = 0;
    } else {
        L131 = L133;
    }
    L130 = (L131 == 3);
    if (L130) {
        L129 = 0;
    } else {
        L129 = L131;
    }
    if (L90) {
        L128 = L129;
    } else {
        L128 = L121;
    }
    if (L45) {
        L127 = L128;
    } else {
        L127 = L121;
    }
    if (L139) {
        L138 = 1;
    } else {
        L138 = 3;
    }
    if (L96) {
        L137 = L128;
    } else {
        L137 = L138;
    }
    if (L102) {
        L307 = L138;
    } else {
        L307 = L121;
    }
    if (L314) {
        L313 = 2;
    } else {
        L313 = 3;
    }
    if (L312) {
        L311 = 1;
    } else {
        L311 = L313;
    }
    if (L459) {
        L458 = L311;
    } else {
        L458 = L121;
    }
    if (L457) {
        L456 = L311;
    } else {
        L456 = L458;
    }
    if (L120) {
        L310 = L311;
    } else {
        L310 = L456;
    }
    if (L96) {
        L309 = L129;
    } else {
        L309 = L310;
    }
    if (L107) {
        L308 = L309;
    } else {
        L308 = L121;
    }
    if (L81) {
        L306 = L307;
    } else {
        L306 = L308;
    }
    if (L67) {
        L305 = L128;
    } else {
        L305 = L306;
    }
    if (L62) {
        L136 = L137;
    } else {
        L136 = L305;
    }
    if (L57) {
        L135 = L128;
    } else {
        L135 = L136;
    }
    if (L96) {
        L463 = L121;
    } else {
        L463 = 3;
    }
    if (L114) {
        L462 = L463;
    } else {
        L462 = L121;
    }
    if (L112) {
        L461 = L121;
    } else {
        L461 = L462;
    }
    if (L110) {
        L460 = L461;
    } else {
        L460 = L121;
    }
    if (L45) {
        L134 = L135;
    } else {
        L134 = L460;
    }
    if (L36) {
        L126 = L127;
    } else {
        L126 = L134;
    }
    if (L33) {
        L125 = L126;
    } else {
        L125 = L121;
    }
    if (L21) {
        L124 = L125;
    } else {
        L124 = L121;
    }
    T123 = L124;
    if (L316) {
        L327 = 0;
    } else {
        L327 = L317;
    }
    L326 = (L327 == 2);
    L352 = (! L326);
    L351 = (L352 && L343);
    if (L90) {
        L350 = L351;
    } else {
        L350 = L343;
    }
    if (L45) {
        L349 = L350;
    } else {
        L349 = L343;
    }
    L361 = (1 > ctx->_CONFIG_IN_Interval_Intermittent_Bolus);
    L364 = (1 <= ctx->_CONFIG_IN_Interval_Intermittent_Bolus);
    if (L364) {
        L363 = ctx->_CONFIG_IN_Interval_Intermittent_Bolus;
    } else {
        L363 = 0;
    }
    L362 = (1 < L363);
    L360 = (L361 || L362);
    L366 = (1 == ctx->_CONFIG_IN_Interval_Intermittent_Bolus);
    if (L366) {
        L365 = 1;
    } else {
        L365 = 0;
    }
    if (L360) {
        L359 = 0;
    } else {
        L359 = L365;
    }
    L358 = (L359 == 0);
    L357 = (! L358);
    if (L96) {
        L356 = L350;
    } else {
        L356 = L357;
    }
    if (ctx->M25) {
        L377 = 0;
    } else {
        L377 = ctx->M378;
    }
    if (L24) {
        L376 = 0;
    } else {
        L376 = L377;
    }
    L375 = (L376 + 1);
    L374 = (L375 > ctx->_CONFIG_IN_Interval_Intermittent_Bolus);
    L442 = (L375 <= ctx->_CONFIG_IN_Interval_Intermittent_Bolus);
    if (L442) {
        L441 = ctx->_CONFIG_IN_Interval_Intermittent_Bolus;
    } else {
        L441 = 0;
    }
    L440 = (L375 < L441);
    L373 = (L374 || L440);
    L394 = (L375 == ctx->_CONFIG_IN_Interval_Intermittent_Bolus);
    if (L394) {
        L443 = 1;
    } else {
        L443 = 0;
    }
    if (L373) {
        L372 = 0;
    } else {
        L372 = L443;
    }
    L371 = (L372 == 0);
    L370 = (! L371);
    if (L102) {
        L369 = L370;
    } else {
        L369 = L343;
    }
    if (L342) {
        L447 = L343;
    } else {
        L447 = L370;
    }
    L449 = (L402 && L370);
    if (L400) {
        L448 = L449;
    } else {
        L448 = L343;
    }
    if (L316) {
        L446 = L447;
    } else {
        L446 = L448;
    }
    if (L96) {
        L445 = L351;
    } else {
        L445 = L446;
    }
    if (L107) {
        L444 = L445;
    } else {
        L444 = L343;
    }
    if (L81) {
        L368 = L369;
    } else {
        L368 = L444;
    }
    if (L67) {
        L367 = L350;
    } else {
        L367 = L368;
    }
    if (L62) {
        L355 = L356;
    } else {
        L355 = L367;
    }
    if (L57) {
        L354 = L350;
    } else {
        L354 = L355;
    }
    if (L96) {
        L453 = L343;
    } else {
        L453 = L357;
    }
    if (L114) {
        L452 = L453;
    } else {
        L452 = L343;
    }
    if (L112) {
        L451 = L343;
    } else {
        L451 = L452;
    }
    if (L110) {
        L450 = L451;
    } else {
        L450 = L343;
    }
    if (L45) {
        L353 = L354;
    } else {
        L353 = L450;
    }
    if (L36) {
        L348 = L349;
    } else {
        L348 = L353;
    }
    if (L33) {
        L347 = L348;
    } else {
        L347 = L343;
    }
    if (L21) {
        L346 = L347;
    } else {
        L346 = L343;
    }
    T345 = L346;
    if (L53) {
        L382 = 0;
    } else {
        L382 = L376;
    }
    if (L366) {
        L388 = 0;
    } else {
        L388 = 1;
    }
    if (L360) {
        L387 = 1;
    } else {
        L387 = L388;
    }
    if (L96) {
        L386 = 0;
    } else {
        L386 = L387;
    }
    if (L394) {
        L393 = 0;
    } else {
        L393 = L375;
    }
    if (L373) {
        L392 = L375;
    } else {
        L392 = L393;
    }
    if (L102) {
        L391 = L392;
    } else {
        L391 = L376;
    }
    if (L342) {
        L398 = L375;
    } else {
        L398 = L392;
    }
    if (L402) {
        L401 = L392;
    } else {
        L401 = L375;
    }
    if (L400) {
        L399 = L401;
    } else {
        L399 = L375;
    }
    if (L316) {
        L397 = L398;
    } else {
        L397 = L399;
    }
    if (L96) {
        L396 = L376;
    } else {
        L396 = L397;
    }
    if (L107) {
        L395 = L396;
    } else {
        L395 = L376;
    }
    if (L81) {
        L390 = L391;
    } else {
        L390 = L395;
    }
    if (L67) {
        L389 = 0;
    } else {
        L389 = L390;
    }
    if (L62) {
        L385 = L386;
    } else {
        L385 = L389;
    }
    if (L57) {
        L384 = 0;
    } else {
        L384 = L385;
    }
    if (L114) {
        L437 = L386;
    } else {
        L437 = L376;
    }
    if (L112) {
        L436 = 0;
    } else {
        L436 = L437;
    }
    if (L110) {
        L435 = L436;
    } else {
        L435 = L376;
    }
    if (L45) {
        L383 = L384;
    } else {
        L383 = L435;
    }
    if (L36) {
        L381 = L382;
    } else {
        L381 = L383;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L439 = 0;
    } else {
        L439 = L376;
    }
    if (L39) {
        L438 = L439;
    } else {
        L438 = L376;
    }
    if (L33) {
        L380 = L381;
    } else {
        L380 = L438;
    }
    if (L21) {
        L379 = L380;
    } else {
        L379 = L439;
    }
    T378 = L379;
    L414 = (L404 + 1);
    if (L326) {
        L413 = L414;
    } else {
        L413 = L404;
    }
    if (L90) {
        L412 = L413;
    } else {
        L412 = L404;
    }
    if (L45) {
        L411 = L412;
    } else {
        L411 = L404;
    }
    if (L53) {
        L410 = 0;
    } else {
        L410 = L411;
    }
    if (L326) {
        L420 = 1;
    } else {
        L420 = 0;
    }
    if (L90) {
        L419 = L420;
    } else {
        L419 = 0;
    }
    if (L96) {
        L418 = L419;
    } else {
        L418 = 0;
    }
    if (L102) {
        L423 = 0;
    } else {
        L423 = L404;
    }
    if (L402) {
        L428 = 0;
    } else {
        L428 = L414;
    }
    if (L400) {
        L427 = L428;
    } else {
        L427 = L404;
    }
    if (L316) {
        L426 = L404;
    } else {
        L426 = L427;
    }
    if (L96) {
        L425 = L413;
    } else {
        L425 = L426;
    }
    if (L107) {
        L424 = L425;
    } else {
        L424 = L404;
    }
    if (L81) {
        L422 = L423;
    } else {
        L422 = L424;
    }
    if (L67) {
        L421 = 0;
    } else {
        L421 = L422;
    }
    if (L62) {
        L417 = L418;
    } else {
        L417 = L421;
    }
    if (L57) {
        L416 = 0;
    } else {
        L416 = L417;
    }
    if (L114) {
        L431 = 0;
    } else {
        L431 = L404;
    }
    if (L112) {
        L430 = 0;
    } else {
        L430 = L431;
    }
    if (L110) {
        L429 = L430;
    } else {
        L429 = L404;
    }
    if (L45) {
        L415 = L416;
    } else {
        L415 = L429;
    }
    if (L36) {
        L409 = L410;
    } else {
        L409 = L415;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L433 = 0;
    } else {
        L433 = L404;
    }
    if (L39) {
        L432 = L433;
    } else {
        L432 = L404;
    }
    if (L33) {
        L408 = L409;
    } else {
        L408 = L432;
    }
    if (L21) {
        L407 = L408;
    } else {
        L407 = L433;
    }
    T406 = L407;
    if (L326) {
        L325 = 0;
    } else {
        L325 = L327;
    }
    if (L90) {
        L324 = L325;
    } else {
        L324 = L317;
    }
    if (L45) {
        L323 = L324;
    } else {
        L323 = L317;
    }
    if (L96) {
        L331 = L324;
    } else {
        L331 = 1;
    }
    if (L102) {
        L334 = 1;
    } else {
        L334 = L317;
    }
    if (L96) {
        L336 = L325;
    } else {
        L336 = L315;
    }
    if (L107) {
        L335 = L336;
    } else {
        L335 = L317;
    }
    if (L81) {
        L333 = L334;
    } else {
        L333 = L335;
    }
    if (L67) {
        L332 = L324;
    } else {
        L332 = L333;
    }
    if (L62) {
        L330 = L331;
    } else {
        L330 = L332;
    }
    if (L57) {
        L329 = L324;
    } else {
        L329 = L330;
    }
    if (L96) {
        L340 = L317;
    } else {
        L340 = 1;
    }
    if (L114) {
        L339 = L340;
    } else {
        L339 = L317;
    }
    if (L112) {
        L338 = L317;
    } else {
        L338 = L339;
    }
    if (L110) {
        L337 = L338;
    } else {
        L337 = L317;
    }
    if (L45) {
        L328 = L329;
    } else {
        L328 = L337;
    }
    if (L36) {
        L322 = L323;
    } else {
        L322 = L328;
    }
    if (L33) {
        L321 = L322;
    } else {
        L321 = L317;
    }
    if (L21) {
        L320 = L321;
    } else {
        L320 = L317;
    }
    T319 = L320;
    L149 = (! L53);
    L148 = (L149 && L141);
    L152 = (! L57);
    L155 = (L141 && L141);
    if (L96) {
        L154 = L141;
    } else {
        L154 = L155;
    }
    L157 = (! L67);
    if (L102) {
        L159 = L155;
    } else {
        L159 = L141;
    }
    L294 = (L218 || L141);
    L297 = (L249 < L277);
    L296 = (L297 && L141);
    if (L246) {
        L295 = L296;
    } else {
        L295 = L141;
    }
    if (L216) {
        L293 = L294;
    } else {
        L293 = L295;
    }
    if (L163) {
        L162 = L141;
    } else {
        L162 = L293;
    }
    if (L96) {
        L161 = L141;
    } else {
        L161 = L162;
    }
    if (L107) {
        L160 = L161;
    } else {
        L160 = L141;
    }
    if (L81) {
        L158 = L159;
    } else {
        L158 = L160;
    }
    L156 = (L157 && L158);
    if (L62) {
        L153 = L154;
    } else {
        L153 = L156;
    }
    L151 = (L152 && L153);
    L300 = (! L112);
    L302 = (! L114);
    L301 = (L302 && L141);
    L299 = (L300 && L301);
    if (L110) {
        L298 = L299;
    } else {
        L298 = L141;
    }
    if (L45) {
        L150 = L151;
    } else {
        L150 = L298;
    }
    if (L36) {
        L147 = L148;
    } else {
        L147 = L150;
    }
    L304 = (L36 && L141);
    if (L39) {
        L303 = L304;
    } else {
        L303 = L141;
    }
    if (L33) {
        L146 = L147;
    } else {
        L146 = L303;
    }
    if (L21) {
        L145 = L146;
    } else {
        L145 = L304;
    }
    T144 = L145;
    if (L163) {
        L176 = 0;
    } else {
        L176 = L164;
    }
    L175 = (L176 == 2);
    if (L175) {
        L174 = 0;
    } else {
        L174 = L176;
    }
    L173 = (L174 == 3);
    if (L173) {
        L172 = 0;
    } else {
        L172 = L174;
    }
    if (L90) {
        L171 = L172;
    } else {
        L171 = L164;
    }
    if (L45) {
        L170 = L171;
    } else {
        L170 = L164;
    }
    if (L96) {
        L180 = L171;
    } else {
        L180 = L140;
    }
    if (L102) {
        L183 = L140;
    } else {
        L183 = L164;
    }
    if (L96) {
        L185 = L172;
    } else {
        L185 = L186;
    }
    if (L107) {
        L184 = L185;
    } else {
        L184 = L164;
    }
    if (L81) {
        L182 = L183;
    } else {
        L182 = L184;
    }
    if (L67) {
        L181 = L171;
    } else {
        L181 = L182;
    }
    if (L62) {
        L179 = L180;
    } else {
        L179 = L181;
    }
    if (L57) {
        L178 = L171;
    } else {
        L178 = L179;
    }
    if (L96) {
        L292 = L164;
    } else {
        L292 = 2;
    }
    if (L114) {
        L291 = L292;
    } else {
        L291 = L164;
    }
    if (L112) {
        L290 = L164;
    } else {
        L290 = L291;
    }
    if (L110) {
        L289 = L290;
    } else {
        L289 = L164;
    }
    if (L45) {
        L177 = L178;
    } else {
        L177 = L289;
    }
    if (L36) {
        L169 = L170;
    } else {
        L169 = L177;
    }
    if (L33) {
        L168 = L169;
    } else {
        L168 = L164;
    }
    if (L21) {
        L167 = L168;
    } else {
        L167 = L164;
    }
    T166 = L167;
    L200 = (L190 + 1);
    if (L163) {
        L199 = L200;
    } else {
        L199 = L190;
    }
    if (L90) {
        L198 = L199;
    } else {
        L198 = L190;
    }
    if (L45) {
        L197 = L198;
    } else {
        L197 = L190;
    }
    if (L53) {
        L196 = 0;
    } else {
        L196 = L197;
    }
    if (L163) {
        L206 = 1;
    } else {
        L206 = 0;
    }
    if (L90) {
        L205 = L206;
    } else {
        L205 = 0;
    }
    if (L141) {
        L207 = L205;
    } else {
        L207 = 0;
    }
    if (L96) {
        L204 = L205;
    } else {
        L204 = L207;
    }
    if (L141) {
        L211 = L190;
    } else {
        L211 = 0;
    }
    if (L102) {
        L210 = L211;
    } else {
        L210 = L190;
    }
    if (L218) {
        L217 = L200;
    } else {
        L217 = L190;
    }
    if (L248) {
        L247 = 0;
    } else {
        L247 = L190;
    }
    if (L246) {
        L245 = L247;
    } else {
        L245 = L190;
    }
    if (L216) {
        L215 = L217;
    } else {
        L215 = L245;
    }
    if (L163) {
        L214 = L200;
    } else {
        L214 = L215;
    }
    if (L96) {
        L213 = L199;
    } else {
        L213 = L214;
    }
    if (L107) {
        L212 = L213;
    } else {
        L212 = L190;
    }
    if (L81) {
        L209 = L210;
    } else {
        L209 = L212;
    }
    if (L67) {
        L208 = 0;
    } else {
        L208 = L209;
    }
    if (L62) {
        L203 = L204;
    } else {
        L203 = L208;
    }
    if (L57) {
        L202 = 0;
    } else {
        L202 = L203;
    }
    if (L114) {
        L280 = 0;
    } else {
        L280 = L190;
    }
    if (L112) {
        L279 = 0;
    } else {
        L279 = L280;
    }
    if (L110) {
        L278 = L279;
    } else {
        L278 = L190;
    }
    if (L45) {
        L201 = L202;
    } else {
        L201 = L278;
    }
    if (L36) {
        L195 = L196;
    } else {
        L195 = L201;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L282 = 0;
    } else {
        L282 = L190;
    }
    if (L39) {
        L281 = L282;
    } else {
        L281 = L190;
    }
    if (L33) {
        L194 = L195;
    } else {
        L194 = L281;
    }
    if (L21) {
        L193 = L194;
    } else {
        L193 = L282;
    }
    T192 = L193;
    if (L53) {
        L255 = 0;
    } else {
        L255 = L249;
    }
    L261 = (L249 + 1);
    if (L141) {
        L260 = L261;
    } else {
        L260 = L249;
    }
    if (L96) {
        L259 = L249;
    } else {
        L259 = L260;
    }
    if (L102) {
        L264 = L260;
    } else {
        L264 = L249;
    }
    if (L188) {
        L268 = 1;
    } else {
        L268 = L249;
    }
    if (L248) {
        L271 = L249;
    } else {
        L271 = L261;
    }
    if (L246) {
        L270 = L271;
    } else {
        L270 = L249;
    }
    if (L216) {
        L269 = L249;
    } else {
        L269 = L270;
    }
    if (L163) {
        L267 = L268;
    } else {
        L267 = L269;
    }
    if (L96) {
        L266 = L249;
    } else {
        L266 = L267;
    }
    if (L107) {
        L265 = L266;
    } else {
        L265 = L249;
    }
    if (L81) {
        L263 = L264;
    } else {
        L263 = L265;
    }
    if (L67) {
        L262 = 0;
    } else {
        L262 = L263;
    }
    if (L62) {
        L258 = L259;
    } else {
        L258 = L262;
    }
    if (L57) {
        L257 = 0;
    } else {
        L257 = L258;
    }
    if (L114) {
        L274 = 0;
    } else {
        L274 = L249;
    }
    if (L112) {
        L273 = 0;
    } else {
        L273 = L274;
    }
    if (L110) {
        L272 = L273;
    } else {
        L272 = L249;
    }
    if (L45) {
        L256 = L257;
    } else {
        L256 = L272;
    }
    if (L36) {
        L254 = L255;
    } else {
        L254 = L256;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L276 = 0;
    } else {
        L276 = L249;
    }
    if (L39) {
        L275 = L276;
    } else {
        L275 = L249;
    }
    if (L33) {
        L253 = L254;
    } else {
        L253 = L275;
    }
    if (L21) {
        L252 = L253;
    } else {
        L252 = L276;
    }
    T251 = L252;
    if (L53) {
        L228 = 0;
    } else {
        L228 = L222;
    }
    L239 = (L222 + 1);
    if (L218) {
        L238 = L239;
    } else {
        L238 = L222;
    }
    if (L216) {
        L237 = L238;
    } else {
        L237 = L222;
    }
    if (L163) {
        L236 = L222;
    } else {
        L236 = L237;
    }
    if (L96) {
        L235 = L222;
    } else {
        L235 = L236;
    }
    if (L107) {
        L234 = L235;
    } else {
        L234 = L222;
    }
    if (L81) {
        L233 = L222;
    } else {
        L233 = L234;
    }
    if (L67) {
        L232 = 0;
    } else {
        L232 = L233;
    }
    if (L62) {
        L231 = 0;
    } else {
        L231 = L232;
    }
    if (L57) {
        L230 = 0;
    } else {
        L230 = L231;
    }
    if (L114) {
        L242 = 0;
    } else {
        L242 = L222;
    }
    if (L112) {
        L241 = 0;
    } else {
        L241 = L242;
    }
    if (L110) {
        L240 = L241;
    } else {
        L240 = L222;
    }
    if (L45) {
        L229 = L230;
    } else {
        L229 = L240;
    }
    if (L36) {
        L227 = L228;
    } else {
        L227 = L229;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L244 = 0;
    } else {
        L244 = L222;
    }
    if (L39) {
        L243 = L244;
    } else {
        L243 = L222;
    }
    if (L33) {
        L226 = L227;
    } else {
        L226 = L243;
    }
    if (L21) {
        L225 = L226;
    } else {
        L225 = L244;
    }
    T224 = L225;
    if (L90) {
        L89 = 0;
    } else {
        L89 = L91;
    }
    if (L45) {
        L88 = L89;
    } else {
        L88 = L82;
    }
    if (L96) {
        L95 = 1;
    } else {
        L95 = 2;
    }
    if (L102) {
        L101 = 2;
    } else {
        L101 = L82;
    }
    if (L96) {
        L108 = 1;
    } else {
        L108 = L82;
    }
    if (L107) {
        L106 = L108;
    } else {
        L106 = L82;
    }
    if (L81) {
        L100 = L101;
    } else {
        L100 = L106;
    }
    if (L67) {
        L99 = L89;
    } else {
        L99 = L100;
    }
    if (L62) {
        L94 = L95;
    } else {
        L94 = L99;
    }
    if (L57) {
        L93 = L89;
    } else {
        L93 = L94;
    }
    if (L114) {
        L113 = L95;
    } else {
        L113 = L82;
    }
    if (L112) {
        L111 = L82;
    } else {
        L111 = L113;
    }
    if (L110) {
        L109 = L111;
    } else {
        L109 = L82;
    }
    if (L45) {
        L92 = L93;
    } else {
        L92 = L109;
    }
    if (L36) {
        L87 = L88;
    } else {
        L87 = L92;
    }
    if (L33) {
        L86 = L87;
    } else {
        L86 = L82;
    }
    if (L21) {
        L85 = L86;
    } else {
        L85 = L82;
    }
    T84 = L85;
    if (L36) {
        L35 = 2;
    } else {
        L35 = L23;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L40 = 1;
    } else {
        L40 = L23;
    }
    if (L39) {
        L38 = L40;
    } else {
        L38 = L23;
    }
    if (L33) {
        L32 = L35;
    } else {
        L32 = L38;
    }
    if (ctx->_TLM_MODE_IN_On_Start) {
        L41 = 1;
    } else {
        L41 = 2;
    }
    if (L21) {
        L31 = L32;
    } else {
        L31 = L41;
    }
    T30 = L31;
    ctx->M638 = T638;
    ctx->M638_nil = _false;
    ctx->M626 = T626;
    ctx->M626_nil = _false;
    ctx->M604 = T604;
    ctx->M604_nil = _false;
    ctx->M567 = T567;
    ctx->M567_nil = _false;
    ctx->M496 = T496;
    ctx->M496_nil = _false;
    ctx->M526 = T526;
    ctx->M526_nil = _false;
    ctx->M48 = T48;
    ctx->M48_nil = _false;
    ctx->M71 = T71;
    ctx->M71_nil = _false;
    ctx->M123 = T123;
    ctx->M123_nil = _false;
    ctx->M345 = T345;
    ctx->M345_nil = _false;
    ctx->M378 = T378;
    ctx->M378_nil = _false;
    ctx->M406 = T406;
    ctx->M406_nil = _false;
    ctx->M319 = T319;
    ctx->M319_nil = _false;
    ctx->M144 = T144;
    ctx->M144_nil = _false;
    ctx->M166 = T166;
    ctx->M166_nil = _false;
    ctx->M192 = T192;
    ctx->M192_nil = _false;
    ctx->M251 = T251;
    ctx->M251_nil = _false;
    ctx->M224 = T224;
    ctx->M224_nil = _false;
    ctx->M84 = T84;
    ctx->M84_nil = _false;
    ctx->M30 = T30;
    ctx->M30_nil = _false;
    ctx->M25 = ctx->M25 && !(_true);
}

/* testing features **********************************************************/
/* testing features **********************************************************/

#define NO_OF_TIMES_TO_RUN 1

typedef struct input_t {
   //INPUTS
   int TLM_MODE_IN_On_Start;           // bool
   int OP_CMD_IN_Infusion_Initiate;    // bool
   int OP_CMD_IN_Infusion_Inhibit;     // bool
   int OP_CMD_IN_Infusion_Cancel;      // bool
   int PATIENT_IN_Bolus_Request;       // bool
   int CONFIG_IN_Flow_Rate_Basal; 
   int CONFIG_IN_Flow_Rate_Intermittent_Bolus;
   int CONFIG_IN_Intermittent_Bolus_Duration;
   int CONFIG_IN_Flow_Rate_Patient_Bolus;
   int CONFIG_IN_Patient_Bolus_Duration;
   int CONFIG_IN_Lock_Out_Duration;
   int CONFIG_IN_Max_Patient_Bolus;
   int CONFIG_IN_Interval_Intermittent_Bolus;
   int CONFIG_IN_Duration_Total;
   int CONFIG_IN_VTBI_Total;
   int CONFIG_IN_Configured;
   int CONFIG_IN_Flow_Rate_KVO;
   int ALARM_IN_Highest_Level_Alarm;
   int SYS_STAT_IN_Reservoir_Empty;    // bool
   int SYS_STAT_Volume_Infused;
} input_t ;

typedef struct input_node_t {
	input_t elem;
	struct input_node_t *next;
} input_node_t ;

typedef struct test_node_t {
	input_node_t *steps;
	struct test_node_t *next;
} test_node_t;

void assign_inputs(top_ctx* ctx, input_t* i) {
   ctx->_TLM_MODE_IN_On_Start = i->TLM_MODE_IN_On_Start;
   ctx->_OP_CMD_IN_Infusion_Initiate = i->OP_CMD_IN_Infusion_Initiate;
   ctx->_OP_CMD_IN_Infusion_Inhibit = i->OP_CMD_IN_Infusion_Inhibit;
   ctx->_OP_CMD_IN_Infusion_Cancel = i->OP_CMD_IN_Infusion_Cancel;
   ctx->_PATIENT_IN_Bolus_Request = i->PATIENT_IN_Bolus_Request;
   ctx->_CONFIG_IN_Flow_Rate_Basal = i->CONFIG_IN_Flow_Rate_Basal;
   ctx->_CONFIG_IN_Flow_Rate_Intermittent_Bolus = i->CONFIG_IN_Flow_Rate_Intermittent_Bolus;
   ctx->_CONFIG_IN_Intermittent_Bolus_Duration = i->CONFIG_IN_Intermittent_Bolus_Duration;
   ctx->_CONFIG_IN_Flow_Rate_Patient_Bolus = i->CONFIG_IN_Flow_Rate_Patient_Bolus;
   ctx->_CONFIG_IN_Patient_Bolus_Duration = i->CONFIG_IN_Patient_Bolus_Duration;
   ctx->_CONFIG_IN_Lock_Out_Duration = i->CONFIG_IN_Lock_Out_Duration;
   ctx->_CONFIG_IN_Max_Patient_Bolus = i->CONFIG_IN_Max_Patient_Bolus;
   ctx->_CONFIG_IN_Interval_Intermittent_Bolus = i->CONFIG_IN_Interval_Intermittent_Bolus;
   ctx->_CONFIG_IN_Duration_Total = i->CONFIG_IN_Duration_Total;
   ctx->_CONFIG_IN_VTBI_Total = i->CONFIG_IN_VTBI_Total;
   ctx->_CONFIG_IN_Configured = i->CONFIG_IN_Configured;
   ctx->_CONFIG_IN_Flow_Rate_KVO = i->CONFIG_IN_Flow_Rate_KVO;
   ctx->_ALARM_IN_Highest_Level_Alarm = i->ALARM_IN_Highest_Level_Alarm;
   ctx->_SYS_STAT_IN_Reservoir_Empty = i->SYS_STAT_IN_Reservoir_Empty;
   ctx->_SYS_STAT_Volume_Infused = i->SYS_STAT_Volume_Infused;
}

int bool_lit_toint(char* boollit) {
    if (strcmp(boollit, "true") == 0) {
        return 1;
    } else if (strcmp(boollit, "false") == 0) {
        return 0;
    } else {
        if (boollit[0] == 't') {
            return 1;
        } else if (boollit[0] == 'f') {
            return 0;
        }
        return -1;
    }
}

double extract_double(char* lit) {
    //TODO
    char numerator[10], denominator[10];
    int j = 0, k = 0;
    int slashed = 0;
    for (int i=0; i<strlen(lit); i++) {
        if (lit[i] == '/') {
            slashed = 1;
            continue;
        }
        if (!slashed) {
            numerator[j++] = lit[i];
        } else {
            denominator[k++] = lit[i];
        }
    }
    numerator[j] = '\0';
    denominator[j] = '\0';
    if (slashed) {
        return (double) atof(numerator) / atof(denominator);
    } else {
        return atof(numerator);
    }
}

void scan_input(char *buffer, input_t *in) {
    // Input variables are given in the following order:
    //
    // ALARM_IN_Highest_Level_Alarm, CONFIG_IN_Configured,
    // CONFIG_IN_Duration_Total, CONFIG_IN_Flow_Rate_Basal,
    // CONFIG_IN_Flow_Rate_Intermittent_Bolus, CONFIG_IN_Flow_Rate_KVO,
    // CONFIG_IN_Flow_Rate_Patient_Bolus, CONFIG_IN_Intermittent_Bolus_Duration,
    // CONFIG_IN_Interval_Intermittent_Bolus, CONFIG_IN_Lock_Out_Duration,
    // CONFIG_IN_Max_Patient_Bolus, CONFIG_IN_Patient_Bolus_Duration,
    // CONFIG_IN_VTBI_Total, OP_CMD_IN_Infusion_Cancel, 
    // OP_CMD_IN_Infusion_Inhibit, OP_CMD_IN_Infusion_Initiate,
    // PATIENT_IN_Bolus_Request, SYS_STAT_IN_Reservoir_Empty,
    // SYS_STAT_Volume_Infused, TLM_MODE_IN_On_Start
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13;
    char b14[8], b15[8], b16[8], b17[8], b18[8];
    int d19;
    char b20[8];

	sscanf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%[^','],%[^','],%[^','],%[^','],%[^','],%d,%[^',']",
            &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12, &d13,
            b14, b15, b16, b17, b18, &d19, b20);
    in->ALARM_IN_Highest_Level_Alarm = d1;
    in->CONFIG_IN_Configured = d2;
    in->CONFIG_IN_Duration_Total = d3;
    in->CONFIG_IN_Flow_Rate_Basal = d4;
    in->CONFIG_IN_Flow_Rate_Intermittent_Bolus = d5;
    in->CONFIG_IN_Flow_Rate_KVO = d6;
    in->CONFIG_IN_Flow_Rate_Patient_Bolus = d7;
    in->CONFIG_IN_Intermittent_Bolus_Duration = d8;
    in->CONFIG_IN_Interval_Intermittent_Bolus = d9;
    in->CONFIG_IN_Lock_Out_Duration = d10;
    in->CONFIG_IN_Max_Patient_Bolus = d11;
    in->CONFIG_IN_Patient_Bolus_Duration = d12;
    in->CONFIG_IN_VTBI_Total = d13;
    in->OP_CMD_IN_Infusion_Cancel = bool_lit_toint(b14);
    in->OP_CMD_IN_Infusion_Inhibit = bool_lit_toint(b15);
    in->OP_CMD_IN_Infusion_Initiate = bool_lit_toint(b16);
    in->PATIENT_IN_Bolus_Request = bool_lit_toint(b17);
    in->SYS_STAT_IN_Reservoir_Empty = bool_lit_toint(b18);
    in->SYS_STAT_Volume_Infused = d19;
    in->TLM_MODE_IN_On_Start = bool_lit_toint(b20);
#if DEBUG
    printf("(%d %d %d %d %d, %d %d %d %d %d, ",
        in->ALARM_IN_Highest_Level_Alarm, in->CONFIG_IN_Configured,
        in->CONFIG_IN_Duration_Total, in->CONFIG_IN_Flow_Rate_Basal,
        in->CONFIG_IN_Flow_Rate_Intermittent_Bolus, in->CONFIG_IN_Flow_Rate_KVO,
        in->CONFIG_IN_Flow_Rate_Patient_Bolus, in->CONFIG_IN_Intermittent_Bolus_Duration,
        in->CONFIG_IN_Interval_Intermittent_Bolus, in->CONFIG_IN_Lock_Out_Duration);
    printf("%d %d %d %d %d, %d %d %d %d %d).\n",
        in->CONFIG_IN_Max_Patient_Bolus, in->CONFIG_IN_Patient_Bolus_Duration,
        in->CONFIG_IN_VTBI_Total, in->OP_CMD_IN_Infusion_Cancel,
        in->OP_CMD_IN_Infusion_Inhibit, in->OP_CMD_IN_Infusion_Initiate,
        in->PATIENT_IN_Bolus_Request, in->SYS_STAT_IN_Reservoir_Empty,
        in->SYS_STAT_Volume_Infused, in->TLM_MODE_IN_On_Start);
#endif
}

FILE* create_trace_file(char* fname) {
    /* open the trace file to dump the output
     * @return the file pointer of the trace file */
  if (NULL == fname) {
    return NULL;
  }
  char* HEADER = "_IM_OUT_Flow_Rate_Commanded,_IM_OUT_Current_System_Mode," \
                  "_IM_OUT_New_Infusion,_IM_OUT_Log_Message_ID," \
                  "_IM_OUT_Actual_Infusion_Duration";
  FILE* fp = fopen(fname, "w");
  /* print the CSV header (5 output variables) */
  //fprintf(fp, "%s\n", HEADER);
  return fp;
}

// 5 outputs in total (in obsnop.trace)
void dump_state(FILE* fp, top_ctx* ctx) {
    /* dump the internal state for the current step
     * so that it can later be compared to the oracle */
  if (NULL == fp) {
    return;
  } else if (NULL == ctx) {
    fprintf(fp, "\n");
    return;
  }
  //HEADER
  //fprintf(fp "_IM_OUT_Flow_Rate_Commanded,_IM_OUT_Current_System_Mode,_IM_OUT_New_Infusion,_IM_OUT_Log_Message_ID,_IM_OUT_Actual_Infusion_Duration\n");
  //fprintf(fp, "%d,%d\n", ctx->_X, ctx->_E);
  fprintf(fp, "%d,%d,%d,%d,%d\n", ctx->_IM_OUT_Flow_Rate_Commanded,
      ctx->_IM_OUT_Current_System_Mode, ctx->_IM_OUT_New_Infusion,
      ctx->_IM_OUT_Log_Message_ID, ctx->_IM_OUT_Actual_Infusion_Duration);
}

void populate_tests(FILE *fp, test_node_t *first) {

	char buffer[1000];
	test_node_t *current_test = first;
	int testCount;
	int stepCount;
	current_test->next = NULL;
	current_test->steps = NULL;

	input_node_t *current_step = NULL;

	int count = 0;
    fgets(buffer, 999, fp); // skip the header
	while (fgets(buffer, 999, fp) != NULL) {
		count++;
		// blank line indicates the beginning of a new test case
		if (strcmp(buffer, "\n") == 0 || strcmp(buffer, "\n") == 0) {
			test_node_t *next = (test_node_t *)malloc(sizeof(test_node_t));
			if(next != NULL) {
				next->steps = NULL;
				next->next = NULL;
				current_test->next = next;
				current_test = next;
				current_step = NULL;
			} else {
				printf("Malloc failed\n");
			}
		} else {
			// non-blank line means the test case continues to a next step
			input_node_t *next = (input_node_t *)malloc(sizeof(input_node_t));
			if(next != NULL) {
				next->next = NULL;
				scan_input(buffer, &(next->elem));
				if (current_step != NULL) {
					current_step->next = next ;
				} else {
					current_test->steps = next;
				}
                current_step = next;
			} else {
				printf("Malloc failed\n");
			}
		}
	}
}

top_ctx ctx;

/* end of testing features ***************************************************/
int main(int argc, char** argv){
  /* testing facility */
  char* test_input_file = NULL;
  char* trace_file = NULL;
  if (argc == 2) {
    test_input_file = argv[1];
  } else if (argc == 3) {
    test_input_file = argv[1];
    trace_file = argv[2];
  } else {
    printf("[infusion] invalid number of argument\n");
    return -1;
  }
  FILE *fp = fopen(test_input_file, "r");
  if(fp == NULL) {
    printf("Unable to open %s\n", argv[1]);
    return -1;
  }
  test_node_t tests;
  populate_tests(fp, &tests);
  fclose(fp);

  /* Context allocation */
  //struct top_ctx* ctx = top_new_ctx(NULL);
  top_reset(&ctx);
  /* Main loop */
  long n_test_cases, n_steps;
  FILE* fp_dump = create_trace_file(trace_file);

  n_test_cases = 0;
  test_node_t *current_test = &tests;
  input_node_t *current_step = NULL;

  while (current_test != NULL) {
    current_step = current_test->steps;

    n_steps = 0;
    while (current_step != NULL) {
      assign_inputs(&ctx, &(current_step->elem));
      top_step(&ctx);
      dump_state(fp_dump, &ctx);
      current_step = current_step->next;
      n_steps++;
    }
    /* finished: consumed all the steps of the current test case */
    //dump_state(fp_dump, NULL);          // dump a blank line
    memset(&ctx, 0, sizeof(top_ctx));    // init the state variables
    top_reset(&ctx);                     // reset the registers
    n_test_cases++;
    current_test = current_test->next;
  }
  if (NULL != fp_dump)
  fclose(fp_dump);

  return 0;
}

