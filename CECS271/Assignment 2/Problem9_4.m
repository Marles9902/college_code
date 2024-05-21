% Define the constant angle of divergence d
d = 137.51;

% Define the maximum number of seeds to plot
max_seeds = 1000;

% Initialize the radius and angle arrays
r = zeros(1, max_seeds);
theta = zeros(1, max_seeds);

% Compute the radius and angle for each seed
for n = 1:max_seeds
    r(n) = sqrt(n);
    theta(n) = (pi*d*n)/180;
end

% Plot the seeds as circles
polarplot(theta, r, 'o');

% Add title and labels
title('Sunflower Seed Arrangement');
