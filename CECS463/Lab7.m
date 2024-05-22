% Define the input signal
xx = 256 * (rem(0:100, 50) < 10);

% Define the FIR filter coefficients
bb = [1, -0.9]; % Coefficients for the FIR filter

% Apply the FIR filter using firfilt
ww = firfilt(bb, xx);

% Given values
r = 0.9;
M = 22;

% Generate the input signal w[n]
fs = 10000;
dt = 1/fs;
T = 0.01; % 10 milliseconds period
tStop = 3;
Amp = 2;

tt = 0:dt:tStop;
qq = rem(tt, T);
w = Amp * (abs(qq - 0.5 * T) - 0.25 * T);

% Generate the FIR filter coefficients r^L
filterCoefficients = r.^(0:M);

% Apply the FIR filter using convolution
y = conv(w, filterCoefficients, 'full');

% Plot the input and output signals
figure;
subplot(2,1,1);
stem(0:length(w)-1, w, 'b', 'LineWidth', 1.5);
title('Input Signal (w[n])');
xlabel('n');
ylabel('w[n]');
grid on;

subplot(2,1,2);
stem(0:length(y)-1, y, 'r', 'LineWidth', 1.5);
title('Output Signal (y[n])');
xlabel('n');
ylabel('y[n]');
grid on;

 
% Plot both input and output waveforms
figure;

% Plot the input signal (xx)
subplot(2,1,1);
stem(0:75, xx(1:76), 'b', 'LineWidth', 1.5);
title('Input Signal (x[n])');
xlabel('n');
ylabel('x[n]');
grid on;

% Plot the output signal (ww)
subplot(2,1,2);
stem(0:75, ww(1:76), 'r', 'LineWidth', 1.5);
title('Output Signal (w[n])');
xlabel('n');
ylabel('w[n]');
grid on;

%------------------------------------------------------------------------
% Define the input signal w[n]
w = firfilt([1, -0.9], xx);

% Define the filter parameters
r = 0.9;
M = 22;

% Generate the filter coefficients h[n] = r^n for 0 <= n <= M
h = r.^(0:M);

% Apply the filter using convolution
y = conv(w, h);

% Trim the result to the same length as the input signal
y = y(1:length(xx));

% error difference
error = xx - y;

% Evaluate the worst-case error
worst_case_error = max(abs(error(1:50)));

% Display the worst-case error
fprintf('Worst-case error: %f\n', worst_case_error);

% Plot the input and output signals
figure;
subplot(3,1,1);
stem(0:75, w(1:76), 'b', 'LineWidth', 1.5);
title('Input Signal (w[n])');
xlabel('n');
ylabel('w[n]');
grid on;

subplot(3,1,2);
stem(0:75, y(1:76), 'r', 'LineWidth', 1.5);
title('Output Signal (y[n])');
xlabel('n');
ylabel('y[n]');
grid on;

subplot(3,1,3);
stem(0:75, y(1:76), 'g', 'LineWidth', 1.5);
title('Error difference');
xlabel('n');
ylabel('Error');
grid on;