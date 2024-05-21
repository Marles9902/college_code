/* 
 * GOOD PRACTICE FOR DOCUMENTATION 
 */

#ifndef CAR_H
#define CAR_H

#include <string>

class Car{
    public:
        /*
         * default constructor
         */
        Car();

        /*
         * Overloaded constructor
         * @param mMake make of a Car
         * @param mModel model of a Car
         * @param mYear year of a Car
         * @param mMPG mpg of a Car
         */
        Car(std::string mMake, std::string mModel, std::string mYear, double mMPG);

        // ~Car();          // destructer (called automatically)

        /*
         * Change the velocity of a car
         * @param acc acceleration of a car
         * @param mTime time in seconds
         */
        void accelerate(double acc, double mTime);

        double getVelocity() const;     // getter or accessor
        void setVelocity(double vel);     // setter or mutator
        void carInfo() const;           // function can not modify anything related to the private functions (const)
        void drawCar() const;
        void drawNewCar() const;

    private:
        std::string make;
        std::string model;
        std::string year;
        double mpg;
        double velocity;

};

#endif