print("Marwin Gonzales")
print("Chapter 4 Exercises 1,3,8")

print("")

print("Exercise 4-1")
# variables
total = 0
# loop getting number of bugs collected for five days
for day in range(5):
    bugs = int(input("Enter the number of bugs collected today: "))
    total += bugs
# display total number of bugs collected
print("Total bugs collected:", total)

print("")

print("Exercise 4-3")
# variables
budget = 0
expense = 0
totalExpense = 0
# get budget
budget = float(input("Enter the amount budgeted for a month: "))
# get first expense
expense = float(input("Enter an amount spent (0 to quit): "))
# loop adding total expenses and getting more expenses (if any)
while expense != 0:
    totalExpense = totalExpense + expense
    expense = float(input("Enter an amount spent (0 to quit): "))
# display total spent
print("Spent: $", format(totalExpense, '.2f'), sep='')
# statements if total spent is over or under budget and by how much
if totalExpense < budget:
    total = budget - totalExpense
    print("You are $", format(total, '.2f',), "under budget. WELL DONE!")
elif totalExpense > budget:
    total = totalExpense - budget
    print("You are $", format(total, '.2f'), "over budget. TOO BAD!")

print("")

print("Exercise 4-8")
# variables
number = 0
totalSum = 0
# loop getting positive numbers and adding the sum
while number >= 0:
    totalSum = totalSum + number
    number = float(input("Enter a positive number (negative to quit): "))
# display total sum
print("Total =", format(totalSum, '.2f'))