#include <time.h>
#include <stdbool.h>
#include "temperature.h"
#include "humidity.h"
#include "room.h"
#include "healthHandler.h"

bool temperature_metricUnits = true;

static void _delayMs(int milliseconds){
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause)
        now = clock();
}

static void _setupApplication(void){
    temperature_create(0);
    humidity_create();
    room_create("Kitchen", 12);
    healthHandler_create();
}

static void _runApplication(void) {
    while (1) {
        healthHandler_showBuildingHealth();
        _delayMs(1000);
    }
}

int main(void){
    _setupApplication();
    _runApplication();
}