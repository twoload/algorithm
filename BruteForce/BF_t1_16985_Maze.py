# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
# ref. https://rebas.kr/842

# 1 board rotate case : 4 
# 5 board ratate case : 4^5
# 5 board subsequence : 5!
# total               : O(4^5 * 5!) = O(32000)

# go(x,y,z)
# direction: left, right, down, up
# visit

# map rotation 

from collections import deque
from itertools import permutations

def bfs():
    global ans
    q = deque()
    q.append((0,0,0))
    dist = [[[-1]*5 for _ in range(5)] for _ in range(5)]
    dist[0][0][0] = 0
    while q:
        x,y,z = q.popleft()
        if (x,y,z) == (4,4,4):
            ans = min(ans, dist[x][y][z])
            if ans == 12:
                print(12)
                exit(0)
            return
        for i in range(6): # direction: 6
            nx,ny,nz = x+dx[i],y+dy[i],z+dz[i]
            if nx<0 or nx>=5 or ny<0 or ny>=5 or nz<0 or nz>=5:
                continue
            if b[nx][ny][nz] and dist[nx][ny][nz] == -1:
                q.append((nx,ny,nz))
                dist[nx][ny][nz] = dist[x][y][z] + 1

def rotate(k):
    temp = [[0]*5 for _ in range(5)]
    for i in range(5): # 0,1,2,3,4
        for j in range(5):
            # -----    --*--
            # -----    --*--
            # ***-- -> *-*--
            # -----    -----
            # --*--    -----
            # (2,0) > (0,2)
            # (2,1) > (1,2)
            # (2,2) > (2,2)
            # (4,2) > (2,0)
            temp[j][4-i] = b[k][i][j] # floor:k
    b[k] = temp
    
def maze(cnt): # 0,1,2,3,4
    if cnt == 5:
        # check if arrival point is 'can go'
        if b[4][4][4]: # end
            bfs()
        return
    for i in range(4): # 0,1,2,3 (rotate)
        # only if (0,0,0) is 'can go', go next floor
        if b[0][0][0]: # start
            maze(cnt+1)
        rotate(cnt) # always rotate (all cases) 
    
def solve():
    for d in permutations([0,1,2,3,4]): # floor
        for i in range(5):
            b[d[i]] = a[i] # floor change in all cases
        maze(0)
        
ans = 10**9
dx = (1,-1,0,0,0,0)
dy = (0,0,1,-1,0,0)
dz = (0,0,0,0,1,-1)
# a[5][5][5]
a = [[list(map(int,input().split())) for _ in range(5)] for _ in range(5)]
# b[i][j][k]
b = [[[0]*5 for _ in range(5)] for _ in range(5)]       
solve()
print(ans if ans != 10**9 else -1)
    