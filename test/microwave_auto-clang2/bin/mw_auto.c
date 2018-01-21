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
#endif
/********
* ec2c version 0.67
* c file generated for node : top
* context   method = HEAP
* ext call  method = PROCEDURES
********/
#include <stdlib.h>
#include <string.h>
#define _top_EC2C_SRC_FILE
/*--------
Internal structure for the call
--------*/
typedef struct  {
   void* client_data;
   //INPUTS
   _boolean _KP_START;
   _boolean _KP_CLEAR;
   _boolean _KP_0;
   _boolean _KP_1;
   _boolean _KP_2;
   _boolean _KP_3;
   _boolean _KP_4;
   _boolean _KP_5;
   _boolean _KP_6;
   _boolean _KP_7;
   _boolean _KP_8;
   _boolean _KP_9;
   _boolean _DOOR_CLOSED;
   //OUTPUTS
   _boolean _enable;
   _integer _LEFT_DIGIT;
   _boolean _SETUP;//
   _boolean _COOKING;//
   _boolean _SUSPENDED;//
   _boolean _START_PRESSED;
   _boolean _CLEAR_PRESSED;
   _integer _MIDDLE_DIGIT;
   _integer _RIGHT_DIGIT;
   _integer _STEPS_TO_COOK;
   _boolean _OK;
   //REGISTERS
   _integer M19;
   _boolean M19_nil;
   _integer M31;
   _boolean M31_nil;
   _boolean M237;
   _boolean M237_nil;
   _integer M210;
   _boolean M210_nil;
   _integer M154;
   _boolean M154_nil;
   _integer M150;
   _boolean M150_nil;
   _integer M143;
   _boolean M143_nil;
   _integer M136;
   _boolean M136_nil;
   _boolean M135;
   _boolean M135_nil;
   _boolean M131;
   _boolean M131_nil;
   _boolean M127;
   _boolean M127_nil;
   _boolean M123;
   _boolean M123_nil;
   _boolean M119;
   _boolean M119_nil;
   _boolean M115;
   _boolean M115_nil;
   _boolean M111;
   _boolean M111_nil;
   _boolean M107;
   _boolean M107_nil;
   _boolean M103;
   _boolean M103_nil;
   _boolean M99;
   _boolean M99_nil;
   _boolean M62;
   _boolean M62_nil;
   _boolean M61;
   _boolean M61_nil;
   _boolean M48;
   _boolean M48_nil;
   _boolean M25;
   _boolean M25_nil;
   _boolean M23;
   _boolean M23_nil;
   _boolean M14;
} top_ctx;

