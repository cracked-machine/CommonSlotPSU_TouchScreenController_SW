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

	void UserDefaultTask();

	// auto-generated in freertos.c
	osThreadId defaultTaskHandle;
	osThreadId PollADCTaskHandle;
	osThreadId DisplayTaskHandle;

#endif	//USE_FREERTOS


void UserDisplayTask();
void UserPollADC();

#endif /* TSC2046_STM32_TASKMANAGER_H_ */
