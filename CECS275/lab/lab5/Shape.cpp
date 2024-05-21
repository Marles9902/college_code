/*
 * This is the program file for the Shape class
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#include "Shape.h"


Shape::Shape(){
    area = 0.0;
}

double Shape::getArea() const{
    return area;
}

void Shape::setArea(double a){
    area = a;
}

double Shape::calcArea(){

}

void Shape::draw(){

}