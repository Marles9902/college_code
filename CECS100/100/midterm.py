# Variables to hold the values, sum, difference, and product

firstValue = 0.0

secondValue = 0.0

sum = 0.0

difference = 0.0

product = 0.0

# Get the first value

firstValue = float(input("Enter first value: "))

# Get the second value

secondValue = float(input("Enter second value: "))

# Calculate the sum of the two values

sum = firstValue + secondValue

# Calculate the difference of the two values

difference = secondValue - firstValue

# Calculate the product of the two values

product = firstValue * secondValue

# Print the sum, difference, and product

print("The sum is:", format(sum, '.2f'))

print("The difference is:", format(difference, '.2f'))

print("The product is:", format(product, '.2f'))