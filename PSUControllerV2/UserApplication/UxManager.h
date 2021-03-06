/*
 * UxColorPalette.h
 *
 *  Created on: 19 Aug 2020
 *      Author: chris
 */

#ifndef UXMANAGER_H_
#define UXMANAGER_H_

#include <stdint.h>

/*
 * colour palette
 */
#define UX_H1_TXT_FGCOLOR		0xDEDD
#define	UX_TOP_BGCOLOR		0x3090
#define UX_TITLE_BGCOLOR		0x7275

#define UX_BODY_BGCOLOR			0xE73D
#define	UX_BODY_TXT_FGCOLOR		BLACK



typedef struct
{
	uint16_t title_ypos;
	uint16_t section1_box_ypos;
	uint16_t section1_heading_ypos;
	uint16_t section1_line1_ypos;
	uint16_t section1_line2_ypos;
	uint16_t section2_box_ypos;
	uint16_t section2_heading_ypos;
	uint16_t section2_line1_ypos;
	uint16_t section2_line2_ypos;
	uint16_t section2_line3_ypos;
} UxDiagLayoutXposTypedef;

UxDiagLayoutXposTypedef UxDiagLayout;

typedef struct
{
	uint16_t title_ypos;
	uint16_t section1_box_ypos;
	uint16_t section1_heading_ypos;
	uint16_t section1_line1_ypos;
	uint16_t section1_line2_ypos;
	uint16_t section2_box_ypos;
	uint16_t section2_heading_ypos;
	uint16_t section2_line1_ypos;
	uint16_t section2_line2_ypos;
	uint16_t section2_line3_ypos;
	uint16_t footer_ypos;
} UxDisplayLayoutXposTypedef;

UxDisplayLayoutXposTypedef UxDisplayLayout;

/*
 * layout types
 */
typedef enum
{
	UxSMBusDiagnosticsLayout = 0U,
	UxPsuDisplayLayout
}	UxLayoutsTypedef;


/*
 * Function declarations
 */
void UxInit();
void UxDrawLayout(UxLayoutsTypedef nextLayout);

#endif /* UXMANAGER_H_ */
