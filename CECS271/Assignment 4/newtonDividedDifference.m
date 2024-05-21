function newtonDividedDifference()
    % setup (function would be in place of this)
    disp("values (x,y):");
    x_values = [-2, -1, 0, 4];
    disp(x_values);
    y_values = [-2, 4, 1, 8];
    disp(y_values);

    disp("getting:")
    % output vector that contains coefficients of the nth degree polynomial
    coeffs = newtonInter(x_values, y_values);
    disp(coeffs);
    % output value of function at xi
    val_xi = newtonInterEval(x_values, y_values, 2);
    disp(val_xi);
end

%--------------------------------------------------------------------------

function a = newtonInter(x,y)
    % Error handling for invalid input
    if length(x) ~= length(y)
        error('Input error: x and y vectors must have the same length.')
    end
    
    n = length(x); % number of data points
    
    % Initialize divided difference table
    f = zeros(n, n);
    f(:,1) = y;
    
    % Calculate divided differences recursively
    for j = 2:n
        for i = j:n
            f(i,j) = (f(i,j-1) - f(i-1,j-1)) / (x(i) - x(i-j+1));
        end
    end

    % Extract coefficients of the polynomial
    a = [];
    for k = 1:n
        coeff = f(k,k);
        a = [a, coeff];
    end
end

%--------------------------------------------------------------------------

function val = newtonInterEval(x, y, xi)
    % Error handling for invalid input
    if length(x) ~= length(y)
        error('Input error: x and y vectors must have the same length.')
    end
    
    n = length(x); % number of data points
    
    % Get the coefficients of the polynomial using Newton's Divided Difference method
    a = newtonInter(x, y);
    
    % Evaluate the polynomial at xi
    val = a(n);
    for k = n-1:-1:1
        val = a(k) + (xi - x(k)) .* val;
    end
end