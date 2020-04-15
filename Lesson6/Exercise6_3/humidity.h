#pragma once
#include <stdint.h>

typedef struct humidity * humidity_t;

humidity_t humidity_create(uint8_t portNo);
void humidity_meassure(humidity_t self);
uint8_t humidity_getHumidity(humidity_t self);