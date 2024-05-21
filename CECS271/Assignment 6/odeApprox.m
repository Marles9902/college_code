f = @(x, y) 2 - exp(-4*x) - 2*y;
x_start = 0;
x_end = 5;
y_start = 1;
N = 20;     % other: 20, 40, 50, 70

euler_solution = euler_ode1(f, x_start, x_end, y_start, N);
disp(euler_solution);
