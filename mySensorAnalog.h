#ifndef _LIB_MYSENSORANALOG_
#define _LIB_MYSENSORANALOG_

#include <Arduino.h>
#include "mySensorInterface.h"
#include "myObservables.h"


class SensorAnalog: public SensorInterface {
public:
    SensorAnalog(const char *sensorName, const uint8_t analogPin, const float conversionParameter):
        m_sensorName(sensorName), m_analogPin(analogPin), m_conversionParameter(conversionParameter),
        m_observable({ Observable("Angle", "deg") }) { }
    bool init() override;
    bool readValues() override;
    bool writeToBuffer(char *, size_t, Variable) override;
private:
    const char *m_sensorName;
    // sensor specific
    const uint8_t m_analogPin;
    const float m_conversionParameter;
    Observable m_observable[1];
};

#endif
