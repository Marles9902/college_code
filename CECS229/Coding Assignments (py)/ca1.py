def div_alg(a, d):
    q = a // d     # use integer division to find the quotient
    r = a % d     # use modulo to find the remainder
    return {'quotient' : q, 'remainder' : r}     # return as dictionary 

    pass


def binary_add(a, b):
    # declare variables
    c = 0     # carry 
    s = ""     # placeholder for the pre-formatted outcome
    s_f = ""     # placeholder for the formatted outcome
    
    # remove the whitespaces from the input (if any)
    a = a.replace(" ", "")
    b = b.replace(" ", "")
    
    # match the lengths of both inputs 
    length = max(len(a), len(b))
    a = (length - len(a))*"0" + a
    b = (length - len(b))*"0" + b
    
    # for each bit
    for i in range(length-1, -1, - 1):
        s = str((int(a[i]) + int(b[i]) + c) % 2) + s     # update the answer
        c = (int(a[i]) + int(b[i]) + c) // 2     # update the carry 
        
    # if there is a carry, add 1 to MSB
    if (c):
        s = '1' + s
        
    # formatting the bits to be in groups of nibbles    
    
    for i in range(len(s)-4, 0, -4):
        s_f = " " + s[i:i+4] + s_f

    # formatted answer
    s_f = s[0:i] + s_f
    
    # check length of s to determine which answer should be returned
    if len(s)>=4:
        return s_f
    else:
        return s

    pass


def mod_exp(b, n, m):
    # check if inputs are positive integers
    if b>=0 and n>=0 and m>=0:
        x = 1
        p = b % m
        a = bin(n)     # get the binary form of the exponent
        a = a[2:]     # get rid of '0b'

        # for each bit in the exponent
        for i in range(len(a)-1, -1, -1):
            if int(a[i]) == 1:     # if the bit is 1
                x = (x * p) % m     # update x 
            p = (p * p) % m     # update p 
    else:     # if any input is negative, set x to 0
        x = 0
    return x 

    pass

