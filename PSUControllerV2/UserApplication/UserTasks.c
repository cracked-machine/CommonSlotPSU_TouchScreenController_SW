/*
 * TSC2046_STM32_TaskManager.c
 *
 *  Created on: Jul 26, 2020
 *      Author: chris
 */

#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "TSC2046_STM32.h"

#include <stdio.h>
#include "UserTasks.h"

#include "adc.h"




#define USE_FLOAT

#ifdef USE_FLOAT
	#define ADC_DATA_SIZE 1.0
	float final_adc_data = 0;
#else
	#define ADC_DATA_SIZE 3
	uint32_t final_adc_data = 0;
#endif // USE_FLOAT


//#define ADC_TO_VOLTS_RES	0.000805	// 3.3v / 4096
#define ADC_TO_VOLTS_RES	0.001611	// 3.3v / 2048

uint32_t adc_data = 0;
uint8_t adc_count = 0;

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
#ifdef USE_FREERTOS

void UserPenIrqManager()
{

	while(1)
	{
		if(myBinarySem01Handle != NULL)
		{
			osSemaphoreWait(myBinarySem01Handle, osWaitForever);

			TSC2046_EM_ProcessEvent(TSC2046_evPen);

			// make sure UserDisplayTask() is not interrupted
			EXTI->IMR &= ~(TS_IRQ_Pin);

			UserDisplayTask();

			// clear bit and resume EXTI
			__HAL_GPIO_EXTI_CLEAR_IT(TS_IRQ_Pin);
			EXTI->IMR |= (TS_IRQ_Pin);
		}
	}
}

#endif



void UserPenIrqISR()
{
#ifdef USE_FREERTOS
	osSemaphoreRelease(myBinarySem01Handle);
#else
	TSC2046_IM_PENIRQ_EXTI_Handler();
#endif
}

void UserDisplayTask()
{



	   // check for penirq interrupt
	   if(TSC2046_EM_GetTouchScreenState())
	   {
		 ILI9341_Draw_Text("HIT ", 100, 10, BLACK, 2, RED);

		 // turn on PSU
		 HAL_GPIO_TogglePin(PSU_SW_ON_GPIO_Port, PSU_SW_ON_Pin);

		 // get touchscreen coordinate data
		 if( TSC2046_HM_RunConversion() == TSC2046_DATAOK )
		 {
		   ILI9341_Draw_Filled_Circle(TSC4026_STM32_HM_GetXpos(), TSC4026_STM32_HM_GetYpos(), 2, WHITE);
		   char pos_string[15];
		   snprintf(pos_string, sizeof(pos_string), "Y:%u,X:%u      ", TSC4026_STM32_HM_GetXpos(), TSC4026_STM32_HM_GetYpos());
		   ILI9341_Draw_Text(pos_string, 180, 10, BLACK, 2, RED);
		 }
		 else
		 {
		   ILI9341_Draw_Text("DATAERR   ", 200, 10, BLACK, 2, RED);
		 }
	   }

	   else
	   {
		 ILI9341_Draw_Text("NONE", 100, 10, BLACK, 2, RED);
	   }

	   // update screen ON/OFF label
	   if(HAL_GPIO_ReadPin(PSU_SW_ON_GPIO_Port, PSU_SW_ON_Pin) == GPIO_PIN_SET)
	   {
		   ILI9341_Draw_Text("ON ", 10, 50, BLACK, 3, GREEN);
	   }
	   else
	   {
		   ILI9341_Draw_Text("OFF", 10, 50, BLACK, 3, RED);
	   }
}

void UserAdcTask()
{
		// if PSU enabled, poll imonitor pin
		if(HAL_GPIO_ReadPin(PSU_SW_ON_GPIO_Port, PSU_SW_ON_Pin) == GPIO_PIN_SET)
		{
		   if(HAL_ADC_PollForConversion(&hadc, 1) == HAL_OK)
		   {
			   if(adc_count == ADC_DATA_SIZE)			// calc adc mean, reset adc data + count
			   {

#ifdef USE_FLOAT
				   final_adc_data = (float)adc_data / ADC_DATA_SIZE;
				   final_adc_data = final_adc_data * ADC_TO_VOLTS_RES;		// convert to decimal
#else
				   final_adc_data = adc_data / ADC_DATA_SIZE;

#endif	//USE_FLOAT
				   adc_data = 0;						// clear the total
				   adc_count = 0;
			   }

			   adc_data += HAL_ADC_GetValue(&hadc);		// add next read value to total
			   adc_count++;
		   }
		}
		else
		{
			final_adc_data = 0;
		}

#ifdef USE_FLOAT
		char imon_string[12];
		sprintf(imon_string, "%f mV", final_adc_data);
		ILI9341_Draw_Text(imon_string, 10, 100, BLACK, 3, RED);
#else
		char imon_string[12];
		snprintf(imon_string, sizeof(imon_string), "%lu mV", final_adc_data);
		ILI9341_Draw_Text(imon_string, 10, 100, BLACK, 3, RED);
#endif	//USE_FLOAT


}
