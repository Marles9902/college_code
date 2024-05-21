/*
 * This is the header file for the Circle class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
    private:
        int centerX;
        int centerY;
        int radius;
    public:
        Circle();
        Circle(int cX, int cY, int r);
        int getCenterX() const;
        int getCenterY() const;
        int getRadius() const;
        void setCenterX(int cX);
        void setCenterY(int cY);
        void setRadius(int r);
        virtual double calcArea();
        void draw();
};

#endif