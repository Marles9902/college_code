%{  
Name: Uniform Beam -- Problem 4.8
Date: 02/05/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Calculate and graph the deflection of a beam a distance from one end of the beam 
Last updated: 02/07/2023  
%}  

% define given values
L = 10;
T = 1000;
W = 100;
EI = 10^4;

% calculate 'a' from given equation of 'a^2'
% original: a^2 = T/EI
a = sqrt(T/EI);

% generate x values from 0 to L for the ends
x = 0:L;

% calculate the deflection (y) based on given formula
y = ((W*EI)/(T^2)) * ((cosh(a*(L/2-x))/cosh(a*L/2)) -1) + (W*x.*(L-x))/(2*T);

% plot x against y
plot(x, y);

% add labels to the axes
xlabel('x (m)');
ylabel('deflection (m)');

% override automatic axis scaling
% xmin = 0
% xmax = 10
% ymin = -0.2
% ymax = 0.2
axis([0 10 -0.2 0.2])
