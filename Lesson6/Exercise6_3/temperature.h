#pragma once
#include <stdint.h>

typedef struct temp * temp_t;

temp_t temperature_create(uint8_t portNo);
void temperature_meassure(temp_t self);
float temperature_getTemperature(temp_t self);