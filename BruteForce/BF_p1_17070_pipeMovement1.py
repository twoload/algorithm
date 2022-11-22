# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N (3 <= N <= 16)
# O(3^16*16) = O(3^16) = O(2^16) = O(64000)

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

def go(x,y,direction):
    if x == n-1 and y == n-1:
        return 1
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
    return ans

print(go(0,1,0))
        