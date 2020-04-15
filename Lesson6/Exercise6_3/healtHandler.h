#pragma once
#include "room.h"

typedef struct health_handler * health_handler_t;

health_handler_t healthHandler_create(void);
void healthHandler_addRoom(health_handler_t self, room_t room);
void healthHandler_showBuildingHealth(health_handler_t self);