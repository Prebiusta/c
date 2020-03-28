#include <stdio.h>
#include "healthHandler.h"
#include "room.h"

static void _printRoomHealth(void){
    printf("%s: area: %d m2 Health: %s\n", 
    room_getLocation(), 
    room_getArea(), 
    room_getRoomHealthText(room_getRoomHealth()));
}

void healthHandler_create(void){
    // TODO Do Something
}

void healthHandler_showBuildingHealth(void){
    _printRoomHealth();
}
