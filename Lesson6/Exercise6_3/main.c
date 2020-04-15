#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#include "temperature.h"
#include "humidity.h"
#include "room.h"
#include "healtHandler.h"

bool temperature_metricUnits = true; // Definition
static health_handler_t hh;

static void _delayMs(int milliseconds)
{
	long _pause;
	clock_t _now, _then;

	_pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	_now = _then = clock();
	while ((_now - _then) < _pause)
		_now = clock();
}

static void _setupApplication(void)
{
	hh = healthHandler_create();

	// Creating living room with 2 temp sensors and 1 humidity sensor
	room_t livingRoom = room_create("Living Room", 75);

	temp_t t0 = temperature_create(0);

	temp_t t1 = temperature_create(1);
	humidity_t h0 = humidity_create(0);

	// room_addTemperature(livingRoom, t0);

	room_addTemperature(livingRoom, t1);

	room_addHumidity(livingRoom, h0);

	// Adding living room to Health Handler
	healthHandler_addRoom(hh, livingRoom);

	// Creating kitchen with temp and humidity sensors
	room_t kitchen = room_create("Kitchen", 16);

	temp_t t2 = temperature_create(2);
	humidity_t h1 = humidity_create(1);

	room_addTemperature(kitchen, t2);
	room_addHumidity(kitchen, h1);

	// Addling kitchen to Health Handler
	healthHandler_addRoom(hh, kitchen);
}

static void _runApplication()
{
	while (1)
	{
		healthHandler_showBuildingHealth(hh);
		_delayMs(1000);
	}
}

int main(void)
{
	_setupApplication();
	_runApplication();

	return 0;
}