function lagrange()
    % setup (function would be in place of this)
    disp("values (x,y):");
    x_values = [-2, -1, 0, 4];
    disp(x_values);
    y_values = [-2, 4, 1, 8];
    disp(y_values);

    disp("getting:")
    % output vector that contains lagrange coefficients in the expansion
    coeffs = lagrangeInter(skip, x_values, y_values);
    disp(coeffs);
    % output value of function at xi
    val_xi = lagrangeInterEval(x_values, y_values, 2);
    disp(val_xi);
end

%--------------------------------------------------------------------------

function Lj = lagrangeInter(j, x, xi)
    % This function calculates the Lagrange coefficient L_j(x) for a given index j
    % and a set of distinct points x0, x1, ..., xn.
    
    n = length(x);  % degree of the polynomial
    
    % Compute the product of factors (x-x_i)/(x_j-x_i) for i=0,1,...,n, i!=j
    Lj = 1;
    for i = 1:n
        if i ~= j
            Lj = Lj .* (xi - x(i)) / (x(j) - x(i));
        end
    end
end

%--------------------------------------------------------------------------

function lagrangeInterEval(x, y, xi)
    % This function evaluates the polynomial that interpolates the data points
    % (x0,y0), (x1,y1), ..., (xn,yn) at the point xi using Lagrange's method.
    
    n = length(x);  % degree of the polynomial
    
    % Compute the Lagrange coefficients
    val = 0;
    for j = 1:n
        Lj = lagrangeInter(j, x, xi);
        val = val + y(j) * Lj;
    end
end