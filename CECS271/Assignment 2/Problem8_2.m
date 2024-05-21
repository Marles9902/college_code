%{  
Name: Problem 8.2
Date: 02/20/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Use various series to compute the value of pi with a degree of
efficiency and precision and compare it to the built-in pi function.
%}  

% main function that computes pi for parts a, b, and c 
function Problem8_2()
    % global number of iterations for all the parts
    n = 100;
    % print value of pi to use for comparison
    fprintf("built-in PI:    %.16f\n", pi);
    
    % PART A
    estimate_a = 0;
    % iterate through every number from 1 to n
    for i = 1:n
        % alternate the signs
        sign = (-1)^(i-1);
        % simplest series: pi/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
        estimate_a = estimate_a + (sign/(2*i-1));
    end
    
    % pi = pi/4 * 4
    estimate_a = estimate_a * 4;
    % print computation and error from true value
    fprintf("PI of part a:   %.16f", estimate_a);
    fprintf("     true error of part a: %.16f\n", pi - estimate_a);


    
    %--------------------------------------------------------------------------
    
    % PART B
    estimate_b = 0;
    % iterate through every number from 1 to n
    for i = 1:n
        % speed up convergence: pi/8 = 1/(1*3) + 1/(5*7) + 1/(9*11) + ...
        estimate_b = estimate_b + (1/((4*i - 3)*(4*i - 1)));
    end
    
    % pi = pi/8 * 8
    estimate_b = estimate_b * 8;
    % print computation and error from true value
    fprintf("PI of part b:   %.16f", estimate_b);
    fprintf("     true error of part b: %.16f\n", pi - estimate_b);
    
    %--------------------------------------------------------------------------
    
    % PART C
    % one of the fast series: pi/4 = 6arctan(1/8) + 2arctan(1/57) + arctan(1/239)
    % compute by calling the function: arctan(x)
    estimate_c = 6*arctan(n, 1/8) + 2*arctan(n, 1/57) + arctan(n, 1/239);
    % pi = pi/4 * 4
    estimate_c = estimate_c * 4;
    % print computate and error from true value
    fprintf("PI of part c:   %.16f", estimate_c);
    fprintf("     true error of part c: %.16f\n", pi - estimate_c);
end

% function that replicates arctan(x)
function y = arctan(n,x)
    estimate_arctan = 0;
    % iterate through every number from 1 to n
    for i = 1:n
        % alternate the signs
        sign = (-1)^(i-1);
        % arctan(x) = x - x^3/3 + x^5/5 - x^7/7 + x^9/9 - ...
        % separated equation for clarity
        numerator = x^(2*i - 1);
        denominator = 2*i - 1;
        estimate_arctan =  estimate_arctan + (sign * numerator / denominator);
        y = estimate_arctan;
    end
    
end

