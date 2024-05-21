%{  
Name: Gaussian Quadrature Rule
Date: 04/14/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This file implements the trapezoidal rule method of finding the
    area under a curve.
%} 

%{
function nGaussTest
    f = @(x) x/((x.^4)+1);  % define your function here
    a = -2;  % lower bound
    b = 2;  % upper bound
    for N = 2:5 % number of points (must be between 2 and 5)
        val = nGaussIntegral(f, a, b, N);  % calculate the integral
        fprintf('Approximation: %.18f\n', val);
    end
end
%}

function val = joshGauss(f, a, b, N)
    % f: function to be integrated
    % a: lower bound
    % b: upper bound
    % N: number of points (2 <= N <= 5)
    % val: approximate value of the integral of function f(x) from a to b 
    
    switch N
        case 2 % 2-point Gauss Quadrature Rule
            x = [-0.5773502691896258, 0.5773502691896258];  % x-values for N = 2
            w = [1, 1];  % weights for N = 2
        case 3 % 3-point Gauss Quadrature Rule
            x = [-0.7745966692414834, 0, 0.7745966692414834];  % x-values for N = 3
            w = [-0.5555555555555556, 0.8888888888888889, 0.5555555555555556];  % weights for N = 3
        case 4 % 4-point Gauss Quadrature Rule
            x = [-0.8611363115940526, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526];  % x-values for N = 4
            w = [0.347854845137454, 0.6521451548625461, 0.6521451548625461, 0.3478548451374539];  % weights for N = 4
        case 5 % 5-point Gauss Quadrature Rule
            x = [-0.9061798459386640, -0.5384693101056831, 0, 0.5384693101056831, 0.9061798459386640];  % x-values for N = 5
            w = [0.2369268850561891, 0.478628670499367, 0.5688888888888889, 0.478628670499367, 0.2369268850561891];  % weights for N = 5
    end
    
    h = (b-a)/2;  % half the width of the interval
    x_mapped = h*x + (a+b)/2;  % map x-values to interval [a,b]
    y = f(x_mapped);  % y-values at each x-value
    
    % calculate the integral using the n-point Gauss Quadrature Rule formula
    val = h*sum(w.*y);
end