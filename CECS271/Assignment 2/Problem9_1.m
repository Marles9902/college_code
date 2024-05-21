% population logistic model
P = @(t) 197273000 ./ (1 + exp(-0.03134*(t-1913.25)));

% time range
t = 1790:1:2000;

% population at each year
pop = P(t);

% actual data (in 1000s)
decades = 1790:10:1950;
data = [3929, 5308, 7240, 9638, 12866, 17069, 23192, ...
    31443, 38558, 50156, 62948, 75995, 91972, 105711, ...
    122775, 131669, 150697];

% plot the results
plot(t, pop)
hold on
scatter(decades, data*1000, 'ro')
xlabel('Year')
ylabel('Population')
title('Population of the USA (1790-2000)')

