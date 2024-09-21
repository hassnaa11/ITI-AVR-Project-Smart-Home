
#include "../../00-LIB/LSTD_types.h"
#include "../../00-LIB/LBIT_math.h"
#include "../../03-MCAL/TIM/TIM_interface.h"
#include <avr/io.h>
#include "servo.h"


void Servo_voidini(void){
	TIM_voidIni(TIM1);
	TIM_voidSetComperMatch(ICR,20000);
	TIM_voidStart(TIM1,TIMS_DIVISION_8);
	DDRD|=0x20;

}
void Servo_voidMoveToLoction(u8 copy_u8Loction){
	f32 local_f32DC= (((f32)copy_u8Loction/180)*7.5)+5;
	if(copy_u8Loction>=0 &&copy_u8Loction<=180){
		TIM_voidSetPWMDC(OC1A,local_f32DC);
	}

}
