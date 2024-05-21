# constants
ZERO = 0
TEN = 10

# get user integer 
num = int(input("Please enter an integer (negative integer to quit): "))

# loop until user inputs negative integer
while num >= ZERO:
    # declare and assign variables inside loop so values wont keep changes 
    # assign many variables to user integer to act as placeholders 
    numFinal = num
    addPersistence = 0
    addRoot = num
    multPersistence = 0
    multRoot = num
    digitSum = 0 
    digitProduct = 1
    numAdd = num
    numMult = num

    # check if integer is more than one digit 
    if num >= TEN:
        # loop while additive root is more than one digit 
        while addRoot >= TEN:
            # loop while the additive number placeholder is not zero 
            while numAdd !=0:
                # adds each digit of the integer by using modulo divison to check the last digit  
                digitSum += (numAdd % TEN)
                # takes the last digit of the integer out
                numAdd //= TEN
            # assign additive root to the sum of the digits
            addRoot = digitSum
            numAdd = digitSum
            digitSum = 0
            # add one to the additive persistence each time a calculation is taken place 
            addPersistence += 1
        
        # loop while multiplicative root is more than one digit
        while multRoot >= TEN:
            # loop while multiplicative number placeholder is not 0 
            while numMult != 0:
                # multiplies each digit of the integer by using modulo division to check the last digit
                digitProduct *= (numMult % TEN)
                # takes the last digit of the integer out 
                numMult //= TEN
            # assign multiplicative root to the product of the digits 
            multRoot = digitProduct
            numMult = digitProduct
            digitProduct = 1
            # add one to the multiplicative persistence each time a calculation is taken place 
            multPersistence += 1
        
        # print output
        print("For the integer:", numFinal)
        print("Additive Persistence:", addPersistence, "Additive Root:", addRoot)
        print("Multiplicative Persistence", multPersistence, "Multiplicative Root:", multRoot)
        print()

    # branched statement if user enters a single digit integer 
    else:
        # prints output which sets persistence to zero and the roots equal to the user integer
        print("For the integer:", numFinal)
        print("Additive Persistence:", addPersistence, "Additive Root:", addRoot)
        print("Multiplicative Persistence:", multPersistence, "Multiplicative Root:", multRoot)
        print()
    
    # repeat getting user input which cycles back to the top of code until user inputs negative 
    num = int(input("Please enter an integer (negative integer to quit): "))

# goodbye message if user inputs negative 
print("Thanks for playing with numbers... Goodbye")