%{
% Define the function to be integrated
f = @(x) x./(x.^4+1);

% Compute the integral from -2 to 2
exact_integral = integral(f, -2, 2);

% Display the result
fprintf('The exact integral is %.16f', exact_integral);
%}



f = @(x) x.^3;  % define your function here
a = -2;  % lower bound
b = 1;  % upper bound

% calculate approximate values w/ the methods
trapezoidal = trapezoidalIntegral(f, a, b, 4);
simpson = simpsonIntegral(f, a, b, 100);

fprintf("TRAPEZOIDAL: \t%.16f\n", trapezoidal);
fprintf("SIMPSON: \t%.16f\n\n", simpson);

for N = 2:5 % number of points (must be between 2 and 5)
    val = joshGauss(f, a, b, N);  % calculate the integral
    fprintf('GAUSS: %.18f\n', val);
end