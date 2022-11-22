# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N (3 <= N <= 32)
# O(3^32*32) = O(3^32) = O(2^32) = O(2000 000 000)
# d[i][j]][dir] : cache

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
# d[i][j]][dir]
d = [[[-1]*3 for j in range(n)] for i in range(n)] 

def go(x,y,direction):
    if x == n-1 and y == n-1:
        return 1
    ans = d[x][y][direction]
    if ans != -1:
        return ans
    ans = 0
    if direction == 0: # -
        if y+1 < n and a[x][y+1] == 0: # 0: can move
            ans += go(x,y+1,0) # -
        if x+1 < n and y+1 < n and a[x][y+1] == 0 and a[x+1][y] == 0 and a[x+1][y+1] == 0:
            ans += go(x+1,y+1,1) # \
    elif direction == 1: # \
        if y+1 < n and a[x][y+1] == 0:
            ans += go(x,y+1,0) # -
        if x+1 < n and a[x+1][y] == 0:
            ans += go(x+1,y,2) # |
        if x+1 < n and y+1 < n and a[x][y+1] == 0 and a[x+1][y] == 0 and a[x+1][y+1] == 0:
            ans += go(x+1,y+1,1) # \
    elif direction == 2: # |
        if x+1 < n and a[x+1][y] == 0:
            ans += go(x+1,y,2) # |
        if x+1 < n and y+1 < n and a[x][y+1] == 0 and a[x+1][y] == 0 and a[x+1][y+1] == 0:
            ans += go(x+1,y+1,1) # \
    d[x][y][direction] = ans
    return ans

print(go(0,1,0))
        