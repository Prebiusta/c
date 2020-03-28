#include <stdio.h>
#include <string.h>
#include "room.h"
#include "temperature.h"
#include "humidity.h"

static char _location[30] = { 0 };
static uint16_t _squareMeters;

static room_roomHealth_t _calculateHealth(float temp, uint8_t humidity){
    uint16_t number = (uint16_t)(temp * humidity) % 5;
    printf("Generated number: %d\n", number);
    return number; // Dummy data
}

void room_create(char* location, uint16_t sqMeter) {
    strncpy(_location, location, sizeof(_location) - 1);
    _squareMeters = sqMeter;
}

room_roomHealth_t room_getRoomHealth(void) {
    temperature_measure();
    humidity_measure();

    return _calculateHealth(temperature_getTemperature(), humidity_getHumidity());
}

char* room_getRoomHealthText(room_roomHealth_t health){
    static const char* _health_text[] = { "PERFECT", "GOOD", "AVERAGE", "BAD", "DISASTER"};
    return (char*)_health_text[health];
}

char* room_getLocation(void){
    return _location;
}

uint16_t room_getArea(void){
    return _squareMeters;
}