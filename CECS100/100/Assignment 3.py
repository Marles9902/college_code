print("Marwin Gonzales")
print("Assignment 3 - Chapter 3 Exercise 15-17")

print("")

print("Exercise 15")
# get number of seconds
seconds = int(input("Enter a number of seconds: "))
# if statements calculating each time 
if seconds >= 60 and seconds < 3600:
    minutes = seconds // 60
    seconds %= 60
    print(minutes, "minutes and", seconds, "seconds")
elif seconds >= 3600 and seconds < 86400:
    hours = (seconds // 3600) % 24
    minutes = (seconds // 60) % 60
    seconds %= 60
    print(hours, "hours,", minutes, "minutes, and", seconds, "seconds")
elif seconds >= 86400:
    days = (seconds // 86400) % 60
    hours = (seconds // 3600) % 24
    minutes = (seconds // 60) % 60    
    seconds %= 60
    print(days, "days", hours, "hours,", minutes, "minutes, and", seconds, "seconds")
else:
    print(seconds, "seconds")

print("")

print("Exercise 16")
# get a year
year = int(input("Enter a year: "))
# statements if it is a leap year or not
if (year % 400) == 0:
    print("February has 29 days and is a leap year in", year)
elif (year % 100) != 0 and (year % 4) == 0:
    print("February has 29 days and is a leap year in", year)
else:
    print("February has 28 days and is not a leap year in", year)

print("")

print("Exercise 17")
print("Reboot the computer and try to connect")
# get a response
response = input("Did that fix the problem? ")
# nested if statments if response is yes or no for each
if response == "yes":
    print("Glad to be of help.")
else:
    print("Reboot the router and try to connect.")
    response = input("Did that fix the problem? ")
    if response == "yes":
        print("Glad to be of help")
    else:
        print("Make sure the cables between the router and modem are plugged in firmly.")
        response = input("Did that fix the problem? ")
        if response == "yes":
            print("Glad to be of help.")
        else:
            print("Move the router to a new location and try to connect.")
            response = input("Did that fix the problem? ")
            if response == "yes":
                print("Glad to be of help.")
            else:
                print("Get a new router.")