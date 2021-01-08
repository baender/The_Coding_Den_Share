#ifndef _LIB_MYOBSERVABLES_
#define _LIB_MYOBSERVABLES_

#include <Arduino.h>

enum class Variable { Quantity, Unit, Value };


class Observable {
public:
    Observable(const char *quantity, const char *unit): m_quantity(quantity), m_unit(unit), m_value(0.0) { }
    bool writeToBuffer(char *, size_t, Variable);
private:
    const char *m_quantity;
    const char *m_unit;
    float m_value;
};

#endif