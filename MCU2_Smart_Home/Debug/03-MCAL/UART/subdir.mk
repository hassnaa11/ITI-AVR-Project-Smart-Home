################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../03-MCAL/UART/Global_Interrupt_program.c \
../03-MCAL/UART/UART_program.c 

OBJS += \
./03-MCAL/UART/Global_Interrupt_program.o \
./03-MCAL/UART/UART_program.o 

C_DEPS += \
./03-MCAL/UART/Global_Interrupt_program.d \
./03-MCAL/UART/UART_program.d 


# Each subdirectory must supply rules for building sources it contributes
03-MCAL/UART/%.o: ../03-MCAL/UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


