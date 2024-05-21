# Marwin Gonzales

import sys

# function that handles the file inputted as an argument, reads each line and adds each number into an array
def fileHandler():
    # variables for a temporary value, the list that will contain the numbers in the file, and the actual file
    temp = 0
    list = []
    fileName = sys.argv[1]
    # open the file in reading mode (default mode)
    with open(fileName) as file:
        # return current line and get rid of whitespace
        currLine = file.readline().strip()
        while currLine:
            # for every number in the current line, add that number to temp
            for i in currLine:
                temp += int(i)
            # add the number obtained into the list
            list.append(temp)
            # reset temporary value
            temp = 0
            # move on to the next line, repeating the process until the end of the list
            currLine = file.readline().strip()
    return list

# function that finds the longest list of consecutive numbers such that there is no repeated sum of digits in the list
def sumNotRepeated():
    # variables for list of sums, dictionary of non repeated sums, iterations, and the longest length 
    sumsOfDigits = fileHandler()
    noRepeats = {}
    longestLength = 0
    i = 0
    # loop until the end of the list of sums
    for j in range(len(sumsOfDigits)):
        # check if the sum is already in the dictionary
        if sumsOfDigits[j] in noRepeats:
            i = max(i, noRepeats[sumsOfDigits[j]])
        # update the longest length 
        longestLength = max(longestLength, j-i+1)
        # go to next index in the dictionary
        noRepeats[sumsOfDigits[j]] = j+1
    return longestLength

# print the solution
print(sumNotRepeated())