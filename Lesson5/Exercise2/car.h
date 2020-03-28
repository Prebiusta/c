#pragma once
#include <stdbool.h>

typedef struct car *car_t;

car_t car_create(int hp, char *brand, char *model);
void car_destroy(car_t self);
void car_start(car_t self);
void car_stop(car_t self);
void car_tune(car_t self, int newHp);
bool car_isStarted(car_t self);
int car_getHp(car_t self);
char *car_getBrand(car_t self);
char *car_getModel(car_t self);