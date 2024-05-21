print("Marwin Gonzales")
print("Assignment 5 - Chapter 5 Excercise 16-18")

print("")

print("Exercise 5-16")
# main function
def main():
    # import random module
    import random
    # variables
    randomNum = 0
    evens = 0 
    odds = 0
    # generating 100 random numbers through loop
    for x in range(100):
        randomNum = random.randint(1,1000)
        # counts random number as even or odd through calling even_odd function
        if even_odd(randomNum):
            evens += 1 
        else:
            odds += 1
    # print result
    print("Out of 100 random numbers,",odds,"were odd, and",evens,"were even")

# function returning true if even and false if odd
def even_odd(randomNum):
    if randomNum % 2 == 0:
        return True
    else:
        return False

# call main function
main()

print("")

print("Exercise 5-17")
# main function
def main():
    # variables
    numInput = 0
    # get number
    numInput = int(input("Enter a number: "))
    # call is_prime function
    is_prime(numInput)

# function to check if inputed number is prime 
def is_prime(numInput):
    # looping through each number from 2 up to inputed number
    for check in range(2, numInput):
        # checks if inputed number is divisible by looped numbers
        if numInput % check == 0:
            print("The number you entered is not a prime number")
            break
    else: 
        print("The number you entered is a prime number")

# call main function
main()

print("")

print("Excercise 5-18")
# main function
def main():
    # start of list
    print("number","\tis prime")
    print("-------------------")
    # using loop to count numbers 1-100
    for prime in range(1,101):
        # call is_prime function
        is_prime(prime)

# function to check if inputed number is prime 
def is_prime(prime):
    for check in range(2, prime):
        if prime % check == 0:
            # checks if inputed number is divisible by looped numbers
            print(prime, "\tnot prime")
            break
    else: 
        print(prime, "\tprime")

# call main function 
main()