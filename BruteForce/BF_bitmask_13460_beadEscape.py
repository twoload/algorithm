# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

dx = [0,0,1,-1] # row
dy = [1,-1,0,0] # colume
LIMIT = 10
class Result:
    def __init__(self, moved, hole, x, y):
        self.moved = moved
        self.hole = hole
        self.x = x
        self.y = y
        
# return: lenth 10 array (4:quartenary)
def gen(k):
    a = [0]*LIMIT # len:10
    for i in range(LIMIT):
        a[i] = (k&3) # 4 cases (00,01,10,11)
        k >>= 2
        # a[i] = k%4
        # k /= 4
    return a

def simulate(a, k, x, y): # k: direction, x, y
    n = len(a)
    m = len(a[0])
    if a[x][y] == '.':
        return Result(False, False, x, y)
    moved = False
    while True:
        nx, ny = x+dx[k], y+dy[k]
        # out of range
        if nx < 0 or nx >=n or ny < 0 or ny >= m:
            return Result(moved, False, x, y)
        ch = a[nx][ny]
        if ch == '#':
            return Result(moved, False, x, y)
        elif ch in 'RB':
            return Result(moved, False, x, y)
        elif ch == '.': # empty
            # . R -> R .
            a[x][y],a[nx][ny] = a[nx][ny],a[x][y]
            n,y  = nx,ny
            moved = True
        elif ch == 'O': # hole
            a[x][y] = '.'
            moved = True
            return Result(moved, True, x, y)
        
def check(a, dirs):
    n = len(a)
    m = len(a[0])
    hx,hy = 0,0
    rx,ry = 0,0
    bx,by = 0,0
    
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'O':
                hx,hy = i,j # hole location x,y
            elif a[i][j] == 'R':
                rx,ry = i,j # red bead x,y
            elif a[i][j] == 'B':
                bx,by = i,j # blue bead x,y
    
    cnt = 0 # movement count
    for k in dirs: # k-th directions
        cnt += 1
        hole1 = hole2 = False
        while True:
            p1 = simulate(a, k, rx, ry) # move red bead to k direction
            rx,ry = p1.x, p1.y
            p2 = simulate(a, k, bx, by) # move blue bead to k direction
            bx,by = p2.x, p2.y
            
            # first: move or not
            # second : meet hole or not
            if not p1.moved and not p2.moved: # until no move
                break
            if p1.hole:
                hole1 = True
            if p2.hole:
                hole2 = True
                
        if hole2:
            return -1
        if hole1:
            return cnt
        
    return -1

def valid(dirs):
    l = len(dirs)
    for i in range(l-1): # where, 1<=i+1<=l-1 -> 0<=i<l-1
        # 0: 00 (0,1), 1: 01 (0,-1), 2:10 (1,0), 3:11 (-1,0)
        # 00 is opposite of 01 (0<->1)
        # 10 is opposite of 11 (2<->3)
        if dirs[i] == 0 and dirs[i+1] == 1: # opposite
            return False
        if dirs[i] == 1 and dirs[i+1] == 0: # opposite
            return False
        if dirs[i] == 2 and dirs[i+1] == 3: # opposite
            return False
        if dirs[i] == 3 and dirs[i+1] == 2: # opposite
            return False
        if dirs[i] == dirs[i+1]: # same direction
            return False 
    return True

n,m = map(int, input().split())
original = [input() for _ in range(n)]
#print(original)
ans = -1
for k in range(1<<(LIMIT*2)): # 4^10 (dir:4) = 2^20 : all cases
    dirs = gen(k) # make size 10 quartenary numbers
    if not valid(dirs): # not valid (1.same dir as previous, 2.opposite dir as previous)
        continue
    a = [list(row) for row in original]
    cur = check(a, dirs)
    if cur == -1:
        continue
    if ans == -1 or ans > cur:
        ans = cur
        
print(ans)
            