/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void top_I_KP_START(top_ctx* ctx, _boolean V){
   ctx->_KP_START = V;
}
void top_I_KP_CLEAR(top_ctx* ctx, _boolean V){
   ctx->_KP_CLEAR = V;
}
void top_I_KP_0(top_ctx* ctx, _boolean V){
   ctx->_KP_0 = V;
}
void top_I_KP_1(top_ctx* ctx, _boolean V){
   ctx->_KP_1 = V;
}
void top_I_KP_2(top_ctx* ctx, _boolean V){
   ctx->_KP_2 = V;
}
void top_I_KP_3(top_ctx* ctx, _boolean V){
   ctx->_KP_3 = V;
}
void top_I_KP_4(top_ctx* ctx, _boolean V){
   ctx->_KP_4 = V;
}
void top_I_KP_5(top_ctx* ctx, _boolean V){
   ctx->_KP_5 = V;
}
void top_I_KP_6(top_ctx* ctx, _boolean V){
   ctx->_KP_6 = V;
}
void top_I_KP_7(top_ctx* ctx, _boolean V){
   ctx->_KP_7 = V;
}
void top_I_KP_8(top_ctx* ctx, _boolean V){
   ctx->_KP_8 = V;
}
void top_I_KP_9(top_ctx* ctx, _boolean V){
   ctx->_KP_9 = V;
}
void top_I_DOOR_CLOSED(top_ctx* ctx, _boolean V){
   ctx->_DOOR_CLOSED = V;
}
extern void top_O_enable(void* cdata, _boolean);
extern void top_O_LEFT_DIGIT(void* cdata, _integer);
extern void top_O_SETUP(void* cdata, _boolean);
extern void top_O_COOKING(void* cdata, _boolean);
extern void top_O_SUSPENDED(void* cdata, _boolean);
extern void top_O_START_PRESSED(void* cdata, _boolean);
extern void top_O_CLEAR_PRESSED(void* cdata, _boolean);
extern void top_O_MIDDLE_DIGIT(void* cdata, _integer);
extern void top_O_RIGHT_DIGIT(void* cdata, _integer);
extern void top_O_STEPS_TO_COOK(void* cdata, _integer);
extern void top_O_OK(void* cdata, _boolean);
#ifdef CKCHECK
extern void top_BOT_enable(void* cdata);
extern void top_BOT_LEFT_DIGIT(void* cdata);
extern void top_BOT_SETUP(void* cdata);
extern void top_BOT_COOKING(void* cdata);
extern void top_BOT_SUSPENDED(void* cdata);
extern void top_BOT_START_PRESSED(void* cdata);
extern void top_BOT_CLEAR_PRESSED(void* cdata);
extern void top_BOT_MIDDLE_DIGIT(void* cdata);
extern void top_BOT_RIGHT_DIGIT(void* cdata);
extern void top_BOT_STEPS_TO_COOK(void* cdata);
extern void top_BOT_OK(void* cdata);
#endif
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
   ctx->M19_nil = _true;
   ctx->M31_nil = _true;
   ctx->M237_nil = _true;
   ctx->M210_nil = _true;
   ctx->M154_nil = _true;
   ctx->M150_nil = _true;
   ctx->M143_nil = _true;
   ctx->M136_nil = _true;
   ctx->M135_nil = _true;
   ctx->M131_nil = _true;
   ctx->M127_nil = _true;
   ctx->M123_nil = _true;
   ctx->M119_nil = _true;
   ctx->M115_nil = _true;
   ctx->M111_nil = _true;
   ctx->M107_nil = _true;
   ctx->M103_nil = _true;
   ctx->M99_nil = _true;
   ctx->M62_nil = _true;
   ctx->M61_nil = _true;
   ctx->M48_nil = _true;
   ctx->M25_nil = _true;
   ctx->M23_nil = _true;
   ctx->M14 = _true;
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
   _boolean L17;
   _boolean L16;
   _boolean L13;
   _boolean L22;
   _boolean L21;
   _integer L209;
   _integer L29;
   _boolean L28;
   _boolean L47;
   _boolean L46;
   _boolean L45;
   _boolean L44;
   _integer L43;
   _boolean L42;
   _boolean L41;
   _boolean L59;
   _boolean L60;
   _boolean L58;
   _boolean L57;
   _boolean L56;
   _integer L87;
   _integer L85;
   _integer L83;
   _integer L81;
   _integer L79;
   _integer L78;
   _integer L76;
   _integer L74;
   _integer L73;
   _integer L72;
   _boolean L71;
   _boolean L70;
   _integer L69;
   _integer L68;
   _boolean L98;
   _boolean L97;
   _boolean L102;
   _boolean L101;
   _boolean L106;
   _boolean L105;
   _boolean L110;
   _boolean L109;
   _boolean L114;
   _boolean L113;
   _boolean L118;
   _boolean L117;
   _boolean L122;
   _boolean L121;
   _boolean L126;
   _boolean L125;
   _boolean L130;
   _boolean L129;
   _boolean L134;
   _boolean L133;
   _integer L132;
   _integer L128;
   _integer L124;
   _integer L120;
   _integer L116;
   _integer L112;
   _integer L108;
   _integer L104;
   _integer L100;
   _integer L96;
   _boolean L95;
   _boolean L94;
   _integer L93;
   _integer L92;
   _integer L91;
   _integer L90;
   _integer L67;
   _integer L66;
   _integer L142;
   _integer L141;
   _integer L140;
   _integer L139;
   _integer L138;
   _integer L137;
   _integer L65;
   _integer L149;
   _integer L148;
   _integer L147;
   _integer L146;
   _integer L145;
   _integer L144;
   _integer L64;
   _integer L63;
   _integer L55;
   _integer L153;
   _integer L152;
   _integer L54;
   _boolean L53;
   _boolean L52;
   _integer L51;
   _boolean L50;
   _boolean L49;
   _boolean L40;
   _boolean L39;
   _boolean L38;
   _boolean L37;
   _integer L165;
   _integer L164;
   _boolean L163;
   _boolean L166;
   _boolean L162;
   _boolean L161;
   _integer L169;
   _boolean L168;
   _boolean L170;
   _boolean L167;
   _boolean L160;
   _boolean L180;
   _integer L179;
   _boolean L178;
   _boolean L177;
   _boolean L176;
   _boolean L175;
   _boolean L183;
   _boolean L182;
   _integer L181;
   _integer L174;
   _boolean L173;
   _boolean L184;
   _boolean L172;
   _boolean L185;
   _boolean L171;
   _boolean L159;
   _boolean L188;
   _boolean L187;
   _integer L186;
   _integer L158;
   _integer L157;
   _boolean L156;
   _boolean L189;
   _boolean L155;
   _boolean L36;
   _boolean L206;
   _integer L208;
   _boolean L207;
   _boolean L205;
   _boolean L204;
   _integer L220;
   _integer L219;
   _boolean L218;
   _boolean L217;
   _integer L216;
   _integer L203;
   _boolean L202;
   _boolean L222;
   _boolean L223;
   _boolean L221;
   _boolean L201;
   _integer L228;
   _integer L227;
   _boolean L226;
   _boolean L225;
   _integer L224;
   _integer L200;
   _boolean L199;
   _boolean L236;
   _boolean L235;
   _boolean L234;
   _boolean L233;
   _integer L232;
   _boolean L231;
   _boolean L230;
   _boolean L239;
   _boolean L238;
   _boolean L229;
   _boolean L198;
   _boolean L240;
   _boolean L197;
   _boolean L247;
   _boolean L248;
   _boolean L246;
   _integer L245;
   _integer L244;
   _boolean L243;
   _boolean L242;
   _integer L241;
   _integer L196;
   _boolean L195;
   _integer L215;
   _boolean L250;
   _boolean L252;
   _boolean L251;
   _boolean L249;
   _boolean L194;
   _integer L214;
   _integer L213;
   _integer L212;
   _integer L211;
   _integer L287;
   _integer L286;
   _boolean L27;
   _integer L268;
   _integer L26;
   _integer L257;
   _integer L256;
   _boolean L255;
   _boolean L254;
   _integer L253;
   _integer L193;
   _boolean L192;
   _boolean L260;
   _boolean L259;
   _boolean L262;
   _boolean L261;
   _boolean L258;
   _boolean L191;
   _integer L267;
   _integer L266;
   _boolean L265;
   _boolean L264;
   _integer L284;
   _integer L283;
   _integer L282;
   _integer L281;
   _integer L280;
   _integer L279;
   _integer L278;
   _integer L277;
   _integer L276;
   _integer L275;
   _integer L274;
   _integer L273;
   _integer L272;
   _integer L271;
   _integer L270;
   _integer L269;
   _integer L20;
   _boolean L290;
   _boolean L289;
   _boolean L293;
   _boolean L292;
   _boolean L296;
   _boolean L295;
   _integer L302;
   _integer L301;
   _integer L300;
   _integer L305;
   _integer L304;
   _boolean L309;
   _boolean L310;
   _boolean L308;
   _integer T19;
   _integer L33;
   _integer L263;
   _integer L190;
   _integer L35;
   _integer L32;
   _integer T31;
   _boolean T237;
   _integer T210;
   _integer T154;
   _integer T150;
   _integer T143;
   _integer T136;
   _boolean T135;
   _boolean T131;
   _boolean T127;
   _boolean T123;
   _boolean T119;
   _boolean T115;
   _boolean T111;
   _boolean T107;
   _boolean T103;
   _boolean T99;
   _boolean T62;
   _boolean T61;
   _boolean T48;
   _boolean T25;
   _boolean T23;
