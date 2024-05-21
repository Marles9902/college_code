#include <iostream>
#include <string>

using namespace std;

struct Registration;
struct Car;
void displayCarInfo(const Car&);
void displayRegistration(const Registration&);

// how to declare a struct
struct Car{
    string model;
    string make;
    string year;
    double mpg;
    Registration* reg;

};

struct Registration{
    string month;
    int year;

};

void getCarInfo(Car& myCar){    // struct pass by value, so use & to pass by reference
    // user input
    // cout << "Enter model: ";
    // cin >> myCar.model;     // use get line if string has spaces in it 
    // cout << "\nEnter make: ";
    // cin >> myCar.make;
    // cout << "\nEnter year: ";
    // cin >> myCar.year;
    // cout << "\nEnter mpg: ";
    // cin >> myCar.mpg;
    // cout << endl;

    // hard code
    myCar.model = "Altima";
    myCar.make = "Nissan";
    myCar.year = "2000";
    myCar.mpg = 25.0;
    myCar.reg = new Registration[2] {
        Registration{"MAR", 2020},
        Registration{"APR", 2022}
    };
}

void displayCarInfo(const Car& myCar){
    cout << "*****************************\n";
    cout << "*        YOUR NEW CAR       *\n";
    cout << "*****************************\n";
    cout << "Model: " << myCar.model << endl;
    cout << "Make: " << myCar.make << endl;
    cout << "Year: " << myCar.year << endl;
    cout << "MPG: " << myCar.mpg << endl;
    // cout << myCar.reg[0].month << endl;
    for(int i = 0; i < 2; ++i){
        displayRegistration(myCar.reg[i]);
    }
}

void displayRegistration(const Registration& myReg){
    cout << "----------------- Registration Information -----------------\n";
    cout << "Month: " << myReg.month << endl;
    cout << "Year: " << myReg.year << endl;
    cout << "------------------------------------------------------------\n";
}

// object-oriented programming
int main()
{
    // struct is public by default, class is private
    // C++ uses classes more, C uses struct

    Car myCar;

    getCarInfo(myCar);
    displayCarInfo(myCar);
    Car* ptrCar = &myCar;
    // (*ptrCar).model = "x5";     // same as line after
    // ptrCar->model = "x5";       // better to use (easier to understand)
    // displayCarInfo(myCar);

    // Registration* r = (*ptrCar).reg;            // these two lines are also the same as both below
    // cout << (*r).month << endl;                 // these are split up so its easier to understand
    // cout << (*(*ptrCar).reg).month << endl;     // same as line after
    // cout << (*ptrCar->reg).year << endl;        // better to use (easier to understand)
    cout << (ptrCar->reg)->year << endl;        // best to use


    // Car myCarCollection[2];
    // Car yourCar;
    // myCarCollection[0] = Car{"TC", "Scion", 1000, 19.6};;
    // myCarCollection[1] = yourCar;

    // for(int i = 0; i < 2; ++i){
    //     displayCarInfo(myCarCollection[i]);
    // }
    
    // more accurate syntax than the one above ^
    // for(const Car& car : myCarCollection){
    //     displayCarInfo(car);
    // }

    // Car* ptrCar;
    // ptrCar = myCarCollection;
    // for(int i = 0; i < 2; ++i){
    //     displayCarInfo(ptrCar[i]);
    // }

    return 0;
}