print("Marwin Gonzales")
print("Assignment 4 - Chapter 4 Exercise 10-12")

print("")

print("Exercise 10")
# variable holding starting tuition
tuition = 8000.00
# print table for year and tuition
print("Year\t", "Projected Tuition (per semester)")
print("------------------------------------------")
# loop years 1 to 5
for year in range(1,6):
    # calculate tuition after 3% increase each year
    tuition += tuition * .03
    # print year number and tuition totals
    print(year, "\t $", format(tuition, '.2f'), sep='')

print("")

print("Exercise 11")
# variable holding weight
weight = 0.0
# get weight
weight = int(input("Enter your weight in pounds: "))
# print table for end of month and weight
print("------------------------")
print("End of Month\t", "Weight")
print("------------------------")
# loop months 1 to 6
for month in range(1,7):
    # calculate weight loss
    weight -= 4
    # print month number and weight totals
    print(month, "\t\t ", weight, "lbs", sep='')

print("")

print("Exercise 12")
# variables holding number and starting factorial
number = 0
factorial = 1
# get number
number = int(input("Enter a nonnegative integer: "))
# loop to repeat question while 0 or negative
while(number <= 0):
    number = int(input("Enter a nonnegative integer: "))
# loop counting factorial numbers up from 1 to inputed integer
for factor in range(1, number + 1):
    # calculate factorial
    factorial *= factor
# print factorial of number
print("The factorial of", number, "is", factorial)
