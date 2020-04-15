#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "humidityDriver.h"
#include "humidity.h"

typedef struct humidity
{
	uint8_t _latestHumidity;
	uint8_t portNo;
} humidity;

humidity_t humidity_create(uint8_t portNo)
{
	humidity_t _newHumidity = calloc(sizeof(humidity_t), 1);

	if (_newHumidity == NULL)
	{
		return NULL;
	};

	_newHumidity->_latestHumidity = 0;
	_newHumidity->portNo = portNo;
	humidityDriver_initDriver(portNo);
	return _newHumidity;
}

void humidity_meassure(humidity_t self)
{
	printf("[Humidity] Start measure");
	self->_latestHumidity = humidityDriver_getHumidity();
}

uint8_t humidity_getHumidity(humidity_t self)
{
	return self->_latestHumidity;
}