print("Marwin Gonzales")
print("Partner: Varune Tomar")
print("Chapter 3 Exercises 1-5")

print("")

print("Exercise 3-1")
# Get the number 
dayNumber = int(input("Enter a number (1-7) for the day of the week: "))
# Statements for each number with corresponding day of the week
if dayNumber == 1:
    print("Monday")
elif dayNumber == 2:
    print("Tuesday")
elif dayNumber == 3:
    print("Wednesday")
elif dayNumber == 4:
    print("Thursday")
elif dayNumber == 5:
    print("Friday")
elif dayNumber == 6:
    print("Saturday")
elif dayNumber == 7:
    print("Sunday")
# Error message if user does not input a number 1-7
else:
    print("ERROR: Please enter a number in the range 1-7")

print("")

print("Exercise 3-2")
# Get the length and width of the first rectangle
first_length = float(input("Enter the length for the first rectangle: "))
first_width = float(input("Enter the width for the first rectangle: "))
# Calculate the area of the first rectangle
first_area = first_length * first_width
# Get the length and width of the second rectangle
second_length = float(input("Enter the length for the second rectangle: "))
second_width = float(input("Enter the width for the second rectangle: "))
# Calculate the area of the first rectangle
second_area = second_length * second_width
# Statement if first rectangle has greater area
if first_area > second_area:
    print("The first rectangle has a greater area of", format(first_area, '.2f'), "than the area of the second rectangle of", format(second_area, '.2f'))
# Statement if second rectangle has greater area
elif first_area < second_area:
    print("The second rectangle has a greater area of", format(second_area, '.2f'), "than the area of the first rectangle of", format(first_area, '.2f'))
# Statement if both areas are the same
elif first_area == second_area:
    print("Both rectangles have the same area of", format(first_area, '.2f'))
    
print("")

print("Exercise 3-3")
# Get the age 
age = int(input("Enter your age: "))
# Statement if age is 1 and less
if age <= 1:
    print("You are an infant")
# Statement if age is betwwen 2-12
elif age > 1 and age < 13:
    print("You are a child")
# Statement if age is betwwen 13-19
elif age >= 13 and age < 20:
    print("You are a teenager")
# Statement if age is 20 and older
else:
    print("You are an adult")
    
print("")

print("Exercise 3-4")
# Get the number
number = int(input("Enter a number (1-10): "))
# Statements for each Roman Numeral
if number == 1:
    print("I")
elif number == 2:
    print("II")
elif number == 3:
    print("III")
elif number == 4:
    print("IV")
elif number == 5:
    print("V")
elif number == 6:
    print("VI")
elif number == 7:
    print("VII")
elif number == 8:
    print("VIII")
elif number == 9:
    print("IX")
elif number == 10:
    print("X")
# Error message if user does not enter a number 1-10
else:
    print("ERROR: Please enter a number in the range 1-10")
    
print("")

print("Exercise 3-5")
# Get the mass
mass = float(input("Enter the object's mass: "))
# Calculate the weight
weight = mass * 9.8
# Print weight
print("Object is", format(weight, '.2f'), "newtons")
# Statement if object is too heavy
if weight > 500:
    print("Object is too heavy")
# Statement if object is too light
elif weight < 100:
    print("Object is too light")