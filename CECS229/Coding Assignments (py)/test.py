# function from coding assignment 2
def bezout_coeffs(a, b):
    roundNum = 0
    ax = a
    bx = b

    if(a == 0):
        return {a : 0, b : 1}
    if(b == 0 or b % a == 0):
        return {a : 1, b : 0}
    
    while(bx % ax != 0):
        roundNum += 1
        if(roundNum == 1):
            s = -(b // a)
            t = 1
            a1 = ax
            ax = a*s + b*t
            bx = a1
        elif(roundNum == 2):
            s2 = 1 
            t2 = 0 
            s1 = s
            t1 = t 
            s = s2 - (s1 * (bx// ax))
            t = t2 - (t1 * (bx // ax))
            a1 = ax
            ax = a*s + b*t
            bx = a1
        else: 
            s2 = s1
            t2 = t1
            s1 = s
            t1 = t
            s = s2 - (s1 * (bx // ax))
            t = t2 - (t1 * (bx // ax))
            a1 = ax
            ax = a*s + b*t
            bx = a1

    return {a : s, b : t}

    pass
# function from coding assignment 2
def gcd(a,b):
    dict = bezout_coeffs(a, b)
    d = a*dict[a] + b*dict[b]
    return abs(d)
    
    pass
# utility function
def digits2letters(digits):
    letters = ""
    start = 0  #initializing starting index of first digit
    while start <= len(digits) - 2:
        digit = digits[start : start + 2]  # accessing the double digit
        letters += chr( int(digit) +65)   # concatenating to the string of letters
        start += 2                         # updating the starting index for next digit
    return letters
# utility function
def letters2digits(letters):
    digits = ""
    for c in letters:
        if c.isalpha():
            letter = c.upper()  #converting to uppercase  
            d = ord(letter)-65
            if d < 10:
                digits += "0" + str(d)     # concatenating to the string of digits
            else:
                digits += str(d)
    return digits
# utility function
def blocksize(n):
    """returns the size of a block in an RSA encrypted string"""
    twofive = "25"
    while int(twofive) < n:
        twofive += "25"
    return len(twofive) - 2

#############################################################

# problem 2
def affineEncrypt(text, a, b):
    # error message if gcd =/= 1
    gcdVal = gcd(a,26)
    if (gcdVal != 1):
        print("The given key is invalid. The gcd(a,26) must be 1.")
        raise ValueError()
    
    # this gets rid of any spaces in the text
    digits = letters2digits(text)
    noSpace = digits2letters(digits)

# for each character, perform affine encryption and concatenate to new string
    encryptText = ''
    for char in noSpace:
        charToDigit = letters2digits(char)
        p = int(charToDigit)
        # affine encryption formula
        newDigit = (((a * p) + b) % 26)
        # if digit is missing a 0 in the front, add one
        if (newDigit < 10):
            newDigit = str(newDigit)
            newDigit = '0' + newDigit
        newDigit = str(newDigit)
        newChar = digits2letters(newDigit)
        encryptText += newChar

    return encryptText

    pass

thing = affineEncrypt('MEET YOU IN THE PARK', 1, 3)
print(thing)