//CODE
   L17 = (1 == ctx->M19);
   if (L17) {
      L16 = _true;
   } else {
      L16 = _false;
   }
   if (ctx->M14) {
      L13 = _true;
   } else {
      L13 = L16;
   }
   ctx->_enable = L13;
   if (ctx->M23) {
      L22 = _false;
   } else {
      L22 = ctx->M25;
   }
   if (ctx->M14) {
      L21 = _true;
   } else {
      L21 = L22;
   }
   if (ctx->M14) {
      L209 = 0;
   } else {
      L209 = ctx->M210;
   }
   if (ctx->M14) {
      L29 = 0;
   } else {
      L29 = ctx->M31;
   }
   L28 = (L29 == 4);
   L47 = (! ctx->M48);
   L46 = (ctx->_KP_START && L47);
   if (ctx->M14) {
      L45 = ctx->_KP_START;
   } else {
      L45 = L46;
   }
   L44 = (L45 == _false);
   if (L44) {
      L43 = 0;
   } else {
      L43 = 1;
   }
   L42 = (L43 != 0);
   if (L42) {
      L41 = _true;
   } else {
      L41 = _false;
   }
   L59 = (! L13);
   if (ctx->M61) {
      L60 = _false;
   } else {
      L60 = ctx->M62;
   }
   if (L59) {
      L58 = _true;
   } else {
      L58 = L60;
   }
   if (ctx->M14) {
      L57 = _true;
   } else {
      L57 = L58;
   }
   L56 = (L57 && L59);
   if (ctx->_KP_9) {
      L87 = 9;
   } else {
      L87 = 10;
   }
   if (ctx->_KP_8) {
      L85 = 8;
   } else {
      L85 = L87;
   }
   if (ctx->_KP_7) {
      L83 = 7;
   } else {
      L83 = L85;
   }
   if (ctx->_KP_6) {
      L81 = 6;
   } else {
      L81 = L83;
   }
   if (ctx->_KP_5) {
      L79 = 5;
   } else {
      L79 = L81;
   }
   if (ctx->_KP_4) {
      L78 = 4;
   } else {
      L78 = L79;
   }
   if (ctx->_KP_3) {
      L76 = 3;
   } else {
      L76 = L78;
   }
   if (ctx->_KP_2) {
      L74 = 2;
   } else {
      L74 = L76;
   }
   if (ctx->_KP_1) {
      L73 = 1;
   } else {
      L73 = L74;
   }
   if (ctx->_KP_0) {
      L72 = 0;
   } else {
      L72 = L73;
   }
   L71 = (L72 <= 9);
   if (L71) {
      L70 = _true;
   } else {
      L70 = _false;
   }
   if (L70) {
      L69 = L72;
   } else {
      L69 = 0;
   }
   if (ctx->_KP_CLEAR) {
      L68 = 0;
   } else {
      L68 = L69;
   }
   L98 = (! ctx->M99);
   L97 = (ctx->_KP_0 && L98);
   L102 = (! ctx->M103);
   L101 = (ctx->_KP_1 && L102);
   L106 = (! ctx->M107);
   L105 = (ctx->_KP_2 && L106);
   L110 = (! ctx->M111);
   L109 = (ctx->_KP_3 && L110);
   L114 = (! ctx->M115);
   L113 = (ctx->_KP_4 && L114);
   L118 = (! ctx->M119);
   L117 = (ctx->_KP_5 && L118);
   L122 = (! ctx->M123);
   L121 = (ctx->_KP_6 && L122);
   L126 = (! ctx->M127);
   L125 = (ctx->_KP_7 && L126);
   L130 = (! ctx->M131);
   L129 = (ctx->_KP_8 && L130);
   L134 = (! ctx->M135);
   L133 = (ctx->_KP_9 && L134);
   if (L133) {
      L132 = 9;
   } else {
      L132 = 10;
   }
   if (L129) {
      L128 = 8;
   } else {
      L128 = L132;
   }
   if (L125) {
      L124 = 7;
   } else {
      L124 = L128;
   }
   if (L121) {
      L120 = 6;
   } else {
      L120 = L124;
   }
   if (L117) {
      L116 = 5;
   } else {
      L116 = L120;
   }
   if (L113) {
      L112 = 4;
   } else {
      L112 = L116;
   }
   if (L109) {
      L108 = 3;
   } else {
      L108 = L112;
   }
   if (L105) {
      L104 = 2;
   } else {
      L104 = L108;
   }
   if (L101) {
      L100 = 1;
   } else {
      L100 = L104;
   }
   if (L97) {
      L96 = 0;
   } else {
      L96 = L100;
   }
   L95 = (L96 <= 9);
   if (L95) {
      L94 = _true;
   } else {
      L94 = _false;
   }
   if (L94) {
      L93 = L96;
   } else {
      L93 = ctx->M136;
   }
   if (ctx->_KP_CLEAR) {
      L92 = 0;
   } else {
      L92 = L93;
   }
   if (L57) {
      L91 = L68;
   } else {
      L91 = L92;
   }
   if (L13) {
      L90 = L91;
   } else {
      L90 = ctx->M136;
   }
   if (ctx->M14) {
      L67 = L68;
   } else {
      L67 = L90;
   }
   L66 = (L67 * 1);
   if (L94) {
      L142 = ctx->M136;
   } else {
      L142 = ctx->M143;
   }
   if (ctx->_KP_CLEAR) {
      L141 = 0;
   } else {
      L141 = L142;
   }
   if (L57) {
      L140 = 0;
   } else {
      L140 = L141;
   }
   if (L13) {
      L139 = L140;
   } else {
      L139 = ctx->M143;
   }
   if (ctx->M14) {
      L138 = 0;
   } else {
      L138 = L139;
   }
   L137 = (L138 * 10);
   L65 = (L66 + L137);
   if (L94) {
      L149 = ctx->M143;
   } else {
      L149 = ctx->M150;
   }
   if (ctx->_KP_CLEAR) {
      L148 = 0;
   } else {
      L148 = L149;
   }
   if (L57) {
      L147 = 0;
   } else {
      L147 = L148;
   }
   if (L13) {
      L146 = L147;
   } else {
      L146 = ctx->M150;
   }
   if (ctx->M14) {
      L145 = 0;
   } else {
      L145 = L146;
   }
   L144 = (L145 * 60);
   L64 = (L65 + L144);
   L63 = (L64 * 1);
   if (L56) {
      L55 = 0;
   } else {
      L55 = L63;
   }
   if (L13) {
      L153 = L63;
   } else {
      L153 = ctx->M154;
   }
   if (L56) {
      L152 = 0;
   } else {
      L152 = L153;
   }
   if (ctx->M14) {
      L54 = L55;
   } else {
      L54 = L152;
   }
   L53 = (L54 > 0);
   L52 = (L53 == _false);
   if (L52) {
      L51 = 0;
   } else {
      L51 = 1;
   }
   L50 = (L51 != 0);
   if (L50) {
      L49 = _true;
   } else {
      L49 = _false;
   }
   L40 = (L41 && L49);
   L39 = (L28 && L40);
   L38 = (L28 && L39);
   L37 = (! L38);
   if (L28) {
      L165 = 0;
   } else {
      L165 = L29;
   }
   if (L38) {
      L164 = L165;
   } else {
      L164 = L29;
   }
   L163 = (L164 >= 1);
   L166 = (L164 <= 3);
   L162 = (L163 && L166);
   L161 = (! L162);
   if (L161) {
      L169 = 1;
   } else {
      L169 = L164;
   }
   L168 = (L169 >= 1);
   L170 = (L169 <= 3);
   L167 = (L168 && L170);
   L160 = (L161 && L167);
   L180 = (ctx->_DOOR_CLOSED == _false);
   if (L180) {
      L179 = 0;
   } else {
      L179 = 1;
   }
   L178 = (L179 != 0);
   if (L178) {
      L177 = _true;
   } else {
      L177 = _false;
   }
   L176 = (L167 && L177);
   L175 = (L160 && L176);
   L183 = (L169 == 2);
   L182 = (! L183);
   if (L182) {
      L181 = 2;
   } else {
      L181 = L169;
   }
   if (L175) {
      L174 = L181;
   } else {
      L174 = L169;
   }
   L173 = (L174 >= 1);
   L184 = (L174 <= 3);
   L172 = (L173 && L184);
   L185 = (! L175);
   L171 = (L172 && L185);
   L159 = (L160 && L171);
   L188 = (L174 == 3);
   L187 = (! L188);
   if (L187) {
      L186 = 3;
   } else {
      L186 = L174;
   }
   if (L159) {
      L158 = L186;
   } else {
      L158 = L174;
   }
   if (L38) {
      L157 = L158;
   } else {
      L157 = L164;
   }
   L156 = (L157 >= 1);
   L189 = (L157 <= 3);
   L155 = (L156 && L189);
   L36 = (L37 && L155);
   L206 = (L157 == 2);
   if (L28) {
      L208 = L54;
   } else {
      L208 = L209;
   }
   L207 = (L208 <= 0);
   L205 = (L206 && L207);
   L204 = (L205 && L206);
   if (L155) {
      L220 = 0;
   } else {
      L220 = L157;
   }
   if (L204) {
      L219 = L220;
   } else {
      L219 = L157;
   }
   L218 = (L219 == 4);
   L217 = (! L218);
   if (L217) {
      L216 = 4;
   } else {
      L216 = L219;
   }
   if (L204) {
      L203 = L216;
   } else {
      L203 = L219;
   }
   L202 = (L203 == 3);
   L222 = (L41 && L177);
   L223 = (! L204);
   L221 = (L222 && L223);
   L201 = (L202 && L221);
   if (L202) {
      L228 = 1;
   } else {
      L228 = L203;
   }
   if (L201) {
      L227 = L228;
   } else {
      L227 = L203;
   }
   L226 = (L227 == 2);
   L225 = (! L226);
   if (L225) {
      L224 = 2;
   } else {
      L224 = L227;
   }
   if (L201) {
      L200 = L224;
   } else {
      L200 = L227;
   }
   L199 = (L200 == 3);
   L236 = (! ctx->M237);
   L235 = (ctx->_KP_CLEAR && L236);
   if (ctx->M14) {
      L234 = ctx->_KP_CLEAR;
   } else {
      L234 = L235;
   }
   L233 = (L234 == _false);
   if (L233) {
      L232 = 0;
   } else {
      L232 = 1;
   }
   L231 = (L232 != 0);
   if (L231) {
      L230 = _true;
   } else {
      L230 = _false;
   }
   L239 = (L201 || L204);
   L238 = (! L239);
   L229 = (L230 && L238);
   L198 = (L199 && L229);
   L240 = (L199 && L238);
   L197 = (L198 && L240);
   L247 = (L200 >= 1);
   L248 = (L200 <= 3);
   L246 = (L247 && L248);
   if (L246) {
      L245 = 0;
   } else {
      L245 = L200;
   }
   if (L197) {
      L244 = L245;
   } else {
      L244 = L200;
   }
   L243 = (L244 == 4);
   L242 = (! L243);
   if (L242) {
      L241 = 4;
   } else {
      L241 = L244;
   }
   if (L197) {
      L196 = L241;
   } else {
      L196 = L244;
   }
   L195 = (L196 == 2);
   if (L197) {
      L215 = 0;
   } else {
      L215 = L208;
   }
   L250 = (L215 > 0);
   L252 = (L197 || L239);
   L251 = (! L252);
   L249 = (L250 && L251);
   L194 = (L195 && L249);
   L214 = (L215 - 1);
   if (L194) {
      L213 = L214;
   } else {
      L213 = L215;
   }
   if (L36) {
      L212 = L213;
   } else {
      L212 = L208;
   }
   if (L21) {
      L211 = L209;
   } else {
      L211 = L212;
   }
   L287 = (L211 / 1);
   L286 = (L287 / 60);
   ctx->_LEFT_DIGIT = L286;
   L27 = (! L28);
   if (ctx->M14) {
      L268 = 0;
   } else {
      L268 = ctx->M19;
   }
   if (L27) {
      L26 = 1;
   } else {
      L26 = L268;
   }
   if (L195) {
      L257 = 1;
   } else {
      L257 = L196;
   }
   if (L194) {
      L256 = L257;
   } else {
      L256 = L196;
   }
   L255 = (L256 == 2);
   L254 = (! L255);
   if (L254) {
      L253 = 2;
   } else {
      L253 = L256;
   }
   if (L194) {
      L193 = L253;
   } else {
      L193 = L256;
   }
   L192 = (L193 == 2);
   L260 = (! L177);
   L259 = (L230 || L260);
   L262 = (L194 || L252);
   L261 = (! L262);
   L258 = (L259 && L261);
   L191 = (L192 && L258);
   if (L192) {
      L267 = 1;
   } else {
      L267 = L193;
   }
   if (L191) {
      L266 = L267;
   } else {
      L266 = L193;
   }
   L265 = (L266 == 3);
   L264 = (! L265);
   if (L182) {
      L284 = 2;
   } else {
      L284 = L268;
   }
   if (L175) {
      L283 = L284;
   } else {
      L283 = L268;
   }
   if (L187) {
      L282 = 3;
   } else {
      L282 = L283;
   }
   if (L159) {
      L281 = L282;
   } else {
      L281 = L283;
   }
   if (L38) {
      L280 = L281;
   } else {
      L280 = L268;
   }
   if (L217) {
      L279 = 1;
   } else {
      L279 = L280;
   }
   if (L204) {
      L278 = L279;
   } else {
      L278 = L280;
   }
   if (L225) {
      L277 = 2;
   } else {
      L277 = L278;
   }
   if (L201) {
      L276 = L277;
   } else {
      L276 = L278;
   }
   if (L242) {
      L275 = 1;
   } else {
      L275 = L276;
   }
   if (L197) {
      L274 = L275;
   } else {
      L274 = L276;
   }
   if (L254) {
      L273 = 2;
   } else {
      L273 = L274;
   }
   if (L194) {
      L272 = L273;
   } else {
      L272 = L274;
   }
   if (L264) {
      L271 = 3;
   } else {
      L271 = L272;
   }
   if (L191) {
      L270 = L271;
   } else {
      L270 = L272;
   }
   if (L36) {
      L269 = L270;
   } else {
      L269 = L280;
   }
   if (L21) {
      L20 = L26;
   } else {
      L20 = L269;
   }
   L290 = (1 == L20);
   if (L290) {
      L289 = _true;
   } else {
      L289 = _false;
   }
   ctx->_SETUP = L289;
   L293 = (2 == L20);
   if (L293) {
      L292 = _true;
   } else {
      L292 = _false;
   }
   ctx->_COOKING = L292;
   L296 = (3 == L20);
   if (L296) {
      L295 = _true;
   } else {
      L295 = _false;
   }
   ctx->_SUSPENDED = L295;
   ctx->_START_PRESSED = L45;
   ctx->_CLEAR_PRESSED = L234;
   L302 = (L286 * 60);
   L301 = (L287 - L302);
   L300 = (L301 / 10);
   ctx->_MIDDLE_DIGIT = L300;
   L305 = (L300 * 10);
   L304 = (L301 - L305);
   ctx->_RIGHT_DIGIT = L304;
   ctx->_STEPS_TO_COOK = L54;
   L309 = (L158 == 2);
   L310 = (L158 == 3);
   L308 = (L309 || L310);
   ctx->_OK = L308;
   T19 = L20;
   if (L27) {
      L33 = 4;
   } else {
      L33 = L29;
   }
   if (L264) {
      L263 = 3;
   } else {
      L263 = L266;
   }
   if (L191) {
      L190 = L263;
   } else {
      L190 = L266;
   }
   if (L36) {
      L35 = L190;
   } else {
      L35 = L157;
   }
   if (L21) {
      L32 = L33;
   } else {
      L32 = L35;
   }
   T31 = L32;
   T237 = ctx->_KP_CLEAR;
   T210 = L211;
   T154 = L54;
   T150 = L145;
   T143 = L138;
   T136 = L67;
   T135 = ctx->_KP_9;
   T131 = ctx->_KP_8;
   T127 = ctx->_KP_7;
   T123 = ctx->_KP_6;
   T119 = ctx->_KP_5;
   T115 = ctx->_KP_4;
   T111 = ctx->_KP_3;
   T107 = ctx->_KP_2;
   T103 = ctx->_KP_1;
   T99 = ctx->_KP_0;
   T62 = L57;
   T61 = L13;
   T48 = ctx->_KP_START;
   T25 = L21;
   T23 = _true;
   ctx->M19 = T19;
   ctx->M19_nil = _false;
   ctx->M31 = T31;
   ctx->M31_nil = _false;
   ctx->M237 = T237;
   ctx->M237_nil = _false;
   ctx->M210 = T210;
   ctx->M210_nil = _false;
   ctx->M154 = T154;
   ctx->M154_nil = _false;
   ctx->M150 = T150;
   ctx->M150_nil = _false;
   ctx->M143 = T143;
   ctx->M143_nil = _false;
   ctx->M136 = T136;
   ctx->M136_nil = _false;
   ctx->M135 = T135;
   ctx->M135_nil = _false;
   ctx->M131 = T131;
   ctx->M131_nil = _false;
   ctx->M127 = T127;
   ctx->M127_nil = _false;
   ctx->M123 = T123;
   ctx->M123_nil = _false;
   ctx->M119 = T119;
   ctx->M119_nil = _false;
   ctx->M115 = T115;
   ctx->M115_nil = _false;
   ctx->M111 = T111;
   ctx->M111_nil = _false;
   ctx->M107 = T107;
   ctx->M107_nil = _false;
   ctx->M103 = T103;
   ctx->M103_nil = _false;
   ctx->M99 = T99;
   ctx->M99_nil = _false;
   ctx->M62 = T62;
   ctx->M62_nil = _false;
   ctx->M61 = T61;
   ctx->M61_nil = _false;
   ctx->M48 = T48;
   ctx->M48_nil = _false;
   ctx->M25 = T25;
   ctx->M25_nil = _false;
   ctx->M23 = T23;
   ctx->M23_nil = _false;
   ctx->M14 = ctx->M14 && !(_true);
}
// LOOP ///////////////////////////////////////////////////////////////////////
#include <stdio.h>

