# Marwin Gonzales

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

#Updates the tree with a value of all 1. 
def traverse(x):
    if not x:
        return
    traverse(x.left)
    x.val = 1
    traverse(x.right)

#Prints the tree as a string. 
def print_tree(x):
    if not x: 
        print("None", end="")
        return
    print("TreeNode(" + str(x.val)+ ", ", end = '')
    print_tree(x.left)
    print(",", end = "")
    print_tree(x.right)
    print(")", end = '')

def my_function(x):
    traverse(x)
    print_tree(x)
    print("") #this creates a new line after the printed result