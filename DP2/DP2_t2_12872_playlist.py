# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 1<=n<=100, 0<=m<=n, n<=p<=100
# Group X : added song
# Group Y : not added song
# (X=0, Y=N) -> (X=N, Y=0)
# d[p][x][y] : num of case when select p-th song, group size: x, y
# 1. y > 0
#    can add any song in y into playlists
#    d[p+1][x+1][y-1]*y
# 2. x > m
#    can add any song of x-m in x
#    d[p+1][x][y]*(x-m)

# because x+y = n,
# we can reduce 3d to 2d dp
# d[p][x] : num of case when select p-th song, group size: x,y (y=n-x)
# 1. y > 0
#    can add any song in y into playlists
#    d[p+1][x+1]*(n-x)
# 2. x > m
#    can add any song of x-m in x
#    d[p+1][x]*:(x-m)
mod = 1000000007

n,m,p = map(int, input().split())
d = [[-1]*(n+1) for _ in range(p+1)]

def go(position, x):
    y = n-x
    if position == p: # base
        if y == 0:
            return 1
        else:
            return 0
    ans = d[position][x] # memoization
    if ans != -1:
        return ans
    ans = 0
    if y > 0:
        ans += go(position+1,x+1)*y
    if x > m:
        ans += go(position+1,x)*(x-m)
        
    ans %= mod
    d[position][x] = ans
    return ans

print(go(0,0))