#ifndef _LIB_MYSENSORCTD_
#define _LIB_MYSENSORCTD_

#include <Arduino.h>
#include "mySensorInterface.h"
#include "myObservables.h"


class SensorCTD: public SensorInterface {
public:
    SensorCTD(const char *sensorName, const char sdiAddress):
        m_sensorName(sensorName), m_sdiAddress(sdiAddress),
        m_observable({ Observable("Conductivity", "uS_cm_1"), 
                       Observable("Temperature", "C"),
                       Observable("Depth", "m") }) { }
    bool init() override;
    bool readValues() override;
    bool writeToBuffer(char *, size_t, Variable) override;
private:
    const char *m_sensorName;
    // sensor specific
    const char m_sdiAddress;
    Observable m_observable[3];
};

#endif