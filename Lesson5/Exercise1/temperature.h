#pragma once
#include <stdint.h>

void temperature_create(uint8_t portnNo);
void temperature_measure(void);
float temperature_getTemperature(void);