def primes(a, b):
    if (a < 1):
        raise ValueError()
    elif(b < a):
        raise ValueError()
    
    primeNums = []
    for i in range(a, b + 1):
        hold = 0
        if i > 1:
            for j in range(2, i):
                if (i % j == 0):
                    hold = 1
            if hold == 0:
                primeNums.append(i)
    
    primes = set(primeNums)
    return(primes)

    pass

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

def gcd(a,b):
    dict = bezout_coeffs(a, b)
    d = a*dict[a] + b*dict[b]
    return abs(d)
    
    pass