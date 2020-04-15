#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tempDriver.h"
#include "temperature.h"

typedef struct temp
{
	// Declaration
	bool temperature_metricUnits;
	float _latestTemp;
	uint8_t _driverPort;
} temp;

static float _calculateTemp(float voltage)
{
	return 15.0 + (voltage * 5.0); // dummy calc
}

temp_t temperature_create(uint8_t portNo)
{
	temp_t _newTemp = malloc(sizeof(temp));

	if (_newTemp == NULL)
	{
		return NULL;
	};

	_newTemp->_driverPort = portNo;
	_newTemp->_latestTemp = 0;
	// temperatureDriver_initDriver(portNo);

	return _newTemp;
}

void temperature_meassure(temp_t self)
{
	self->_latestTemp = _calculateTemp(temperatureDriver_getVoltage(self->_driverPort));
}

float temperature_getTemperature(temp_t self)
{
	float _tmp = self->_latestTemp;
	if (self->temperature_metricUnits)
	{
		_tmp *= 0.2; // dummy conversion
	}

	return _tmp;
}
