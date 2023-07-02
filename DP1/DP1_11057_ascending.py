#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

# d[i][j] : last num = j
#           num of ascending at len i
#  += d[i-1][k], 0<=k<j => 0<=k<=j (correct!) 

# d[1][i] = 1

d = [[0]*10 for _ in range(1001)]
mod = 10007
n = int(input())
for i in range(10):
    d[1][i] = 1
for i in range(2, n+1): #2~n
    for j in range(10): #0~9
        for k in range(j+1): # 0~j (0<=k<=j)
            d[i][j] += d[i-1][k]
            d[i][j] %= mod
ans = sum(d[n])
print(ans%mod)
