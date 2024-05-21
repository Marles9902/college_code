%{  
Name: Electricity Bill -- Problem 5.7
Date: 02/05/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Calculate electricity bills from the units consumed utilizing logical vectors 
Last updated: 02/07/2023  
%}  

% vector for the amount of electricity used by each resident
use = [200 500 700 1000 1500];

% calculate cost for each resident
cost = zeros(1, length(use)); % vector for cost initialized to 0 and spans length of "use" vector  
basicFee = 5; % basic service fee of $5 

% for those using 500 or less units of electricity -- $0.02
cost(use <= 500) = use(use <= 500) * 0.02; 

% for those using 500 > x <= 1000 units -- $10 for first 500, $0.10 for every unit after in excess
cost((use > 500) & (use <= 1000)) = 10 + (use(use > 500 & use <= 1000) - 500) * 0.05;

% for those using 1000 or more units -- $35 for first 1000, $0.10 for every after in excess
cost(use > 1000) = 35 + (use(use > 1000) - 1000) * 0.1;

% add the service fee of $5
cost = cost + basicFee;

% display results
fprintf('Electricity Units (units)\tAmount Billed ($)\n')
for i = 1:length(use)
    fprintf('\t\t%0.2f\t\t\t\t\t$%0.2f\n', use(i), cost(i))
end

