#include "00-LIB/LSTD_types.h"
#include "00-LIB/LBIT_math.h"
#include <avr/io.h>
#include <avr/delay.h>


#ifdef 	F_CPU
#undef 	F_CPU
#endif
#define F_CPU 						8000000L

#include "02-HAL/LCD/LCD.h"
#include "02-HAL/KEYPAD/KEYPAD.h"
#include "03-MCAL/ADC/ADC_interface.h"
#include "03-MCAL/TIM/TIM_interface.h"
#include "03-MCAL/UART/UART_interface.h"
#include "03-MCAL/DIO/DIO_interface.h"

#include "Main_Interface_2.h"


#define fan 		DIO_PIN7
#define pushButton 	DIO_PIN0

u8 Rx_data;
u8 option_final;
u8 mode_final;
u16 Poten_Analog ,Temp_Analog;
f32 poten_digital , Temp_digital;
u8 is_first=0;
u8 i =2;
u8 option = '\0', mode = '\0';
void myfun(void);
void counter_func (void){
static  u32 count =0 ;
	LCD_voidClearDisplay();
	LCD_voidwriteString((u8 *)"counter : ");
	LCD_voidWriteNumber(count+1);
	count++;
}


void receive_char(void){
	Rx_data=UART_u8ReceiveData();
	enable_tx();
	if(i%2 == 0){
		mode = Rx_data;
	}else{
		option = Rx_data;
		mode = '\0';
	}
	i+=1;
	disable_tx();
}



size_t main(void){

	UART_voidInit();
	LCD_voidini();
	LCD_voidwriteString((u8 *)"welcome : ");
	UARTRX_vidSetISR(receive_char);
	Global_Interrupt_Enable();


	//led
	DIO_voidIniPins(DIOB,DIO_PIN0 ,DIO_OUTPUT);
	DIO_voidIniPins(DIOB,DIO_PIN1 ,DIO_INPUT);
	DIO_voidSetPinsValue(DIOB,DIO_PIN1 ,DIO_HIGH);

	  //Pin for the potentiometer input , ADC0 , ADC1>> Temp sensor
	  DIO_voidIniPins(DIOA , DIO_PIN0|DIO_PIN1 , DIO_INPUT);
	  //for oc2 output
	  DIO_voidIniPins(DIOD, DIO_PIN7 , DIO_OUTPUT);

	  DIO_voidIniPins(DIOA , DIO_PIN2|DIO_PIN3| DIO_PIN4| DIO_PIN5 , DIO_OUTPUT);

	  ADC_voidini();
	  ADC_voidEnable();


	  TIM_voidIni(TIM2);
	  TIM_voidStart(TIM2,TIMS_DIVISION_1024);

	while(1){
		if((option != '\0') && (mode != '\0')){
				myfun();
				_delay_ms(200);
			}
	}

}

void myfun(void){

	LCD_voidClearDisplay();

    if(option !='\0' && mode!='\0'){

	if(option=='T'){
	 if(mode=='M'){

		   while(1){
		     LCD_voidClearDisplay();
		     Poten_Analog=ADC_u16Conversion(ADC0);
		 	 poten_digital=(((f32)Poten_Analog *5)/1024);
             LCD_voidwriteString((u8 *)"Manual");
             LCD_voidWriteFloatNumber(poten_digital,2);
		 	 Motor_Speed_Func_Manual(poten_digital);
		 	break;
		   }

	 }
	 else if (mode=='A'){

		    LCD_voidClearDisplay();
		    while(1){
				Temp_Analog=ADC_u16Conversion(ADC1);
				Temp_digital=(((f32)Temp_Analog *500)/1024);
				LCD_voidwriteString((u8 *) "Auto : ");
				LCD_voidWriteFloatNumber(Temp_digital,2);
				Temp_Automatic_measure( Temp_digital);
				break;
		    }
	 }

	}
	else if(option=='L'){
		if(mode=='M'){

				   while(1){
				     LCD_voidClearDisplay();

		             LCD_voidwriteString((u8 *)"Manual");
		             if(DIO_u8GetPinsValue(DIOB,DIO_PIN1) == 0){
		            	 DIO_voidSetPinsValue(DIOB,DIO_PIN0,DIO_HIGH);
		             }else{
		            	 DIO_voidSetPinsValue(DIOB,DIO_PIN0,DIO_LOW);
		             }

				 	break;
				   }

			 }
			 else if (mode=='A'){

				    LCD_voidClearDisplay();
				    while(1){
				    LCD_voidwriteString((u8 *) "Auto : ");
				    DIO_voidSetPinsValue(DIOB,DIO_PIN0,DIO_HIGH);
					 break;
				    }
	}
	}
    }
}


void Motor_Speed_Func_Manual(f32 Potentiometer_read){
	TIM_voidSetPWMDC(OC2,Potentiometer_read*20);
}


void Temp_Automatic_measure(f32 Temp_read){

	if(Temp_read <20){
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN2 ,DIO_HIGH);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN3 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN4 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN5 ,DIO_LOW);
		 TIM_voidSetPWMDC(OC2,0);
	}
	else if(Temp_read>=20 && Temp_read<40){
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN2 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN3 ,DIO_HIGH);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN4 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN5 ,DIO_LOW);
		TIM_voidSetPWMDC(OC2, (u8)Temp_read+50);
	}
	else if(Temp_read>40 && Temp_read<50){
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN2 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN3 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN4 ,DIO_HIGH);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN5 ,DIO_LOW);
		 TIM_voidSetPWMDC(OC2,90 );
	}
	else if(Temp_read>=50){
		 LCD_voidSetCursorLocation(1,0);
		 LCD_voidwriteString((u8 *)"Emergency State");
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN2 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN3 ,DIO_LOW);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN4 ,DIO_HIGH);
		 DIO_voidSetPinsValue(DIOA ,DIO_PIN5 ,DIO_HIGH);
         _delay_ms(20);
	}

}

