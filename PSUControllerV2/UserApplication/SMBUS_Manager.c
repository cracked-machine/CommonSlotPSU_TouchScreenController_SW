/*
 * SMBUS_Manager.c
 *
 *  Created on: 9 Aug 2020
 *      Author: chris
 */

#include "SMBUS_Manager.h"

/*
 * UNIT TESTS
 */
// 1. force "smbus device callback" errors
//#define FORCE_SMBUS_DEV_CLBK_ERRS

// 2. force "smbus transmit command" errors
//#define FORCE_SMBUS_DEV_TX_ERRS

// 3. force "smbus receive command" errors
//#define FORCE_SMBUS_DEV_RX_ERRS


/*
 *	Function Prototypes
 */
void SM_InitDiagnostics();
SM_DeviceFoundTypedef SM_DeviceScan();
uint8_t SM_GetLastCommand();
uint16_t SM_GetDeviceAddress(uint8_t device);
void SM_DisplayDiagnostics();

/*
 *	Private Variables
 */



SM_DeviceHandleTypedef the_smbus_device;
SM_DiagnosticPlanTypedef the_diagnostic_plan;
uint8_t test_index = 0;
int8_t last_test_index = -1;

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
void SM_Init(SMBUS_HandleTypeDef *instance)
{
	the_smbus_device.instance = instance;
	the_smbus_device.status = SM_DeviceScan();
	the_smbus_device.last_cmd = 0;
}

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
SM_DeviceFoundTypedef SM_DeviceScan() {

	SM_DeviceFoundTypedef smbus_status = SMBUS_DEVICE_MISSING;
    int num_addr_found=0;


    HAL_StatusTypeDef res;
    for(uint16_t i = 0; i < 128; i++)
    {
        res = HAL_SMBUS_IsDeviceReady(&hsmbus1, i << 1, 1, 10);
        if(res == HAL_OK)
        {
        	num_addr_found++;
           	smbus_status = SMBUS_DEVICE_FOUND;

        	// add dual addresses to the SM_DeviceHandleTypedef handle
           	switch(num_addr_found)
           	{
           		case 1:
           			the_smbus_device.addr[0] = i;
           			break;
           		case 2:
           			the_smbus_device.addr[1] = i;
           			break;
           	}
        }
    }

    return smbus_status;
}




/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
void SM_InitDiagnostics()
{


	uint8_t bufferrx[1] = {0};

	// make sure device is ready
	if(HAL_SMBUS_GetState(the_smbus_device.instance) != HAL_SMBUS_STATE_READY)
	{
		Error_Handler();
	}

	// try sending PMBUS commands to device, see if any call HAL_SMBUS_ErrorCallback.
	for(uint8_t tmp_cmd = 0; tmp_cmd < NUMBER_OF_BOOT_TESTS; tmp_cmd++)
	{
		the_diagnostic_plan.testitem[test_index].smbus_cmd = tmp_cmd;
		the_diagnostic_plan.exe_cmds_count++;

		// UNIT TEST: "smbus device callback"
		#ifdef FORCE_SMBUS_DEV_CLBK_ERRS
				uint16_t tmp_smbus_addr = 0x87 << 1;							// force DEV CMD ERRs on all commmands
		#else
				uint16_t tmp_smbus_addr = SM_GetDeviceAddress(0) << 1;			// next SMBUS device address to use
		#endif //FORCE_SMBUS_DEV_CLBK_ERRS

		the_smbus_device.last_cmd = &tmp_cmd;							// next SMBUS command to run


		// send
		if(HAL_SMBUS_Master_Transmit_IT(	the_smbus_device.instance,
											tmp_smbus_addr,
											&tmp_cmd,
											1,
											SMBUS_FIRST_AND_LAST_FRAME_NO_PEC)
											!= HAL_OK)
		{
			the_diagnostic_plan.tx_failed_count++;

		}

		// UNIT TEST: "smbus transmit commands"
		#ifndef FORCE_SMBUS_DEV_TX_ERRS

			// UNIT TEST: "smbus receive commands"
			#ifndef FORCE_SMBUS_DEV_RX_ERRS

				while(HAL_SMBUS_GetState(the_smbus_device.instance) != HAL_SMBUS_STATE_READY);

			#endif	//FORCE_SMBUS_DEV_RX_ERRS

			// receive
			if (HAL_SMBUS_Master_Receive_IT(	the_smbus_device.instance,
												tmp_smbus_addr,
												&bufferrx[0],
												sizeof(bufferrx),
												SMBUS_FIRST_AND_LAST_FRAME_NO_PEC)
												!= HAL_OK)
			{
				the_diagnostic_plan.rx_failed_count++;
			}
			while(HAL_SMBUS_GetState(the_smbus_device.instance) != HAL_SMBUS_STATE_READY);

		#endif //FORCE_SMBUS_DEV_TX_ERRS

		the_diagnostic_plan.testitem[test_index].result[0] = bufferrx[0];
		the_diagnostic_plan.testitem[test_index].status = 0;

		test_index++;
	}


}

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
uint8_t SM_GetLastCommand()
{
	return *the_smbus_device.last_cmd;
}

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
uint16_t SM_GetDeviceAddress(uint8_t device)
{
	return the_smbus_device.addr[device];
}

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval
 *
 */
