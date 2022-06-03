#include "The_Chain.h"

namespace The_Chain {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Delay m_delay_30;
	Delay m_delay_16;
	Delay m_delay_32;
	Delay m_delay_34;
	Delay m_delay_36;
	Delay m_delay_14;
	Delay m_delay_12;
	Delay m_delay_18;
	Delay m_delay_20;
	Delay m_delay_26;
	Delay m_delay_28;
	Delay m_delay_22;
	Delay m_delay_27;
	Delay m_delay_24;
	Delay m_delay_38;
	Delay m_delay_40;
	Delay m_delay_10;
	Delay m_delay_48;
	Delay m_delay_57;
	Delay m_delay_46;
	Delay m_delay_47;
	Delay m_delay_44;
	Delay m_delay_45;
	Delay m_delay_8;
	Delay m_delay_25;
	Delay m_delay_42;
	Delta __m_delta_58;
	PlusEquals __m_pluseq_59;
	int __exception;
	int vectorsize;
	t_sample m_history_49;
	t_sample m_history_21;
	t_sample m_history_50;
	t_sample m_history_51;
	t_sample m_C_2;
	t_sample m_Push_4;
	t_sample m_Exp_3;
	t_sample m_history_52;
	t_sample m_history_53;
	t_sample m_history_54;
	t_sample samplerate;
	t_sample __m_count_60;
	t_sample m_B_5;
	t_sample m_history_1;
	t_sample m_history_55;
	t_sample m_history_56;
	t_sample m_history_23;
	t_sample m_D_6;
	t_sample m_A_7;
	t_sample m_history_31;
	t_sample m_history_17;
	t_sample m_history_33;
	t_sample __m_latch_61;
	t_sample m_history_19;
	t_sample m_history_29;
	t_sample m_history_43;
	t_sample m_history_15;
	t_sample m_history_13;
	t_sample m_history_9;
	t_sample m_history_41;
	t_sample m_history_35;
	t_sample m_history_39;
	t_sample m_history_37;
	t_sample m_history_11;
	t_sample __m_slide_62;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_C_2 = ((int)0);
		m_Exp_3 = ((int)0);
		m_Push_4 = ((int)0);
		m_B_5 = ((int)0);
		m_D_6 = ((int)0);
		m_A_7 = ((int)0);
		m_delay_8.reset("m_delay_8", ((int)2000));
		m_history_9 = ((int)0);
		m_delay_10.reset("m_delay_10", ((int)2000));
		m_history_11 = ((int)0);
		m_delay_12.reset("m_delay_12", ((int)2000));
		m_history_13 = ((int)0);
		m_delay_14.reset("m_delay_14", ((int)2000));
		m_history_15 = ((int)0);
		m_delay_16.reset("m_delay_16", ((int)2000));
		m_history_17 = ((int)0);
		m_delay_18.reset("m_delay_18", ((int)2000));
		m_history_19 = ((int)0);
		m_delay_20.reset("m_delay_20", ((int)2000));
		m_history_21 = ((int)0);
		m_delay_22.reset("m_delay_22", ((int)2000));
		m_history_23 = ((int)0);
		m_delay_24.reset("m_delay_24", ((int)2000));
		m_delay_25.reset("m_delay_25", ((int)2000));
		m_delay_26.reset("m_delay_26", ((int)2000));
		m_delay_27.reset("m_delay_27", ((int)2000));
		m_delay_28.reset("m_delay_28", ((int)2000));
		m_history_29 = ((int)0);
		m_delay_30.reset("m_delay_30", ((int)2000));
		m_history_31 = ((int)0);
		m_delay_32.reset("m_delay_32", ((int)2000));
		m_history_33 = ((int)0);
		m_delay_34.reset("m_delay_34", ((int)2000));
		m_history_35 = ((int)0);
		m_delay_36.reset("m_delay_36", ((int)2000));
		m_history_37 = ((int)0);
		m_delay_38.reset("m_delay_38", ((int)2000));
		m_history_39 = ((int)0);
		m_delay_40.reset("m_delay_40", ((int)2000));
		m_history_41 = ((int)0);
		m_delay_42.reset("m_delay_42", ((int)2000));
		m_history_43 = ((int)0);
		m_delay_44.reset("m_delay_44", ((int)2000));
		m_delay_45.reset("m_delay_45", ((int)2000));
		m_delay_46.reset("m_delay_46", ((int)2000));
		m_delay_47.reset("m_delay_47", ((int)2000));
		m_delay_48.reset("m_delay_48", ((int)48000));
		m_history_49 = ((int)0);
		m_history_50 = ((int)0);
		m_history_51 = ((int)0);
		m_history_52 = ((int)0);
		m_history_53 = ((int)0);
		m_history_54 = ((int)0);
		m_history_55 = ((int)0);
		m_history_56 = ((int)0);
		m_delay_57.reset("m_delay_57", ((int)48000));
		__m_delta_58.reset(0);
		__m_pluseq_59.reset(0);
		__m_count_60 = 0;
		__m_latch_61 = 0;
		__m_slide_62 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample mul_1638 = (m_A_7 * ((int)10));
		t_sample round_2114 = round(mul_1638);
		t_sample iup_63 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_64 = (1 / maximum(1, abs(((int)3000))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample delta_21 = __m_delta_58(m_Push_4);
			t_sample gtep_20 = ((delta_21 >= ((int)1)) ? delta_21 : 0);
			t_sample plusequals_19 = __m_pluseq_59.post(gtep_20, m_history_1, 0);
			int eq_17 = (plusequals_19 == ((int)2));
			__m_count_60 = (m_history_1 ? 0 : (fixdenorm(__m_count_60 + plusequals_19)));
			t_sample counter_14 = __m_count_60;
			int counter_15 = ((int)0);
			int counter_16 = ((int)0);
			__m_latch_61 = ((eq_17 != 0) ? counter_14 : __m_latch_61);
			t_sample latch_13 = __m_latch_61;
			t_sample history_18_next_22 = fixdenorm(eq_17);
			t_sample out3 = latch_13;
			t_sample mul_278 = (in2 * ((t_sample)0.015));
			t_sample tap_220 = m_delay_8.read_step(((int)1557));
			t_sample gen_258 = tap_220;
			t_sample mul_218 = (tap_220 * ((t_sample)0.13));
			t_sample mul_216 = (m_history_9 * ((t_sample)0.87));
			t_sample add_217 = (mul_218 + mul_216);
			t_sample mul_214 = (add_217 * ((t_sample)0.96));
			t_sample add_221 = (mul_278 + mul_214);
			t_sample history_215_next_222 = fixdenorm(add_217);
			t_sample tap_285 = m_delay_10.read_step(((int)1617));
			t_sample gen_277 = tap_285;
			t_sample mul_283 = (tap_285 * ((t_sample)0.13));
			t_sample mul_282 = (m_history_11 * ((t_sample)0.87));
			t_sample add_281 = (mul_283 + mul_282);
			t_sample mul_279 = (add_281 * ((t_sample)0.96));
			t_sample add_280 = (mul_278 + mul_279);
			t_sample history_215_next_287 = fixdenorm(add_281);
			t_sample tap_297 = m_delay_12.read_step(((int)1491));
			t_sample gen_257 = tap_297;
			t_sample mul_295 = (tap_297 * ((t_sample)0.13));
			t_sample mul_294 = (m_history_13 * ((t_sample)0.87));
			t_sample add_293 = (mul_295 + mul_294);
			t_sample mul_291 = (add_293 * ((t_sample)0.96));
			t_sample add_292 = (mul_278 + mul_291);
			t_sample history_215_next_299 = fixdenorm(add_293);
			t_sample tap_305 = m_delay_14.read_step(((int)1422));
			t_sample gen_256 = tap_305;
			t_sample mul_310 = (tap_305 * ((t_sample)0.13));
			t_sample mul_306 = (m_history_15 * ((t_sample)0.87));
			t_sample add_309 = (mul_310 + mul_306);
			t_sample mul_312 = (add_309 * ((t_sample)0.96));
			t_sample add_307 = (mul_278 + mul_312);
			t_sample history_215_next_304 = fixdenorm(add_309);
			t_sample tap_317 = m_delay_16.read_step(((int)1356));
			t_sample gen_255 = tap_317;
			t_sample mul_323 = (tap_317 * ((t_sample)0.13));
			t_sample mul_318 = (m_history_17 * ((t_sample)0.87));
			t_sample add_321 = (mul_323 + mul_318);
			t_sample mul_320 = (add_321 * ((t_sample)0.96));
			t_sample add_319 = (mul_278 + mul_320);
			t_sample history_215_next_316 = fixdenorm(add_321);
			t_sample tap_329 = m_delay_18.read_step(((int)1277));
			t_sample gen_254 = tap_329;
			t_sample mul_335 = (tap_329 * ((t_sample)0.13));
			t_sample mul_330 = (m_history_19 * ((t_sample)0.87));
			t_sample add_333 = (mul_335 + mul_330);
			t_sample mul_331 = (add_333 * ((t_sample)0.96));
			t_sample add_332 = (mul_278 + mul_331);
			t_sample history_215_next_328 = fixdenorm(add_333);
			t_sample tap_342 = m_delay_20.read_step(((int)1188));
			t_sample gen_253 = tap_342;
			t_sample mul_346 = (tap_342 * ((t_sample)0.13));
			t_sample mul_344 = (m_history_21 * ((t_sample)0.87));
			t_sample add_340 = (mul_346 + mul_344);
			t_sample mul_347 = (add_340 * ((t_sample)0.96));
			t_sample add_343 = (mul_278 + mul_347);
			t_sample history_215_next_341 = fixdenorm(add_340);
			t_sample tap_354 = m_delay_22.read_step(((int)1116));
			t_sample gen_252 = tap_354;
			t_sample mul_358 = (tap_354 * ((t_sample)0.13));
			t_sample mul_355 = (m_history_23 * ((t_sample)0.87));
			t_sample add_351 = (mul_358 + mul_355);
			t_sample mul_359 = (add_351 * ((t_sample)0.96));
			t_sample add_356 = (mul_278 + mul_359);
			t_sample history_215_next_353 = fixdenorm(add_351);
			t_sample add_275 = ((((((((gen_252 + gen_253) + gen_254) + gen_255) + gen_256) + gen_257) + gen_277) + gen_258) + ((int)0));
			t_sample tap_211 = m_delay_24.read_step(((int)556));
			t_sample sub_207 = (add_275 - tap_211);
			t_sample mul_209 = (tap_211 * ((t_sample)0.25));
			t_sample add_208 = (add_275 + mul_209);
			t_sample tap_364 = m_delay_25.read_step(((int)441));
			t_sample sub_365 = (sub_207 - tap_364);
			t_sample mul_363 = (tap_364 * ((t_sample)0.25));
			t_sample add_366 = (sub_207 + mul_363);
			t_sample tap_370 = m_delay_26.read_step(((int)341));
			t_sample sub_371 = (sub_365 - tap_370);
			t_sample mul_369 = (tap_370 * ((t_sample)0.25));
			t_sample add_372 = (sub_365 + mul_369);
			t_sample tap_376 = m_delay_27.read_step(((int)225));
			t_sample sub_377 = (sub_371 - tap_376);
			t_sample mul_375 = (tap_376 * ((t_sample)0.25));
			t_sample add_378 = (sub_371 + mul_375);
			t_sample mul_32 = (sub_377 * m_D_6);
			t_sample mul_11502 = (in1 * ((t_sample)0.015));
			t_sample tap_11469 = m_delay_28.read_step(((int)1557));
			t_sample gen_11587 = tap_11469;
			t_sample mul_11586 = (tap_11469 * ((t_sample)0.13));
			t_sample mul_11567 = (m_history_29 * ((t_sample)0.87));
			t_sample add_11524 = (mul_11586 + mul_11567);
			t_sample mul_11575 = (add_11524 * ((t_sample)0.96));
			t_sample add_11485 = (mul_11502 + mul_11575);
			t_sample history_215_next_11535 = fixdenorm(add_11524);
			t_sample tap_11462 = m_delay_30.read_step(((int)1617));
			t_sample gen_11475 = tap_11462;
			t_sample mul_11488 = (tap_11462 * ((t_sample)0.13));
			t_sample mul_11470 = (m_history_31 * ((t_sample)0.87));
			t_sample add_11466 = (mul_11488 + mul_11470);
			t_sample mul_11451 = (add_11466 * ((t_sample)0.96));
			t_sample add_11484 = (mul_11502 + mul_11451);
			t_sample history_215_next_11482 = fixdenorm(add_11466);
			t_sample tap_11506 = m_delay_32.read_step(((int)1491));
			t_sample gen_11569 = tap_11506;
			t_sample mul_11472 = (tap_11506 * ((t_sample)0.13));
			t_sample mul_11499 = (m_history_33 * ((t_sample)0.87));
			t_sample add_11503 = (mul_11472 + mul_11499);
			t_sample mul_11474 = (add_11503 * ((t_sample)0.96));
			t_sample add_11468 = (mul_11502 + mul_11474);
			t_sample history_215_next_11461 = fixdenorm(add_11503);
			t_sample tap_11581 = m_delay_34.read_step(((int)1422));
			t_sample gen_11579 = tap_11581;
			t_sample mul_11570 = (tap_11581 * ((t_sample)0.13));
			t_sample mul_11498 = (m_history_35 * ((t_sample)0.87));
			t_sample add_11584 = (mul_11570 + mul_11498);
			t_sample mul_11550 = (add_11584 * ((t_sample)0.96));
			t_sample add_11558 = (mul_11502 + mul_11550);
			t_sample history_215_next_11574 = fixdenorm(add_11584);
			t_sample tap_11443 = m_delay_36.read_step(((int)1356));
			t_sample gen_11565 = tap_11443;
			t_sample mul_11564 = (tap_11443 * ((t_sample)0.13));
			t_sample mul_11459 = (m_history_37 * ((t_sample)0.87));
			t_sample add_11561 = (mul_11564 + mul_11459);
			t_sample mul_11559 = (add_11561 * ((t_sample)0.96));
			t_sample add_11554 = (mul_11502 + mul_11559);
			t_sample history_215_next_11553 = fixdenorm(add_11561);
			t_sample tap_11532 = m_delay_38.read_step(((int)1277));
			t_sample gen_11549 = tap_11532;
			t_sample mul_11437 = (tap_11532 * ((t_sample)0.13));
			t_sample mul_11504 = (m_history_39 * ((t_sample)0.87));
			t_sample add_11548 = (mul_11437 + mul_11504);
			t_sample mul_11440 = (add_11548 * ((t_sample)0.96));
			t_sample add_11483 = (mul_11502 + mul_11440);
			t_sample history_215_next_11467 = fixdenorm(add_11548);
			t_sample tap_11545 = m_delay_40.read_step(((int)1188));
			t_sample gen_11509 = tap_11545;
			t_sample mul_11543 = (tap_11545 * ((t_sample)0.13));
			t_sample mul_11541 = (m_history_41 * ((t_sample)0.87));
			t_sample add_11540 = (mul_11543 + mul_11541);
			t_sample mul_11539 = (add_11540 * ((t_sample)0.96));
			t_sample add_11538 = (mul_11502 + mul_11539);
			t_sample history_215_next_11536 = fixdenorm(add_11540);
			t_sample tap_11465 = m_delay_42.read_step(((int)1116));
			t_sample gen_11588 = tap_11465;
			t_sample mul_11530 = (tap_11465 * ((t_sample)0.13));
			t_sample mul_11445 = (m_history_43 * ((t_sample)0.87));
			t_sample add_11590 = (mul_11530 + mul_11445);
			t_sample mul_11520 = (add_11590 * ((t_sample)0.96));
			t_sample add_11454 = (mul_11502 + mul_11520);
			t_sample history_215_next_11464 = fixdenorm(add_11590);
			t_sample add_11449 = ((((((((gen_11588 + gen_11509) + gen_11549) + gen_11565) + gen_11579) + gen_11569) + gen_11475) + gen_11587) + ((int)0));
			t_sample tap_11500 = m_delay_44.read_step(((int)556));
			t_sample sub_11510 = (add_11449 - tap_11500);
			t_sample mul_11476 = (tap_11500 * ((t_sample)0.25));
			t_sample add_11526 = (add_11449 + mul_11476);
			t_sample tap_11515 = m_delay_45.read_step(((int)441));
			t_sample sub_11447 = (sub_11510 - tap_11515);
			t_sample mul_11471 = (tap_11515 * ((t_sample)0.25));
			t_sample add_11522 = (sub_11510 + mul_11471);
			t_sample tap_11521 = m_delay_46.read_step(((int)341));
			t_sample sub_11446 = (sub_11447 - tap_11521);
			t_sample mul_11516 = (tap_11521 * ((t_sample)0.25));
			t_sample add_11497 = (sub_11447 + mul_11516);
			t_sample tap_11514 = m_delay_47.read_step(((int)225));
			t_sample sub_11439 = (sub_11446 - tap_11514);
			t_sample mul_11544 = (tap_11514 * ((t_sample)0.25));
			t_sample add_11508 = (sub_11446 + mul_11544);
			t_sample mul_382 = (sub_11439 * m_D_6);
			t_sample tap_453 = m_delay_48.read_step(((int)0));
			t_sample mul_402 = (tap_453 * ((int)100));
			t_sample ceil_401 = ceil(mul_402);
			t_sample div_400 = (ceil_401 * ((t_sample)0.01));
			t_sample mul_450 = (div_400 * m_C_2);
			t_sample out1 = ((mul_382 + mul_450) + in1);
			t_sample mul_28 = (tap_453 * m_B_5);
			t_sample mul_430 = (in2 * ((t_sample)0.001));
			t_sample mul_427 = (m_history_51 * ((t_sample)0.003));
			t_sample mul_425 = (m_history_49 * ((t_sample)0.001));
			t_sample mul_421 = (m_history_50 * ((t_sample)0.852));
			t_sample mul_423 = (m_history_52 * ((t_sample)-1.846));
			t_sample sub_429 = (((mul_425 + mul_427) + mul_430) - (mul_423 + mul_421));
			t_sample gen_435 = sub_429;
			t_sample history_426_next_431 = fixdenorm(m_history_51);
			t_sample history_422_next_432 = fixdenorm(m_history_52);
			t_sample history_428_next_433 = fixdenorm(in2);
			t_sample history_424_next_434 = fixdenorm(sub_429);
			t_sample mul_11626 = (in1 * ((t_sample)0.001));
			t_sample mul_11633 = (m_history_55 * ((t_sample)0.003));
			t_sample mul_11625 = (m_history_53 * ((t_sample)0.001));
			t_sample mul_11618 = (m_history_54 * ((t_sample)0.852));
			t_sample mul_11620 = (m_history_56 * ((t_sample)-1.846));
			t_sample sub_11632 = (((mul_11625 + mul_11633) + mul_11626) - (mul_11620 + mul_11618));
			t_sample gen_446 = sub_11632;
			t_sample history_426_next_11629 = fixdenorm(m_history_55);
			t_sample history_422_next_11624 = fixdenorm(m_history_56);
			t_sample history_428_next_11630 = fixdenorm(in1);
			t_sample history_424_next_11634 = fixdenorm(sub_11632);
			t_sample mul_4724 = (latch_13 * ((int)16));
			t_sample div_11435 = safediv(mul_4724, round_2114);
			t_sample mul_2 = (div_11435 * ((int)1));
			__m_slide_62 = fixdenorm((__m_slide_62 + (((mul_2 > __m_slide_62) ? iup_63 : idown_64) * (mul_2 - __m_slide_62))));
			t_sample slide_25 = __m_slide_62;
			t_sample tap_449 = m_delay_57.read_linear(slide_25);
			t_sample mul_11645 = (tap_449 * ((int)100));
			t_sample ceil_11641 = ceil(mul_11645);
			t_sample div_11642 = (ceil_11641 * ((t_sample)0.01));
			t_sample mul_447 = (div_11642 * m_C_2);
			t_sample out2 = ((mul_32 + mul_447) + in2);
			t_sample mul_27 = (tap_449 * m_B_5);
			m_history_1 = history_18_next_22;
			m_delay_57.write((mul_27 + gen_435));
			m_history_54 = history_422_next_11624;
			m_history_55 = history_428_next_11630;
			m_history_56 = history_424_next_11634;
			m_history_53 = history_426_next_11629;
			m_history_50 = history_422_next_432;
			m_history_51 = history_428_next_433;
			m_history_52 = history_424_next_434;
			m_history_49 = history_426_next_431;
			m_delay_48.write((mul_28 + gen_446));
			m_history_29 = history_215_next_11535;
			m_delay_30.write(add_11484);
			m_history_31 = history_215_next_11482;
			m_delay_32.write(add_11468);
			m_history_33 = history_215_next_11461;
			m_delay_34.write(add_11558);
			m_history_35 = history_215_next_11574;
			m_delay_36.write(add_11554);
			m_history_37 = history_215_next_11553;
			m_delay_38.write(add_11483);
			m_history_39 = history_215_next_11467;
			m_delay_40.write(add_11538);
			m_history_41 = history_215_next_11536;
			m_delay_42.write(add_11454);
			m_history_43 = history_215_next_11464;
			m_delay_44.write(add_11526);
			m_delay_45.write(add_11522);
			m_delay_46.write(add_11497);
			m_delay_47.write(add_11508);
			m_delay_28.write(add_11485);
			m_history_9 = history_215_next_222;
			m_delay_10.write(add_280);
			m_history_11 = history_215_next_287;
			m_delay_12.write(add_292);
			m_history_13 = history_215_next_299;
			m_delay_14.write(add_307);
			m_history_15 = history_215_next_304;
			m_delay_16.write(add_319);
			m_history_17 = history_215_next_316;
			m_delay_18.write(add_332);
			m_history_19 = history_215_next_328;
			m_delay_20.write(add_343);
			m_history_21 = history_215_next_341;
			m_delay_22.write(add_356);
			m_history_23 = history_215_next_353;
			m_delay_24.write(add_208);
			m_delay_25.write(add_366);
			m_delay_26.write(add_372);
			m_delay_27.write(add_378);
			m_delay_8.write(add_221);
			m_delay_8.step();
			m_delay_10.step();
			m_delay_12.step();
			m_delay_14.step();
			m_delay_16.step();
			m_delay_18.step();
			m_delay_20.step();
			m_delay_22.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_30.step();
			m_delay_32.step();
			m_delay_34.step();
			m_delay_36.step();
			m_delay_38.step();
			m_delay_40.step();
			m_delay_42.step();
			m_delay_44.step();
			m_delay_45.step();
			m_delay_46.step();
			m_delay_47.step();
			m_delay_48.step();
			m_delay_57.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			
		};
		return __exception;
		
	};
	inline void set_C(t_param _value) {
		m_C_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Exp(t_param _value) {
		m_Exp_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Push(t_param _value) {
		m_Push_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_B(t_param _value) {
		m_B_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_D(t_param _value) {
		m_D_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_A(t_param _value) {
		m_A_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 3;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 6; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_A(value); break;
		case 1: self->set_B(value); break;
		case 2: self->set_C(value); break;
		case 3: self->set_D(value); break;
		case 4: self->set_Exp(value); break;
		case 5: self->set_Push(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_A_7; break;
		case 1: *value = self->m_B_5; break;
		case 2: *value = self->m_C_2; break;
		case 3: *value = self->m_D_6; break;
		case 4: *value = self->m_Exp_3; break;
		case 5: *value = self->m_Push_4; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(6 * sizeof(ParamInfo));
	self->__commonstate.numparams = 6;
	// initialize parameter 0 ("m_A_7")
	pi = self->__commonstate.params + 0;
	pi->name = "A";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_A_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_B_5")
	pi = self->__commonstate.params + 1;
	pi->name = "B";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_B_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_C_2")
	pi = self->__commonstate.params + 2;
	pi->name = "C";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_C_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_D_6")
	pi = self->__commonstate.params + 3;
	pi->name = "D";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_D_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_Exp_3")
	pi = self->__commonstate.params + 4;
	pi->name = "Exp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Exp_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_Push_4")
	pi = self->__commonstate.params + 5;
	pi->name = "Push";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Push_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // The_Chain::
