% PART A: generate time vector to cover a range of t
% time vector that will go through two cycles of a 4000Hz sinusoid
% this represents the x-value for the plots
tt = -0.00025 : 0.00001 : 0.00025;

% 3.2
% zz = real(21*exp(j*-0.8 * pi)*exp(j* 8000 * pi * tt))
% 
% 
% plot( tt, zz, 'b-'), grid on
% title('Sinusoid 1')
% xlabel('time (sec)')
% ylabel('x_1(t)')

% PART B: generate two 4000 Hz sinusoids
% amplitudes: A_1 = user's age, A_2 is a constant given in lab
A_1 = 21
A_2 = 1.2 * A_1

% T = period of the sinusoids, D,M = day,month of user's birthday
T = 0.00025
D = 21
M = 3

% time shifts (formulas given in lab)
t_m1 = (37.2 / M) * T
t_m2 = -(41.3 / D) * T

% x(t) = cos(2pi(4000)(t-t_m)   formula given in lab
% this represents the y-value for the plots
x_1 = A_1 * cos((2*pi *4000) * (tt - t_m1))
x_2 = A_2 * cos((2*pi *4000) * (tt - t_m2))
% PART C: summing the vectors that hold the values of each sinusoid
x_3 = x_1 + x_2

% PART D: adding details to the plots
subplot(3, 1, 1)
plot( tt, x_1, 'b-'), grid on
title('Sinusoid 1')
xlabel('time (sec)')
ylabel('x_1(t)')

subplot(3, 1, 2)
plot(tt, x_2, 'r--'), grid on
title('Sinusoid 2')
xlabel('time (sec)')
ylabel('x_2(t)')

subplot(3, 1, 3)
plot(tt, x_3, 'g--o'), grid on
title('Sinusoid 3')
xlabel('time (sec)')
ylabel('x_3(t)')



% BELOW IS CODE FROM 2.2(d) USED AS REFERENCE
% tt = -1 : 0.01 : 1;
% xx = cos( 5*pi*tt );
% zz = 1.4*exp(j*pi/2)*exp(j*5*pi*tt);
% plot( tt, xx, 'b-' , tt, real(zz), 'r--' ), grid on %<--- plot a sinusoid
% title('TEST PLOT of a SINUSOID')
% xlabel('TIME (sec)')
