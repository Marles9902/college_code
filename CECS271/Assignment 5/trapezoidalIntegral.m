%{  
Name: Trapezoidal Integral
Date: 04/16/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This file implements the trapezoidal rule to approximate a
    definite integral f with bounds [a,b] within a number of subintervals N.
%} 

function val = trapezoidalIntegral(f, a, b, N)
    % calculate delta x using bounds and number of subintervals
    delta_x = (b-a)/N;
    % declare variable to hold the middle value
    fmiddle = 0;
    % for every subinterval within the bounds besides a or b
    for i = (a+delta_x):delta_x:(b-delta_x)
        % calculate the middle value
        fmiddle = fmiddle + 2*f(i);
    end
    % calculate approx value of integral using trapezoidal rule formula
    % T = delta_x/2 * [f(x0) + 2f(x1) + ... + 2f(xn-1) + f(xn)]
    val = delta_x/2*(f(a) + fmiddle + f(b));
end