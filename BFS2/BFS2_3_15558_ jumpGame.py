# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.


from collections import deque
n, k = map(int, input().split())
a = [input() for _ in range(2)]
dirs = [(0,1),(0,-1),(1,k)] # next
dist = [[-1]*n for _ in range(2)] # minimum distance initialization
q = deque()
q.append((0,0))
dist[0][0] = 0
ok = False
while q:
    x,y = q.popleft()
    for dx,dy in dirs:
        nx,ny = (x+dx)%2,y+dy # 0->1, 1->0 (1+1%2=0)
        if ny >= n: # pass
            ok = True
            break
        if ny < 0: # out of range
            continue
        if dist[nx][ny] != -1: # visited
            continue
        if a[nx][ny] == '0': # can't go
            continue
        if ny < dist[x][y] + 1: #room disappear condition
            continue
        dist[nx][ny] = dist[x][y] + 1
        q.append((nx,ny))
    if ok:
        break
print(1 if ok else 0)