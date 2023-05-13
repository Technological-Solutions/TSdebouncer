#ifndef TSdebouncer_h
#define TSdebouncer_h

#include "Arduino.h"

class TSdebouncer {
    public:
        TSdebouncer(int PINNUMBER, int LEVELSHIFT=4, bool ISACTIVEHIGH=1);
        void poll();
        void (*event)(bool);
        bool BUTTON_STATE = 1;
        
    private:
        int _PINNUMBER;
        bool _ISACTIVEHIGH;
        uint8_t _DBMASK = 0b11111111;
        uint8_t _BUTTON_STATE_RAW = 0b11111111;
};

#endif