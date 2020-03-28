#pragma once
#include <stdint.h>

void humidity_create(void);
void humidity_measure(void);
uint8_t humidity_getHumidity(void);