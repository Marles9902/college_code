%{  
Name: Secant Method
Date: 03/03/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This function implements the secant method of finding a root of
    a function.
%}      

function [root, fx, x] = secant(f, x0, x1, tol, maxIter)

% store initial approximations and calculations in vectors
x = [x0, x1];
fx = [f(x0), f(x1)];

% start iteration count at x2, x0 and x1 predefined 
i = 2;

% general formula:
% x_i+1 = xi - f(xi)(xi-x_i-1)/f(xi)-f(x_i-1)

% keep iterating until the max iterations are reached and 
% until the last two approximations become less than the tolerance 
% to ensure root is found
% uses "end" to get the last index in the x vector
while i <= maxIter && tol <= abs(x(end) - x(end-1))
    
    % calculate next approximation with the formula
    x(i+1) = x(i) - (f(x(i)) * (x(i) - x(i-1))) / (f(x(i)) - f(x(i-1)));

    % put approximation into fx
    fx(i+1) = f(x(i+1));
    
    % go to next iteration
    i = i + 1;
end

% set root to be the final iteration's approximation
root = x(end);
end