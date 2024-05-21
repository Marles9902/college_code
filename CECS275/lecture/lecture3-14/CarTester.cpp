#include <iostream>
#include "Car.h"

using namespace std;

// to compile in terminal:
// g++ Car.cpp CarTester.cpp 
// most extreme compile if nothing works:
// g++ Car.cpp CarTester.cpp -std=c+11 -0 car.exe 
// to compile all .cpp files in folder (wildcard):
// g++ *.cpp
int main()
{
    // Car myCar;          // default constructor (take no argument)
    Car myCar = Car("Tesla", "Model S", "2020", 25.5);
    myCar.carInfo();
    myCar.setVelocity(60.0);

    myCar.accelerate(4.0, 2);
    cout << "Velocity: " << myCar.getVelocity() << endl;
    myCar.drawCar();

    myCar.accelerate(4.0, 2);
    cout << "Velocity: " << myCar.getVelocity() << endl;
    myCar.drawNewCar();

    myCar.accelerate(-10.0, 2);
    cout << "Velocity: " << myCar.getVelocity() << endl;
    myCar.drawCar();

    return 0;
}