void SM_DisplayDiagnostics()
{

	ILI9341_Draw_Text("SMBUS Init Diagnostics", 20, 20, LBLUE, 2, BLACK);

	// print out SMBUS device scan results to TFTLCD
	char address[20] = "";
	if(the_smbus_device.status == SMBUS_DEVICE_FOUND)
	{
		if(the_smbus_device.addr[0] != 0)
		{
			snprintf(address, sizeof(address), "SMBUS FOUND: %d", the_smbus_device.addr[0]);
			ILI9341_Draw_Text(address, 50, 50, BLACK, 2, GREEN);
		}
		if(the_smbus_device.addr[1] != 0)
		{
			snprintf(address, sizeof(address), "SMBUS FOUND: %d", the_smbus_device.addr[1]);
			ILI9341_Draw_Text(address, 50, 65, BLACK, 2, GREEN);
		}
	}
	else
	{
			ILI9341_Draw_Text("SMBUS ERROR", 50, 50, BLACK, 2, RED);
			return;
	}


	// print out SMBUS command test report to TFTLCD
	char smbus_results[50] = "";

	snprintf(smbus_results, sizeof(smbus_results), "RAN %d TESTS:", the_diagnostic_plan.exe_cmds_count);
	ILI9341_Draw_Text(smbus_results, 50, 90, LBLUE, 2, BLACK);

	snprintf(smbus_results, sizeof(smbus_results), "TRANSMIT ERR: %d", the_diagnostic_plan.tx_failed_count);
	if(the_diagnostic_plan.tx_failed_count == 0)
		ILI9341_Draw_Text(smbus_results, 50, 120, BLACK, 2, GREEN);
	else
		ILI9341_Draw_Text(smbus_results, 50, 120, BLACK, 2, RED);

	snprintf(smbus_results, sizeof(smbus_results), "RECEIVE ERR: %d", the_diagnostic_plan.rx_failed_count);
	if(the_diagnostic_plan.rx_failed_count == 0)
		ILI9341_Draw_Text(smbus_results, 50, 135, BLACK, 2, GREEN);
	else
		ILI9341_Draw_Text(smbus_results, 50, 135, BLACK, 2, RED);

	snprintf(smbus_results, sizeof(smbus_results), "DEVICE ERR: %d", the_diagnostic_plan.isr_failed_count);
	if(the_diagnostic_plan.isr_failed_count == 0)
		ILI9341_Draw_Text(smbus_results, 50, 150, BLACK, 2, GREEN);
	else
		ILI9341_Draw_Text(smbus_results, 50, 150, BLACK, 2, RED);

}


/*
 *	HAL SMBUS Callbacks
 */
void HAL_SMBUS_ErrorCallback(SMBUS_HandleTypeDef *hsmbus)
{
	if(test_index > last_test_index)
	{
		the_diagnostic_plan.isr_failed_count++;
		the_diagnostic_plan.testitem[test_index].status = hsmbus->ErrorCode;
	}

	last_test_index = test_index;
/*
	char tmp[25] = "";
	snprintf(tmp, sizeof(tmp), "CMD (%d) 0x%x ERR %lu", SM_GetLastCommand(), SM_GetLastCommand(), hsmbus->ErrorCode);
	ILI9341_Draw_Text(tmp, 1, (cmds_failed_count * 20), BLACK, 2, LBLUE);
*/
}