/* testing features **/

typedef struct input_t {
	char KP_START;
	char KP_CLEAR;
	char KP_0;
	char KP_1;
	char KP_2;
	char KP_3;
	char KP_4;
	char KP_5;
	char KP_6;
	char KP_7;
	char KP_8;
	char KP_9;
	char DOOR_CLOSED;
} input_t;

typedef struct input_node_t {
	input_t elem;
	struct input_node_t *next;
} input_node_t ;

typedef struct test_node_t {
	input_node_t *steps;
	struct test_node_t *next;
} test_node_t;

void assign_inputs(top_ctx* ctx, input_t* elem) {
	ctx->_DOOR_CLOSED = elem->DOOR_CLOSED;
	ctx->_KP_0 = elem->KP_0;
	ctx->_KP_1 = elem->KP_1;
	ctx->_KP_2 = elem->KP_2;
	ctx->_KP_3 = elem->KP_3;
	ctx->_KP_4 = elem->KP_4;
	ctx->_KP_5 = elem->KP_5;
	ctx->_KP_6 = elem->KP_6;
	ctx->_KP_7 = elem->KP_7;
	ctx->_KP_8 = elem->KP_8;
	ctx->_KP_9 = elem->KP_9;
    ctx->_KP_CLEAR = elem->KP_CLEAR;
	ctx->_KP_START = elem->KP_START;
}

