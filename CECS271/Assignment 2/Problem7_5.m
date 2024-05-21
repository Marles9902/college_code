%{  
Name: Problem 7.5
Date: 02/20/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Computes the exponential function directly from the Taylor series
    of e^x and compares it with the built-in e^x.
%}  

% main problem function
function Problem7_5()
    % Test function against built-in exp function
    x = 10;      % amount of terms to be tested
    
    % for loop to iterate through x terms
    for i = 1:x
        
        % error between built-in value and computed value
        error = exp(i) - calcExp(i);
    
        % display results
        fprintf('x = %d: calcExp(x) = %.16f, exp(x) = %.16f, ERROR = %.16f\n', i, calcExp(i), exp(i), error);
        
    end
end

% function for computed e^x from Taylor series 
function y = calcExp(x)
% Compute e^x until last term is less than 10^-6
    terms = 1;      % terms in the series -- starting term
    y = terms;      % set y to hold the approximation of e^x
    n = 1;          % factorial terms

    % while loop to go on until current term is less than 10^-6 precision
    while abs(terms) >= 10e-6       % 10^-6 precision
        terms = terms * x / n;      % terms calculated by multiplying previous terms by x/n      
        y = y + terms;              % adds terms to y 
        n = n + 1;                  % increment to next term in series
    end
end
