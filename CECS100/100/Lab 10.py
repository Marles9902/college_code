print("Marwin Gonzales")
print("Chapter 5 Exercises 1-5")

print("")

print("Exercise 5-1")
# main function
def main():
    # variable
    kilometers = 0.0
    # get input
    kilometers = float(input("Enter a distance in kilometers: "))
    # call function
    showMiles(kilometers)

# function converting kilometers to miles
def showMiles(kilometers):
    # calculate miles
    miles = kilometers * 0.6214
    # print outputs
    print("The conversion of", format(kilometers, ',.2f'), "kilometers")
    print("to miles", format(miles, ',.2f'), "miles")

main()

print("")

print("Exercise 5-2")
# main function
def main():
    # variable
    purchase = 0.0
    # get input
    purchase = float(input("Enter the amount of the purchase: "))
    # call function
    showSale(purchase)

# function to show sales
def showSale(purchase):
    # calculation of sales
    stateTax = purchase * 0.05
    countyTax = purchase * 0.025
    totalTax = stateTax + countyTax
    totalSale = purchase + totalTax
    # printing sales
    print("Purchase Amount: $", format(purchase, ',.2f'), sep='')
    print("State Tax: $", format(stateTax, ',.2f'), sep='')
    print("County Tax: $", format(countyTax, ',.2f'), sep='')
    print("Total Tax: $", format(totalTax, ',.2f'), sep='')
    print("Sale Total: $", format(totalSale, ',.2f'), sep='')

main()

print("")

print("Exercise 5-3")
# main function 
def main():
    # variable
    replaceCost = 0.0
    # get input
    replaceCost = float(input("Enter the replacement cost of a building: "))
    # call function
    showInsure(replaceCost)

# function to show insures
def showInsure(replaceCost):
    # calculate minimum insurance
    insurance = replaceCost * .8
    # print outputs
    print("Replacement cost: $", format(replaceCost, ',.2f'), sep='')
    print("Percent insured: 80%")
    print("Minimum insurance: $", format(insurance, ',.2f'), sep='')

main()

print("")

print("Exercise 5-4")
# main function
def main():
    # variables
    loan = 0.0
    insurance = 0.0
    gas = 0.0
    oil = 0.0
    tires = 0.0
    maintenance = 0.0
    # get input
    loan = float(input("Enter the monthly loan amount: "))
    insurance = float(input("Enter the monthly insurance amount: "))
    gas = float(input("Enter the monthly gas amount: "))
    oil = float(input("Enter the monthly oil amount: "))
    tires = float(input("Enter the monthly tires amount: "))
    maintenance = float(input("Enter the monthly maintenance amount: "))
    # call function
    showExpenses(loan, insurance, gas, oil, tires, maintenance)

# function to show expenses
def showExpenses(loan, insurance, gas, oil, tires, maintenance):
    # calculate monthly and yearly expenses
    monthly = loan + insurance + gas + oil + tires + maintenance
    yearly = monthly * 12
    # print output
    print("Total monthly expense: $", format(monthly, ',.2f'), sep='')
    print("Total yearly expense: $", format(yearly, ',.2f'), sep='')

main()

print("")

print("Exercise 5-5")
# main function
def main():
    # variable
    actualValue = 0.0
    # get input
    actualValue = float(input("Enter the actual value of a piece of property: "))
    # call function
    showPropertyTax(actualValue)

# function to show property tax
def showPropertyTax(actualValue):
    # calculate assessment value and property tax
    assessedValue = actualValue * .6
    propertyTax = assessedValue * .0072
    # print outputs
    print("Assessed value: $", format(assessedValue, ',.2f'),sep='')
    print("Property tax: $", format(propertyTax, ',.2f'), sep='')

main()