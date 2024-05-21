/*
 * This is the header file for the Rectangle class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
    private:
        int width;
        int height;
        int centerX;
        int centerY;
    public:
        Rectangle();
        Rectangle(int w, int h, int cX, int cY);
        int getWidth() const;
        int getHeight() const;
        int getCenterX() const;
        int getCenterY() const;
        void setWidth(int w);
        void setHeight(int h);
        void setCenterX(int cX);
        void setCenterY(int cY);
        virtual double calcArea();
        void draw();
};

#endif