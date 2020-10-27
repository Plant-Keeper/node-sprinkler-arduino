#ifndef display
#define display

#if (ARDUINO >= 100 )
	#include "Arduino.h"
	#include "Adafruit_GFX.h"
	#include "Adafruit_ST7735.h"
	#include "SPI.h"
#else
	#include "WProgram.h"
#endif

class DisplayLib {
	public:
		// constructor
		void initR();
		// test method
		void printSomething();

	private:

};


#endif
