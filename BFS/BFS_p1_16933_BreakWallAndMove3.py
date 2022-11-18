# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N x M (1 ~ 1000), K (1~10)
# 0 : move
# 1 : wall
# (1,1) -> (N,M) : move in shortest path
# can break k walls
# can only break at day
# day/night change every step

from collections import deque
dx = [0,0,1,-1]
dy = [1,-1,0,0]
n,m,l = map(int, input().split())
a = [list(map(int,list(input()))) for _ in range(n)]
# dist[i][j][k][t] , k = break the k-th wall (Yes/No), t = day/night
dist = [[[[0]*2 for k in range(11)] for j in range(m)] for i in range(n)]
q = deque()
q.append((0,0,0,0))
dist[0][0][0][0] = 1
while q:
    x,y,z,night = q.popleft()
    for k in range(4): # move
        nx,ny = x+dx[k], y+dy[k]
        if nx < 0 or nx >= n or ny < 0 or ny >= m :
            continue
        if a[nx][ny] == 0 and dist[nx][ny][z][1-night] == 0:
            dist[nx][ny][z][1-night] = dist[x][y][z][night] + 1
            q.append((nx,ny,z,1-night))
        if night == 0 and z+1 <= l and a[nx][ny] == 1 and dist[nx][ny][z+1][1-night] == 0:
            dist[nx][ny][z+1][1-night] = dist[x][y][z][night] + 1
            q.append((nx,ny,z+1,1-night))
    if dist[x][y][z][1-night] == 0: # not move
        dist[x][y][z][1-night] = dist[x][y][z][night] + 1
        q.append((x,y,z,1-night))

ans = -1
for j in range(2): # day,night
    for i in range(l+1): # 0~l
        if dist[n-1][m-1][i][j] == 0:
            continue
        if ans == -1:
            ans = dist[n-1][m-1][i][j]
        elif ans > dist[n-1][m-1][i][j]:
            ans = dist[n-1][m-1][i][j]
print(ans)