print("Marwin Gonzales")
print("Assignment 1 - Chapter 2 Exercise 12 & 13")

print("")

print("Exercise 12")
# Variables to hold amount for stocks bought and sold, commission for broker after buying and selling stock, and total amount left
stockBought = 0.00
stockSold = 0.00
commissionBought = 0.00
commissionSold = 0.00
moneyLeft = 0.00
# Constants for total shares amount, stockbroker commission, buying price of share, and selling price of share
TOTAL_SHARES = 2000
STOCKBROKER_COMMISSION = 0.03
SHARE_BUY = 40.00
SHARE_SELL = 42.75
# Calculate the amount Joe paid for the stock
stockBought = TOTAL_SHARES * SHARE_BUY
# Calculate the commission paid to broker after buying stock
commissionBought = stockBought * STOCKBROKER_COMMISSION
# Calculate the amount Joe got for selling stocks
stockSold = TOTAL_SHARES * SHARE_SELL
# Calculate the commission paid to broker after selling stock
commissionSold = stockSold * STOCKBROKER_COMMISSION
# Calculate money Joe had left after selling stock and paying broker
moneyLeft = (stockSold - stockBought)-(commissionBought + commissionSold)
# Print all calculations
print("The amount of money Joe paid for the stock: $", format(stockBought, ',.2f'), sep='')
print("The amount of commission Joe paid his broker when he bought the stock: $", format(commissionBought, ',.2f'), sep='')
print("The amount for which Joe sold the stock: $", format(stockSold, ',.2f'), sep='')
print("The amount of commission Joe paid his broker when he sold the stock: $", format(commissionSold, ',.2f'), sep='')
print("The amount of money that Joe had left: $", format(moneyLeft, ',.2f'), sep='')

print("")

print("Exercise 13")
# Variables to hold the number of grapevines, length of the row, amount of space used by an end-post assembly, and amount of space between the vines all in feet
grapevines = 0.0
length = 0.0
spaceAssembly = 0.0
spaceBetween = 0.0
# Get the length of the row
length = float(input("Enter the length of the row (in feet): "))
# Get the amount of space used by an end-post assembly
spaceAssembly = float(input("Enter the amount of space used by an end-post assembly (in feet): "))
# Get the amount space between the vines
spaceBetween = float(input("Enter the amount of space between the vines (in feet): "))
# Calculate the number of grapevines that will fit in the row
grapevines = (length - (2 * spaceAssembly)) / spaceBetween
# Print the number of grapevines that will fit in the row
print(format(grapevines, '.1f'), "grapevines will fit in a row.")