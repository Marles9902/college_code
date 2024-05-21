print("Marwin Gonzales")
print("Partner: Erick Mao-Espinoza")
print("Chapter 3 Exercises 6-8,10")

print("")

print("Exercise 3-6")
# variables
month = 0
day = 0
year = 0
date = 0
# get month, day, and year
month = int(input("Enter the month in numeric form (1-12): "))
day = int(input("Enter the day of the month(1-31): "))
year = int(input("Enter the year in two digit format(00-99): "))
# statement if inputs are valid
if month > 0 and month < 13 and day > 0 and day < 32 and year >= 00 and year <= 99:
    # calculate "magic date" if any
    date = month * day
    # statement if date is magic
    if year == date:
        print("The date is magic")
    else:
        print("The date is not magic")
else:
    print("Invalid input")

print("")

print("Exercise 3-7")
# get the primary colors
first = input("Enter the first primary color in lower case letters: ")
second = input("Enter the second primary color in lower case letters: ")
# statement checking if first primary is valid
if first == "blue" or first == "red" or first == "yellow":
    # statement checking if second primary is valid
    if second == "blue" or second == "red" or second == "yellow":
        #statement for each secondary color
        if first == "blue" and second == "red":
            print("purple")
        elif first == "red" and second == "blue":
            print("purple")
        elif first == "red" and second == "yellow":
            print("orange")
        elif first == "yellow" and second == "red":
            print("orange")
        elif first == "blue" and second == "yellow":
            print("green")
        elif first == "yellow" and second == "blue":
            print("green")
        else:
            print("Nothing happens")
    else:
        print("Invalid second primary color")
else:
    print("Invalid first primary color")
    
print("")

print("Exercise 3-8")
# variables
people = 0
dogsPer = 0
dogsTotal = 0
dogPack = 0
dogLeft = 0
bunPack =0
bunLeft = 0
# constants
DOG_PACK = 10
BUN_PACK = 8
# get
people = int(input("Enter the number of people attending the cookout: "))
dogsPer = int(input("Enter the number of hot dogs for each person: "))
# calculate
dogsTotal = people * dogsPer
# statements
if dogsTotal / DOG_PACK == dogsTotal // DOG_PACK:
    dogPack = dogsTotal // DOG_PACK
    dogLeft = 0
else:
    dogPack = dogsTotal // DOG_PACK + 1
    dogLeft = DOG_PACK - dogsTotal % DOG_PACK
if dogsTotal / BUN_PACK == dogsTotal // BUN_PACK:
    bunPack = dogsTotal // BUN_PACK
    bunLeft = 0
else:
    bunPack = dogsTotal // BUN_PACK + 1
    bunLeft = BUN_PACK - dogsTotal % BUN_PACK
# print results
print("Minimum packages of hot dogs needed:", dogPack)
print("Minimum packages of hot dog buns needed:", bunPack)
print("Hot dogs left over:", dogLeft)
print("Hot dog buns left over:", bunLeft)
      
print("")

print("Exercise 3-10")
# variables
pennies = 0
nickels = 0
dimes = 0
quarters = 0
# constants
PENNY = .01
NICKEL = .05
DIME = .1
QUARTER = .25
# get amount of pennies, nickels, dimes, and quarters
pennies = int(input("Enter the number of pennies: "))
nickels = int(input("Enter the number of nickels: "))
dimes = int(input("Enter the number of dimes: "))
quarters = int(input("Enter the number of quarters: "))
# calculate total of each in money
totalPennies = pennies * PENNY
totalNickels = nickels * NICKEL
totalDimes = dimes * DIME
totalQuarters = quarters * QUARTER
# calculate grand total
total = totalPennies + totalNickels + totalDimes + totalQuarters
# statements if user won or not and how much they entered
if total == 1:
    print("Congratulations! The amount you entered was exactly $1! You won the game!")
elif total > 1:
    print("Sorry, the amount you entered was more than a dollar: $", format(total, '.2f'), sep='')
elif total < 1:
    print("Sorry, the amount you entered was more than a dollar: $", format(total, '.2f'), sep='')