int bool_lit_to_int(char* boollit) {
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

void scan_input(char *buffer, input_t *elem) {
	/* Conversions due to *$%@$ Reactis.  Everything is a float there.  */
	char temp1[7], temp2[7], temp3[7], temp4[7], temp5[7], temp6[7], temp7[7], 
         temp8[7], temp9[7], temp10[7], temp11[7], temp12[7], temp13[7];

	sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],\
            %[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^',']", 
            temp1, temp2, temp3, temp4, temp5, temp6, temp7, 
            temp8, temp9, temp10, temp11, temp12, temp13);

	elem->DOOR_CLOSED = bool_lit_to_int(temp1);
	elem->KP_0 = bool_lit_to_int(temp2);
	elem->KP_1 = bool_lit_to_int(temp3);
	elem->KP_2 = bool_lit_to_int(temp4);
	elem->KP_3 = bool_lit_to_int(temp5);
	elem->KP_4 = bool_lit_to_int(temp6);
	elem->KP_5 = bool_lit_to_int(temp7);
	elem->KP_6 = bool_lit_to_int(temp8);
	elem->KP_7 = bool_lit_to_int(temp9);
	elem->KP_8 = bool_lit_to_int(temp10);
	elem->KP_9 = bool_lit_to_int(temp11);
	elem->KP_CLEAR = bool_lit_to_int(temp12);
	elem->KP_START = bool_lit_to_int(temp13);
