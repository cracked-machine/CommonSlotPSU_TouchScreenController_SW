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
	while (1)
	{
	  ILI9341_Draw_Text("TEST6", 10, 10, BLACK, 2, RED);

	  if(TSC2046_EM_GetTouchScreenState())
	  {
		  ILI9341_Draw_Text("HIT ", 100, 10, BLACK, 2, RED);
		  HAL_GPIO_TogglePin(PSU_SW_ON_GPIO_Port, PSU_SW_ON_Pin);

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
}