# constants for the limit bounds of meter readings 
UPPER_LIMIT = 999999999
LOWER_LIMIT = 0

# variables to hold beginning meter reading, ending meter reading, gallons of water used, amount billed, and extra gallon counter
begin = 0 
end = 0 
water = 0 
bill = 0
extra = 0

# get customer code, beginning meter reading, and ending meter reading inputs
code = str(input("Enter the customer's code: "))
begin = int(input("Enter the customer's beginning meter reading: "))
end = int(input("Enter the customer's ending meter reading: "))

# checking if meter readings are withing limit bounds
if (LOWER_LIMIT < begin < UPPER_LIMIT) and (end < UPPER_LIMIT) and (end > LOWER_LIMIT):
    # checking if customer code is r or R
    if (code == "r") or (code == "R"):
        # statement if position of end and begin to calculate gallons of water correctly
        if end > begin:
            # calculate gallons used and amount bill
            water = (end - begin) / 10
            bill = 5 + (.0005 * water)
        if end < begin:
            # calculate gallons used and amount bill
            water = ((end - begin) % 10) / 10
            bill = 5 + (.0005 * water)

    # checking if customer code is c or C
    elif (code == "c") or (code == "C"):
        # statement if position of end and begin to calculate gallons of water correctly
        if end > begin:
            # calculate gallons of water used
            water = (end - begin) / 10
            # checking if gallons of water used does not exceed 4 million 
            if water <= 4000000:
                bill = 1000
            else:
                # extra variable countes the extra gallons after 4 million and calculates the bill according to extra gallons
                extra = water - 4000000
                bill = 1000 + (extra * .00025)
        # statement if position of end and begin to calculate gallons of water correctly
        elif end < begin:
            water = ((end - begin) % 10) / 10
            if water <= 4000000:
                bill = 1000
            else: 
                extra = water - 4000000
                bill = 1000 + (extra * .00025)

    # checking if customer code is i or I  
    elif (code == "i") or (code == "I"):
        # statement if position of end and begin to calculate gallons of water correctly
        if end > begin:
            water = (end - begin) / 10
            # checking if gallons of water used does not exceed 4 million and assigns amount bill
            if water <= 4000000:
                bill = 1000
            # checking if gallons of water used exceeds 4 million but does not exceed 10 million and assign amount bill
            elif 4000000 < water <= 10000000:
                bill = 2000
            # checking if gallons of water used exceeds 10 million 
            else:
                # extra counter for gallons exceeding 10 million and calculates bill according to extra 
                extra = water - 10000000
                bill = 2000 + (extra * .00025)
        # statement if position of end and begin to calculate gallons of water correctly
        elif end < begin:
            water = ((end - begin) % 10) / 10
            if water <= 4000000:
                bill = 1000
            elif 4000000 < water <= 10000000:
                bill = 2000
            else: 
                extra = water - 10000000
                bill = 2000 + (extra * .00025)

    # if customer code is invalid, print error
    else:
        water = 0
        bill = 0
        print("")
        print("ERROR: INVALID INPUT")

# if beginning and/or ending meter reading is outside limit bounds, print error
else:
    water = 0
    bill = 0
    print("")
    print("ERROR: INVALID INPUT")

# display results
print("")
print("Customer code:", code)
print("Beginning meter reading: {:0>9}".format(begin)) 
print("Ending meter reading: {:0>9}".format(end)) 
print("Gallons of water used:", format(water, '.1f'))
print("Amount billed: $", format(bill, '.2f'), sep='')

