#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "room.h"

#define MAX_TEMP_SENSORS 3
#define MAX_HUMIDITY_SENSORS 2

typedef struct room
{
	char _location[30];
	uint8_t _squareMeters;
	temp_t _tempSensors[MAX_TEMP_SENSORS];
	humidity_t _humiditySensors[MAX_HUMIDITY_SENSORS];
} room;

static room_roomHealth_t _calculateHealth(float temp, uint8_t hum)
{
	return (uint16_t)(temp * hum) % 5; // dummy calculation;
}

static float _calculateAverageTemperature(float totalTemp, int numberOfMeasurements)
{
	return (float)totalTemp / numberOfMeasurements;
}

static uint8_t _calculateAverageHumidity(uint8_t totalHumidity, int numberOfMeasurements)
{
	return (uint8_t)totalHumidity / numberOfMeasurements;
}

room_t room_create(char *location, uint8_t sqMeter)
{
	room_t _newRoom = malloc(sizeof(room_t));

	if (_newRoom == NULL)
	{
		return NULL;
	}

	strncpy(_newRoom->_location, location, sizeof(_newRoom->_location) - 1);
	_newRoom->_squareMeters = sqMeter;

	printf("[Room] Area on create %d m2\n", _newRoom->_squareMeters);

	return _newRoom;
}

void room_destroy(room_t self)
{
	for (int i = 0; i < MAX_HUMIDITY_SENSORS; i++)
	{
		free(self->_humiditySensors[i]);
	}

	for (int i = 0; i < MAX_TEMP_SENSORS; i++)
	{
		free(self->_tempSensors[i]);
	}

	free(self);
}

void room_addTemperature(room_t self, temp_t temperature)
{
	for (int i = 0; i < MAX_TEMP_SENSORS; i++)
	{
		if (self->_tempSensors[i] == NULL)
		{
			self->_tempSensors[i] = temperature;
			return;
		}
	}
}

void room_addHumidity(room_t self, humidity_t humidity)
{
	for (int i = 0; i < MAX_HUMIDITY_SENSORS; i++)
	{
		if (self->_humiditySensors[i] == NULL)
		{
			self->_humiditySensors[i] = humidity;
			return;
		}
	}
}

room_roomHealth_t room_getRoomHealth(room_t self)
{
	printf("[Room] Area %d m2\n", self->_squareMeters);
	// Measure humidity on all sensors connected to the room
	int _humidityMeasurements = 0;
	uint8_t _totalHumidity = 0;

	for (int i = 0; i < MAX_HUMIDITY_SENSORS; i++)
	{
		if (self->_humiditySensors[i] != NULL)
		{
			humidity_meassure(self->_humiditySensors[i]);
			_totalHumidity += humidity_getHumidity(self->_humiditySensors[i]);
			_humidityMeasurements++;
		}
	}

	// Measure temperature on all sensors connected to the room
	int _tempMeasurements = 0;
	float _totalTemp = 0;

	for (int i = 0; i < MAX_TEMP_SENSORS; i++)
	{
		if (self->_tempSensors[i] != NULL)
		{
			temperature_meassure(self->_tempSensors[i]);
			_totalTemp += temperature_getTemperature(self->_tempSensors[i]);
			_tempMeasurements++;
		}
	}

	float averageTemp = _calculateAverageTemperature(_totalTemp, _tempMeasurements);

	float averageHumidity = _calculateAverageHumidity(_totalHumidity, _humidityMeasurements);

	return _calculateHealth(averageTemp, averageHumidity);
}

char *room_getRoomHealthText(room_roomHealth_t health)
{
	static const char *_health_text[] = {"PERFECT", "GOOD", "AVERAGE", "BAD", "DISASTER"};
	return (char *) _health_text[health];
}

char *room_getLocation(room_t self)
{
	return self->_location;
}

uint8_t room_getArea(room_t self)
{
	return self->_squareMeters;
}