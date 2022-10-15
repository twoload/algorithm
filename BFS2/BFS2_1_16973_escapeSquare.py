# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

from collections import deque
dx = [0,0,1,-1]
dy = [1,-1,0,0]
def get_sum(x1,y1,x2,y2): #cumulative (x1,y1~x2,y2) sum : O(n)
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]

n,m = map(int, input().split())
a = [[0]*(m+1) for _ in range(n+1)]
s = [[0]*(m+1) for _ in range(n+1)]
for i in range(1, n+1):
    for i in range(1, n+1):
    a[i][1:] = list(map(int, input().split()))
    
d = [[-1]*(m+1) for _ in range(n+1)]
h, w, x1, y1, x2, y2 = map(int, input().split())
for i in range(1, n+1):
    for j in range(1, m+1): #cumulative sum (S[1][1] ~ S[i][j])
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]

q = deque()
q.append((x1,y1))
d[x1][y1] = 0

while q:
    x,y = q.popleft()
    for k in range(4):
        nx,ny = x+dx[k],y+dy[k]
        # check range (n, m)
        if 1<=nx and nx+h-1 <= n and 1 <= ny and ny+w-1 <= m:
            # if movement is possible, (there is no obstacles)
            if get_sum(nx,ny,nx+h-1,ny+w-1) == 0:
                # if no visit,
                if d[nx][ny] == -1:
                    q.append((nx,ny))
                    d[nx][ny] = d[x][y] + 1
                    
print(d[x2][y2])
