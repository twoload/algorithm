# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

from collections import deque

# total 2 BFS
#   BFS : ice -> water 
#   BFS : swan -> where swan can swim

# (sx, sy) -> (ex, ey)
dx = [0,0,1,-1]
dy = [1,-1,0,0]
n, m = map(int, input().split())
wcheck = [[False]*m for _ in range(n)]
scheck = [[False]*m for _ in range(n)]
sx,sy,ex,ey = -1,-1,-1,-1
swan = deque()
nswan = deque()
water = deque()
nwater = deque()
a = [list(input()) for _ in range(n)]

# pypy3 : pass, python3 : timeout

# find swan, water
for i in range(n):
    for j in range(m):
        if a[i][j] == 'L':
            if sx == -1:
                sx,sy = i,j
            else:
                ex,ey = i,j
            a[i][j] = '.' # because found, change into '.' not any
            # no. '#' -> wrong, '.' -> correct
            # swan in on the lake (water)           
            
        if a[i][j] == '.':
            water.append((i,j)) # water
            wcheck[i][j] = True # water position
        
swan.append((sx,sy)) # start position of swan
scheck[sx][sy] = True

i = 0
while True: # BFS1. water 
    while water:
        x,y = water.popleft() # take one from water deque
        a[x][y] = '.' # change into water (ice->water, water->water)
        for k in range(4):
            nx,ny = x+dx[k],y+dy[k] # find next position
            if nx < 0 or nx >= n or ny < 0 or ny >= m: # range check
                continue
            if wcheck[nx][ny]: # check next visit position. already visited ? 
                continue
            if a[nx][ny] == '.': # insert into water deque
                water.append((nx,ny))
                wcheck[nx][ny] = True
            else: # not '.' 
                nwater.append((nx,ny)) # insert into next water deque
                wcheck[nx][ny] = True
    while swan:
        x,y = swan.popleft()
        for k in range(4):
            nx,ny = x+dx[k],y+dy[k]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if scheck[nx][ny]:
                continue
            if a[nx][ny] == '.':
                swan.append((nx,ny))
                scheck[nx][ny] = True
            else:
                nswan.append((nx,ny))
                scheck[nx][ny] = True
    if scheck[ex][ey]:
        print(i)
        break
    i += 1 # increate number to meet
    water = nwater # swap
    swan = nswan # swap
    nwater = deque() # new
    nswan = deque() # new