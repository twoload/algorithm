# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# Do BFS by turn
# q : deque as much as player's number
# next_q : for next turn

from collections import deque
dx = [0,0,1,-1]
dy = [1,-1,0,0]
n,m,p = map(int, input().split())
s = [0] + list(map(int, input().split()))
a = [[0]*m for _ in range(n)]
for i in range(n):
    line = input()
    for j in range(m):
        if line[j] == '.': # road
            a[i][j] = 0
        elif line[j] == '#': # wall
            a[i][j] = -1
        else: # each player's castle
            a[i][j] = ord(line[j])-ord('0')
            
# create queue as much as player's number
q = [deque() for _ in range(p+1)]
# create next_queue
next_q = [deque() for _ in range(p+1)]

for i in range(n):
    for j in range(m):
        if a[i][j] > 0:
            q[a[i][j]].append((i,j)) # update map info (init) (save position info as tuple)
            
while True:
    # every turn
    ok = False
    for who in range(1, p+1): # every player
        d = [[0]*m for _ in range(n)]
        while q[who]:
            ok = True
            x,y = q[who].popleft()
            if d[x][y] == s[who]: #dist == ability to go
                next_q[who].append((x,y)) # will do at next turn
            if a[x][y] > 0 and a[x][y] != who: # other player's castle
                continue
            a[x][y] = who
            for k in range(4):
                nx,ny = x+dx[k],y+dy[k] # next pos
                if 0<= nx < n and 0 <= ny < m: # check range
                    if a[nx][ny] == 0: # if road
                        d[nx][ny] = d[x][y] + 1
                        if d[nx][ny] <= s[who]: 
                            a[nx][ny] = who # build who's castle, next pos
                            q[who].append((nx,ny)) # add
        q[who] = next_q[who]
        next_q[who] = deque()
    # if there is no place for each player to go/build
    if not ok:
        break
    
ans = [0]*(p+1)
for i in range(n):
    for j in range(m):
        if a[i][j] > 0:
            ans[a[i][j]] += 1
print(' '.join(map(str,ans[1:])))
        
            
        


            