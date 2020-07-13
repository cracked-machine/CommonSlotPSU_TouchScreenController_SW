################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Optimized_TSC2046_TouchSceen/subdir.mk
-include Optimized_STM32_ILI9341/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
HPECommonSlot_BreakoutModule_SW_F072.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
HPECommonSlot_BreakoutModule_SW_F072.list \

OBJCOPY_BIN += \
HPECommonSlot_BreakoutModule_SW_F072.bin \


# All Target
all: HPECommonSlot_BreakoutModule_SW_F072.elf secondary-outputs

# Tool invocations
HPECommonSlot_BreakoutModule_SW_F072.elf: $(OBJS) $(USER_OBJS) /home/chris/Projects/Embedded/HPECommonSlot_BreakoutModule_SW/HPECommonSlot_BreakoutModule_SW_F072/HPECommonSlot_BreakoutModule_SW_F072/STM32F072RBTX_FLASH.ld
	arm-none-eabi-gcc -o "HPECommonSlot_BreakoutModule_SW_F072.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"/home/chris/Projects/Embedded/HPECommonSlot_BreakoutModule_SW/HPECommonSlot_BreakoutModule_SW_F072/HPECommonSlot_BreakoutModule_SW_F072/STM32F072RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="HPECommonSlot_BreakoutModule_SW_F072.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

HPECommonSlot_BreakoutModule_SW_F072.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "HPECommonSlot_BreakoutModule_SW_F072.list"
	@echo 'Finished building: $@'
	@echo ' '

HPECommonSlot_BreakoutModule_SW_F072.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "HPECommonSlot_BreakoutModule_SW_F072.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
