#include "00-LIB/LSTD_types.h"
#include "00-LIB/LBIT_math.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "math.h"
#include "util/delay.h"
#ifdef  F_CPU
#undef  F_CPU
#endif
#define F_CPU 8000000L

#include "02-HAL/LCD/LCD.h"
#include "02-HAL/KEYPAD/KEYPAD.h"
#include "02-HAL/servo/servo.h"
#include "03-MCAL/DIO/DIO_interface.h"
#include "03-MCAL/UART/UART_interface.h"
#include "Main_Interface_1.h"

void send_char(u8 Tx_data){

	UART_voidSendData_Asynch(Tx_data);
	disable_tx();
}

void do_option(u8 option);
u8 entered_mode = 0;
u8 takepasword = 1;

int main(void) {
		Servo_voidini();
		UART_voidInit();
		UARTTX_vidSetISR(send_char);
		Global_Interrupt_Enable();

    KEYPAD_voidini();
    LCD_voidini();


    DIO_voidIniPins(DIOB, DIO_PIN2, DIO_OUTPUT);

    u8 pass_char = '\0';
    u32 password = 0;
    u8 first_time = 0;

    u8 option = '\0';

    LCD_voidwriteString((u8 *)"Enter The pass : ");
    LCD_voidSetCursorLocation(1, 0);

    // Password entry loop
    while (takepasword == 1) {
        pass_char = KEYPAD_u8Scan();
        _delay_ms(20);
        if (pass_char != '\0') {
            LCD_voidSendData(pass_char);
            password = password * 10 + (pass_char - '0');
            first_time++;
            _delay_ms(1000);
        }

        if (first_time == 4) {
            LCD_voidClearDisplay();
            if (password == (u32)Main_Password) {
                LCD_voidwriteString((u8 *)"Correct Password");
                Servo_voidMoveToLoction(90);
                _delay_ms(3000);
                Servo_voidMoveToLoction(0);
                takepasword = 0;
            } else {
                LCD_voidwriteString((u8 *)"Wrong Password");
                _delay_ms(1000);
                // Reset for another attempt
                pass_char = '\0';
                password = 0;
                first_time = 0;
                LCD_voidClearDisplay();
                LCD_voidwriteString((u8 *)"Enter The pass : ");
                LCD_voidSetCursorLocation(1, 0);
            }
        }
    }

    LCD_voidClearDisplay();

    // Option selection loop
    while (takepasword == 0) {
        LCD_voidSetCursorLocation(0, 0);
        LCD_voidwriteString((u8 *)"Temp 1, Light 2");
        LCD_voidSetCursorLocation(1, 0);
        LCD_voidwriteString((u8 *)"Enter: ");

        while (1) {
            option = KEYPAD_u8Scan();
            if (option != '\0') {
                LCD_voidSendData(option);
                _delay_ms(1000);  // Small delay to allow the user to see their input
                do_option(option);
                break;
            }
        }
    }


}

// Function to handle the option selected by the user
void do_option(u8 option) {
    u8 mode_char = '\0';
    u8 selected_option = option;

    LCD_voidClearDisplay();

    if (selected_option == '1') {  // Temperature control
        LCD_voidwriteString((u8 *)"Auto Temp 1,Man 2");
    } else if (selected_option == '2') {  // Light control
        LCD_voidwriteString((u8 *)"Auto Light 1,Man 2");
    }

    LCD_voidSetCursorLocation(1, 0);
    LCD_voidwriteString((u8 *)"Enter: ");
    _delay_ms(1000);

    // Mode selection loop
    while (entered_mode == 0) {
        mode_char = KEYPAD_u8Scan();
        if (mode_char != '\0') {
            LCD_voidSendData(mode_char);
            mode_char = mode_char - '0';

            if (mode_char == 1 || mode_char == 2) {
                entered_mode = mode_char;
                break;
            }

            _delay_ms(1000);
        }
    }

    // UART transmission based on selected option and mode
    LCD_voidClearDisplay();
    LCD_voidwriteString((u8 *)"Sending Data...");
    _delay_ms(500);

    if (selected_option == '1') {
    	send_char('T');  // Temperature option
    } else if (selected_option == '2') {
    	send_char('L');  // Light option
    }

    _delay_ms(1000);

    if (entered_mode == 1) {
    	send_char('A');  // Auto mode
    } else if (entered_mode == 2) {
    	send_char('M');  // Manual mode
    }

    _delay_ms(1000);
    LCD_voidClearDisplay();
    LCD_voidwriteString((u8 *)"Data Sent!");
    _delay_ms(1000);
    entered_mode = 0;  // Reset for the next operation
}
