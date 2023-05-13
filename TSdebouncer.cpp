#include <Arduino.h>
#include <TSdebouncer.h>

TSdebouncer::TSdebouncer(int PINNUMBER, int LEVELSHIFT = 4, bool ISACTIVEHIGH = 1) {
    _PINNUMBER = PINNUMBER;
    _DBMASK = _DBMASK << LEVELSHIFT;
    _ISACTIVEHIGH = ISACTIVEHIGH;
}

void TSdebouncer::poll() {
    _BUTTON_STATE_RAW = _BUTTON_STATE_RAW << 1;
    _BUTTON_STATE_RAW |= (_ISACTIVEHIGH ? !digitalRead(_PINNUMBER) : digitalRead(_PINNUMBER));

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