#if DEBUG
  printf("kp: (%d %d %d %d %d, %d %d %d %d %d), s: %d, c: %d, d: %d\n",
      elem->DOOR_CLOSED, elem->KP_0, elem->KP_1, elem->KP_2, elem->KP_3,
      elem->KP_4, elem->KP_5, elem->KP_6, elem->KP_7, elem->KP_8, elem->KP_9,
      elem->KP_CLEAR, elem->KP_START);
#endif
}


FILE* create_trace_file(char* fname) {
  /* open the trace file to dump the output
   * @return the file pointer of the trace file */
  if (NULL == fname) {
    return NULL;
  }
  char* HEADER = "enable,LEFT_DIGIT,SETUP,COOKING,SUSPENDED,START_PRESSED," \
                  "CLEAR_PRESSED,MIDDLE_DIGIT,RIGHT_DIGIT,STEPS_TO_COOK,OK";
  FILE* fp = fopen(fname, "w");
  /* print the CSV header (11 output variables) */
  //fprintf(fp, "%s\n", HEADER);
  return fp;
}

// 11 outputs in total (in obsnop.trace)
void dump_state(FILE* fp, top_ctx* ctx) {
    /* dump the output variables of the current step */
    if (ctx == NULL) {
      // blank line separates runs / each test case
      fprintf(fp, "\n");
      return;
    }
    fprintf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            ctx->_enable, ctx->_LEFT_DIGIT, ctx->_SETUP, ctx->_COOKING,
            ctx->_SUSPENDED, ctx->_START_PRESSED, ctx->_CLEAR_PRESSED,
            ctx->_MIDDLE_DIGIT, ctx->_RIGHT_DIGIT, ctx->_STEPS_TO_COOK,
            ctx->_OK);
}
// TODO

