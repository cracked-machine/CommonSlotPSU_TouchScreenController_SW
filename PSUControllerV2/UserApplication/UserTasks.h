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
	void UserAdcManager();

	// must match the tasks auto-generated by STMCubeMX in freertos.c
	osThreadId DisplayTaskHandle;
	osThreadId AdcTaskHandle;
	osThreadId PenIrqTaskHandle;

	osSemaphoreId myBinarySem01Handle;
	osSemaphoreId myBinarySem02Handle;

#endif	//USE_FREERTOS


void UserDisplayTask();
void UserAdcTask();



#endif /* TSC2046_STM32_TASKMANAGER_H_ */
