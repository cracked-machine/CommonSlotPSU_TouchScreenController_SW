################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/UserTasks.c 

OBJS += \
./UserApplication/UserTasks.o 

C_DEPS += \
./UserApplication/UserTasks.d 


# Each subdirectory must supply rules for building sources it contributes
UserApplication/UserTasks.o: /home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/UserTasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"UserApplication/UserTasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

