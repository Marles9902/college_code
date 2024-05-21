# Marwin Gonzales
# Partner: Erick Mao-Espinoza
# Week 4 Lab - Chapter 2 Examples 2-6

# Example 2
# Variables to hold the sales total and the profit
salesTotal = 0.0
profit = 0.0
# Get the amount of projected sales
salesTotal = float(input("Enter the projected sales: "))
# Calculate the projected profit
profit = salesTotal * .23
# Print the projected profit
print("The projected profit is", format(profit, '.2f'))

print("____________________________________________________________________________")

# Example 3
# Variables to hold the tract size and the acres
tractSize = 0.0
acres = 0.0
# Constant for the number of square feet in an acre
SQ_FEET_PER_ACRE = 43560
# Get the number of square feet in the tract
tractSize = float(input("Enter the number of square feet in the tract: "))
# Calculate the acres 
acres = tractSize / SQ_FEET_PER_ACRE
# Print the number of acres
print("The size of that tract is", format(acres, '.2f'), "acres")

print("____________________________________________________________________________")

# Example 4
# Variables to hold items 1,2,3,4,5, the subtotal,the tax, and the total
item1 = 0.0
item2 = 0.0
item3 = 0.0
item4 = 0.0
item5 = 0.0
subtotal = 0.0
tax = 0.0
total = 0.0
# Constant for the tax rate
TAX_RATE = 0.07
# Get the price of item #1
item1 = float(input("Enter the price of item #1: "))
# Get the price of item #2
item2 = float(input("Enter the price of item #2: "))
# Get the price of item #3
item3 = float(input("Enter the price of item #3: "))
# Get the price of item #4
item4 = float(input("Enter the price of item #4: "))
# Get the price of item #5
item5 = float(input("Enter the price of item #5: "))
# Calculate subtotal of items
subtotal = item1 + item2 + item3 + item4 + item5
# Calculate tax
tax = subtotal * TAX_RATE
# Calculate total
total = subtotal + tax
# Print subtotal
print("Subtotal Tax: $", format(subtotal, '.2f'))
# Print tax
print("Sales Tax: $", format(tax, '.2f'))
# Print total
print("Total: $", format(total, '.2f'))

print("____________________________________________________________________________")

# Example 5
# Variables to hold the distance the car will travel in 6, 10, and 15 hours
distance6Hours = 0.0
distance10Hours = 0.0
distance15Hours = 0.0
# Constant for the speed of the car
SPEED = 70
# Calculate the distance traveled in 6 hours
distance6Hours = SPEED * 6
# Calculate the distance traveled in 10 hours
distance10Hours = SPEED * 10
# Calculate the distance traveled in 15 hours
distance15Hours = SPEED * 15
# Print the distance traveled for each time limit
print("The car will travel the following distances:")
print(format(distance6Hours, '.0f'), "miles in 6 hours")
print(format(distance10Hours, '.0f'), "miles in 10 hours")
print(format(distance15Hours, '.0f'), "miles in 15 hours")

print("____________________________________________________________________________")

# Example 6
# Variables to hold the purchase, state tax, county tax, total tax, and sale total
purchase = 0.0
stateTax = 0.0
countyTax = 0.0
totalTax = 0.0
totalSale = 0.0
# Constant for the state tax rate
STATE_TAX_RATE = 0.05
# Constant for the county tax rate
COUNTY_TAX_RATE = 0.025
# Get the amount of the purchase
purchase = float(input("Enter the amount of the purchase:"))
# Calculate state tax
stateTax = purchase * STATE_TAX_RATE
# Calculate county tax
countyTax = purchase * COUNTY_TAX_RATE
# Calculate total tax
totalTax = stateTax + countyTax
# Calculate sale total
totalSale = purchase +totalTax
# Print purchase amount
print("Purchase Amount:", format(purchase, '.2f'))
# Print state tax
print("State Tax:", format(stateTax, '.2f'))
# Print county tax
print("County TAx:", format(countyTax, '.2f'))
# Print total tax
print("Total Tax:", format(totalTax, '.2f'))
# Print sale total
print("Sale Total:", format(totalSale, '.2f'))