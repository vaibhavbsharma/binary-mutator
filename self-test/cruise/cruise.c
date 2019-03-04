/********
 * ec2c version 0.67
 * context   method = HEAP
 * ext call  method = PROCEDURES
 * c header file generated for node : top 
 * to be used with : top.c 
 ********/
/*-------- Predefined types ---------*/
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
/*--------- Pragmas ----------------*/
//MODULE: top 8 1
//IN: _boolean onOff
//IN: _boolean decelSet
//IN: _boolean accelResume
//IN: _boolean cancel
//IN: _boolean brakePedal
//IN: _integer carGear
//IN: _real carSpeed
//IN: _boolean validInputs
//OUT: _boolean OK

/********
 * ec2c version 0.67
 * c file generated for node : top 
 * context   method = HEAP
 * ext call  method = PROCEDURES
 ********/
#include <stdlib.h>
#include <string.h>
/*--------
  Internal structure for the call
  --------*/
typedef struct  {
   void* client_data;
   //INPUTS
   _boolean _onOff;
   _boolean _decelSet;
   _boolean _accelResume;
   _boolean _cancel;
   _boolean _brakePedal;
   _integer _carGear;
   _real _carSpeed;
   _boolean _validInputs;
   //OUTPUTS
   _boolean _OK;
   _integer _mode;
   _real _cruiseThrottle;
   _real _desiredSpeed;
   //REGISTERS
   _real M439;
   _boolean M439_nil;
   _real M414;
   _boolean M414_nil;
   _boolean M409;
   _boolean M409_nil;
   _boolean M408;
   _boolean M408_nil;
   _real M401;
   _boolean M401_nil;
   _real M394;
   _boolean M394_nil;
   _real M393;
   _boolean M393_nil;
   _boolean M392;
   _boolean M392_nil;
   _boolean M384;
   _boolean M384_nil;
   _boolean M383;
   _boolean M383_nil;
   _integer M350;
   _boolean M350_nil;
   _integer M295;
   _boolean M295_nil;
   _boolean M260;
   _boolean M260_nil;
   _integer M39;
   _boolean M39_nil;
   _integer M144;
   _boolean M144_nil;
   _integer M118;
   _boolean M118_nil;
   _boolean M93;
   _boolean M93_nil;
   _boolean M45;
   _boolean M45_nil;
   _boolean M43;
   _boolean M43_nil;
   _boolean M36;
} top_ctx;

/*--------
  Reset procedure
  --------*/
