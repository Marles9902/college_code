%{  
Name: Mexican Hat Animation modified -- Problem 1.2
Date: 02/08/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Modified version of the Mexican Hat animation according to problem  
Last updated: 02/08/2023  
%}  

% ----MODIFIED FROM A PREVIOUS CODE FOUND IN THE BOOK----

% create a 2D mesh grid from -8 to 8, in steps of 0.5
[x, y] = meshgrid(-8 : 0.5 : 8);

% calculate square root of these sum of squares 
r = sqrt(x.^2 + y.^2) + eps;

% for loop that iterates and plots 3D surface, creating an animation as it 
% plays out
for n = -3 : 0.1 : 4   % original max value was 3, changed to 4
    %z = sin(r.*n) ./ r;  --- original 
    z = cos(r.*n);      % --- new
    surf(z), view(-37, 38), axis([0, 40, 0, 40, -4, 4]);
    pause(0.05) % original delay was 0.1, changed to 0.05
end
