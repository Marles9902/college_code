# Marwin Gonzales

def max_gold(arr, cap):
    mat = [[0 for _ in range (cap+1)] for _ in range(len(arr))]
    for i in range(0, len(arr)):
        for j in range(1, cap+1):
            if arr[i] > j:
                mat[i][j] = mat[i-1][j]
            else:
                mat[i][j] = max(mat[i-1][j], mat[i-1][j-arr[i]] + arr[i])
    return(mat[-1][-1])