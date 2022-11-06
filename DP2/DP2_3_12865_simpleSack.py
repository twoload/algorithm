# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# sack that can have max K weight -> DP is possible
# d[i][j]
#   i : num of product
#   j : weight of sack
#   max value of i, j
#   0 <= i <= N, 0 <= j <= K
# d[i+1][j+w[i]] = max(d[][], d[i][j] + v[i])
#   j < j+w[i] <= K
#-------------------------------------------------
# 1) in case of not putting i product in sack
#    d[i-1][j]
# 2) in case of putting i product in sack
#    d[i-1][j-w[i]] + v[i]
# O(NK) by DP 
# O(2^N) by BruteForce
n, k = map(int, input().split())
temp = [list(map(int,input().split())) for _ in range(n)]
w, v = zip(*temp) # *: unzip operator
w = [0] + list(w)
v = [0] + list(v)
d = [[0] * (k+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, k+1):
        d[i][j] = d[i-1][j] # not putting
        if j-w[i] >= 0:
            d[i][j] = max(d[i][j], d[i-1][j-w[i]]+v[i]) # putting
            
print(d[n][k])

