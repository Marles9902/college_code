import math



# problem 1
def translate(S, z0):

    T = set()
    for i in S:
        z = i + z0
        T.add(z)
        
    return T
    
    pass
    


# problem 2
def scale(S, k):

    if (k <= 0):
        raise ValueError()
    
    T = set()
    for i in S:
        z = i * k
        T.add(z)
        
    return T
    
    pass



# problem 3
def rotate(S, theta):

    T = set()
    for i in S:
        z = i * (math.e**(theta*1j))
        T.add(z)
        
    return T
    
    pass



# problem 4
class Vec:
    def __init__(self, contents = []):
        """
        Constructor defaults to empty vector
        INPUT: list of elements to initialize a vector object, defaults to empty list
        """
        
        self.elements = contents
        
        return
    
    def __abs__(self):
        """
        Overloads the built-in function abs(v)
        returns the Euclidean norm of vector v
        """
        
        euclNorm = 0.0
        for i in range(len(self.elements)):
            self.elements[i] = abs(self.elements[i])
            euclNorm += self.elements[i] * self.elements[i]
        euclNorm = math.sqrt(euclNorm)
        
        return euclNorm
    
        pass
        
    def __add__(self, other):
        """Overloads the + operator to support Vec + Vec
         raises ValueError if vectors are not same length
        """
        sumVec = []
        
        if(len(self.elements) != len(other.elements)):
            raise ValueError
            
        for i in range(len(self.elements)):
            sumElem = self.elements[i] + other.elements[i]
            sumVec.append(sumElem)
            
        return Vec(sumVec)
    
        pass
    
    def __sub__(self, other):
        """
        Overloads the - operator to support Vec - Vec
        Raises a ValueError if the lengths of both Vec objects are not the same
        """
        diffVec = []
        
        if(len(self.elements) != len(other.elements)):
            raise ValueError
            
        for i in range(len(self.elements)):
            diffElem = self.elements[i] - other.elements[i]
            diffVec.append(diffElem)
            
        return Vec(diffVec)
    
        pass
    
    
    
    def __mul__(self, other):
        """Overloads the * operator to support 
            - Vec * Vec (dot product) raises ValueError if vectors are not same length in the case of dot product
            - Vec * float (component-wise product)
            - Vec * int (component-wise product)
            
        """
        if type(other) == Vec: #define dot product
            #FIXME: IMPLEMENT
            dotProd = 0
            
            if(len(self.elements) != len(other.elements)):
                raise ValueError
                
            for i in range(len(self.elements)):
                dotProd += self.elements[i] * other.elements[i]
                
            return dotProd
        
            pass
        
        elif type(other) == float or type(other) == int: #scalar-vector multiplication
            #FIXME: IMPLEMENT
            scalarVec = []
            for i in range(len(self.elements)):
                scalarElem = self.elements[i] * other
                scalarVec.append(scalarElem)
                
            return Vec(scalarVec)
        
            pass
            
    
    def __rmul__(self, other):
        """Overloads the * operation to support 
            - float * Vec
            - int * Vec
        """
        scalarVec = []
        for i in range(len(self.elements)):
            scalarElem = self.elements[i] * other
            scalarVec.append(scalarElem)
            
        return Vec(scalarVec)
    
        pass
    

    
    def __str__(self):
        """returns string representation of this Vec object"""
        return str(self.elements) # does NOT need further implementation