# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

import sys
from collections import deque
dx1 = [-2,-1,1,2,2,1,-1,-2] # knight
dy1 = [1,2,2,1,-1,-2,-2,-1] 
dx2 = [0,0,1,-1] # rook
dy2 = [1,-1,0,0]
dx3 = [1,1,-1,-1] # bishop
dy3 = [1,-1,1,-1]
n = int(input())
# chess board number
a = [list(map(int,input().split())) for _ in range(n)]
# d[x][y][num][piece] 
d = [[[[-1]*3 for k in range(n*n)] for j in range(n)] for i in range(n)]
q = deque()
for i in range(n):
    for j in range(n):
        a[i][j] -= 1 # 1~N^2 => 0~n^2-1
        if a[i][j] == 0: # start point
            for k in range(3): # knight,rook,bishop
                d[i][j][0][k] = 0 # start distance init
                q.append((i,j,0,k))
   
ans = -1
while q:
    x,y,num,piece = q.popleft() # num -> num+1
    if num == n*n-1: # finish 
        # because reach n^2-1 several times,
        #   it needs to compare : ans > d[][][][]
        if ans == -1 or ans > d[x][y][num][piece]: # minimum of answer
            ans = d[x][y][num][piece]
    # change piece > +1
    for i in range(3): 
        if piece == i:
            continue
        if d[x][y][num][i] == -1:
            d[x][y][num][i] = d[x][y][num][piece] + 1
            q.append((x,y,num,i))
    # move    
    if piece == 0: # knight
        for k in range(8):
            nx,ny = x+dx1[k],y+dy1[k]
            if 0 <= nx < n and 0 <=ny < n:
                next_num = num
                # num -> num + 1
                if a[nx][ny] == num+1: # if find next position,  
                    next_num = num+1
                if d[nx][ny][next_num][piece] == -1:
                    d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1
                    q.append((nx,ny,next_num,piece))
    elif piece == 1: #rook
        for k in range(4):
            l = 1
            while True:
                nx,ny = x+dx2[k]*l,y+dy2[k]*l
                if 0 <= nx < n and 0 <= ny < n:
                    next_num = num
                    if a[nx][ny] == num+1: # if find next position,  
                        next_num = num+1
                    if d[nx][ny][next_num][piece] == -1:
                        d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1
                        q.append((nx,ny,next_num,piece))
                else:
                    break
                l += 1
    else: #bishop
        for k in range(4):
            l = 1
            while True:
                nx,ny = x+dx3[k]*l,y+dy3[k]*l
                if 0 <= nx < n and 0 <= ny < n:
                    next_num = num
                    if a[nx][ny] == num+1: # if find next position,  
                        next_num = num+1
                    if d[nx][ny][next_num][piece] == -1:
                        d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1
                        q.append((nx,ny,next_num,piece))
                else:
                    break
                l += 1
                
print(ans)
                
                    
                            
