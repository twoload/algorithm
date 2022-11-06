# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# the reason why dp is possible
#    continous multiplication

# d[i][j] : min multiplication at matrix i~j
# i....k....j
# d[i][j] => d[i][k] + d[k+1][j] + r[i]*c[k]*r[j]
#    i <= k < j

def go(i,j):
    if d[i][j] != -1: # memoization
        return d[i][j]
    if i == j:
        return 0
    if i+1 == j:
        return r[i]*c[i]*c[j]
    ans = d[i][j]
    for k in range(i,j): # i~j-1
        t1 = go(i,k)
        t2 = go(k+1,j)
        
        cur = t1+t2+r[i]*c[k]*c[j]
        if ans == -1 or ans > cur:
            ans = cur
    d[i][j] = ans
    return ans        

n = int(input())
r = []
c = []
for _ in range(n):
    r_temp, c_temp = map(int, input().split())
    r.append(r_temp)
    c.append(c_temp)

d = [[-1]*n for _ in range(n)]
print(go(0,n-1))