void top_reset(top_ctx* ctx){
   ctx->M439_nil = _true;
   ctx->M414_nil = _true;
   ctx->M409_nil = _true;
   ctx->M408_nil = _true;
   ctx->M401_nil = _true;
   ctx->M394_nil = _true;
   ctx->M393_nil = _true;
   ctx->M392_nil = _true;
   ctx->M384_nil = _true;
   ctx->M383_nil = _true;
   ctx->M350_nil = _true;
   ctx->M295_nil = _true;
   ctx->M260_nil = _true;
   ctx->M39_nil = _true;
   ctx->M144_nil = _true;
   ctx->M118_nil = _true;
   ctx->M93_nil = _true;
   ctx->M45_nil = _true;
   ctx->M43_nil = _true;
   ctx->M36 = _true;
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
Initialisation of an internal structure
--------*/
void top_init(top_ctx* ctx, void* cdata){
   ctx->client_data = cdata;
   top_reset(ctx);
}
/*--------
  Step procedure
  --------*/
void top_step(top_ctx* ctx) {
//LOCAL VARIABLES
   _integer L35;
   _boolean L34;
   _boolean L170;
   _boolean L33;
   _boolean L175;
   _integer L174;
   _boolean L173;
   _boolean L172;
   _boolean L171;
   _boolean L32;
   _integer L180;
   _integer L179;
   _boolean L178;
   _boolean L177;
   _integer L176;
   _integer L31;
   _boolean L30;
   _boolean L182;
   _boolean L181;
   _boolean L29;
   _integer L189;
   _integer L188;
   _boolean L187;
   _boolean L190;
   _boolean L186;
   _boolean L185;
   _integer L193;
   _boolean L192;
   _boolean L194;
   _boolean L191;
   _boolean L184;
   _boolean L197;
   _boolean L196;
   _integer L195;
   _integer L183;
   _integer L28;
   _boolean L27;
   _boolean L199;
   _boolean L26;
   _boolean L209;
   _boolean L210;
   _boolean L208;
   _boolean L212;
   _boolean L211;
   _boolean L207;
   _boolean L214;
   _boolean L213;
   _boolean L206;
   _boolean L205;
   _boolean L204;
   _integer L203;
   _boolean L202;
   _boolean L201;
   _boolean L200;
   _boolean L25;
   _integer L220;
   _integer L219;
   _boolean L218;
   _boolean L217;
   _integer L216;
   _integer L24;
   _boolean L23;
   _boolean L92;
   _boolean L91;
   _boolean L90;
   _boolean L89;
   _integer L88;
   _boolean L87;
   _boolean L226;
   _integer L225;
   _boolean L224;
   _boolean L223;
   _boolean L231;
   _boolean L230;
   _integer L229;
   _boolean L228;
   _boolean L227;
   _boolean L222;
   _boolean L232;
   _boolean L221;
   _boolean L22;
   _integer L239;
   _integer L238;
   _boolean L237;
   _boolean L240;
   _boolean L236;
   _boolean L235;
   _integer L243;
   _boolean L242;
   _boolean L244;
   _boolean L241;
   _boolean L234;
   _boolean L247;
   _boolean L246;
   _integer L245;
   _integer L233;
   _integer L21;
   _boolean L20;
   _boolean L259;
   _boolean L258;
   _boolean L257;
   _boolean L256;
   _integer L255;
   _boolean L254;
   _boolean L253;
   _integer L252;
   _boolean L251;
   _boolean L250;
   _boolean L249;
   _boolean L64;
   _boolean L261;
   _boolean L248;
   _boolean L19;
   _integer L268;
   _integer L267;
   _boolean L266;
   _boolean L269;
   _boolean L265;
   _boolean L264;
   _integer L272;
   _boolean L271;
   _boolean L273;
   _boolean L270;
   _boolean L263;
   _boolean L276;
   _boolean L275;
   _integer L274;
   _integer L262;
   _integer L18;
   _boolean L17;
   _boolean L63;
   _boolean L278;
   _boolean L277;
   _boolean L16;
   _integer L279;
   _integer L15;
   _boolean L14;
   _boolean L280;
   _boolean L13;
   _boolean L12;
   _integer L283;
   _boolean L282;
   _boolean L284;
   _boolean L281;
   _boolean L11;
   _boolean L287;
   _boolean L286;
   _integer L285;
   _integer L10;
   _boolean L9;
   _boolean L289;
   _boolean L290;
   _boolean L288;
   _boolean L8;
   _boolean L42;
   _boolean L41;
   _boolean L48;
   _boolean L47;
   _integer L294;
   _integer L293;
   _boolean L53;
   _boolean L52;
   _boolean L55;
   _boolean L57;
   _boolean L54;
   _boolean L51;
   _boolean L62;
   _boolean L61;
   _integer L67;
   _boolean L66;
   _boolean L69;
   _boolean L65;
   _boolean L60;
   _boolean L85;
   _boolean L84;
   _integer L98;
   _integer L97;
   _boolean L96;
   _boolean L95;
   _integer L94;
   _integer L83;
   _boolean L82;
   _integer L110;
   _boolean L109;
   _integer L108;
   _boolean L107;
   _integer L106;
   _integer L117;
   _integer L116;
   _boolean L115;
   _integer L114;
   _boolean L113;
   _integer L112;
   _integer L105;
   _boolean L104;
   _boolean L103;
   _boolean L102;
   _integer L101;
   _boolean L100;
   _boolean L119;
   _boolean L99;
   _boolean L81;
   _integer L124;
   _integer L123;
   _boolean L122;
   _boolean L121;
   _integer L120;
   _integer L80;
   _boolean L79;
   _integer L137;
   _boolean L136;
   _integer L135;
   _boolean L134;
   _integer L133;
   _integer L143;
   _integer L142;
   _boolean L141;
   _integer L140;
   _boolean L139;
   _integer L138;
   _integer L132;
   _boolean L131;
   _boolean L130;
   _boolean L129;
   _integer L128;
   _boolean L127;
   _boolean L146;
   _boolean L145;
   _boolean L126;
   _boolean L78;
   _integer L151;
   _integer L150;
   _boolean L149;
   _boolean L148;
   _integer L147;
   _integer L77;
   _boolean L76;
   _boolean L153;
   _boolean L155;
   _boolean L154;
   _boolean L152;
   _boolean L75;
   _integer L160;
   _integer L159;
   _boolean L158;
   _boolean L157;
   _integer L156;
   _integer L74;
   _boolean L73;
   _boolean L162;
   _boolean L164;
   _boolean L163;
   _boolean L161;
   _boolean L72;
   _integer L169;
   _integer L168;
   _boolean L167;
   _boolean L166;
   _integer L323;
   _integer L322;
   _integer L321;
   _integer L320;
   _integer L319;
   _integer L318;
   _integer L317;
   _integer L316;
   _integer L315;
   _integer L314;
   _integer L313;
   _integer L312;
   _integer L311;
   _integer L310;
   _integer L309;
   _integer L308;
   _integer L307;
   _integer L306;
   _integer L305;
   _integer L304;
   _integer L303;
   _integer L302;
   _integer L301;
   _integer L300;
   _integer L299;
   _integer L298;
   _integer L297;
   _integer L296;
   _integer L292;
   _boolean L329;
   _boolean L328;
   _boolean L331;
   _boolean L330;
   _boolean L327;
   _boolean L333;
   _boolean L332;
   _boolean L326;
   _integer L349;
   _boolean L356;
   _boolean L355;
   _integer L165;
   _integer L71;
   _boolean L357;
   _boolean L354;
   _boolean L368;
   _boolean L373;
   _boolean L374;
   _boolean L372;
   _boolean L376;
   _integer L375;
   _integer L371;
   _integer L370;
   _integer L369;
   _integer L367;
   _integer L366;
   _integer L365;
   _integer L364;
   _integer L363;
   _integer L362;
   _integer L361;
   _integer L360;
   _integer L359;
   _integer L358;
   _integer L353;
   _integer L352;
   _integer L351;
   _integer L348;
   _boolean L347;
   _boolean L346;
   _boolean L382;
   _boolean L381;
   _boolean L385;
   _boolean L380;
   _real L391;
   _boolean L390;
   _boolean L396;
   _real L395;
   _real L389;
   _real L388;
   _real L387;
   _real L379;
   _real L400;
   _real L399;
   _real L378;
   _boolean L407;
   _boolean L406;
   _boolean L410;
   _boolean L405;
   _real L411;
   _real L404;
   _real L413;
   _real L412;
   _real L403;
   _boolean L418;
   _boolean L417;
   _real L416;
   _real L415;
   _real L402;
   _real L377;
   _real L345;
   _boolean L344;
   _boolean L420;
   _real L419;
   _real L343;
   _real L342;
   _real L341;
   _real L422;
   _boolean L340;
   _boolean L425;
   _real L424;
   _real L339;
   _real L338;
   _real L337;
   _boolean L432;
   _boolean L431;
   _boolean L434;
   _boolean L433;
   _boolean L430;
   _boolean L436;
   _boolean L435;
   _boolean L429;
   _boolean L438;
   _boolean L441;
   _real L440;
   _real L437;
   _real L428;
   _real L427;
   _real L336;
   _boolean L335;
   _boolean L443;
   _real L442;
   _real L334;
   _real L325;
   _real T439;
   _real T414;
   _boolean T409;
   _boolean T408;
   _real T401;
   _real T394;
   _real T393;
   _boolean T392;
   _boolean T384;
   _boolean T383;
   _integer T350;
   _integer T295;
   _boolean T260;
   _integer L46;
   _integer L59;
   _integer L50;
   _integer L40;
   _integer T39;
   _integer T144;
   _integer T118;
   _boolean T93;
   _boolean T45;
   _boolean T43;
//CODE
   if (ctx->M36) {
      L35 = 0;
   } else {
      L35 = ctx->M39;
   }
   L34 = (L35 >= 2);
   L170 = (L35 <= 8);
   L33 = (L34 && L170);
   L175 = (ctx->_onOff == _false);
   if (L175) {
      L174 = 0;
   } else {
      L174 = 1;
   }
   L173 = (L174 != 0);
   if (L173) {
      L172 = _true;
   } else {
      L172 = _false;
   }
   L171 = (! L172);
   L32 = (L33 && L171);
   if (L33) {
      L180 = 0;
   } else {
      L180 = L35;
   }
   if (L32) {
      L179 = L180;
   } else {
      L179 = L35;
   }
   L178 = (L179 == 1);
   L177 = (! L178);
   if (L177) {
      L176 = 1;
   } else {
      L176 = L179;
   }
   if (L32) {
      L31 = L176;
   } else {
      L31 = L179;
   }
   L30 = (L31 == 1);
   L182 = (! L32);
   L181 = (L172 && L182);
   L29 = (L30 && L181);
   if (L30) {
      L189 = 0;
   } else {
      L189 = L31;
   }
   if (L29) {
      L188 = L189;
   } else {
      L188 = L31;
   }
   L187 = (L188 >= 2);
   L190 = (L188 <= 8);
   L186 = (L187 && L190);
   L185 = (! L186);
   if (L185) {
      L193 = 2;
   } else {
      L193 = L188;
   }
   L192 = (L193 >= 2);
   L194 = (L193 <= 8);
   L191 = (L192 && L194);
   L184 = (L185 && L191);
   L197 = (L193 == 7);
   L196 = (! L197);
   if (L196) {
      L195 = 7;
   } else {
      L195 = L193;
   }
   if (L184) {
      L183 = L195;
   } else {
      L183 = L193;
   }
   if (L29) {
      L28 = L183;
   } else {
      L28 = L188;
   }
   L27 = (L28 >= 3);
   L199 = (L28 <= 6);
   L26 = (L27 && L199);
   L209 = (! ctx->_cancel);
   L210 = (! ctx->_brakePedal);
   L208 = (L209 && L210);
   L212 = (ctx->_carGear == 3);
   if (L212) {
      L211 = _true;
   } else {
      L211 = _false;
   }
   L207 = (L208 && L211);
   L214 = (ctx->_carSpeed >= 15.000000);
   if (L214) {
      L213 = _true;
   } else {
      L213 = _false;
   }
   L206 = (L207 && L213);
   L205 = (L206 && ctx->_validInputs);
   L204 = (L205 == _false);
   if (L204) {
      L203 = 0;
   } else {
      L203 = 1;
   }
   L202 = (L203 != 0);
   if (L202) {
      L201 = _true;
   } else {
      L201 = _false;
   }
   L200 = (! L201);
   L25 = (L26 && L200);
   if (L26) {
      L220 = 2;
   } else {
      L220 = L28;
   }
   if (L25) {
      L219 = L220;
   } else {
      L219 = L28;
   }
   L218 = (L219 == 8);
   L217 = (! L218);
   if (L217) {
      L216 = 8;
   } else {
      L216 = L219;
   }
   if (L25) {
      L24 = L216;
   } else {
      L24 = L219;
   }
   L23 = (L24 == 8);
   L92 = (! ctx->M93);
   L91 = (L92 && ctx->_decelSet);
   if (ctx->M36) {
      L90 = _false;
   } else {
      L90 = L91;
   }
   L89 = (L90 == _false);
   if (L89) {
      L88 = 0;
   } else {
      L88 = 1;
   }
   L87 = (L88 == 1);
   L226 = (L87 == _false);
   if (L226) {
      L225 = 0;
   } else {
      L225 = 1;
   }
   L224 = (L225 != 0);
   if (L224) {
      L223 = _true;
   } else {
      L223 = _false;
   }
   L231 = (L203 == 1);
   L230 = (L231 == _false);
   if (L230) {
      L229 = 0;
   } else {
      L229 = 1;
   }
   L228 = (L229 != 0);
   if (L228) {
      L227 = _true;
   } else {
      L227 = _false;
   }
   L222 = (L223 && L227);
   L232 = (! L25);
   L221 = (L222 && L232);
   L22 = (L23 && L221);
   if (L23) {
      L239 = 2;
   } else {
      L239 = L24;
   }
   if (L22) {
      L238 = L239;
   } else {
      L238 = L24;
   }
   L237 = (L238 >= 3);
   L240 = (L238 <= 6);
   L236 = (L237 && L240);
   L235 = (! L236);
   if (L235) {
      L243 = 3;
   } else {
      L243 = L238;
   }
   L242 = (L243 >= 3);
   L244 = (L243 <= 6);
   L241 = (L242 && L244);
   L234 = (L235 && L241);
   L247 = (L243 == 4);
   L246 = (! L247);
   if (L246) {
      L245 = 4;
   } else {
      L245 = L243;
   }
   if (L234) {
      L233 = L245;
   } else {
      L233 = L243;
   }
   if (L22) {
      L21 = L233;
   } else {
      L21 = L238;
   }
   L20 = (L21 == 8);
   L259 = (! ctx->M260);
   L258 = (L259 && ctx->_accelResume);
   if (ctx->M36) {
      L257 = _false;
   } else {
      L257 = L258;
   }
   L256 = (L257 == _false);
   if (L256) {
      L255 = 0;
   } else {
      L255 = 1;
   }
   L254 = (L255 == 1);
   L253 = (L254 == _false);
   if (L253) {
      L252 = 0;
   } else {
      L252 = 1;
   }
   L251 = (L252 != 0);
   if (L251) {
      L250 = _true;
   } else {
      L250 = _false;
   }
   L249 = (L250 && L227);
   L64 = (L22 || L25);
   L261 = (! L64);
   L248 = (L249 && L261);
   L19 = (L20 && L248);
   if (L20) {
      L268 = 2;
   } else {
      L268 = L21;
   }
   if (L19) {
      L267 = L268;
   } else {
      L267 = L21;
   }
   L266 = (L267 >= 3);
   L269 = (L267 <= 6);
   L265 = (L266 && L269);
   L264 = (! L265);
   if (L264) {
      L272 = 3;
   } else {
      L272 = L267;
   }
   L271 = (L272 >= 3);
   L273 = (L272 <= 6);
   L270 = (L271 && L273);
   L263 = (L264 && L270);
   L276 = (L272 == 4);
   L275 = (! L276);
   if (L275) {
      L274 = 4;
   } else {
      L274 = L272;
   }
   if (L263) {
      L262 = L274;
   } else {
      L262 = L272;
   }
   if (L19) {
      L18 = L262;
   } else {
      L18 = L267;
   }
   L17 = (L18 == 7);
   L63 = (L19 || L64);
   L278 = (! L63);
   L277 = (L222 && L278);
   L16 = (L17 && L277);
   if (L17) {
      L279 = 2;
   } else {
      L279 = L18;
   }
   if (L16) {
      L15 = L279;
   } else {
      L15 = L18;
   }
   L14 = (L15 >= 3);
   L280 = (L15 <= 6);
   L13 = (L14 && L280);
   L12 = (! L13);
   if (L12) {
      L283 = 3;
   } else {
      L283 = L15;
   }
   L282 = (L283 >= 3);
   L284 = (L283 <= 6);
   L281 = (L282 && L284);
   L11 = (L12 && L281);
   L287 = (L283 == 4);
   L286 = (! L287);
   if (L286) {
      L285 = 4;
   } else {
      L285 = L283;
   }
   if (L11) {
      L10 = L285;
   } else {
      L10 = L283;
   }
   L9 = (L10 == 4);
   L289 = (L10 == 5);
   L290 = (L10 == 6);
   L288 = (L289 || L290);
   L8 = (L9 || L288);
   ctx->_OK = L8;
   if (ctx->M43) {
      L42 = _false;
   } else {
      L42 = ctx->M45;
   }
   if (ctx->M36) {
      L41 = _true;
   } else {
      L41 = L42;
   }
   L48 = (L35 == 1);
   L47 = (! L48);
   if (ctx->M36) {
      L294 = 0;
   } else {
      L294 = ctx->M295;
   }
   if (L47) {
      L293 = 1;
   } else {
      L293 = L294;
   }
   L53 = (L29 || L32);
   L52 = (! L53);
   L55 = (L28 >= 2);
   L57 = (L28 <= 8);
   L54 = (L55 && L57);
   L51 = (L52 && L54);
   L62 = (L16 || L63);
   L61 = (! L62);
   if (L16) {
      L67 = L10;
   } else {
      L67 = L15;
   }
   L66 = (L67 >= 3);
   L69 = (L67 <= 6);
   L65 = (L66 && L69);
   L60 = (L61 && L65);
   L85 = (L67 == 4);
   L84 = (L85 && L87);
   if (L85) {
      L98 = 3;
   } else {
      L98 = L67;
   }
   if (L84) {
      L97 = L98;
   } else {
      L97 = L67;
   }
   L96 = (L97 == 4);
   L95 = (! L96);
   if (L95) {
      L94 = 4;
   } else {
      L94 = L97;
   }
   if (L84) {
      L83 = L94;
   } else {
      L83 = L97;
   }
   L82 = (L83 == 4);
   if (ctx->_accelResume) {
      L110 = 1;
   } else {
      L110 = 0;
   }
   L109 = (0 >= L110);
   if (L109) {
      L108 = 0;
   } else {
      L108 = L110;
   }
   L107 = (L108 <= 20);
   if (L107) {
      L106 = L108;
   } else {
      L106 = 20;
   }
   L117 = (ctx->M118 + 1);
   if (ctx->_accelResume) {
      L116 = L117;
   } else {
      L116 = 0;
   }
   L115 = (0 >= L116);
   if (L115) {
      L114 = 0;
   } else {
      L114 = L116;
   }
   L113 = (L114 <= 20);
   if (L113) {
      L112 = L114;
   } else {
      L112 = 20;
   }
   if (ctx->M36) {
      L105 = L106;
   } else {
      L105 = L112;
   }
   L104 = (L105 == 20);
   if (L104) {
      L103 = _true;
   } else {
      L103 = _false;
   }
   L102 = (L103 == _false);
   if (L102) {
      L101 = 0;
   } else {
      L101 = 1;
   }
   L100 = (L101 == 1);
   L119 = (! L84);
   L99 = (L100 && L119);
   L81 = (L82 && L99);
   if (L82) {
      L124 = 3;
   } else {
      L124 = L83;
   }
   if (L81) {
      L123 = L124;
   } else {
      L123 = L83;
   }
   L122 = (L123 == 5);
   L121 = (! L122);
   if (L121) {
      L120 = 5;
   } else {
      L120 = L123;
   }
   if (L81) {
      L80 = L120;
   } else {
      L80 = L123;
   }
   L79 = (L80 == 4);
   if (ctx->_decelSet) {
      L137 = 1;
   } else {
      L137 = 0;
   }
   L136 = (0 >= L137);
   if (L136) {
      L135 = 0;
   } else {
      L135 = L137;
   }
   L134 = (L135 <= 20);
   if (L134) {
      L133 = L135;
   } else {
      L133 = 20;
   }
   L143 = (ctx->M144 + 1);
   if (ctx->_decelSet) {
      L142 = L143;
   } else {
      L142 = 0;
   }
   L141 = (0 >= L142);
   if (L141) {
      L140 = 0;
   } else {
      L140 = L142;
   }
   L139 = (L140 <= 20);
   if (L139) {
      L138 = L140;
   } else {
      L138 = 20;
   }
   if (ctx->M36) {
      L132 = L133;
   } else {
      L132 = L138;
   }
   L131 = (L132 == 20);
   if (L131) {
      L130 = _true;
   } else {
      L130 = _false;
   }
   L129 = (L130 == _false);
   if (L129) {
      L128 = 0;
   } else {
      L128 = 1;
   }
   L127 = (L128 == 1);
   L146 = (L81 || L84);
   L145 = (! L146);
   L126 = (L127 && L145);
   L78 = (L79 && L126);
   if (L79) {
      L151 = 3;
   } else {
      L151 = L80;
   }
   if (L78) {
      L150 = L151;
   } else {
      L150 = L80;
   }
   L149 = (L150 == 6);
   L148 = (! L149);
   if (L148) {
      L147 = 6;
   } else {
      L147 = L150;
   }
   if (L78) {
      L77 = L147;
   } else {
      L77 = L150;
   }
   L76 = (L77 == 6);
   L153 = (L128 == 0);
   L155 = (L78 || L146);
   L154 = (! L155);
   L152 = (L153 && L154);
   L75 = (L76 && L152);
   if (L76) {
      L160 = 3;
   } else {
      L160 = L77;
   }
   if (L75) {
      L159 = L160;
   } else {
      L159 = L77;
   }
   L158 = (L159 == 4);
   L157 = (! L158);
   if (L157) {
      L156 = 4;
   } else {
      L156 = L159;
   }
   if (L75) {
      L74 = L156;
   } else {
      L74 = L159;
   }
   L73 = (L74 == 5);
   L162 = (L101 == 0);
   L164 = (L75 || L155);
   L163 = (! L164);
   L161 = (L162 && L163);
   L72 = (L73 && L161);
   if (L73) {
      L169 = 3;
   } else {
      L169 = L74;
   }
   if (L72) {
      L168 = L169;
   } else {
      L168 = L74;
   }
   L167 = (L168 == 4);
   L166 = (! L167);
   if (L177) {
      L323 = 1;
   } else {
      L323 = L294;
   }
   if (L32) {
      L322 = L323;
   } else {
      L322 = L294;
   }
   if (L196) {
      L321 = 2;
   } else {
      L321 = L322;
   }
   if (L184) {
      L320 = L321;
   } else {
      L320 = L322;
   }
   if (L29) {
      L319 = L320;
   } else {
      L319 = L322;
   }
   if (L217) {
      L318 = 3;
   } else {
      L318 = L319;
   }
   if (L25) {
      L317 = L318;
   } else {
      L317 = L319;
   }
   if (L246) {
      L316 = 4;
   } else {
      L316 = L317;
   }
   if (L234) {
      L315 = L316;
   } else {
      L315 = L317;
   }
   if (L22) {
      L314 = L315;
   } else {
      L314 = L317;
   }
   if (L275) {
      L313 = 4;
   } else {
      L313 = L314;
   }
   if (L263) {
      L312 = L313;
   } else {
      L312 = L314;
   }
   if (L19) {
      L311 = L312;
   } else {
      L311 = L314;
   }
   if (L286) {
      L310 = 4;
   } else {
      L310 = L311;
   }
   if (L11) {
      L309 = L310;
   } else {
      L309 = L311;
   }
   if (L16) {
      L308 = L309;
   } else {
      L308 = L311;
   }
   if (L95) {
      L307 = 4;
   } else {
      L307 = L308;
   }
   if (L84) {
      L306 = L307;
   } else {
      L306 = L308;
   }
   if (L121) {
      L305 = 6;
   } else {
      L305 = L306;
   }
   if (L81) {
      L304 = L305;
   } else {
      L304 = L306;
   }
   if (L148) {
      L303 = 5;
   } else {
      L303 = L304;
   }
   if (L78) {
      L302 = L303;
   } else {
      L302 = L304;
   }
   if (L157) {
      L301 = 4;
   } else {
      L301 = L302;
   }
   if (L75) {
      L300 = L301;
   } else {
      L300 = L302;
   }
   if (L166) {
      L299 = 4;
   } else {
      L299 = L300;
   }
   if (L72) {
      L298 = L299;
   } else {
      L298 = L300;
   }
   if (L60) {
      L297 = L298;
   } else {
      L297 = L308;
   }
   if (L51) {
      L296 = L297;
   } else {
      L296 = L319;
   }
   if (L41) {
      L292 = L293;
   } else {
      L292 = L296;
   }
   ctx->_mode = L292;
   L329 = (L292 == 4);
   if (L329) {
      L328 = _true;
   } else {
      L328 = _false;
   }
   L331 = (L292 == 5);
   if (L331) {
      L330 = _true;
   } else {
      L330 = _false;
   }
   L327 = (L328 || L330);
   L333 = (L292 == 6);
   if (L333) {
      L332 = _true;
   } else {
      L332 = _false;
   }
   L326 = (L327 || L332);
   if (ctx->M36) {
      L349 = 0;
   } else {
      L349 = ctx->M350;
   }
   L356 = (L72 || L164);
   L355 = (! L356);
   if (L166) {
      L165 = 4;
   } else {
      L165 = L168;
   }
   if (L72) {
      L71 = L165;
   } else {
      L71 = L168;
   }
   L357 = (L71 == 4);
   L354 = (L355 && L357);
   L368 = (L28 == 4);
   L373 = (L35 >= 3);
   L374 = (L35 <= 6);
   L372 = (L373 && L374);
   L376 = (L35 == 4);
   if (L376) {
      L375 = 0;
   } else {
      L375 = L349;
   }
   if (L372) {
      L371 = L375;
   } else {
      L371 = L349;
   }
   if (L33) {
      L370 = L371;
   } else {
      L370 = L349;
   }
   if (L32) {
      L369 = L370;
   } else {
      L369 = L349;
   }
   if (L368) {
      L367 = 0;
   } else {
      L367 = L369;
   }
   if (L26) {
      L366 = L367;
   } else {
      L366 = L369;
   }
   if (L25) {
      L365 = L366;
   } else {
      L365 = L369;
   }
   if (L22) {
      L364 = 1;
   } else {
      L364 = L365;
   }
   if (L16) {
      L363 = 1;
   } else {
      L363 = L364;
   }
   if (L84) {
      L362 = 1;
   } else {
      L362 = L363;
   }
   if (L82) {
      L361 = 0;
   } else {
      L361 = L362;
   }
   if (L81) {
      L360 = L361;
   } else {
      L360 = L362;
   }
   if (L79) {
      L359 = 0;
   } else {
      L359 = L360;
   }
   if (L78) {
      L358 = L359;
   } else {
      L358 = L360;
   }
   if (L354) {
      L353 = 0;
   } else {
      L353 = L358;
   }
   if (L60) {
      L352 = L353;
   } else {
      L352 = L363;
   }
   if (L51) {
      L351 = L352;
   } else {
      L351 = L369;
   }
   if (L41) {
      L348 = L349;
   } else {
      L348 = L351;
   }
   L347 = (L348 != 0);
   if (L347) {
      L346 = _true;
   } else {
      L346 = _false;
   }
   if (ctx->M383) {
      L382 = _false;
   } else {
      L382 = ctx->M384;
   }
   if (ctx->M36) {
      L381 = _true;
   } else {
      L381 = L382;
   }
   L385 = (! L332);
   L380 = (L381 && L385);
   if (ctx->M392) {
      L391 = ctx->M393;
   } else {
      L391 = ctx->M394;
   }
   L390 = (L391 < 0.000000);
   L396 = (L391 > 100.000000);
   if (L396) {
      L395 = 100.000000;
   } else {
      L395 = L391;
   }
   if (L390) {
      L389 = 0.000000;
   } else {
      L389 = L395;
   }
   if (ctx->M36) {
      L388 = 0.000000;
   } else {
      L388 = L389;
   }
   L387 = (L388 + 0.050000);
   if (L380) {
      L379 = 0.000000;
   } else {
      L379 = L387;
   }
   if (L332) {
      L400 = L387;
   } else {
      L400 = ctx->M401;
   }
   if (L380) {
      L399 = 0.000000;
   } else {
      L399 = L400;
   }
   if (ctx->M36) {
      L378 = L379;
   } else {
      L378 = L399;
   }
   if (ctx->M408) {
      L407 = _false;
   } else {
      L407 = ctx->M409;
   }
   if (ctx->M36) {
      L406 = _true;
   } else {
      L406 = L407;
   }
   L410 = (! L330);
   L405 = (L406 && L410);
   L411 = (L388 - 0.050000);
   if (L405) {
      L404 = 0.000000;
   } else {
      L404 = L411;
   }
   if (L330) {
      L413 = L411;
   } else {
      L413 = ctx->M414;
   }
   if (L405) {
      L412 = 0.000000;
   } else {
      L412 = L413;
   }
   if (ctx->M36) {
      L403 = L404;
   } else {
      L403 = L412;
   }
   L418 = (L292 == 3);
   if (L418) {
      L417 = _true;
   } else {
      L417 = _false;
   }
   if (L417) {
      L416 = L388;
   } else {
      L416 = 0.000000;
   }
   if (L328) {
      L415 = L388;
   } else {
      L415 = L416;
   }
   if (L330) {
      L402 = L403;
   } else {
      L402 = L415;
   }
   if (L332) {
      L377 = L378;
   } else {
      L377 = L402;
   }
   if (L346) {
      L345 = ctx->_carSpeed;
   } else {
      L345 = L377;
   }
   L344 = (L345 < 0.000000);
   L420 = (L345 > 100.000000);
   if (L420) {
      L419 = 100.000000;
   } else {
      L419 = L345;
   }
   if (L344) {
      L343 = 0.000000;
   } else {
      L343 = L419;
   }
   L342 = (L343 - ctx->_carSpeed);
   L341 = (L342 * 1.000000);
   L422 = (- 10.000000);
   L340 = (L341 < L422);
   L425 = (L341 > 10.000000);
   if (L425) {
      L424 = 10.000000;
   } else {
      L424 = L341;
   }
   if (L340) {
      L339 = L422;
   } else {
      L339 = L424;
   }
   L338 = (L339 / 20.000000);
   L337 = (L338 + 0.000000);
   L432 = (ctx->M295 == 4);
   if (L432) {
      L431 = _true;
   } else {
      L431 = _false;
   }
   L434 = (ctx->M295 == 5);
   if (L434) {
      L433 = _true;
   } else {
      L433 = _false;
   }
   L430 = (L431 || L433);
   L436 = (ctx->M295 == 6);
   if (L436) {
      L435 = _true;
   } else {
      L435 = _false;
   }
   L429 = (L430 || L435);
   L438 = (ctx->M439 < 0.000000);
   L441 = (ctx->M439 > 100.000000);
   if (L441) {
      L440 = 100.000000;
   } else {
      L440 = ctx->M439;
   }
   if (L438) {
      L437 = 0.000000;
   } else {
      L437 = L440;
   }
   if (L429) {
      L428 = L437;
   } else {
      L428 = 0.000000;
   }
   L427 = (L338 + L428);
   if (ctx->M36) {
      L336 = L337;
   } else {
      L336 = L427;
   }
   L335 = (L336 < 0.000000);
   L443 = (L336 > 100.000000);
   if (L443) {
      L442 = 100.000000;
   } else {
      L442 = L336;
   }
   if (L335) {
      L334 = 0.000000;
   } else {
      L334 = L442;
   }
   if (L326) {
      L325 = L334;
   } else {
      L325 = 0.000000;
   }
   ctx->_cruiseThrottle = L325;
   ctx->_desiredSpeed = L343;
   T439 = L336;
   T414 = L403;
   T409 = L406;
   T408 = L330;
   T401 = L378;
   T394 = L377;
   T393 = ctx->_carSpeed;
   T392 = L346;
   T384 = L381;
   T383 = L332;
   T350 = L348;
   T295 = L292;
   T260 = ctx->_accelResume;
   if (L47) {
      L46 = 1;
   } else {
      L46 = L35;
   }
   if (L60) {
      L59 = L71;
   } else {
      L59 = L67;
   }
   if (L51) {
      L50 = L59;
   } else {
      L50 = L28;
   }
   if (L41) {
      L40 = L46;
   } else {
      L40 = L50;
   }
   T39 = L40;
   T144 = L132;
   T118 = L105;
   T93 = ctx->_decelSet;
   T45 = L41;
   T43 = _true;
   ctx->M439 = T439;
   ctx->M439_nil = _false;
   ctx->M414 = T414;
   ctx->M414_nil = _false;
   ctx->M409 = T409;
   ctx->M409_nil = _false;
   ctx->M408 = T408;
   ctx->M408_nil = _false;
   ctx->M401 = T401;
   ctx->M401_nil = _false;
   ctx->M394 = T394;
   ctx->M394_nil = _false;
   ctx->M393 = T393;
   ctx->M393_nil = _false;
   ctx->M392 = T392;
   ctx->M392_nil = _false;
   ctx->M384 = T384;
   ctx->M384_nil = _false;
   ctx->M383 = T383;
   ctx->M383_nil = _false;
   ctx->M350 = T350;
   ctx->M350_nil = _false;
   ctx->M295 = T295;
   ctx->M295_nil = _false;
   ctx->M260 = T260;
   ctx->M260_nil = _false;
   ctx->M39 = T39;
   ctx->M39_nil = _false;
   ctx->M144 = T144;
   ctx->M144_nil = _false;
   ctx->M118 = T118;
   ctx->M118_nil = _false;
   ctx->M93 = T93;
   ctx->M93_nil = _false;
   ctx->M45 = T45;
   ctx->M45_nil = _false;
   ctx->M43 = T43;
   ctx->M43_nil = _false;
   ctx->M36 = ctx->M36 && !(_true);
}
/********
 * ec2c version 0.67
 * c main file generated for node : Edge 
 * to be used with : edge.c 
 * and             : edge.h 
 * context   method = HEAP
 * ext call  method = PROCEDURES
 ********/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/* testing features **********************************************************/

typedef struct input_t {
  //INPUTS
  int onOff;       // boolean
  int decelSet;    // boolean
  int accelResume; // boolean
  int cancel;      // boolean
  int brakePedal;  // boolean
  int carGear;     // integer
  double carSpeed; // _real
  int validInputs; // boolean
  //OUTPUTS
  //_boolean _OK;
} input_t ; 

typedef struct input_node_t {
  input_t elem; 
  struct input_node_t *next;
} input_node_t ;

typedef struct test_node_t {
  input_node_t *steps;
  struct test_node_t *next;
} test_node_t;

void assign_inputs(top_ctx* ctx, input_t* elem) {
  ctx->_onOff = elem->onOff;
  ctx->_decelSet = elem->decelSet;
  ctx->_accelResume = elem->accelResume;
  ctx->_cancel = elem->cancel;
  ctx->_brakePedal = elem->brakePedal;
  ctx->_carGear = elem->carGear;
  ctx->_carSpeed = elem->carSpeed;
  ctx->_validInputs = elem->validInputs;
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
  // accelResume, brakePedal, cancel, carGear, carSpeed, decelSet, onOff, validInputs
  char tmp1[8], tmp2[8], tmp3[8];
  int tmp4;
  char tmp5[16], tmp6[8], tmp7[8], tmp8[8];

  sscanf(buffer, "%[^','],%[^','],%[^','],%d,%[^','],%[^','],%[^','],%[^',']", 
      tmp1, tmp2, tmp3, &tmp4, tmp5, tmp6, tmp7, tmp8);
  in->accelResume = bool_lit_to_int(tmp1);
  in->brakePedal = bool_lit_to_int(tmp2);
  in->cancel = bool_lit_to_int(tmp3);
  in->carGear = tmp4;
  in->carSpeed = extract_double(tmp5);
  in->decelSet = bool_lit_to_int(tmp6);
  in->onOff = bool_lit_to_int(tmp7);
  in->validInputs = bool_lit_to_int(tmp8);
#if DEBUG
  printf("(%d %d %d %d %lf, %d %d %d)\n", 
      in->accelResume, in->brakePedal, in->cancel, in->carGear, 
      in->carSpeed, in->decelSet, in->onOff, in->validInputs);
#endif
}

FILE* create_trace_file(char* fname) {
  /* open the trace file to dump the output 
   * @return the file pointer of the trace file */
  if (NULL == fname) {
    return NULL;
  }
  FILE* fp = fopen(fname, "w");
  /* print the CSV header (11 output variables) */
  return fp;
}

// 11 outputs in total (in obsnop.trace)
void dump_state(FILE* fp, top_ctx* ctx) {
  /* dump the internal state for the current step 
   * so that it can later be compared to the oracle */
  if (NULL == ctx || NULL == fp) {
    fprintf(fp, "\n");
    return;
  }
  fprintf(fp, "%d,%d,%f,%f\n", ctx->_OK, ctx->_mode, ctx->_cruiseThrottle,
      ctx->_desiredSpeed);
}

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

/* end of testing features ***/


top_ctx ctx;

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
    printf("[cc] invalid number of argument\n");
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
  top_init(&ctx, NULL);
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
#if DEBUG
    //printf("TC #%d, %d steps\n", n_test_cases, n_steps);
#endif
    /* finished: consumed all the steps of the current test case */
    //dump_state(fp_dump, NULL);          // dump a blank line
    memset(&ctx, 0, sizeof(top_ctx));    // init the state variables
    top_reset(&ctx);                     // reset the registers
    n_test_cases++;
    current_test = current_test->next;
  }
  fclose(fp_dump);
  printf("No.of test cases completed:%lu\n", n_test_cases);

  return 0;
}

