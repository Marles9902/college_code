%{  
Name: Problem 6.4
Date: 02/20/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Computes the residual of a system of equations and confirm 
    ill conditioning.  
%}  

% create matricces for the system of equation:
% x + 5.000y = 17.0
% 1.5x + 7.501y = 25.503
% solution SHOULD be x = 2, y = 3

% left-hand side of the equation
% x + 5.000y
% 1.5x + 7.501y
% turns into:
%    top row  bot row
A = [1      5.000; 
     1.5    7.501];

% right-hand side of the equation
% = 17.0
% = 25.503
%    top    bot
b = [17.0; 
     25.504];

% left division operator to solve the system for x
x = A\b;
disp("Solution to system:");
disp("x = " + x(1) + ", y = " + x(2));

fprintf("\n");

% calculate the residual -- if the solution satisfies the equations
% if a residual is close to 0 --> solution is close to actual solution
% if farther from 0, then BAD
residual = A*x - b;
disp("Residual of solution:");
disp("Residual of x = " + residual(1) + ", Residual of y = " + residual(2));

fprintf("\n");

% condition estimator -- how sensitive solution is to small changes in 
%   coefficients of matrix
% close to 0 -- ill condition -- small changes to coefficient = large 
%   change to solution
% close to 1 -- well condition -- small changes... = hardly any change
fprintf("Condition estimator: %.16f\n", rcond(A));

% determinant -- how invertible the matrix is/# of solutions (1,inf.,none) 
% non-zero -- invertible/unique solution
% zero -- singular/infinitely many or no solutions
fprintf("Determinant: %.16f\n", det(A));
