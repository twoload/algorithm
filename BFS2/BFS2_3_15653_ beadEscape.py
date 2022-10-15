# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# Do BFS by turn
# q : deque as much as player's number
# next_q : for next turn

from collections import deque
import copy
dx = [0,0,1,-1]
dy = [1,-1,0,0]
# function to make it move toward it's direction until stopping
# return : moved or not, come in hole or not
def simulate(a, k, x, y): # board status:a, direction: k
    # a[x][y] = 'R', 'B' are expected
    # if 'R' meets hole, 'R' is changed into '.'
    #    so if a[x][y] == '.', it means R met hole.
    #    so return right now. further finding isn't needed any more
    if a[x][y] == '.': # 'R', 'B' are expected.  
        return (False,False,x,y)
    n = len(a)
    m = len(a[0])
    moved = False
    while True: # keep moving towards it's direction
        nx,ny = x+dx[k],y+dy[k]
        if nx < 0 or nx >= n or ny < 0 or ny >= m: # out of range
            return (moved, False, x, y) 
        if a[nx][ny] == '#': # wall
            return (moved, False, x, y) 
        elif a[nx][ny] in 'RB': # R,B is moving. if R,B exists, if another one exists, 
            return (moved, False, x, y)
        # in case of movement
        elif a[nx][ny] == '.': # place to be able to move
            a[x][y], a[nx][ny] = a[nx][ny], a[x][y]
            x,y = nx,ny
            moved = True
        # in case of hole
        elif a[nx][ny] == 'O':
            a[x][y] = '.'
            moved = True
            return (moved, True, x, y)

def go(b,rx,ry,bx,by,direction):
    a = copy.deepcopy(b)
    a[rx][ry] = 'R' # in room, place red bead, blue bead 
    a[bx][by] = 'B'
    hole1 = False
    hole2 = False
    while True:
        # toward k direction, move until stopping
        rmoved, rhole, rx, ry = simulate(a, direction, rx, ry) # move until stopping
        bmoved, bhole, bx, by = simulate(a, direction, bx, by)
        if not rmoved and not bmoved: # if both doesn't move, finish
            break
        # who came in hole ?
        if rhole:
            hole1 = True
        if bhole:
            hole2 = True
    return (hole1,hole2,rx,ry,bx,by)

n,m = map(int, input().split())
a = [list(input()) for _ in range(n)]
# d[rx][ry][bx][by] : Max = 10^4 : OK
d = [[[[-1]*m for k in range(n)] for j in range(m)] for i in range(n)] # every room init
ans = -1
q = deque()
for i in range(n):
    for j in range(m):
        if a[i][j] == 'O':
            hx,hy = i,j # hole
        elif a[i][j] == 'R':
            rx,ry = i,j
            a[i][j] = '.' #Red (place to move)
        elif a[i][j] == 'B':
            bx,by = i,j
            a[i][j] = '.'
q.append((rx,ry,bx,by)) # start position
d[rx][ry][bx][by] = 0 # distance : how many turn 
found = False
while q:
    rx,ry,bx,by = q.popleft() # move toward 4 direction 
    for k in range(4):
        # a : map or array , k : direction
        hole1,hole2,nrx,nry,nbx,nby = go(a,rx,ry,bx,by,k)
        if hole2: # blue
            continue
        if hole1: # red
            found = True
            ans = d[rx][ry][bx][by] + 1 # always minimum at BFS
            break
        if d[nrx][nry][nbx][nby] != -1: # already visited
            continue
        q.append((nrx,nry,nbx,nby)) # first visit -> put in queue
        d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1 
    if found:
        break
print(ans)