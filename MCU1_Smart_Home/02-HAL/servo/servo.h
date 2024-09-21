
#ifndef __HAL_SERVO_SERVO_H_
#define __HAL_SERVO_SERVO_H_

/*
 *  TIM1 must be in mode 	14 1 1 1 0 Fast PWM ICR1 BOTTOM TOP
 *  pin-> OC1A
 */
void Servo_voidini(void);
void Servo_voidMoveToLoction(u8 copy_u8Loction);

#endif /* 02_HAL_SERVO_SERVO_H_ */
