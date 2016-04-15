################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Release/MMA7455/subdir.mk
-include Release/MKUART/subdir.mk
-include Release/LCD/subdir.mk
-include Release/I2C_TWI/subdir.mk
-include Release/subdir.mk
-include MMA7455/subdir.mk
-include MKUART/subdir.mk
-include LCD/subdir.mk
-include I2C_TWI/subdir.mk
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
apollo_hw.lss \

FLASH_IMAGE += \
apollo_hw.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: apollo_hw.elf secondary-outputs

# Tool invocations
apollo_hw.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,apollo_hw.map -mmcu=atmega32 -o "apollo_hw.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

apollo_hw.lss: apollo_hw.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S apollo_hw.elf  >"apollo_hw.lss"
	@echo 'Finished building: $@'
	@echo ' '

apollo_hw.hex: apollo_hw.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex apollo_hw.elf  "apollo_hw.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: apollo_hw.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 apollo_hw.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) apollo_hw.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
