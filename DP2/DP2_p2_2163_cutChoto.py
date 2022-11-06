# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[i][j] : max cheer-up numbers at i~j
#     d[i+1][j] : no match
#     d[i+1][k-1] + d[k+1][j] + 1 where i<k<=j, a[i] == a[k]

# d[n][m] : min cut num from nxm to 1x1
# 1. when cut in row
#    d[i][m] + d[n-i][m] + 1, 1<i<n
# 2. when cut in col
#    d[n][i] + d[n][m-i] + 1, 1<i<m

n,m = map(int, input().split())
d = [[-1]*301 for _ in range(301)]

def go(n, m):
    # base condition
    if n == 1 and m == 1:
        return 0
    
    ans = d[n][m]
    if ans != -1:
        return ans
    
    ans = 1000000000
    for i in range(1,n):
        if ans > go(i,m)+go(n-i,m)+1:
            ans = go(i,m)+go(n-i,m)+1
            d[n][m] = ans
    for i in range(1,m): 
        if ans > go(n,i)+go(n,m-i)+1:
            ans = go(n,i)+go(n,m-i)+1
            d[n][m] = ans
    return ans
        
print(go(n,m))
        
