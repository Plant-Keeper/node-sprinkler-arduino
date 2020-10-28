#include "Arduino.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ST7735.h"
#include "OGDisplay.h"

#define TFT_CS   15
#define TFT_RST  4
#define TFT_DC   2
#define TFT_MOSI 23
#define TFT_SCLK 18
// not required
// #define TFT_MISO 12

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


void DisplayLib::initR(){

	tft.initR(INITR_BLACKTAB);
	tft.fillScreen(ST7735_BLACK);
	delay(500);
	// large block of text
	tft.fillScreen(ST7735_BLACK);
	drawtext("Screen initialised",ST7735_WHITE);

}


void DisplayLib::initWifi(){
	drawtext("Connecting to WIFI", ST7735_WHITE);
}


void DisplayLib::connectedWifi(){
	drawtext("Connected to WIFI", ST7735_WHITE);
}


void DisplayLib::drawtext(char *text, uint16_t color) {
	tft.fillScreen(ST7735_BLACK);
	tft.setCursor(0, 0);
	tft.setTextColor(color);
	tft.setTextWrap(true);
	tft.print(text);
}

