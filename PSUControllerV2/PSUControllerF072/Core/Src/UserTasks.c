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

#define ADC_DATA_SIZE 10.0
uint32_t adc_data = 0;

uint8_t adc_count = 0;
float f_adc_data = 0.0;


/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
void UserDisplayTask()
{
	   if(HAL_GPIO_ReadPin(PSU_SW_ON_GPIO_Port, PSU_SW_ON_Pin) == GPIO_PIN_SET)
	   {
		   ILI9341_Draw_Text("ON ", 10, 50, BLACK, 3, GREEN);
	   }
	   else
	   {
		   ILI9341_Draw_Text("OFF", 10, 50, BLACK, 3, RED);
	   }

	   // check for penirq interrupt
	   if(TSC2046_EM_GetTouchScreenState())
	   {
		 ILI9341_Draw_Text("HIT ", 100, 10, BLACK, 2, RED);
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

}

void UserPollADC()
{
   // if PSU enabled, poll imonitor pin
   if(HAL_GPIO_ReadPin(PSU_SW_ON_GPIO_Port, PSU_SW_ON_Pin) == GPIO_PIN_SET)
   {
	   if(HAL_ADC_PollForConversion(&hadc, 1) == HAL_OK)
	   {
		   if(adc_count == ADC_DATA_SIZE)			// calc adc mean, reset adc data + count
		   {
			   f_adc_data = (float)adc_data / ADC_DATA_SIZE;
			   f_adc_data = adc_data / 4095.0;		// convert to decimal
			   adc_data = 0;						// clear the total
			   adc_count = 0;
		   }

		   adc_data += HAL_ADC_GetValue(&hadc);		// add next read value to total
		   adc_count++;
	   }
   }
   else
   {
	   f_adc_data = 0.0;
   }

   char imon_string[15];
   snprintf(imon_string, sizeof(imon_string), "%f mA", f_adc_data);
   ILI9341_Draw_Text(imon_string, 10, 100, BLACK, 3, RED);
}