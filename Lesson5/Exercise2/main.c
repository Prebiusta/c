#include "car.h"

void main()
{
    car_t myCar = car_create(360, "Tesla", "S");

    printf("Power of a car: %d", car_getHp(myCar));
    printf("Brand of the car: %s", car_getBrand(myCar));
    printf("Model of the car: %s", car_getModel(myCar));
}