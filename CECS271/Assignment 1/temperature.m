%{  
Name: Temperature -- Problem 2.11a
Date: 02/07/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Ask user for a temperature in Celsius, converting it 
    into Fahrenheit, and displaying the result
Last updated: 02/07/2023  
%}  

% input a temperature in Celsius
c = input('Enter a Celsius temperature: ');

% convert the entered temperature into Fahrenheit with given formula
f = ((9*c)/5) + 32;

% display the result
disp(['The Fahrenheit temperature is: ', num2str(f)])
