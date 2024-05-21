%{  
Name: Temperature Table -- Problem 2.11b
Date: 02/07/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Change the script from 2.11a into one that creates a table of
    converted temperatures from 20 up to 30 in Celsius to Fahrenheit
Last updated: 02/07/2023  
%}  

% create a Celsius vector starting at 20, going to 30 by 1 step each time
c = 20:1:30;

% convert each Celsius temperature to Fahrenheit
f = ((9*c)/5) + 32;

% display the results in a table-like format
%disp('Celsius\t\tFahrenheit')
disp('Celsius     Fahrenheit')

%{ for loop to iterate through the Celsius vector -- 10 elements 
for element = 1:11

    % display table with formatted values to two decimal places and spacing
    fprintf('%.2f\t\t%.2f\n', c(element), f(element))

end