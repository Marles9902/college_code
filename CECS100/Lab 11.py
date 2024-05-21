print("Marwin Gonzales")
print("Chapter 5 Exercises 6-10")

print("")

print("Exercise 5-6")
# main function
def main():
    # variables
    fatGrams = 0.0
    carbGrams = 0.0
    # get input
    fatGrams = float(input("Enter the fat grams consumed: "))
    carbGrams = float(input("Enter the carbohydrate grams consumed: "))
    # call function
    showCarbs(fatGrams, carbGrams)

#function to show carbs
def showCarbs(fatGrams, carbGrams):
    # calculate calories
    calFat = fatGrams * 9 
    calCarb = carbGrams * 4 
    # print outputs
    print("Grams of fat:", format(fatGrams, '.2f'))
    print("Fat calories:", format(calFat, '.2f'))
    print("Grams of carbs:", format(carbGrams, '.2f'))
    print("Carb calories:",format(calCarb, '.2f'))

main()

print("")

print("Exercise 5-7")
# main function
def main():
    # variables
    countA = 0
    countB = 0
    countC = 0
    # get input
    countA = int(input("Enter count of A seats: "))
    countB = int(input("Enter count of B seats: "))
    countC = int(input("Enter count of C seats: "))
    # call function
    showIncome(countA, countB, countC)

# function to show income
def showIncome(countA, countB, countC):
    # calculate income for each seat and total
    incomeA = countA * 20
    incomeB = countB * 15
    incomeC = countC * 10
    totalIncome = incomeA + incomeB + incomeC
    # print outputs
    print("Income from class A seats: $", format(incomeA, '.2f'), sep='')
    print("Income from class B seats: $", format(incomeB, '.2f'), sep='')
    print("Income from class C seats: $", format(incomeC, '.2f'), sep='')
    print("Total income: $", format(totalIncome, '.2f'), sep='')

main()

print("")

print("Exercise 5-8")
# main function
def main():
    # variables 
    wallSpace = 0.0
    paintPricePerGal = 0.0
    # get input
    wallSpace = float(input("Enter wall space in square feet: "))
    paintPricePerGal = float(input("Enter paint price per gallon: "))
    # call function
    showCost(wallSpace, paintPricePerGal)

# function to show cost
def showCost(wallSpace, paintPricePerGal):
    # calculate gallons of paint, hours of labor, cost of paint, cost of labor, and total cost
    paintGal = round(wallSpace / 112)
    laborHours = paintGal * 8
    paintCost = paintGal * paintPricePerGal
    laborCost = laborHours * 35
    totalCost = paintCost + laborCost
    # print outputs
    print("Gallons of paint:", int(paintGal))
    print("Hours of labor:", int(laborHours))
    print("Paint charges: $", format(paintCost, '.2f'), sep='')
    print("Labor charges: $", format(laborCost, '.2f'), sep='')
    print("Total cost: $", format(totalCost, '.2f'), sep='')

main()

print("")

print("Exercise 5-9")
# main function
def main():
    # variables
    totalSales = 0.0
    # get input
    totalSales = float(input("Enter the total sales for the month: "))
    # call function
    showTaxes(totalSales)

# function to show taxes
def showTaxes(totalSales):
    # calculate taxes
    stateTax = totalSales * .05
    countyTax = totalSales * .025
    totalTax = countyTax + stateTax
    # print outputs
    print("State Tax: $", format(stateTax, '.2f'), sep='')
    print("County Tax: $", format(countyTax, '.2f'), sep='')
    print("Total Tax: $", format(totalTax, '.2f'), sep='')

main()

print("")

print("Exercise 5-10")
# main function
def main():
    # variables
    feet = 0.0
    # get input
    feet = float(input("Enter the number of feet: "))
    # call function
    feet_to_inches(feet)

# function converting feet to inches
def feet_to_inches(feet):
    # calcualte inches
    inches = feet * 12
    # print output
    print(feet, "feet =", inches, "inches")

main()