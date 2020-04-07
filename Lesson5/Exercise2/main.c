#include <stdio.h>
#include "car.h"

void main()
{
    car_t myCar = car_create(360, "Tesla", "S");

    printf("Power of a car: %d\n", car_getHp(myCar));
    printf("Brand of the car: %s\n", car_getBrand(myCar));
    printf("Model of the car: %s\n", car_getModel(myCar));

    printf("Chaning power of my car.\n");
    car_tune(myCar, 400);
    printf("New power of a car: %d\n", car_getHp(myCar));

    car_start(myCar);
    printf("Car is running: %d\n", car_isStarted(myCar));
    car_stop(myCar);
    printf("Car is running: %d\n", car_isStarted(myCar));

    car_destroy(myCar);
}