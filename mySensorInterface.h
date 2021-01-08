#ifndef _LIB_MYSENSORINTERFACE_
#define _LIB_MYSENSORINTERFACE_

#include <Arduino.h>

enum class Variable { Name, Quantity, Unit, Value };


class SensorInterface {
public:
    virtual bool init();
    virtual bool readValues(); 
    virtual bool writeToBuffer(char *, size_t, Variable);
};

#endif
