#include <Arduino.h>
#include <TSdebouncer.h>

TSdebouncer::TSdebouncer(int PINNUMBER, int LEVELSHIFT=4) {
    _PINNUMBER = PINNUMBER;
    _DBMASK = _DBMASK << LEVELSHIFT;
}

void TSdebouncer::poll() {
    _BUTTON_STATE_RAW = _BUTTON_STATE_RAW << 1;
    _BUTTON_STATE_RAW |= (ISACTIVEHIGH ? !digitalRead(_PINNUMBER) : digitalRead(_PINNUMBER));

    if ((_BUTTON_STATE_RAW | (uint8_t)(_DBMASK << 1)) == (uint8_t)(_DBMASK)) {
        // Rising event
        BUTTON_STATE = 1;
        (*event)(BUTTON_STATE);
    }
    if ((_BUTTON_STATE_RAW | (uint8_t)(~_DBMASK) >> 1) == (uint8_t)(~_DBMASK)) {
        // falling event
        BUTTON_STATE = 0;
        (*event)(BUTTON_STATE);
    }
}