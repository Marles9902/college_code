# Marwin Gonzales

def cargo(crates, T, W, D):
    i_crates = [count(crate) for crate in crates]
    n = len(i_crates)
    dp = [[[[0] * (D + 1) for _ in range(W + 1)] for _ in range(T + 1)] for _ in range(n+1)]

    for i in range(1, n + 1):
        for t in range(T + 1):
            for w in range(W + 1):
                for d in range(D + 1):

                    current_t = i_crates[i-1][0]
                    current_w = i_crates[i-1][1]
                    current_d = i_crates[i-1][2]

                    if t >= current_t and w >= current_w and d >= current_d:
                        dp[i][t][w][d] = max(dp[i - 1][t][w][d],
                                             1 + dp[i - 1][t - current_t][w - current_w][d - current_d])
                    else:
                        dp[i][t][w][d] = dp[i - 1][t][w][d]

    return dp[n][T][W][D]


def count(crate):
    temp_array = [0, 0, 0]
    for item in crate:
        if item == 't':
            temp_array[0] += 1
        if item == 'w':
            temp_array[1] += 1
        if item == 'd':
            temp_array[2] += 1
    return temp_array