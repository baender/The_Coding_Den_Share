#include "myObservables.h"
#include "api/deprecated-avr-comp/avr/dtostrf.h"

bool Observable::writeToBuffer(char *buffer, size_t size, Variable variable) {
    switch (variable) {
        case Variable::Quantity:
            strncat(buffer, m_quantity, size - (strlen(buffer) + 1));
            break;
        case Variable::Unit:
            strncat(buffer, m_unit, size - (strlen(buffer) + 1));
            break;
        case Variable::Value:
            dtostrf(m_value, size - strlen(buffer), 3, &buffer[strlen(buffer)]);
            break;
    }
    strncat(buffer, "\t", size - (strlen(buffer) + 1));
}