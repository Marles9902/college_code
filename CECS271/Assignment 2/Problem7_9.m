%{  
Name: Problem 7.9
Date: 02/20/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Use recursive functions to generate Legendre polynomials given P0
    and P1 to compute P2 and compare it using the analytical form of P2.
%}  

% main function to call the Legendre Polynomial p function
function Problem7_9()
    % want to compute p(2,x)
    subsc = 2;
    % array of random x values
    x_list = [94.94 18.80 80.25 55.56 92.69 76.76 29.62 35.44 93.40 13.59];
    disp("x values: 94.94 18.80 80.25 55.56 92.69 76.76 29.62 35.44 93.40 13.59")
    % iterate through each x value of array
    for i = 1:length(x_list)
        % assign each value as x 
        x = x_list(i);
        % compute p(2,x) using general recurrence formula
        general_answer = p(subsc,x);
        % compute p(2,x) using analytic formula given in problem
        formula_answer = (3*(x^2) - 1)/2;
        % print both answers
        fprintf("General Legendre Polynomial: %.4f", general_answer)
        fprintf("     Formula Legendre Polynomial: %.4f\n", formula_answer);
    end
end

% function for the general recurrence formula for Legendre polynomials
function y = p(n,x)
    % p(0,x) = 1
    if n == 0
        y = 1;
    % p(1,x) = x
    elseif n == 1
        y = x;
    % p(2,x) = (n+1)*p(n+1,x) - (2*n+1)*x*p(n,x) + n*p(n-1,x);
    % reaaranged to better fit the arguments
    else
        y = ((2*n-1)*x*p(n-1,x) - (n-1)*p(n-2,x)) / n;
    end
end
