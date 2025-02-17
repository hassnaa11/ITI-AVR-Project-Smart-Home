
#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#define KEYPAD_PIN0					0
#define KEYPAD_PIN1					1
#define KEYPAD_PIN2					2
#define KEYPAD_PIN3					3
#define KEYPAD_PIN4					4
#define KEYPAD_PIN5					5
#define KEYPAD_PIN6					6
#define KEYPAD_PIN7					7

/*ROWS and COLUM*/
#define KEYPAD_ROW0					KEYPAD_PIN0
#define KEYPAD_ROW1					KEYPAD_PIN1
#define KEYPAD_ROW2					KEYPAD_PIN2
#define KEYPAD_ROW3					KEYPAD_PIN3

#define KEYPAD_COLUM0				KEYPAD_PIN4
#define KEYPAD_COLUM1				KEYPAD_PIN5
#define KEYPAD_COLUM2				KEYPAD_PIN6
#define KEYPAD_COLUM3				KEYPAD_PIN7

#define KEYPAD_PORT					PORTA
#define KEYPAD_DDR					DDRA
#define KEYPAD_PIN					PINA
#define ROWS_NUMBER					4
#define COLUMS_NUMBER				4


void 	KEYPAD_voidini				(void);
u8 		KEYPAD_u8Scan				(void);
u8 		KEYPAD_u8ScanWithStop		(void);

#endif /* KEYPAD_KEYPAD_H_ */
