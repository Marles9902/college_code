/*
 * This is the header file for the Shape class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef SHAPE_H
#define SHAPE_H

class Shape{
    private:
        double area;
    public:
        Shape();
        double getArea() const;
        void setArea(double a);
        virtual double calcArea() = 0;
        void draw();
};

#endif