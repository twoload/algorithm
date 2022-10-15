# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[i][j] : min cost that combines i ~ j
# combining continuous numbers -> dynamic is possible
# i ~~~~~ j
# i   k   j
# d[i][j] = min(d[i][k] + d[k+1][j] + sum(i~j)), i<=k<j

#limit=500
#d = [[-1]*limit for _ in range(limit)]
def go(i,j):
    if i==j:
        return 0
    if d[i][j] != -1:
        return d[i][j]
    ans = d[i][j]
    cost = sum(a[i:j+1])
    #for k in range(i,j+1):
    #    sum += a[k]
    #for k in range(i,j):
    #    d[i][j] = min(d[i][j], go(i,k) + go(k+1,j) + sum) 
    for k in range(i,j):
        temp = go(i,k) + go(k+1,j) + cost
        if ans == -1 or ans > temp:
            ans = temp
    d[i][j] = ans
    return ans

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    d = [[-1]*n for _ in range(n)]
    print(go(0,n-1))