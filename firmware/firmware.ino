#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ST7735.h"
#include "SPI.h"
#include "display.h"


DisplayLib displayLib ;

void setup() {
	Serial.begin(115200);
	displayLib.initR();


}


void loop() {
	displayLib.printSomething();
	delay(250);
}