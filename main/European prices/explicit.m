% Read data from the CSV file
data = csvread('build/option_prices.csv', 1, 0);

% Extract columns
K = data(:, 1);
T = data(:, 2);
Price = data(:, 3);

% Create a 3D plot
figure;
scatter3(K, T, Price, 'filled');
xlabel('K');
ylabel('T');
zlabel('Price');
title('European Put Option Prices');
grid on;
