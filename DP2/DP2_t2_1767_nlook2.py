# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[n][m][k] : case num that put k-num rook in nxm board
# 1. no put rook in n-row
#    d[n-1][m][k]
# 2. put a rook in n-row but no attack by another rook
#    d[n-1][m-1][k-1]*m
# 3. put two rooks in n-row
#    d[n-1][m-2][k-2]*m*(m-1)/2
# 4. put a rook in n-row and attack by another rook
#    d[n-2][m-1][k-2]*m*(n-1)
 
n = int(input())
m = int(input())
k = int(input())
 
d = [[[-1]*101 for _ in range(101)] for _ in range(101)]
def go(n,m,k):
    if k == 0:
        return 1
    if n <= 0 or m <= 0 or k < 0: # can handle minus numbers
        return 0
    ans = d[n][m][k]
    if ans != -1:
        return ans
    d[n][m][k] = 0
    ans = go(n-1,m,k) + \
        go(n-1,m-1,k-1)*m + \
        go(n-1,m-2,k-2)*m*(m-1)//2 + \
        go(n-2,m-1,k-2)*m*(n-1)
    ans %= 1000001
    d[n][m][k] = ans
    return ans
print(go(n,m,k))     