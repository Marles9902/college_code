%{  
Name: Simpson Integral
Date: 04/16/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This file implements the Simpson's rule to approximate a definite
    integral f with bounds [a,b] within a number of subintervals N.
%} 

function val = simpsonIntegral(f, a, b, N)
    % calculate delta x using bounds and number of subintervals
    delta_x = (b - a)/N;
    % variables for odd and even to separate the middle portion of function
    odd = 0;
    even = 0;
    % for odd-number subintervals, add them to multiply by 4 later
    for i = 1:2:N-1
        xi= a + (i*delta_x);
        odd = odd + f(xi);
    end
    % for even-number subintervals, add them to multiply by 2 later
    for i = 2:2:N-2
        xi = a + (i*delta_x);
        even = even + f(xi);
    end
    % calculate approx value of integral using simpson's rule formula
    % S = delta_x/3 * [f(x0) + 4f(x1) + 2f(x2) + ... + f(xn)]
    val = (delta_x/3)*(f(a) + 4*odd + 2*even + f(b));
end