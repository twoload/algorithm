# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

from collections import deque
dx = [0,0,-1,1]
dy = [1,-1,0,0]
n = 3
a = [list(map(int,input().split())) for _ in range(n)]
start = 0 # [[1,2,3],[4,5,6],[7,8,0]] => 123456789
for i in range(n):
    for j in range(n):
        if a[i][j] == 0:
            a[i][j] = 9
        start = start * 10 + a[i][j] 
q = deque()
dist = dict() # dictionary {key, value}
dist[start] = 0 # minimum movement count
q.append(start)
while q:
    now_num = q.popleft()
    now = str(now_num)
    z = now.find('9') # empty element
    x = z//3 
    y = z%3
    for k in range(4):
        nx,ny = x+dx[k], y+dy[k] # empty element move (changible)
        if 0 <= nx < n and 0 <= ny < n:
            temp = list(now)
            temp[x*3+y],temp[nx*3+ny] = temp[nx*3+ny],temp[x*3+y] # swap
            num = int(''.join(temp))
            if num not in dist:
                dist[num] = dist[now_num] + 1
                q.append(num)
if 123456789 in dist:
    print(dist[123456789])
else:
    print(-1)
            

