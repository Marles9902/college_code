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

# problem 1
def modinv(a,m):
    # error message if gcd =/= 1
    gcdVal = gcd(a,m)
    if (gcdVal != 1):
        print("The given values are not relatively prime")
        raise ValueError()

    # use bezout coefficient to find the inverse of a under modulo m
    dict = bezout_coeffs(a,m)
    inverseA = dict[a]
    # if the inverse is negative, keep adding m to a 
    while (inverseA < 0):
        inverseA += m

    return inverseA

    pass


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


# problem 3
def affineDecrypt(ciphertext, a, b):
    # error message if gcd =/= 1
    gcdVal = gcd(a,26)
    if (gcdVal != 1):
        print("The given key is invalid. The gcd(a,26) must be 1.")
        raise ValueError()

    # get inverse of a under mod 26
    inverseA = modinv(a,26)
    # for each character, perform affine decryption and concatenate to new string
    decryptText = ''
    for char in ciphertext:
        charToDigit = letters2digits(char)
        c = int(charToDigit)
        # affine decryption formula
        newDigit = (inverseA * (c - b)) % 26
        # add a zero in front if needed
        if (newDigit < 10):
            newDigit = str(newDigit)
            newDigit = '0' + newDigit
        newDigit = str(newDigit)
        newChar = digits2letters(newDigit)
        decryptText += newChar

    return decryptText

    pass


# problem 4
def encryptRSA(m, n, e):

    l = blocksize(n)

    # add 'X' after message if the groups dont have the same amount 
    digits = letters2digits(m)
    if (len(digits) % 4 != 0):
        digits += '23'

    # for each group of 4, encrypt and add to new string
    getRSAd = ''
    i = 0
    for i in range(0, len(digits), l):
        mi = digits[i:i + l]
        mi = int(mi)
        # RSA encryption formula
        encrypted = (mi ** e) % n
        # add 0 in the front of an encryption if needed
        if (encrypted < 1000):
            encrypted = '0' + str(encrypted)
        encrypted = str(encrypted)
        getRSAd += encrypted + ' '

    return getRSAd


    pass


# problem 5
def decryptRSA(c, p, q, e):
    # getting things ready
    c = c.replace(' ', '')
    n = p * q
    inverseE = modinv(e,(p-1)*(q-1))
    l = blocksize(n)

    # for each group of 4, decrypt and add to new string
    message = ''
    for i in range(0, len(c), l):
        ci = c[i:i + l]
        ci = int(ci)
        #RSA decryption formula
        decrpyted = (ci ** inverseE) % n
        # add zero in front of decryption if needed
        if (decrpyted < 1000):
            decrpyted = '0' + str(decrpyted)
        decrpyted = str(decrpyted)
        # translate digits into letters for the message
        letter = digits2letters(decrpyted)
        message += letter

    return message

    pass
