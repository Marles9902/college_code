f = @(x) x^3;
a = 4;
b = 5;
N = 4;

trap_val = trapezoidalIntegral(f, a, b, N);
fprintf('trapezoidal: %.16f\n', trap_val);

simp_val = simpsonIntegral(f, a, b, N);
fprintf('simpsons: %.16f\n', simp_val);