#include "humidity.h"
#include <stdlib.h>

static uint8_t _latestHumidity = 0;

void humidity_create(void){
    // TODO: do something
}

void humidity_measure(void){
    _latestHumidity = rand() + 1;
}

uint8_t humidity_getHumidity(void){
    uint8_t tmp = _latestHumidity;
    return tmp * 1.5;
}



