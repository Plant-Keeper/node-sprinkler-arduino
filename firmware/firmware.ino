#include "OGDisplay.h"
#include <WiFi.h>


char* NODE_TYPE = "sprinkler" ;
char* NODE_TAG  = "orchid" ;
char* WIFI_SSID = "*";
char* WIFI_PASSWORD  = "*";
char* API_GATEWAY_URL = "http://api.af120153-db6a-4fdd-a81b-6d902b00e936.nodes.k8s.fr-par.scw.cloud/sprinkler/registry";
char* API_GATEWAY_BASIC_AUTH_USER = "";
char* API_GATEWAY_BASIC_AUTH_PASSWORD = "";
int API_GATEWAY_PORT = 0;
char* MQTT_SERVER = "af120153-db6a-4fdd-a81b-6d902b00e936.nodes.k8s.fr-par.scw.cloud";
int MQTT_PORT = 32500;
bool registered = false;


DisplayLib displayLib;


void setup(void) {

	Serial.begin(115200);
	displayLib.initR();

	delay(1000);
	Serial.println("\n");

	displayLib.initWifi();
	Serial.print("Connecting to wifi "); Serial.print(WIFI_SSID);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


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
