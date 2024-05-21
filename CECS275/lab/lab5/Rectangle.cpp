/*
 * This is the program file for the Rectangle class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Rectangle.h"

Rectangle::Rectangle(){
    width = 0;
    height = 0;
    centerX = 0;
    centerY = 0;
}

Rectangle::Rectangle(int w, int h, int cX, int cY){
    width = w;
    height = h;
    centerX = cX;
    centerY = cY;
}

int Rectangle::getWidth() const{
    return width;
}

int Rectangle::getHeight() const{
    return height;
}

int Rectangle::getCenterX() const{
    return centerX;
}

int Rectangle::getCenterY() const{
    return centerY;
}

void Rectangle::setWidth(int w){
    width = w;
}

void Rectangle::setHeight(int h){
    height = h;
}

void Rectangle::setCenterX(int cX){
    centerX = cX;
}

void Rectangle::setCenterY(int cY){
    centerY = cY;
}

double Rectangle::calcArea(){
    return (width * height);
}

void Rectangle::draw(){

}