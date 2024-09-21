################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 03-MCAL/UART/subdir.mk
-include 03-MCAL/TIM/subdir.mk
-include 03-MCAL/DIO/subdir.mk
-include 02-HAL/servo/subdir.mk
-include 02-HAL/LCD/subdir.mk
-include 02-HAL/KEYPAD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MCU1_Smart_Home.lss \

FLASH_IMAGE += \
MCU1_Smart_Home.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MCU1_Smart_Home.elf secondary-outputs

# Tool invocations
MCU1_Smart_Home.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MCU1_Smart_Home.map -mmcu=atmega32 -o "MCU1_Smart_Home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MCU1_Smart_Home.lss: MCU1_Smart_Home.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MCU1_Smart_Home.elf  >"MCU1_Smart_Home.lss"
	@echo 'Finished building: $@'
	@echo ' '

MCU1_Smart_Home.hex: MCU1_Smart_Home.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MCU1_Smart_Home.elf  "MCU1_Smart_Home.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MCU1_Smart_Home.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MCU1_Smart_Home.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MCU1_Smart_Home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
