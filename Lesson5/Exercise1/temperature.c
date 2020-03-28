#include "temperature.h"
#include <stdbool.h>
#include <stdlib.h>
// #include <tempDriver.h>

extern bool temperature_metricUnits;

static float _latestTemp = 0.0;
static uint8_t _driverPort;

static float _calculateTemp(float voltage){
    return 13.0 + (voltage * 5.0);
}

void temperature_create(uint8_t portNo){
    _driverPort = portNo;
    // temperatureDriver_initDriver(portNo);
}

void temperature_measure(void){
    // _latestTemp = _calculateTemp(temperatureDriver_getVoltage());
    _latestTemp = rand() + 2;
}

float temperature_getTemperature(void){
    float _tmp = _latestTemp;
    
    if (temperature_metricUnits){
        _tmp *= 0.22;
    }

    return _tmp;
}