void populate_tests(FILE *fp, test_node_t *first) {

	char buffer[255];
	test_node_t *current_test = first;
	int testCount;
	int stepCount;
	current_test->next = NULL;
	current_test->steps = NULL;

	input_node_t *current_step = NULL;

	int count = 0;
    fgets(buffer, 255, fp); // skip the header
	while (fgets(buffer, 255, fp) != NULL) {
		count++;
		// blank line indicates the beginning of a new test case
		if (strcmp(buffer, ",,,,,,,,,,,,\n") == 0 || strcmp(buffer, "\n") == 0) {
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
          current_step->next = next;
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

/* end of testing features ***/

top_ctx ctx;

/* Main procedure *************************/
int main(int argc, char** argv){
#include <stddef.h>
  /*
     _boolean _enable;
     _integer _LEFT_DIGIT;
     _boolean _SETUP;
     _boolean _COOKING;
     _boolean _SUSPENDED;
     _boolean _START_PRESSED;
     _boolean _CLEAR_PRESSED;
     _integer _MIDDLE_DIGIT;
     _integer _RIGHT_DIGIT;
     _integer _STEPS_TO_COOK;
     */
  /* testing facility */
  char* test_input_file = NULL;
  char* trace_file = NULL;
  if (argc == 2) {
    test_input_file = argv[1];
  } else if (argc == 3) {
    test_input_file = argv[1];
    trace_file = argv[2];
  } else {
    printf("[mw] invalid number of argument\n");
    return -1;
  }
  FILE *fp = fopen(test_input_file, "r");
  if(fp == NULL) {
    printf("Unable to open %s\n", test_input_file);
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
  int i;
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
      if (NULL != fp_dump) {
        dump_state(fp_dump, &ctx);
      }
      current_step = current_step->next;
      n_steps++;
    }
#if DEBUG
    //printf("TC #%d, %d steps\n", n_test_cases, n_steps);
#endif
    /* finished: consumed all the steps of the current test case */
    //dump_state(fp_dump, NULL);           // dump a blank line as a separator
    memset(&ctx, 0, sizeof(top_ctx));    // init the state variables
    top_reset(&ctx);                     // reset the registers
    n_test_cases++;
    current_test = current_test->next;
  }
  if (NULL != fp_dump) {
    fclose(fp_dump);
  }

  return 0;
}

