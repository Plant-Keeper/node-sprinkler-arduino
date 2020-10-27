#include "Arduino.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ST7735.h"
#include "display.h"

#define TFT_CS   15
#define TFT_RST  4
#define TFT_DC   2
#define TFT_MOSI 23
#define TFT_SCLK 18
// not required
// #define TFT_MISO 12

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// color definitions
extern uint16_t  Display_Color_Black        = 0x0000;
extern uint16_t  Display_Color_Blue         = 0x001F;
extern uint16_t  Display_Color_Red          = 0xF800;
extern uint16_t  Display_Color_Green        = 0x07E0;
extern uint16_t  Display_Color_Cyan         = 0x07FF;
extern uint16_t  Display_Color_Magenta      = 0xF81F;
extern uint16_t  Display_Color_Yellow       = 0xFFE0;
extern uint16_t  Display_Color_White        = 0xFFFF;

// declare size of working string buffers. Basic strlen("d hh:mm:ss") = 10
const size_t    MaxString                  = 16;
char oldTimeString[MaxString]           = { 0 };

void DisplayLib::initR(){

	// settling time
	delay(250);
	tft.enableDisplay(true);
	tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
	// initialise the display
	tft.setFont();
	tft.fillScreen(0x07E0);
	tft.setTextColor(0xFFFF);
	tft.setTextSize(1);
	return tft;
}

void DisplayLib::printSomething() {

	char newTimeString[MaxString] = { 0 };

	// yes! home the cursor
	tft.setCursor(0,0);

	// change the text color to the background color
	tft.setTextColor(0xFFFF);

	sprintf(
			newTimeString,
			"this a simple test"
   );
	// redraw the old value to erase
	tft.print(newTimeString);
	delay(200);
}