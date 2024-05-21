#include <iostream>
#include "Car.h"

using namespace std;

Car::Car(){
    make = "makeOfACar";
    model = "modelOfACar";
    year = "yearOfACar";
    mpg = 0.0;
}

Car::Car(string mMake, string mModel, string mYear, double mMPG){
    make = mMake;
    model = mModel;
    year = mYear;
    mpg = mMPG;
}

void Car::carInfo() const{          // this particular function belongs to the Car class (Car::)
    cout << "Year: " << year << endl;
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "MPG: " << mpg << endl;

}

void Car::accelerate(double acc, double mTime){
    // velocity changes by acc every second
    velocity = velocity + acc *mTime;
}

double Car::getVelocity() const{
    return velocity;
}

void Car::setVelocity(double vel){
    velocity = vel;
}

void Car::drawCar() const{
    cout << "                ." << endl;
    cout << "   __            |\\" << endl;
    cout << "__/__\\___________| \\_" << endl;
    cout << "|   ___    |  ,|   ___`-." << endl;
    cout << "|  /   \\   |___/  /   \\  `-." << endl;
    cout << "|_| (O) |________| (O) |____|" << endl;
    cout << "   \\___/          \\___/" << endl;

}

// professor used if else with condition of velocity but i found out too late
void Car::drawNewCar() const{
    cout << "                      ." << endl;
    cout << "         __            |\\" << endl;
    cout << "      __/__\\___________| \\_" << endl;
    cout << "-- -- |   ___    |  ,|   ___`-." << endl;
    cout << "      |  /   \\   |___/  /   \\  `-." << endl;
    cout << " -- - |_| (O) |________| (O) |____|" << endl;
    cout << "         \\___/          \\___/" << endl;

}
