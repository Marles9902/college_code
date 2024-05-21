%{  
Name: Plumber Savings -- Problem 2.25
Date: 01/26/2023  
Class: CECS 271  
Student: Joshua Siajuat, Marwin Gonzales, Jason Chan  
Purpose: Display a plumber's savings accounts over the course of a year
    with the current balance, interest rate, interest amount, and the new
    balance.
Last updated: 01/26/2023  
%}  

% known values
balance = 100000;   % current balance - $100,000
deposit = 1000;     % deposits $1000 at the end of each month

% table headers
fprintf('Month\tInterest rate\tInterest\tNew balance\n')

% for loop to go over each month for 12 months
for i = 1:12

    % interest rate changes based on current balance
    if balance <= 110000
        interestRate = 0.01;    % 1%

    elseif balance <= 125000    
        interestRate = 0.015;   % 1.5%
    
    else
        interestRate = 0.02;    % 2%
    
    end

    % calculate interest amount
    interestAmount = balance * interestRate;

    % update current balance with the new balance
    balance = balance + interestAmount + deposit;

    % use an array to group the information for easier formatting
    information = [i, interestRate, interestAmount, balance];
    % display situation at the end of each month 
    for j = 1:length(i)
        fprintf('%d \t\t\t %0.2f \t\t $%0.2f \t $%0.2f \n', information)
    
    end
end
