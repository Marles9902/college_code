% Define the function
f = @(x) x./(x.^4 + 1);

% Task 1: Evaluate the value of f(x) for x = -2 : 0.01 : 2
x = -2:0.01:2;
y = f(x);

% Task 2: Interpolate 5 random points using Newton's and Lagrange's Interpolation
rng(1); % Set the random seed for reproducibility
x_interp = linspace(-2, 2, 5);
y_interp = f(x_interp);

% Interpolate using Newton's Divided Differences
a_newton = newtonInter(x_interp, y_interp);
display(x_interp)
display(y_interp)
y_newton = newtonInterEval(x_interp, y_interp, x);

% Interpolate using Lagrange's Interpolation
y_lagrange = zeros(size(x));
for i = 1:length(x)
    y_lagrange(i) = lagrangeInterEval(x_interp, y_interp, x(i));
end

% Plot the results
figure;
plot(x, y, 'k-', 'LineWidth', 2);
hold on;
plot(x_interp, y_interp, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 8);
plot(x, y_newton, 'b--', 'LineWidth', 1.5);
plot(x, y_lagrange, 'm-.', 'LineWidth', 1.5);
legend('f(x)', 'Interpolation points', 'Newton', 'Lagrange', 'Location', 'SouthEast');
xlabel('x');
ylabel('y');
title('Interpolation of 5 random points on f(x)');

% Task 3: Interpolate 11 random points using Newton's and Lagrange's Interpolation
rng(2); % Set another random seed for reproducibility
x_interp = linspace(-2, 2, 11);
y_interp = f(x_interp);

% Interpolate using Newton's Divided Differences
a_newton = newtonInter(x_interp, y_interp);
y_newton = newtonInterEval(x_interp, y_interp, x);

% Interpolate using Lagrange's Interpolation
y_lagrange = zeros(size(x));
for i = 1:length(x)
    y_lagrange(i) = lagrangeInterEval(x_interp, y_interp, x(i));
end

% Plot the results
figure;
plot(x, y, 'k-', 'LineWidth', 2);
hold on;
plot(x_interp, y_interp, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 8);
plot(x, y_newton, 'b--', 'LineWidth', 1.5);
plot(x, y_lagrange, 'm-.', 'LineWidth', 1.5);
legend('f(x)', 'Interpolation points', 'Newton', 'Lagrange', 'Location', 'SouthEast');
xlabel('x');
ylabel('y');
ylim([-2 16]);
title('Interpolation of 11 random points on f(x)');