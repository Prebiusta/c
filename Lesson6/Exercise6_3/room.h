#pragma once
#include <stdint.h>
#include "temperature.h"
#include "humidity.h"

typedef struct room * room_t;

typedef enum {
	PERFECT
	,GOOD
	,AVERAGE
	,BAD
	,DISASTER
}room_roomHealth_t;

room_t room_create(char* location, uint8_t sqMeter);
void room_addTemperature(room_t self, temp_t temperature);
void room_addHumidity(room_t self, humidity_t humidity);
room_roomHealth_t room_getRoomHealth(room_t self);
char* room_getRoomHealthText(room_roomHealth_t health);
char* room_getLocation(room_t self);
uint8_t room_getArea(room_t self);