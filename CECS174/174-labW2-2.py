P = 10000
n = 12
r = 0.08

t = int(input("Enter the number of years that the money will be compounded for: "))

A = P * (1 + r / n) ** (n * t)

print("The final amount after ", t, " years is: $", format(A, '.2f'), sep='')
