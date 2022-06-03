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
	Delay m_delay_27;
	Delay m_delay_31;
	Delay m_delay_15;
	Delay m_delay_13;
	Delay m_delay_33;
	Delay m_delay_11;
	Delay m_delay_29;
	Delay m_delay_28;
	Delay m_delay_21;
	Delay m_delay_17;
	Delay m_delay_26;
	Delay m_delay_19;
	Delay m_delay_25;
	Delay m_delay_35;
	Delay m_delay_8;
	Delay m_delay_46;
	Delay m_delay_45;
	Delay m_delay_47;
	Delay m_delay_48;
	Delay m_delay_9;
	Delay m_delay_43;
	Delay m_delay_39;
	Delay m_delay_41;
	Delay m_delay_7;
	Delay m_delay_37;
	Delay m_delay_23;
	int __exception;
	int vectorsize;
	t_sample m_Push_2;
	t_sample m_C_1;
	t_sample samplerate;
	t_sample m_history_44;
	t_sample m_history_42;
	t_sample m_D_3;
	t_sample m_B_4;
	t_sample m_history_22;
	t_sample m_history_50;
	t_sample m_history_54;
	t_sample m_history_49;
	t_sample m_history_53;
	t_sample m_history_51;
	t_sample m_history_52;
	t_sample m_history_24;
	t_sample m_history_40;
	t_sample m_history_38;
	t_sample m_history_16;
	t_sample m_history_30;
	t_sample m_history_18;
	t_sample m_history_20;
	t_sample m_history_55;
	t_sample m_Exp_5;
	t_sample m_history_14;
	t_sample m_history_12;
	t_sample m_A_6;
	t_sample m_history_32;
	t_sample m_history_36;
	t_sample m_history_34;
	t_sample m_history_10;
	t_sample m_history_56;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_C_1 = ((int)0);
		m_Push_2 = ((int)0);
		m_D_3 = ((int)0);
		m_B_4 = ((int)0);
		m_Exp_5 = ((int)0);
		m_A_6 = ((int)0);
		m_delay_7.reset("m_delay_7", ((int)48000));
		m_delay_8.reset("m_delay_8", ((int)48000));
		m_delay_9.reset("m_delay_9", ((int)2000));
		m_history_10 = ((int)0);
		m_delay_11.reset("m_delay_11", ((int)2000));
		m_history_12 = ((int)0);
		m_delay_13.reset("m_delay_13", ((int)2000));
		m_history_14 = ((int)0);
		m_delay_15.reset("m_delay_15", ((int)2000));
		m_history_16 = ((int)0);
		m_delay_17.reset("m_delay_17", ((int)2000));
		m_history_18 = ((int)0);
		m_delay_19.reset("m_delay_19", ((int)2000));
		m_history_20 = ((int)0);
		m_delay_21.reset("m_delay_21", ((int)2000));
		m_history_22 = ((int)0);
		m_delay_23.reset("m_delay_23", ((int)2000));
		m_history_24 = ((int)0);
		m_delay_25.reset("m_delay_25", ((int)2000));
		m_delay_26.reset("m_delay_26", ((int)2000));
		m_delay_27.reset("m_delay_27", ((int)2000));
		m_delay_28.reset("m_delay_28", ((int)2000));
		m_delay_29.reset("m_delay_29", ((int)2000));
		m_history_30 = ((int)0);
		m_delay_31.reset("m_delay_31", ((int)2000));
		m_history_32 = ((int)0);
		m_delay_33.reset("m_delay_33", ((int)2000));
		m_history_34 = ((int)0);
		m_delay_35.reset("m_delay_35", ((int)2000));
		m_history_36 = ((int)0);
		m_delay_37.reset("m_delay_37", ((int)2000));
		m_history_38 = ((int)0);
		m_delay_39.reset("m_delay_39", ((int)2000));
		m_history_40 = ((int)0);
		m_delay_41.reset("m_delay_41", ((int)2000));
		m_history_42 = ((int)0);
		m_delay_43.reset("m_delay_43", ((int)2000));
		m_history_44 = ((int)0);
		m_delay_45.reset("m_delay_45", ((int)2000));
		m_delay_46.reset("m_delay_46", ((int)2000));
		m_delay_47.reset("m_delay_47", ((int)2000));
		m_delay_48.reset("m_delay_48", ((int)2000));
		m_history_49 = ((int)0);
		m_history_50 = ((int)0);
		m_history_51 = ((int)0);
		m_history_52 = ((int)0);
		m_history_53 = ((int)0);
		m_history_54 = ((int)0);
		m_history_55 = ((int)0);
		m_history_56 = ((int)0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample mul_63 = (m_B_4 * ((int)48000));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample tap_61 = m_delay_7.read_linear(mul_63);
			t_sample tap_65 = m_delay_8.read_linear(mul_63);
			t_sample mul_756 = (tap_61 * ((int)100));
			t_sample ceil_755 = ceil(mul_756);
			t_sample div_754 = (ceil_755 * ((t_sample)0.01));
			t_sample mul_59 = (div_754 * m_C_1);
			t_sample mul_7738 = (tap_65 * ((int)100));
			t_sample ceil_7735 = ceil(mul_7738);
			t_sample div_7731 = (ceil_7735 * ((t_sample)0.01));
			t_sample mul_62 = (div_7731 * m_C_1);
			t_sample mul_4433 = (in2 * ((t_sample)0.015));
			t_sample tap_3129 = m_delay_9.read_step(((int)1557));
			t_sample gen_4413 = tap_3129;
			t_sample mul_3127 = (tap_3129 * ((t_sample)0.26));
			t_sample mul_3125 = (m_history_10 * ((t_sample)0.74));
			t_sample add_3126 = (mul_3127 + mul_3125);
			t_sample mul_3123 = (add_3126 * ((int)1));
			t_sample add_3130 = (mul_4433 + mul_3123);
			t_sample history_3124_next_3131 = fixdenorm(add_3126);
			t_sample tap_4438 = m_delay_11.read_step(((int)1617));
			t_sample gen_4432 = tap_4438;
			t_sample mul_4443 = (tap_4438 * ((t_sample)0.26));
			t_sample mul_4434 = (m_history_12 * ((t_sample)0.74));
			t_sample add_4436 = (mul_4443 + mul_4434);
			t_sample mul_4440 = (add_4436 * ((int)1));
			t_sample add_4442 = (mul_4433 + mul_4440);
			t_sample history_3124_next_4439 = fixdenorm(add_4436);
			t_sample tap_4450 = m_delay_13.read_step(((int)1491));
			t_sample gen_4412 = tap_4450;
			t_sample mul_4455 = (tap_4450 * ((t_sample)0.26));
			t_sample mul_4446 = (m_history_14 * ((t_sample)0.74));
			t_sample add_4448 = (mul_4455 + mul_4446);
			t_sample mul_4452 = (add_4448 * ((int)1));
			t_sample add_4454 = (mul_4433 + mul_4452);
			t_sample history_3124_next_4451 = fixdenorm(add_4448);
			t_sample tap_4460 = m_delay_15.read_step(((int)1422));
			t_sample gen_4411 = tap_4460;
			t_sample mul_4466 = (tap_4460 * ((t_sample)0.26));
			t_sample mul_4458 = (m_history_16 * ((t_sample)0.74));
			t_sample add_4462 = (mul_4466 + mul_4458);
			t_sample mul_4459 = (add_4462 * ((int)1));
			t_sample add_4461 = (mul_4433 + mul_4459);
			t_sample history_3124_next_4465 = fixdenorm(add_4462);
			t_sample tap_4472 = m_delay_17.read_step(((int)1356));
			t_sample gen_4410 = tap_4472;
			t_sample mul_4478 = (tap_4472 * ((t_sample)0.26));
			t_sample mul_4470 = (m_history_18 * ((t_sample)0.74));
			t_sample add_4474 = (mul_4478 + mul_4470);
			t_sample mul_4471 = (add_4474 * ((int)1));
			t_sample add_4473 = (mul_4433 + mul_4471);
			t_sample history_3124_next_4477 = fixdenorm(add_4474);
			t_sample tap_4484 = m_delay_19.read_step(((int)1277));
			t_sample gen_4409 = tap_4484;
			t_sample mul_4491 = (tap_4484 * ((t_sample)0.26));
			t_sample mul_4482 = (m_history_20 * ((t_sample)0.74));
			t_sample add_4487 = (mul_4491 + mul_4482);
			t_sample mul_4483 = (add_4487 * ((int)1));
			t_sample add_4485 = (mul_4433 + mul_4483);
			t_sample history_3124_next_4490 = fixdenorm(add_4487);
			t_sample tap_4496 = m_delay_21.read_step(((int)1188));
			t_sample gen_4408 = tap_4496;
			t_sample mul_4503 = (tap_4496 * ((t_sample)0.26));
			t_sample mul_4494 = (m_history_22 * ((t_sample)0.74));
			t_sample add_4499 = (mul_4503 + mul_4494);
			t_sample mul_4495 = (add_4499 * ((int)1));
			t_sample add_4497 = (mul_4433 + mul_4495);
			t_sample history_3124_next_4502 = fixdenorm(add_4499);
			t_sample tap_4509 = m_delay_23.read_step(((int)1116));
			t_sample gen_4407 = tap_4509;
			t_sample mul_4515 = (tap_4509 * ((t_sample)0.26));
			t_sample mul_4506 = (m_history_24 * ((t_sample)0.74));
			t_sample add_4511 = (mul_4515 + mul_4506);
			t_sample mul_4507 = (add_4511 * ((int)1));
			t_sample add_4510 = (mul_4433 + mul_4507);
			t_sample history_3124_next_4508 = fixdenorm(add_4511);
			t_sample add_4430 = ((((((((gen_4407 + gen_4408) + gen_4409) + gen_4410) + gen_4411) + gen_4412) + gen_4432) + gen_4413) + ((int)0));
			t_sample tap_3120 = m_delay_25.read_step(((int)556));
			t_sample sub_3116 = (add_4430 - tap_3120);
			t_sample mul_3118 = (tap_3120 * ((t_sample)0.25));
			t_sample add_3117 = (add_4430 + mul_3118);
			t_sample tap_4522 = m_delay_26.read_step(((int)441));
			t_sample sub_4520 = (sub_3116 - tap_4522);
			t_sample mul_4519 = (tap_4522 * ((t_sample)0.25));
			t_sample add_4518 = (sub_3116 + mul_4519);
			t_sample tap_4528 = m_delay_27.read_step(((int)341));
			t_sample sub_4526 = (sub_4520 - tap_4528);
			t_sample mul_4525 = (tap_4528 * ((t_sample)0.25));
			t_sample add_4524 = (sub_4520 + mul_4525);
			t_sample tap_4534 = m_delay_28.read_step(((int)225));
			t_sample sub_4532 = (sub_4526 - tap_4534);
			t_sample mul_4531 = (tap_4534 * ((t_sample)0.25));
			t_sample add_4530 = (sub_4526 + mul_4531);
			t_sample mul_4742 = (sub_4532 * m_D_3);
			t_sample out2 = ((mul_4742 + mul_59) + in2);
			t_sample mul_7876 = (in1 * ((t_sample)0.015));
			t_sample tap_7750 = m_delay_29.read_step(((int)1557));
			t_sample gen_7760 = tap_7750;
			t_sample mul_7895 = (tap_7750 * ((t_sample)0.26));
			t_sample mul_7880 = (m_history_30 * ((t_sample)0.74));
			t_sample add_7871 = (mul_7895 + mul_7880);
			t_sample mul_7892 = (add_7871 * ((int)1));
			t_sample add_7763 = (mul_7876 + mul_7892);
			t_sample history_3124_next_7890 = fixdenorm(add_7871);
			t_sample tap_7889 = m_delay_31.read_step(((int)1617));
			t_sample gen_7762 = tap_7889;
			t_sample mul_7888 = (tap_7889 * ((t_sample)0.26));
			t_sample mul_7887 = (m_history_32 * ((t_sample)0.74));
			t_sample add_7864 = (mul_7888 + mul_7887);
			t_sample mul_7740 = (add_7864 * ((int)1));
			t_sample add_7743 = (mul_7876 + mul_7740);
			t_sample history_3124_next_7825 = fixdenorm(add_7864);
			t_sample tap_7853 = m_delay_33.read_step(((int)1491));
			t_sample gen_7779 = tap_7853;
			t_sample mul_7845 = (tap_7853 * ((t_sample)0.26));
			t_sample mul_7797 = (m_history_34 * ((t_sample)0.74));
			t_sample add_7808 = (mul_7845 + mul_7797);
			t_sample mul_7755 = (add_7808 * ((int)1));
			t_sample add_7800 = (mul_7876 + mul_7755);
			t_sample history_3124_next_7782 = fixdenorm(add_7808);
			t_sample tap_7877 = m_delay_35.read_step(((int)1422));
			t_sample gen_7751 = tap_7877;
			t_sample mul_7870 = (tap_7877 * ((t_sample)0.26));
			t_sample mul_7774 = (m_history_36 * ((t_sample)0.74));
			t_sample add_7787 = (mul_7870 + mul_7774);
			t_sample mul_7796 = (add_7787 * ((int)1));
			t_sample add_7776 = (mul_7876 + mul_7796);
			t_sample history_3124_next_7868 = fixdenorm(add_7787);
			t_sample tap_7860 = m_delay_37.read_step(((int)1356));
			t_sample gen_7847 = tap_7860;
			t_sample mul_7805 = (tap_7860 * ((t_sample)0.26));
			t_sample mul_7756 = (m_history_38 * ((t_sample)0.74));
			t_sample add_7781 = (mul_7805 + mul_7756);
			t_sample mul_7761 = (add_7781 * ((int)1));
			t_sample add_7817 = (mul_7876 + mul_7761);
			t_sample history_3124_next_7855 = fixdenorm(add_7781);
			t_sample tap_7754 = m_delay_39.read_step(((int)1277));
			t_sample gen_7775 = tap_7754;
			t_sample mul_7861 = (tap_7754 * ((t_sample)0.26));
			t_sample mul_7859 = (m_history_40 * ((t_sample)0.74));
			t_sample add_7810 = (mul_7861 + mul_7859);
			t_sample mul_7856 = (add_7810 * ((int)1));
			t_sample add_7822 = (mul_7876 + mul_7856);
			t_sample history_3124_next_7874 = fixdenorm(add_7810);
			t_sample tap_7852 = m_delay_41.read_step(((int)1188));
			t_sample gen_7849 = tap_7852;
			t_sample mul_7799 = (tap_7852 * ((t_sample)0.26));
			t_sample mul_7844 = (m_history_42 * ((t_sample)0.74));
			t_sample add_7843 = (mul_7799 + mul_7844);
			t_sample mul_7842 = (add_7843 * ((int)1));
			t_sample add_7840 = (mul_7876 + mul_7842);
			t_sample history_3124_next_7816 = fixdenorm(add_7843);
			t_sample tap_7746 = m_delay_43.read_step(((int)1116));
			t_sample gen_7767 = tap_7746;
			t_sample mul_7873 = (tap_7746 * ((t_sample)0.26));
			t_sample mul_7770 = (m_history_44 * ((t_sample)0.74));
			t_sample add_7789 = (mul_7873 + mul_7770);
			t_sample mul_7834 = (add_7789 * ((int)1));
			t_sample add_7832 = (mul_7876 + mul_7834);
			t_sample history_3124_next_7829 = fixdenorm(add_7789);
			t_sample add_7793 = ((((((((gen_7767 + gen_7849) + gen_7775) + gen_7847) + gen_7751) + gen_7779) + gen_7762) + gen_7760) + ((int)0));
			t_sample tap_7827 = m_delay_45.read_step(((int)556));
			t_sample sub_7826 = (add_7793 - tap_7827);
			t_sample mul_7819 = (tap_7827 * ((t_sample)0.25));
			t_sample add_7741 = (add_7793 + mul_7819);
			t_sample tap_7769 = m_delay_46.read_step(((int)441));
			t_sample sub_7818 = (sub_7826 - tap_7769);
			t_sample mul_7749 = (tap_7769 * ((t_sample)0.25));
			t_sample add_7748 = (sub_7826 + mul_7749);
			t_sample tap_7815 = m_delay_47.read_step(((int)341));
			t_sample sub_7814 = (sub_7818 - tap_7815);
			t_sample mul_7807 = (tap_7815 * ((t_sample)0.25));
			t_sample add_7804 = (sub_7818 + mul_7807);
			t_sample tap_7803 = m_delay_48.read_step(((int)225));
			t_sample sub_7893 = (sub_7814 - tap_7803);
			t_sample mul_7801 = (tap_7803 * ((t_sample)0.25));
			t_sample add_7881 = (sub_7814 + mul_7801);
			t_sample mul_4125 = (sub_7893 * m_D_3);
			t_sample out1 = ((mul_4125 + mul_62) + in1);
			t_sample mul_125 = (in2 * ((t_sample)0.001));
			t_sample mul_122 = (m_history_51 * ((t_sample)0.003));
			t_sample mul_120 = (m_history_49 * ((t_sample)0.001));
			t_sample mul_116 = (m_history_50 * ((t_sample)0.852));
			t_sample mul_118 = (m_history_52 * ((t_sample)-1.846));
			t_sample sub_124 = (((mul_120 + mul_122) + mul_125) - (mul_118 + mul_116));
			t_sample gen_130 = sub_124;
			t_sample history_121_next_126 = fixdenorm(m_history_51);
			t_sample history_117_next_127 = fixdenorm(m_history_52);
			t_sample history_123_next_128 = fixdenorm(in2);
			t_sample history_119_next_129 = fixdenorm(sub_124);
			t_sample mul_53 = (in1 * ((t_sample)0.001));
			t_sample mul_50 = (m_history_55 * ((t_sample)0.003));
			t_sample mul_48 = (m_history_53 * ((t_sample)0.001));
			t_sample mul_44 = (m_history_54 * ((t_sample)0.852));
			t_sample mul_46 = (m_history_56 * ((t_sample)-1.846));
			t_sample sub_52 = (((mul_48 + mul_50) + mul_53) - (mul_46 + mul_44));
			t_sample gen_58 = sub_52;
			t_sample history_49_next_54 = fixdenorm(m_history_55);
			t_sample history_45_next_55 = fixdenorm(m_history_56);
			t_sample history_51_next_56 = fixdenorm(in1);
			t_sample history_47_next_57 = fixdenorm(sub_52);
			m_delay_7.write(gen_130);
			m_history_54 = history_45_next_55;
			m_history_55 = history_51_next_56;
			m_history_56 = history_47_next_57;
			m_history_53 = history_49_next_54;
			m_history_50 = history_117_next_127;
			m_history_51 = history_123_next_128;
			m_history_52 = history_119_next_129;
			m_history_49 = history_121_next_126;
			m_history_30 = history_3124_next_7890;
			m_delay_31.write(add_7743);
			m_history_32 = history_3124_next_7825;
			m_delay_33.write(add_7800);
			m_history_34 = history_3124_next_7782;
			m_delay_35.write(add_7776);
			m_history_36 = history_3124_next_7868;
			m_delay_37.write(add_7817);
			m_history_38 = history_3124_next_7855;
			m_delay_39.write(add_7822);
			m_history_40 = history_3124_next_7874;
			m_delay_41.write(add_7840);
			m_history_42 = history_3124_next_7816;
			m_delay_43.write(add_7832);
			m_history_44 = history_3124_next_7829;
			m_delay_45.write(add_7741);
			m_delay_46.write(add_7748);
			m_delay_47.write(add_7804);
			m_delay_48.write(add_7881);
			m_delay_29.write(add_7763);
			m_history_10 = history_3124_next_3131;
			m_delay_11.write(add_4442);
			m_history_12 = history_3124_next_4439;
			m_delay_13.write(add_4454);
			m_history_14 = history_3124_next_4451;
			m_delay_15.write(add_4461);
			m_history_16 = history_3124_next_4465;
			m_delay_17.write(add_4473);
			m_history_18 = history_3124_next_4477;
			m_delay_19.write(add_4485);
			m_history_20 = history_3124_next_4490;
			m_delay_21.write(add_4497);
			m_history_22 = history_3124_next_4502;
			m_delay_23.write(add_4510);
			m_history_24 = history_3124_next_4508;
			m_delay_25.write(add_3117);
			m_delay_26.write(add_4518);
			m_delay_27.write(add_4524);
			m_delay_28.write(add_4530);
			m_delay_9.write(add_3130);
			m_delay_8.write(gen_58);
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_11.step();
			m_delay_13.step();
			m_delay_15.step();
			m_delay_17.step();
			m_delay_19.step();
			m_delay_21.step();
			m_delay_23.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_31.step();
			m_delay_33.step();
			m_delay_35.step();
			m_delay_37.step();
			m_delay_39.step();
			m_delay_41.step();
			m_delay_43.step();
			m_delay_45.step();
			m_delay_46.step();
			m_delay_47.step();
			m_delay_48.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_C(t_param _value) {
		m_C_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Push(t_param _value) {
		m_Push_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_D(t_param _value) {
		m_D_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_B(t_param _value) {
		m_B_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Exp(t_param _value) {
		m_Exp_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_A(t_param _value) {
		m_A_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 6; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

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
		case 0: *value = self->m_A_6; break;
		case 1: *value = self->m_B_4; break;
		case 2: *value = self->m_C_1; break;
		case 3: *value = self->m_D_3; break;
		case 4: *value = self->m_Exp_5; break;
		case 5: *value = self->m_Push_2; break;
		
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
	// initialize parameter 0 ("m_A_6")
	pi = self->__commonstate.params + 0;
	pi->name = "A";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_A_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_B_4")
	pi = self->__commonstate.params + 1;
	pi->name = "B";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_B_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_C_1")
	pi = self->__commonstate.params + 2;
	pi->name = "C";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_C_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_D_3")
	pi = self->__commonstate.params + 3;
	pi->name = "D";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_D_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_Exp_5")
	pi = self->__commonstate.params + 4;
	pi->name = "Exp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Exp_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_Push_2")
	pi = self->__commonstate.params + 5;
	pi->name = "Push";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Push_2;
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
