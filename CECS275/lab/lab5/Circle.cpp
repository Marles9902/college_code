/*
 * This is the program file for the Circle class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Circle.h"

Circle::Circle(){
    centerX = 0;
    centerY = 0;
    radius = 0;
}

Circle::Circle(int cX, int cY, int r){
    centerX = cX;
    centerY = cY;
    radius = r;
}

int Circle::getCenterX() const{
    return centerX;
}

int Circle::getCenterY() const{
    return centerY;
}

int Circle::getRadius() const{
    return radius;
}

void Circle::setCenterX(int cX){
    centerX = cX;
}

void Circle::setCenterY(int cY){
    centerY = cY;
}

void Circle::setRadius(int r){
    radius = r;
}

double Circle::calcArea(){
    return (3.14 * radius * radius);
}

void Circle::draw(){

}