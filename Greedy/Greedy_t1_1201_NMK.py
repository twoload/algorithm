# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# m+k-1 <= n <= m+k
# 15 5 4
# g = [0 4 7 10 13 15]
# [0 4=m] : first interval
# no to over 4=m, (1 if r>0 else 0)
#    n//m < m
#    n//m + 1 <= m
n,m,k = map(int,input().split())
if m+k-1 <= n <= m*k:
    a = [i+1 for i in range(n)] # 1,2,3,... , n
    g = [0,k] # first interval
    n -= k
    m -= 1
    gs = 1 if m == 0 else n//m
    r = 0 if m == 0 else n%m
    for i in range(m):
        g += [g[-1] + gs + (1 if r>0 else 0)] #
        if r > 0:
            r -= 1
    for i in range(len(g)-1):
        u = g[i]
        v = g[i+1]
        a[u:v] = a[u:v][::-1]
    print(' '.join(map(str,a)))
else:
    print(-1)