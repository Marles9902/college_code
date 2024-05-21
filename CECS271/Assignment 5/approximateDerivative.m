%{  
Name: Approximating Derivates
Date: 04/14/2023
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: This file uses the forward difference, backward difference, and
    central difference to approximate f'(pi/8) with varying step sizes and
    comparing the approximations with the built-in derivative.
%} 
% use anonymous function (@) to define function
f = @(x) x.*cos(x) - sin(x)/x;   

% value to approximate
x = pi/8;

% exact derivative
syms dx;
df = diff(f(dx));
exactDeriv = double(subs(df,dx,x));

% step sizes
h = [0.2, 0.02, 0.002, 0.0002, 0.00002, 0.000002, 0.0000002]; 

% forward difference
fwdDiff = zeros(1, length(h));      % preallocate vector
fwdDiffRErr = zeros(1, length(h));   % preallocate vector
prevFwdDiff = 0;                    % initialize previous approx. for RAE
for i = 1:length(h)
    fwdDiff(i) = (f(x+h(i)) - f(x)) / h(i);
    fwdDiffRErr(i) = abs((fwdDiff(i) - prevFwdDiff)/abs(fwdDiff(i)));
    prevFwdDiff = fwdDiff(i);
end

% backward difference
bckDiff = zeros(1, length(h));
bckDiffErr = zeros(1, length(h));
prevBckDiff = 0;
for i = 1:length(h)
    bckDiff(i) = (f(x) - f(x-h(i))) / h(i);
    bckDiffErr(i) = abs((bckDiff(i) - prevBckDiff)/abs(bckDiff(i)));
    prevBckDiff = bckDiff(i);
end

% central difference
cenDiff = zeros(1, length(h));
cenDiffErr = zeros(1, length(h));
prevCenDiff = 0;
for i = 1:length(h)
    cenDiff(i) = (f(x+h(i)) - f(x-h(i))) / (2*h(i));
    cenDiffErr(i) = abs((cenDiff(i) - prevCenDiff)/abs(cenDiff(i)));
    prevCenDiff = cenDiff(i);
end

% output results -- table of progress
fprintf('EXACT DERIVATIVE: %.16f\n\n', exactDeriv);

% FORWARD DIFFERENCE
fprintf('Forward Difference\n');
fprintf('h\t\tApproximation\t\tRelative Error\n');
fprintf('--------------------------------------------------\n');
for i = 1:length(h)
    fprintf('%.7f\t%.16f\t%.16f\n', h(i), fwdDiff(i), fwdDiffRErr(i));
end
fprintf('\n');

% BACKWARD DIFFERENCE
fprintf('Backward Difference\n');
fprintf('h\t\tApproximation\t\tRelative Error\n');
fprintf('--------------------------------------------------\n');
for i = 1:length(h)
    fprintf('%.7f\t%.16f\t%.16f\n', h(i), bckDiff(i), bckDiffErr(i));
end
fprintf('\n');

% CENTRAL DIFFERENCE
fprintf('Central Difference\n');
fprintf('h\t\tApproximation\t\tRelative Approx. Error\n');
fprintf('------------------------------------------------------------------\n');
for i = 1:length(h)
    fprintf('%.7f\t%.16f\t%.16f\n', h(i), cenDiff(i), cenDiffErr(i));
end
fprintf('\n');

% Comparing true value with approximations
fprintf('Comparison:\n')
fprintf('Method\t\tExact\t\t\tApproximation\t\tTrue Error\n');
fprintf('----------------------------------------------------------------------------------\n');
fprintf('Forward\t\t%.16f\t%.16f\t%.16f\n', exactDeriv, fwdDiff(i), abs((exactDeriv-fwdDiff(i))));
fprintf('Backward\t%.16f\t%.16f\t%.16f\n', exactDeriv, bckDiff(i), abs((exactDeriv-bckDiff(i))));
fprintf('Central\t\t%.16f\t%.16f\t%.16f\n', exactDeriv, cenDiff(i), abs((exactDeriv-cenDiff(i))));

