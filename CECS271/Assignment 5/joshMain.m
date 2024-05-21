% Define the function to be integrated
f = @(x) x./(x.^4+1);

% Compute the integral from -2 to 2
exact = integral(f, -2, 2);

% Display the result
fprintf('EXACT: \t\t%.16f\n', exact);

% calculate approximate values w/ the methods
trapezoidal = trapezoidalIntegral(f, -2, 2, 100);
simpson = simpsonIntegral(f, -2, 2, 100);

fprintf("TRAPEZOIDAL: \t%.16f\n", trapezoidal);
fprintf("SIMPSON: \t%.16f\n", simpson);

for N = 2:5 % number of points (must be between 2 and 5)
    gauss = nGaussIntegral(f, -2, 2, N);  % calculate the integral
    fprintf('GAUSS: \t\t%.18f\n', gauss);
end