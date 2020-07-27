################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Optimized_TSC2046_TouchSceen/subdir.mk
-include Optimized_STM32_ILI9341/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
PSUControllerF072_FreeRTOS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PSUControllerF072_FreeRTOS.list \

OBJCOPY_BIN += \
PSUControllerF072_FreeRTOS.bin \


# All Target
all: PSUControllerF072_FreeRTOS.elf secondary-outputs

# Tool invocations
PSUControllerF072_FreeRTOS.elf: $(OBJS) $(USER_OBJS) /home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/PSUControllerF072_FreeRTOS/STM32F072RBTX_FLASH.ld
	arm-none-eabi-gcc -o "PSUControllerF072_FreeRTOS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/PSUControllerF072_FreeRTOS/STM32F072RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PSUControllerF072_FreeRTOS.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PSUControllerF072_FreeRTOS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PSUControllerF072_FreeRTOS.list"
	@echo 'Finished building: $@'
	@echo ' '

PSUControllerF072_FreeRTOS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PSUControllerF072_FreeRTOS.bin"
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
