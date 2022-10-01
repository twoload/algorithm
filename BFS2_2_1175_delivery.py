# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

import sys
from collections import deque
input = sys.stdin.readline
dx = [0,0,1,-1]
dy = [1,-1,0,0]

n, m = map(int, input().split())
# delivery map
a = [input().strip() for _ in range(n)]
# d[r][c][k][s] : minimum distance
#   s : status (0: no visit, 1: c1 visit, 2: c2 visit, 3: c1,c2 visit)
d = [[[[-1]*4 for k in range(4)] for j in range(m)] for i in range(n)]

ans = -1
x1, y1, x2, y2 = -1,-1,-1,-1
q = deque()
# As touring nxm, find S, C1, C2
for i in range(n):
    for j in range(m):
        if a[i][j] == 'S': # start
            for k in range(4): # all directions
                q.append((i,j,k,0)) # s: no visit
                d[i][j][k][0] = 0 # init value
        elif a[i][j] == 'C': # C1, C2
            if x1 == -1:
                x1, y1 = i, j
            else:x2, y2 = i, j
                
while q:
    x, y, direction, s = q.popleft()
    if s == 3: # c1,c2 visit
        ans = d[x][y][direction][s]
        break
    for k in range(4): # direction (left,right,up,down)
        if direction == k: # direction change
            continue               
        nx = x + dx[k]
        ny = y + dy[k]
        if 0 <= nx < n and 0 <= ny < m: # range 0~n-1,0~m-1
            if a[nx][ny] != '#':
                ns = s
                if a[nx][ny] == 'C':
                    if nx == x1 and ny == y1:
                        ns |= 1
                    else:
                        ns |= 2
                        
                if d[nx][ny][k][ns] == -1:
                    d[nx][ny][k][ns] = d[x][y][direction][s] + 1
                    q.append((nx,ny,k,ns))
                    
print(ans)
                        