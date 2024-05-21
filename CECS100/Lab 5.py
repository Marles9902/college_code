print("Marwin Gonzales")
print("Partner: Jaedon Truong")
print("Week 5 Lab - Chapter 2 Examples 7-11")

print(" ")

print("Example 7")
# Variables to hold the miles, gallons, and mpq
miles = 0.0
gallons = 0.0
mpg = 0.0
# Get the amount of miles driven
miles = float(input("Enter the miles driven: "))
# Get the amount of gallons of fuel used
gallons = float(input("Enter the gallons of fuel used: "))
# Calculate the mpg
mpg = miles / gallons
# Print the mpg
print("You used", format(mpg, '.2f'), "miles per gallon")

print(" ")


print("Example 8")
# Variables to hold price of food, tax, tip, and total
food = 0.0
tax = 0.0
tip = 0.0
total = 0.0
# Constant for tax rate and tip rate
TAX_RATE = 0.07
TIP_RATE = 0.18
# Get the amount charged for food
food = float(input("Enter the charge for food: "))
# Calculate the tip, tax, and total
tip = food * TIP_RATE
tax = food* TAX_RATE
total = food + tip + tax
# Print the tip, tax, and total
print("Tip: $", format(tip, '.2f'))
print("Tax: $", format(tax, '.2f'))
print("Total: $", format(total, '.2f'))


print(" ")


print("Example 9")
# Variables to hold temperatures in Celsius and Fahrenheit
celsius = 0.0
fahrenheit = 0.0
# Get the temperature in Celsius
celsius = float(input("Enter a Celsius temperature: "))
# Calculate temperature in Fahrenheit
fahrenheit = (9.0 / 5.0) * celsius + 32
# Print conversion from Celsius to Fahrenheit
print("That is equal to", format(fahrenheit, '.2f'), "degrees Fahrenheit.")

print(" ")


print("Example 10")
# Variables to hold the amount cookies, sugar, butter, and flour
cookies = 0.0
sugar = 0.0
butter = 0.0
flour = 0.0
# Constant for the amount of cookies, sugar, butter, and flour in the recipe
COOKIES_RECIPE = 48.0
SUGAR_RECIPE = 1.5
BUTTER_RECIPE = 1.0
FLOUR_RECIPE = 2.75
# Get the number of cookies
cookies = int(input("Enter the number of cookies: "))
# Calculate amount of sugar, butter, and flour needed
sugar = (cookies * SUGAR_RECIPE) / COOKIES_RECIPE
butter = (cookies * BUTTER_RECIPE) / COOKIES_RECIPE
flour = (cookies * FLOUR_RECIPE) / COOKIES_RECIPE
# Print the amount of ingredients needed to make the inputed amount of cookies
print("To make", cookies, "cookies, you will need:")
print(format(sugar, '.2f'), "cups of sugar.")
print(format(butter, '.2f'), "cups of butter.")
print(format(flour, '.2f'), "cups of flour.")

print(" ")


print("Example 11")
# Variables to hold number of males, number of females, and total 
male = 0.0
female = 0.0
total = 0.0
# Variables to hold the percentages of males and females
percent_Male = 0.0
percent_Female = 0.0
# Get the amount of males and females
male = int(input("Number of males: "))
female = int(input("Number of females: "))
# Calculate the total
total = male + female
# Calculate the percentages of males and females
percentMale = male / total * 100 
percentFemale = female / total * 100
# Print the percentages of males and females
print("Male:", format(percentMale, '.2f'), "%")
print("Female:", format(percentFemale, '.2f'), "%")