print("Marwin Gonzales")
print("Assignment 2 - Chapter 3 Exercise 12,13,14")

print("")

print("Exercise 12")
# Variables for number of packages, subtotal amount, discount amount, and total amount
packages = 0.0
quantityDiscount = 0.0
subtotal = 0.0
discount = 0.0
total = 0.0
# Constant for package retail price
PACKAGE_RETAIL = 99.0
# Get number of packages
packages = int(input("Enter the number of packages purchased: "))
# Calculate subtotal of packages
subtotal = PACKAGE_RETAIL * packages
# Statements if discount is applied
if packages >= 10 and packages <= 19:
    quantityDiscount = .1
elif packages >= 20 and packages <= 49:
    quantityDiscount = .2
elif packages >= 50 and packages <= 99:
    quantityDiscount = .3
elif packages >= 100:
    quantityDiscount = .4
# Calculate discount and total
discount = subtotal * quantityDiscount
total = subtotal - discount
# Print discount and total
print("Discount: $", format(discount, '.2f'), sep='')
print("Total: $", format(total, '.2f'), sep='')

print("")

print("Exercise 13")
# Variables to hold weight of package and shipping charges
weight = 0.0
shipping = 0.0
# Get the weight of package
weight = float(input("Enter the weight of a package (pounds): "))
# Statement for each rate per pound 
if weight <= 2:
    RATE_PER_POUND = 1.50
elif weight > 2 and weight <= 6:
    RATE_PER_POUND = 3.00
elif weight > 6 and weight <= 10:
    RATE_PER_POUND = 4.00
elif weight > 10:
    RATE_PER_POUND = 4.75
# Calculate shipping charges
shipping = weight * RATE_PER_POUND
# Print shipping charges
print("Shipping charges: $", format(shipping, '.2f'), sep='')

print("")

print("Exercise 14")
# Variables to hold weight, height, and BMI
weight = 0.0
height= 0.0
BMI = 0.0
# Get weight and Height
weight = float(input("Enter your weight (pounds): "))
height = float(input("Enter your height (inches): "))
# Calculate BMI
BMI = weight * 703 / height**2
# Print BMI
print("BMI:", format(BMI, '.2f'))
# Statements for each category of BMI
if BMI >= 18.5 and BMI <= 25:
    print("You have optimal weight")
elif BMI < 18.5:
    print("You are underweight")
elif BMI > 25:
    print("You are overweight")