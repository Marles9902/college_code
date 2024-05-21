
%{
function ODEtest

    % Define the differential equation f(x,y)
    f = @(x,y) x*y^2;
    
    % Define the starting and ending values of x, the starting value of y, and the number of steps
    x_start = 0;
    x_end = 1;
    y_start = 1;
    N = 10;
    
    % Call the euler_ode1 function with the inputs
    [x, y] = euler_ode1(f, x_start, x_end, y_start, N);
    
    % Plot the results
    plot(x, y);
    xlabel('x');
    ylabel('y');
    title('Euler''s method for y'' = x*y^2');

end
%}

function [x, y] = josh_euler(f, x_start, x_end, y_start, N)

% Compute step size
h = (x_end - x_start) / N;

% Initialize x and y vectors
x = zeros(N+1, 1);
y = zeros(N+1, 1);
x(1) = x_start;
y(1) = y_start;

% Perform Euler's method
for i = 1:N
    y(i+1) = y(i) + h*f(x(i), y(i));
    x(i+1) = x(i) + h;
end

end

