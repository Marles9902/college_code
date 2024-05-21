print("Marwin Gonzales")
print("Assignment 6 - Chapter 5 Exercise 15,20,21")

print("")

# import random module
import random

print("Exercise 5-15")
# main function
def main():
    # get scores 1-5
    scoreOne = float(input("Enter score 1: "))
    scoreTwo = float(input("Enter score 2: "))
    scoreThree = float(input("Enter score 3: "))
    scoreFour = float(input("Enter score 4: "))
    scoreFive = float(input("Enter score 5: "))
    # table format
    print("score \t\tnumeric grade \tletter grade")
    print("--------------------------------------------")
    # call functions
    determine_grade(scoreOne,scoreTwo,scoreThree,scoreFour,scoreFive)
    calc_average(scoreOne,scoreTwo,scoreThree,scoreFour,scoreFive)

# function to calculate average grade
def calc_average(scoreOne,scoreTwo,scoreThree,scoreFour,scoreFive):
    # calculates average number grade
    average = (scoreOne + scoreTwo + scoreThree + scoreFour + scoreFive) / 5
    # table format
    print("--------------------------------------------")
    # prints average number grade and average letter grade through if statements
    if average >= 90:
        print("Average score:\t", average, "\t\tA")
    elif average >= 80 and average <= 89:
        print("Average score:\t", average, "\t\tB")
    elif average >= 70 and average <= 79:
        print("Average score:\t", average, "\t\tC")
    elif average >= 60 and average <= 69:
        print("Average score:\t", average, "\t\tD")
    elif average < 60:
        print("Average score:\t", average, "\t\tE")

# function to determine letter grade for each score input
def determine_grade(scoreOne,scoreTwo,scoreThree,scoreFour,scoreFive):
    # variable for score number
    count = 0
    # loop through each score
    for x in scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive:
        # counts score up one
        count += 1
        # checking if score gets which letter grade and prints result
        if x >= 90:
            print("score",count, "\t",x, "\t\tA")
        elif x >= 80 and x <= 89:
            print("score",count, "\t",x, "\t\tB")
        elif x >= 70 and x <= 79:
            print("score",count, "\t",x, "\t\tC")
        elif x >= 60 and x <= 69:
            print("score",count, "\t",x, "\t\tD")
        elif x < 60:
            print("score",count, "\t",x, "\t\tF")
    
# call main function
main()

print("")

print("Exercise 5-20")
# main function
def main():
    # generates random number 1-100
    randomNum = random.randint(1,100)
    # get number guess
    guess = int(input("Enter a number between 1 and 100 (0 to quit): "))
    #call function 
    guess_check(randomNum,guess)

# function to check guessed number
def guess_check(randomNum,guess):
    # checks if user wants to quit
    if guess !=0:
        # loops while random number is not the guessed number
        while randomNum != guess:
            # checks if guessed number is higher or lower than random number and prints result and asks for retry
            if guess > randomNum:
                print("Too high, try again")
                guess = int(input("Enter a number between 1 and 100 (0 to quit): "))
            elif guess < randomNum:
                print("Too low, try again")
                guess = int(input("Enter a number between 1 and 100 (0 to quit): "))
        # prints result if number is guessed correctly and asks to try again
        print("Congratulations! You guessed the right number!")
        guess = int(input("Enter a number between 1 and 100 (0 to quit): "))
    # prints when user enters 0 to quit
    print("Thank you for playing!")

# call main function
main()

print("")

print("Exercise 5-21")
# call main function
def main():
    # generates random number 1-3
    comNum = random.randint(1,3)
    # gets number input
    userNum = int(input("Enter 1 for rock, 2 for paper, 3 for scissors: "))
    # call functions
    choices(comNum,userNum)
    rules(comNum,userNum)

# function to determine the choices of both computer and user
def choices(comNum,userNum):
    # prints computer choice if random number is 1-3
    if comNum == 1:
        print("Computer chose rock")
    elif comNum == 2:
        print("Computer chose paper")
    elif comNum == 3:
        print("Computer chose scissors")
    # prints user choice if input number is 1-3
    if userNum == 1:
        print("You chose rock")
    elif userNum == 2:
        print("You chose paper")
    elif userNum == 3:
        print("You chose scissors")

# function checking the rules of the game
def rules(comNum,userNum):
    # checks the conditions of each rule in the rock, paper, scissors game and prints outcome
    if comNum == 1 and userNum == 2:
        print("You win the game")
    elif comNum == 1 and userNum == 3:
        print("The computer wins the game")
    elif comNum == 2 and userNum == 1:
        print("The computer wins the game")
    elif comNum == 2 and userNum == 3:
        print("You win the game")
    elif comNum == 3 and userNum == 1:
        print("You win the game")
    elif comNum == 3 and userNum == 2:
        print("The computer wins the game")
    # statement if computer and user ties and restarts the game from beginning
    else:
        print("You and the computer tied, try again")
        main()

# call main function
main()