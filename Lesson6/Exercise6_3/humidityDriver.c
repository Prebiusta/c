#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#include "humidityDriver.h"

void humidityDriver_initDriver() {
	srand(time(NULL));
}

uint8_t humidityDriver_getHumidity() {
	uint8_t number = (rand() % (85 - 35 + 1)) + 35;
	return number;
}