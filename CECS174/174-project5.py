# function that prompts user for Roman Numerals and returns valid number
def getRomanN():
    romNum = input().upper()
    # loop that keeps asking for valid input until given calling on isValidRoman to check 
    while(not isValidRoman(romNum)):
        romNum = input("Please enter a valid roman number: ").upper()
    return romNum

# function that takes Roman Numerals and returns True if valid, False otherwise
def isValidRoman(roman):
    # loop through the lenghth of the string of Roman Numerals
    for i in range(len(roman)):
        # checks if each Roman Numeral is a valid input returning True
        if((roman[i] =='I') or (roman[i] =='V') or (roman[i] =='X') or (roman[i] =='L') or (roman[i] =='C')):
            return True
    return False

# added function used in romanToArabic to return correct value for respective Roman Numerals
def valueOfRN(roman):
    # if branches returning values
    if (roman == 'I'):
        return 1
    if (roman == 'V'):
        return 5
    if (roman == 'X'):
        return 10
    if (roman == 'L'):
        return 50
    if (roman == 'C'):
        return 100

# function that takes Roman Numerals and returns the number in Arabic symbols
def romanToArabic(roman):
    # variable placeholders
    arabicNum = 0
    i = 0
    # loops throughout the length of the Roman Numeral
    while(i < len(roman)):
        # value placeholder for the first Roman Numeral using valueOfRN as a guide
        value1 = valueOfRN(roman[i])
        # checks if the Roman Numeral is longer 
        if((i + 1) < len(roman)):
            # value placeholder for the second Roman Numeral using valueOfRN as a guide
            value2 = valueOfRN(roman[i + 1])
            # branch checking for any "subtraction rule" Roman Numerals
            if value1 >= value2:
                arabicNum = arabicNum + value1
                i += 1
            else:
                arabicNum += (value2 - value1)
                i += 2
        else:
            arabicNum += value1
            i += 2
    return arabicNum

# function that takes the number in Arabic symbols and return its equivalent Roman Numerals
def arabicToRoman(arabic):
    # lists holding Roman Numerals and their respective values
    numeralValue = [1, 4, 5, 9, 10, 40, 50, 90, 100]
    numeral = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C"]
    # placeholder to start at the end of the list
    location = 8
    # assigning variable as a string to keep as Roman Numeral 
    romanNumeral = ""
    # loop using floor and modulo divison to check if the location of the list is valid
    while arabic:
        check = arabic // numeralValue[location]
        arabic %= numeralValue[location]
        # while the floor division is a number more than 0, it adds the respective "location" Numeral
        while check:
            romanNumeral += numeral[location]
            check -= 1
        # go down the list
        location -= 1
    return romanNumeral

# function that takes two roman numerals and returns the result of their summation in Roman Numerals
def add(roman1, roman2):
    arabicNum1 = romanToArabic(roman1)
    arabicNum2 = romanToArabic(roman2)
    sumRoman = arabicToRoman(arabicNum1 + arabicNum2)
    print(roman1, "+", roman2, "=", sumRoman)
    sumArabic = arabicNum1 + arabicNum2
    print(arabicNum1, "+", arabicNum2, "=", sumArabic)

# function that takes two roman numerals and returns the result of their difference in Roman Numerals
def sub(roman1, roman2):
    arabicNum1 = romanToArabic(roman1)
    arabicNum2 = romanToArabic(roman2)
    # checks if the first number is bigger, carrying out the correct procedure for subtraction
    if arabicNum1 > arabicNum2:
        differenceRoman = arabicToRoman(arabicNum1 - arabicNum2)
        print(roman1, "-", roman2, "=", differenceRoman)
        differenceArabic = arabicNum1 - arabicNum2
        print(arabicNum1, "-", arabicNum2, "=", differenceArabic)
    elif arabicNum1 < arabicNum2:
        differenceRoman = arabicToRoman(arabicNum2 - arabicNum1)
        print(roman2, " - ", roman1, " = ", "-",differenceRoman, sep='')
        differenceArabic = arabicNum1 - arabicNum2
        print(arabicNum1, "-", arabicNum2, "=", differenceArabic)

# function that takes two roman numerals and returns the result of their product in Roman Numerals
def mul(roman1, roman2):
    arabicNum1 = romanToArabic(roman1)
    arabicNum2 = romanToArabic(roman2)
    productRoman = arabicToRoman(arabicNum1 * arabicNum2)
    print(roman1, "*", roman2, "=", productRoman)
    productArabic = arabicNum1 * arabicNum2
    print(arabicNum1, "*", arabicNum2, "=", productArabic)

# function that takes two roman numerals and returns the result of their quotient in Roman Numerals
def div(roman1, roman2):
    arabicNum1 = romanToArabic(roman1)
    arabicNum2 = romanToArabic(roman2)
    quotientRoman = arabicToRoman(arabicNum1 // arabicNum2)
    remainderRoman = arabicToRoman(arabicNum1 % arabicNum2)
    # checks if the remainder is 0 or not, printing the correct output
    if (arabicNum1 % arabicNum2) != 0:
        print(roman1, "/", roman2, "=", quotientRoman, "with remainder of", remainderRoman)
    else:
        print(roman1, "/", roman2, "=", quotientRoman, "with no remainder")
    quotientArabic = arabicNum1 // arabicNum2
    remainderArabic = arabicNum1 % arabicNum2
    print(arabicNum1, "/", arabicNum2, "=", quotientArabic, "with remainder of", remainderArabic)

# function that outputs the menu only
def menu():
    print(
        "Please select from the following: \n"
        "\n"
        "A - Add two Roman Numerals \n"
        "S - Subtract two Roman Numerals \n"
        "M - Multiply two Roman Numerals \n"
        "D - Divide two Roman Numerals \n"
        "Q - Quit\n"
        )

# main code that calls other functions
def main():
    print("Welcome to the Roman Numerals Calculator")
    # looping the choice of the menu until it is valid
    loop = True
    while(loop):
        print()
        # call menu function
        menu()
        # prompt the user for menu input
        choice = input("Select A, S, M, D or Q only: ").upper()
        print()
        # checks whether the menu input is valid and if it is, it will call getRomanN to make sure the Roman Numerals are valid
        if (choice == "A") or (choice == "S") or (choice == "M") or (choice == "D"):
            # prints Roman Numerals value in Arabic symbols
            print("Enter First Roman Number (no spaces): ")
            roman1 = getRomanN()
            print("Value of ", roman1, ": ", romanToArabic(roman1), sep='')
            print("Enter Second Roman Number (no spaces): ")
            roman2 = getRomanN()
            print("Value of ", roman2, ": ", romanToArabic(roman2), sep='')
            # addition
            if(choice == "A"):
                add(roman1, roman2)
            # subtraction
            elif(choice == "S"):
                sub(roman1, roman2)
            # multiplication 
            elif(choice == "M"):
                mul(roman1, roman2)
            # divison
            elif(choice == "D"):
                div(roman1, roman2)
        # quits program
        elif(choice == "Q"):
                print("Good Bye.")
                loop = False
        # if input is invalid, loops back to top
        else:
            print("Invalid Entry, Please try again.")

# call main function
main()