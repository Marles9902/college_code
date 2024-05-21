%{  
Name: Bisection Method
Date: 03/03/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This function implements the bisection method of finding a root 
    of a function.
%}    

function [root, error, x] = bisec(f, a, b, tol, maxIter)

% store approximations in vectors -- all elements are 0 at first
x = zeros(maxIter, 1);
error = zeros(maxIter, 1);

% root calculation
root = (a + b) / 2;

% start iteration count at x1
i = 1;

% keep iterating until tolerance reached and without passing max iterations
% to ensure root is found
while abs(f(root)) >= tol && i <= maxIter
    
    % calculate the middle of the interval
    c = (a + b) / 2;

    % check if f(c) is zero -- f(c) is the root
    if f(c) == 0
        root = c;
        break;
    end

    % change bounds of the interval if c != root
    if sign(f(c)) == sign(f(a))
        a = c;  % change lower bound (a) with c
    else
        b = c;  % change upper bound (b) with c
    end

    % calculate the root and go the next iteration
    root = (a + b) / 2;
    i = i + 1;

    % calculate the error
    error(i) = abs((root - x(i-1)) / root);
    x(i) = root;
end

% change the vector sizes to remove unnecessary/uncalculated elements to
% prevent mismatching with the vectors
error = error(1:i);
x = x(1:i);

end