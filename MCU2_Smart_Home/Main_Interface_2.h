
#ifndef MAIN_INTERFACE_H_
#define MAIN_INTERFACE_H_


#define GREEN_LED             1
#define YELLOW_LED            2
#define RED_LED               3
#define RED_LED_STOP_MACHINE  4
#define EMERGENCY             5


void  Temp_Automatic_measure(f32 Temp_read);
void Motor_Speed_Func_Manual(f32 Potentiometer_read);
void UART_ReceiveButtonAndTemp(uint8_t *button_state, uint8_t *temp_value) ;
#endif /* MAIN_INTERFACE_H_ */
