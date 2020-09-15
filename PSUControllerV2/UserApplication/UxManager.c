/*
 * UxManager.c
 *
 *  Created on: 19 Aug 2020
 *      Author: chris
 */


#include "UxManager.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"



void UxInit()
{
	UxDiagLayout.title_ypos = 				15;

	UxDiagLayout.section1_box_ypos =		48;
	UxDiagLayout.section1_heading_ypos = 	40;
	UxDiagLayout.section1_line1_ypos = 		60;
	UxDiagLayout.section1_line2_ypos = 		80;

	UxDiagLayout.section2_box_ypos =		122;
	UxDiagLayout.section2_heading_ypos = 	113;
	UxDiagLayout.section2_line1_ypos = 		140;
	UxDiagLayout.section2_line2_ypos = 		160;
	UxDiagLayout.section2_line3_ypos = 		180;


	UxDisplayLayout.title_ypos = 				15;

	UxDisplayLayout.section1_box_ypos =			48;
	UxDisplayLayout.section1_heading_ypos = 	40;
	UxDisplayLayout.section1_line1_ypos = 		70;
	UxDisplayLayout.section1_line2_ypos = 		80;

	UxDisplayLayout.section2_box_ypos =			122;
	UxDisplayLayout.section2_heading_ypos = 	113;
	UxDisplayLayout.section2_line1_ypos = 		140;
	UxDisplayLayout.section2_line2_ypos = 		170;
	UxDisplayLayout.section2_line3_ypos = 		180;
	UxDisplayLayout.footer_ypos = 				225;
}

void UxDrawLayout(UxLayoutsTypedef nextLayout)
{
	switch(nextLayout)
	{
		case UxSMBusDiagnosticsLayout:
			ILI9341_Fill_Screen(UX_BODY_BGCOLOR);
			ILI9341_Draw_Rectangle(0, 0, 320, 10, UX_TOP_BGCOLOR, AREA_CHUNK);
			ILI9341_Draw_Rectangle(0, 10, 320, 30, UX_TITLE_BGCOLOR, AREA_CHUNK);

			// address discovery results
			ILI9341_Draw_Bordered_Filled_Rectangle_Coord(20, UxDiagLayout.section1_box_ypos, 280, 60, UX_BODY_BGCOLOR, 1, BLACK);


			// smbus test results
			ILI9341_Draw_Bordered_Filled_Rectangle_Coord(20, UxDiagLayout.section2_box_ypos, 280, 90, UX_BODY_BGCOLOR, 1, BLACK);

			ILI9341_Draw_Rectangle(0, 220, 320, 230, UX_TITLE_BGCOLOR, AREA_CHUNK);
			ILI9341_Draw_Rectangle(0, 230, 320, 240, UX_TITLE_BGCOLOR, AREA_CHUNK);
		break;

		case UxPsuDisplayLayout:
			ILI9341_Fill_Screen(UX_BODY_BGCOLOR);
			ILI9341_Draw_Rectangle(0, 0, 320, 10, UX_TOP_BGCOLOR, AREA_CHUNK);
			ILI9341_Draw_Rectangle(0, 10, 320, 30, UX_TITLE_BGCOLOR, AREA_CHUNK);

			// PSU Status
			ILI9341_Draw_Bordered_Filled_Rectangle_Coord(20, UxDiagLayout.section1_box_ypos, 280, 60, UX_BODY_BGCOLOR, 1, BLACK);

			// PSU Current Reading
			ILI9341_Draw_Bordered_Filled_Rectangle_Coord(20, UxDiagLayout.section2_box_ypos, 280, 90, UX_BODY_BGCOLOR, 1, BLACK);

			ILI9341_Draw_Rectangle(0, 220, 320, 230, UX_TITLE_BGCOLOR, AREA_CHUNK);
			ILI9341_Draw_Rectangle(0, 230, 320, 240, UX_TITLE_BGCOLOR, AREA_CHUNK);
			break;
	}

}


