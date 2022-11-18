# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N x M (1 ~ 1000), K (1~10)
# 0 : move
# 1 : wall
# (1,1) -> (N,M) : move in shortest path
# can break k walls

from collections import deque
dx = [0,0,1,-1]
dy = [1,-1,0,0]
n,m,l = map(int, input().split())
a = [list(map(int,list(input()))) for _ in range(n)]
# dist[i][j][k] , k = break the wall (Yes/No)
# [0]*11 -> [k] can store k state 
# (0000000001)
# (0000000010)
# (0000000011)
# ...
dist = [[[0]*11 for j in range(m)] for i in range(n)]
q = deque()
q.append((0,0,0))
dist[0][0][0] = 1
while q:
    x,y,z = q.popleft()
    for k in range(4):
        nx,ny = x+dx[k], y+dy[k]
        if nx < 0 or nx >= n or ny < 0 or ny >= m :
            continue
        if a[nx][ny] == 0 and dist[nx][ny][z] == 0:
            dist[nx][ny][z] = dist[x][y][z] + 1
            q.append((nx,ny,z))
        if z+1 <= l and a[nx][ny] == 1 and dist[nx][ny][z+1] == 0:
            dist[nx][ny][z+1] = dist[x][y][z] + 1
            q.append((nx,ny,z+1))

ans = -1
for i in range(l+1): # 0~l
    if dist[n-1][m-1][i] == 0:
        continue
    if ans == -1:
        ans = dist[n-1][m-1][i]
    elif ans > dist[n-1][m-1][i]:
        ans = dist[n-1][m-1][i]
print(ans)