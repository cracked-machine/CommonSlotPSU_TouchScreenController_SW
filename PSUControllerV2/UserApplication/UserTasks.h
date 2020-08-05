/*
 * TSC2046_STM32_TaskManager.h
 *
 *  Created on: Jul 26, 2020
 *      Author: chris
 */

#ifndef TSC2046_STM32_TASKMANAGER_H_
#define TSC2046_STM32_TASKMANAGER_H_



#ifdef USE_FREERTOS

	#include "cmsis_os.h"

	void UserDisplayManager();
	void UserPenIrqManager();

	// auto-generated in freertos.c
	osThreadId DisplayTaskHandle;
	osThreadId AdcTaskHandle;
	osThreadId PenIrqTaskHandle;

	osSemaphoreId myBinarySem01Handle;

#endif	//USE_FREERTOS


void UserDisplayTask();
void UserAdcTask();
void UserPenIrqISR();


#endif /* TSC2046_STM32_TASKMANAGER_H_ */