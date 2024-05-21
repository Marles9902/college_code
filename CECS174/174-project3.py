# constants for the limit bounds of meter readings 
UPPER_LIMIT = 999999999
LOWER_LIMIT = 0

# constants for the extra million gallons
FOUR_MIL = 4000000
TEN_MIL = 10000000

# constants for initial bill amount
INITIAL_RES = 5
INITIAL_COM_IND = 1000
INITIAL_IND_EXCEEDED = 2000

# constants to calculate bill amount if extra gallons detected
ADDITIONAL_RES = .0005
ADDITIONAL_COM_IND = .00025

# variables to hold beginning meter reading, ending meter reading, gallons of water used, amount billed, and extra gallon counter
begin = 0 
end = 0 
water = 0 
bill = 0
extra = 0

# condition to keep the whole code looping unless condition is changed
restart = "y"
# looping whole code
while restart == "y" or restart == "Y":

    # get customer code, repeat if input is invalid
    code = str(input("Enter the customer's code: "))
    while (code != "r" and code != "R" and code != "c" and code != "C" and code != "i" and code != "I"):
        print("Invalid entry try again:")
        code = str(input("Enter the customer's code: "))

    # get beginning meter reading, repeat if input is invalid
    begin = int(input("Enter the customer's beginning meter reading: "))
    while (begin < LOWER_LIMIT or begin > UPPER_LIMIT):
        print("Invalid entry try again:")
        begin = int(input("Enter the customer's beginning meter reading: "))

    # get ending meter reading, repeat if input is invalid
    end = int(input("Enter the customer's ending meter reading: "))
    while (end < LOWER_LIMIT or end > UPPER_LIMIT):
        print("Invalid entry try again:")
        end = int(input("Enter the customer's ending meter reading: "))

    # checking if customer code is r or R
    if (code == "r") or (code == "R"):
        # statement if position of end and begin to calculate gallons of water correctly
        if end > begin:
            # calculate gallons used and amount bill
            water = (end - begin) / 10
            bill = INITIAL_RES + (ADDITIONAL_RES * water)
        if end < begin:
            # calculate gallons used and amount bill
            water = ((end - begin) % 10) / 10
            bill = INITIAL_RES + (ADDITIONAL_RES * water)

    # checking if customer code is c or C
    elif (code == "c") or (code == "C"):
        # statement if position of end and begin to calculate gallons of water correctly
        if end > begin:
            # calculate gallons of water used
            water = (end - begin) / 10
            # checking if gallons of water used does not exceed 4 million 
            if water <= FOUR_MIL:
                bill = INITIAL_COM_IND
            else:
                # extra variable countes the extra gallons after 4 million and calculates the bill according to extra gallons
                extra = water - FOUR_MIL
                bill = INITIAL_COM_IND + (extra * ADDITIONAL_COM_IND)
        # statement if position of end and begin to calculate gallons of water correctly
        elif end < begin:
            water = ((end - begin) % 10) / 10
            if water <= FOUR_MIL:
                bill = INITIAL_COM_IND
            else: 
                extra = water - FOUR_MIL
                bill = INITIAL_COM_IND + (extra * ADDITIONAL_COM_IND)

    # checking if customer code is i or I  
    elif (code == "i") or (code == "I"):
        # statement if position of end and begin to calculate gallons of water correctly
        if end > begin:
            water = (end - begin) / 10
            # checking if gallons of water used does not exceed 4 million and assigns amount bill
            if water <= FOUR_MIL:
                bill = INITIAL_COM_IND
            # checking if gallons of water used exceeds 4 million but does not exceed 10 million and assign amount bill
            elif FOUR_MIL < water <= TEN_MIL:
                bill = INITIAL_IND_EXCEEDED
            # checking if gallons of water used exceeds 10 million 
            else:
                # extra counter for gallons exceeding 10 million and calculates bill according to extra 
                extra = water - TEN_MIL
                bill = INITIAL_IND_EXCEEDED + (extra * ADDITIONAL_COM_IND)
        # statement if position of end and begin to calculate gallons of water correctly
        elif end < begin:
            water = ((end - begin) % 10) / 10
            if water <= FOUR_MIL:
                bill = INITIAL_COM_IND
            elif FOUR_MIL < water <= TEN_MIL:
                bill = INITIAL_IND_EXCEEDED
            else: 
                extra = water - TEN_MIL
                bill = INITIAL_IND_EXCEEDED + (extra * ADDITIONAL_COM_IND)

    # display results
    print("")
    print("Customer code:", code)
    print("Beginning meter reading: {:0>9}".format(begin)) 
    print("Ending meter reading: {:0>9}".format(end)) 
    print("Gallons of water used:", format(water, '.1f'))
    print("Amount billed: $", format(bill, '.2f'), sep='')

    # get input if user wants to run program again, repeat if input is invalid
    restart = str(input("Do you want to perform the calculation again? "))
    while restart != "y" and restart != "Y" and restart != "n" and restart != "N" :
        print("Invalid entry try again:")
        restart = str(input("Do you want to perform the calculation again? "))

# display exit message
print("OK. Enjoy your day.")
