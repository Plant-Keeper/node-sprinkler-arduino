#include "OGDisplay.h"
#include <WiFi.h>

const char* ssid = "*";
const char* password = "*";


DisplayLib displayLib;

#define TFT_CS   15
#define TFT_RST  4
#define TFT_DC   2
#define TFT_MOSI 23
#define TFT_SCLK 18
// not required
// #define TFT_MISO 12



void setup(void) {

	Serial.begin(115200);
	displayLib.initR();

	delay(1000);
	Serial.println("\n");

	displayLib.initWifi();
	Serial.print("Connecting to wifi "); Serial.print(ssid);

	WiFi.begin(ssid, password);


	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}

	Serial.println("\n");
	displayLib.connectedWifi();
	Serial.println("Connected ");
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

}

void loop() {

}
