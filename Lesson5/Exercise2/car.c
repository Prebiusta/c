#include <stdlib.h>
#include <string.h>

#include "car.h"

typedef struct car
{
    int hp;
    char brand[30];
    char model[30];
    bool isStarted;
} car;

car_t car_create(int hp, char *brand, char *model)
{
    car_t _newCar = calloc(sizeof(car), 1);

    if (NULL == _newCar)
    {
        return NULL;
    }

    _newCar->hp = hp;
    strncpy(_newCar->brand, brand, sizeof(_newCar->brand) - 1);
    strncpy(_newCar->model, model, sizeof(_newCar->model) - 1);

    return _newCar;
}

void car_destroy(car_t self)
{
    if (self != NULL)
    {
        free(self);
    }
}

void car_start(car_t self)
{
    self->isStarted = true;
}

void car_stop(car_t self)
{
    self->isStarted = false;
}

void car_tune(car_t self, int newHp)
{
    self->hp = newHp;
}

bool car_isStarted(car_t self)
{
    return self->isStarted;
}

int car_getHp(car_t self)
{
    return self->hp;
}

char *car_getBrand(car_t self)
{
    return self->brand;
}

char *car_getModel(car_t self)
{
    return self->model;
}