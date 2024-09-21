
#ifndef __MCAL_TIM_TIM_CONFIG_H_
#define __MCAL_TIM_TIM_CONFIG_H_

/*
 * CPU_F in Mhz
 */

#define TIM_CPU_F		8


/*
 * TIM0 Modes:
 * TIM0_TIM2_NORMAL
 * TIM0_TIM2_PWM_PHASECORRECT
 * TIM0_TIM2_CTC
 * TIM0_TIM2_FAST_PWM
 */
#define TIM0_MODE	TIM0_TIM2_FAST_PWM

/*
 * TOP of TIM1
 */

#define TIMS_TOP_TIM1	20000
/*
 *	TIM1 Modes:
 *	TIM1_NORMAL
 *	TIM1_PWM_PHASECORRECT_8BIT
 *	TIM1_PWM_PHASECORRECT_9BIT
 *	TIM1_PWM_PHASECORRECT_10BIT
 *	TIM1_CTC_TOP_OCR1A
 *	TIM1_FAST_PWM_8BIT
 *	TIM1_FAST_PWM_9BIT
 *	TIM1_FAST_PWM_10BIT
 *	TIM1_PWM_PHASE_FRE_TOP_ICR1
 *	TIM1_PWM_PHASE_FRE_TOP_OCR1A
 *	TIM1_PWM_PHASECORRECT_TOP_ICR1
 *	TIM1_PWM_PHASECORRECT_TOP_OCR1A
 *	TIM1_CTC_TOP_ICR1
 *	TIM1_FAST_TOP_ICR1
 *	TIM1_FAST_TOP_OCR1A
 */
#define TIM1_MODE					TIM1_FAST_TOP_ICR1

/*
 * TIM2 Modes:
 * TIM0_TIM2_NORMAL
 * TIM0_TIM2_PWM_PHASECORRECT
 * TIM0_TIM2_CTC
 * TIM0_TIM2_FAST_PWM
 */
#define TIM2_MODE					TIM0_TIM2_PWM_PHASECORRECT

/*
 * Force Output Compare Options for pins
 * Note: IN PWM MODES This configuration has no effect
 * ENABLE_FORCE_OUTPUT_COMPARE
 * DISABLE_FORCE_OUTPUT_COMPARE
 */
#define OC0_FORCE_COMPARE			DISABLE_FORCE_OUTPUT_COMPARE
#define OC1B_FORCE_COMPARE			DISABLE_FORCE_OUTPUT_COMPARE
#define OC1A_FORCE_COMPARE			DISABLE_FORCE_OUTPUT_COMPARE
#define OC2_FORCE_COMPARE			DISABLE_FORCE_OUTPUT_COMPARE

/*
 * Compare Output Mode, non-PWM Mode:
 * OC_DISCONNECTED
 * OC_TOGGLE
 * OC_CLEAR
 * OC_SET
 *
 * Compare Output Mode, Fast PWM Mode:
 * OC_DISCONNECTED
 * OC_CLEAR_COMPARE_SET_ON_BOTTOM
 * OC_SET_COMPARE_CLEAR_ON_BOTTOM
 *
 * Compare Output Mode, Phase Correct PWM Mode:
 * OC_DISCONNECTED
 * OC_CLEAR_UP_SET_DOWN
 * OC_SET_UP_CLEAR_DOWN
 */
#define OC0_MODE					OC_CLEAR_COMPARE_SET_ON_BOTTOM
#define OC1B_MODE					OC_DISCONNECTED
#define OC1A_MODE					OC_CLEAR_COMPARE_SET_ON_BOTTOM
#define OC2_MODE					OC_CLEAR_UP_SET_DOWN


#endif /* 03_MCAL_TIM_TIM_CONFIG_H_ */
