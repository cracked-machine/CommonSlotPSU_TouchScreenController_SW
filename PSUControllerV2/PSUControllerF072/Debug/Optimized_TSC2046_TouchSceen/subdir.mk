################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen/TSC2046_STM32_EventManager.c \
/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen/TSC2046_STM32_HardwareManager.c \
/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen/TSC2046_STM32_InterruptManager.c 

OBJS += \
./Optimized_TSC2046_TouchSceen/TSC2046_STM32_EventManager.o \
./Optimized_TSC2046_TouchSceen/TSC2046_STM32_HardwareManager.o \
./Optimized_TSC2046_TouchSceen/TSC2046_STM32_InterruptManager.o 

C_DEPS += \
./Optimized_TSC2046_TouchSceen/TSC2046_STM32_EventManager.d \
./Optimized_TSC2046_TouchSceen/TSC2046_STM32_HardwareManager.d \
./Optimized_TSC2046_TouchSceen/TSC2046_STM32_InterruptManager.d 


# Each subdirectory must supply rules for building sources it contributes
Optimized_TSC2046_TouchSceen/TSC2046_STM32_EventManager.o: /home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen/TSC2046_STM32_EventManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_TSC2046_TouchSceen/TSC2046_STM32_EventManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Optimized_TSC2046_TouchSceen/TSC2046_STM32_HardwareManager.o: /home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen/TSC2046_STM32_HardwareManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_TSC2046_TouchSceen/TSC2046_STM32_HardwareManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Optimized_TSC2046_TouchSceen/TSC2046_STM32_InterruptManager.o: /home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen/TSC2046_STM32_InterruptManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_TSC2046_TouchSceen/TSC2046_STM32_InterruptManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

