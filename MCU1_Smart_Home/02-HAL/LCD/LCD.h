
#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#define Clear_display 				0x01
#define Return_Home 				0x02
#define Entery_mode_set 			0x06
#define Display_OFF_Control 		0x08
#define Display_ON_Control 			0x0C
#define Cursor_Display_Shfit		0x80
#define LCD_FunictionReset			0x30
#define LCD_FunictionSet8bit		0x38
#define DDR_ADDRESS					0x80

#define LCD_PIN0					0
#define LCD_PIN1					1
#define LCD_PIN2					2
#define LCD_PIN3					3
#define LCD_PIN4					4
#define LCD_PIN5					5
#define LCD_PIN6					6
#define LCD_PIN7					7

#define LCD_Data_Port				PORTA
#define LCD_Control_Port			PORTB

#define LCD_Data_DDR				DDRA
#define LCD_Control_DDR				DDRB

#define LCD_RS_PIN					PIN5
#define LCD_RW_PIN					PIN6
#define LCD_E_PIN					PIN7


void LCD_voidSendData(u8 copy_u8Data);
void LCD_voidSendCommand(u8 copy_u8Command);

void LCD_voidini(void);
void LCD_voidSetCursorLocation(u8 copy_u8Row,u8 copy_u8Column);
void LCD_voidClearDisplay(void);
void LCD_voidSaveCustomchar(u8 *ptr_u8toCustomchar,u8 copy_u8SaveLocation);

void LCD_voidwriteString(u8 *ptr_u8toString);

void LCD_voidWriteNumber(u32 copy_u32DataValue);

void LCD_voidWriteFloatNumber(f32 copy_f32DataValue,u8 copy_u8decimalPlaces);

#endif /* LCD_LCD_H_ */
