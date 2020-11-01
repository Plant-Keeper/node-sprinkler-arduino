#include "OGDisplay.h"
#include <WiFi.h>

char* NODE_TYPE = "sprinkler" ;
char* NODE_TAG  = "orchid" ;
char* WIFI_SSID = "*";
char* PASSWORD  = "*";


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
	Serial.print("Connecting to wifi "); Serial.print(WIFI_SSID);
	WiFi.begin(WIFI_SSID, PASSWORD);


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

	displayLib.printHeader(WIFI_SSID, WiFi.localIP(), NODE_TYPE, NODE_TAG);

}

void loop() {

	delay(100);
}
