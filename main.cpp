#include <Arduino.h>

#include "mySensorInterface.h"
#include "mySensorAnalog.h"
#include "mySensorCTD.h"


char lineBuffer[255];

SensorAnalog a("SensorA", 8, 1.4142);
SensorAnalog b("Sensor321", 6, 3.1415);
SensorCTD    c("CTD1", 'H');
SensorCTD    d("CTD2", 'Q');
SensorInterface *sensors[] = {&a, &b, &c, &d, nullptr};


void setup() {
    Serial.begin(9600);
    while(!Serial);

    Serial.print("Init sensors... ");
    uint8_t i = 0;
    while (sensors[i]) {
        sensors[i]->init();
        i++;
    }
    Serial.println("done!");
    Serial.println("");
}

void loop() {
    uint8_t i;
    
    Serial.println("### Start cycle ###");
    Serial.println("");

    Serial.print("Read value... ");
    i = 0;
    while (sensors[i]) {
        sensors[i]->readValues();
        i++;
    }
    Serial.println("done!");

    Serial.println("");
    Serial.println("### End cycle ###");
    Serial.println("");

    delay(5000);
}
