################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/SMBUS_Manager.c \
/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/UserTasks.c \
/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/UxManager.c 

OBJS += \
./UserApplication/SMBUS_Manager.o \
./UserApplication/UserTasks.o \
./UserApplication/UxManager.o 

C_DEPS += \
./UserApplication/SMBUS_Manager.d \
./UserApplication/UserTasks.d \
./UserApplication/UxManager.d 


# Each subdirectory must supply rules for building sources it contributes
UserApplication/SMBUS_Manager.o: /home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/SMBUS_Manager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -DUSE_FREERTOS -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I"/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"UserApplication/SMBUS_Manager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
UserApplication/UserTasks.o: /home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/UserTasks.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -DUSE_FREERTOS -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I"/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"UserApplication/UserTasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
UserApplication/UxManager.o: /home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication/UxManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -DUSE_FREERTOS -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I"/home/chris/Projects/Embedded/Optimized_TSC2046_TouchSceen" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I"/home/chris/Projects/Embedded/CommonSlotPSU_TouchScreenController_SW/PSUControllerV2/UserApplication" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"UserApplication/UxManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

