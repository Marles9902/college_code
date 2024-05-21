%{  
Name: Find Root Main
Date: 03/10/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This file calls the implemented methods of finding a root to
    find the roots of the function sin(x) + (0.5 * ln(x)) and compare the
    approximations with the built-in MATLAB function of finding a root.
%}    

% define the function and its derivative
% using anonymous function "@x" to define the functions
f = @(x) sin(x) + (0.5*log(x));
df = @(x) cos(x) + (0.5./x);        % derivative for newton-raphson

% set initial intervals/guesses for the root
a = 0.25;          % [a,b] for bisection
b = 1;
x0 = 0.25;       % x0 and x1 for newton-raphson and secant
x1 = 1;
tol = 10e-6;     % set tolerance to 10e-6
maxIter = 100;  % go for 100 max possible iterations

% use bisection method to find root
[rootB, errB, xB] = bisec(f, a, b, tol, maxIter);

% use Newton-Raphson method to find root
[rootNR, fxNR, xNR] = newraph(f, df, x0, tol, maxIter);

% use secant method to find root
[rootS, fxS, xS] = secant(f, x0, x1, tol, maxIter);

% use built-in MATLAB function to find root
rootExact = fzero(f, x0);

% TABLES OF PROGRESS:

% BISECTION
fprintf('BISECTION PROGRESS:\n')
fprintf('Iterations\tApproximation\t\t\tf(Approximation)\n');
fprintf('-------------------------------------------------------------\n');
for i = 1:length(xB)
    fprintf('%d\t\t\t%.16f\t\t%.16f\n', i-1, xB(i), errB(i));
end

% NEWTON-RAPHSON
fprintf('NEWTON-RAPHSON PROGRESS:\n')
fprintf('Iterations\tApproximation\t\t\tf(Approximation)\n');
fprintf('-------------------------------------------------------------\n');
for i = 1:length(xNR)
    fprintf('%d\t\t\t%.16f\t\t%.16f\n', i-1, xNR(i), fxNR(i));
end

% SECANT 
fprintf('SECANT PROGRESS:\n')
fprintf('Iterations\tApproximation\t\t\tf(Approximation)\n');
fprintf('-------------------------------------------------------------\n');
for i = 1:length(xS)
    fprintf('%d\t\t\t%.16f\t\t%.16f\n', i-1, xS(i), fxS(i));
end

% print table with roots and error difference b/w exact and approximations
fprintf('\nMethod\t\t\tRoot\t\t\t\t\tError\n');
fprintf('-------------------------------------------------------------\n');
fprintf('Built-in\t\t%.16f\t\t%.16f\n', rootExact, abs(rootExact - rootExact));
fprintf('Bisection\t\t%.16f\t\t%.16f\n', rootB, abs(rootB - rootExact));
fprintf('Newton-Raphson\t%.16f\t\t%.16f\n', rootNR, abs(rootNR - rootExact));
fprintf('Secant\t\t\t%.16f\t\t%.16f\n\n', rootS, abs(rootS - rootExact));