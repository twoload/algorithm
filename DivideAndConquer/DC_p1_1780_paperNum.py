# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 1<=n<=3^7

# solve(x,y,n) : paper number in (x,y)~(x+n-1,y+n-1)
# m = n/3
# 0: solve(x,y,m)
# 1: solve(x,y+m,m)
# 2: solve(x,y+2*m,m)
# 3: solve(x+m,y,m)
# 4: ...

import sys
# check if all are same in (x,y)~(x+n-1,y+n-1)
def same(a,x,y,n): 
    for i in range(x,x+n):
        for j in range(y,y+n):
            if a[x][y] != a[i][j]:
                return False
    return True

# cnt[0],cnt[1],cnt[2] // -1,0,1
def solve(a,cnt,x,y,n):
    if same(a,x,y,n):
        cnt[a[x][y]+1] += 1 # a[x][y] = -1,0,1
        return
    m = n//3 # divide
    for i in range(3):
        for j in range(3):
            solve(a,cnt,x+i*m,y+j*m,m)
    
n = int(sys.stdin.readline())
a = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cnt = [0]*3 
solve(a,cnt,0,0,n)
print('\n'.join(map(str,cnt)))   