# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 3
# a=1, b=1, c=1
# (a)(b)(c)
# (a)(c)(b)
# (b)(a)(c)
# (b)(c)(a)
# (c)(a)(b)
# (c)(b)(a)
# d[n][a][b][c]: n song, num of a,b,c should sing
#                num of way to make album
# d[n][a][b][c] = sum (d[n-1][a-i][b-j][c-k]) 
#      (i,j,k: a,b,c attend or not 0, 1)

mod = 1000000007
n,a,b,c = map(int, input().split())
d = [[[[-1]*51 for k in range(51)] for j in range(51)] for i in range(51)]

def go(n,a,b,c):
    if n == 0:
        if a == 0 and b == 0 and c == 0:
            return 1 # base: num of way to make album
        else:
            return 0
    if a < 0 or b < 0 or c < 0:
        return 0
    ans = d[n][a][b][c]
    if ans != -1:
        return ans
    ans = 0
    for i in range(2):
        for j in range(2):
            for k in range(2):
                if i+j+k == 0: # at least one
                    continue
                ans += go(n-1,a-i,b-j,c-k)
    ans %= mod
    d[n][a][b][c] = ans
    return ans
print(go(n,a,b,c))


