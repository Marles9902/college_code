% Define the right-hand side of the differential equation
f = @(x, y) 2 - exp(-4*x) - 2*y;

% Define the starting and ending values of x, the starting value of y, and the values of N to use
x_start = 0;
x_end = 5;
y_start = 1;
N_values = [20 40 50 70];

% Initialize matrices to store the results for each value of N
y_values = zeros(length(N_values), max(N_values)+1);
x_values = zeros(length(N_values), max(N_values)+1);

% Solve the differential equation using Euler's method with different values of N
for i = 1:length(N_values)
    N = N_values(i);
    [x, y] = josh_euler(f, x_start, x_end, y_start, N);
    y_values(i, 1:N+1) = y;
    x_values(i, 1:N+1) = x;
end

% Calculate the exact solution
syms x t;
y_exact(x) = (1/2) + (1/2)*exp(-2*x) - (1/2)*exp(-4*x) + (1/2)*exp(-4*x)*int(exp(4*t), t, 0, x);
y_exact_values = double(y_exact(x_values(end,:)));

% Plot the results
figure;
hold on;
plot(x_values(1,:), y_values(1,:), '-o');
plot(x_values(2,:), y_values(2,:), '-o');
plot(x_values(3,:), y_values(3,:), '-o');
plot(x_values(4,:), y_values(4,:), '-o');
plot(x_values(end,:), y_exact_values, '-');
xlabel('x');
ylabel('y');
title('Euler''s method for y'' + 2y = 2 - e^{-4x}, y(0) = 1');
legend('N = 20', 'N = 40', 'N = 50', 'N = 70', 'Exact solution');
set(gca, 'YDir','normal');
hold off;
