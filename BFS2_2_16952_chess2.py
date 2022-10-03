# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

import sys
from collections import deque
from typing import List, Dict
dx1 = [-2,-1,1,2,2,1,-1,-2] # knight
dy1 = [1,2,2,1,-1,-2,-2,-1] 
dx2 = [0,0,1,-1] # rook
dy2 = [1,-1,0,0]
dx3 = [1,1,-1,-1] # bishop
dy3 = [1,-1,1,-1]

# d[][][][] = {"d": , "c":}
# -> return value 1 element => other idea : d array, c array 2 element can be eaiser to implement

def compare_dict(a:Dict[str,int], b:Dict[str,int]):
    if a["d"] == b["d"]:
        if a["c"] < b["c"]:
            return 1
        elif a["c"] == b["c"]:
            return 0
        else:
            return -1
    elif a["d"] < b["d"]:
        return 1
    else:
        return -1

n = int(input())
# chess board number
a = [list(map(int,input().split())) for _ in range(n)]
# (min_dist, min_change) = d[x][y][num][piece] 
d = [[[[{"d":-1,"c":-1}]*3 for k in range(n*n)] for j in range(n)] for i in range(n)]
q = deque()


for i in range(n):
    for j in range(n):
        a[i][j] -= 1 # 1~N^2 => 0~n^2-1
        if a[i][j] == 0: # start point
            for k in range(3): # knight,rook,bishop
                d[i][j][0][k] = {"d":0,"c":0} # start distance,change init
                q.append((i,j,0,k))
                #print(f'st: [{i},{j},{0},{k}] = [0,0]')
   
ans = {"d":-1,"c":-1}

while q:
    x,y,num,piece = q.popleft() # num -> num+1
    if num == n*n-1: # finish 
        # because reach n^2-1 several times,
        #   it needs to compare : ans > d[][][][]
        #print(f'>>> d = {d[x][y][num][piece]}')
        if ans["d"] == -1 or compare_dict(ans, d[x][y][num][piece])==-1: # minimum of answer
            ans = d[x][y][num][piece]
            #print(f'ans: [{x},{y},{num},{piece}] = [ans["c"],ans["c"]]')

    # change piece > +1
    for i in range(3): 
        if piece == i:
            continue
        #print(f'(change piece) d[{x}][{y}][{num}][{piece}] = {d[x][y][num][piece]}')
        np = {"d": d[x][y][num][piece]["d"] + 1, "c":d[x][y][num][piece]["c"] + 1}
        #print(f'np = {np}')
        if d[x][y][num][i]["d"] == -1 or compare_dict(d[x][y][num][i], np)==-1:
            d[x][y][num][i] = np
            q.append((x,y,num,i))
            #print(f'change: [{x},{y},{num},{i}] = [{np["d"]}][{np["c"]}]')

    # move    
    if piece == 0: # knight
        for k in range(8):
            nx,ny = x+dx1[k],y+dy1[k]
            #print(f'knight move {x},{y}->{nx},{ny}')
            if 0 <= nx < n and 0 <=ny < n:
                next_num = num
                # num -> num + 1
                #print(f'> next_num : {next_num}, a[nx][ny] : {a[nx][ny]}')
                if a[nx][ny] == num+1: # if find next position,  
                    next_num = num+1
                    #print(f'> next_num of knight {num}->{next_num}')
                np = {"d": d[x][y][num][piece]["d"] + 1, "c":d[x][y][num][piece]["c"]}
                if d[nx][ny][next_num][piece]["d"] == -1 or compare_dict(d[nx][ny][next_num][piece], np)==-1:
                    d[nx][ny][next_num][piece] = np
                    q.append((nx,ny,next_num,piece))
                    #print(f'knight: [{nx},{ny},{next_num},{piece}] = [{np["d"]}][{np["c"]}]')
    elif piece == 1: #rook
        for k in range(4):
            l = 1
            while True:
                nx,ny = x+dx2[k]*l,y+dy2[k]*l
                if 0 <= nx < n and 0 <= ny < n:
                    next_num = num
                    if a[nx][ny] == num+1: # if find next position,  
                        next_num = num+1
                    np = {"d": d[x][y][num][piece]["d"] + 1, "c":d[x][y][num][piece]["c"]}
                    #print(f'<----[{nx},{ny},{next_num},{piece}] d:({d[nx][ny][next_num][piece]["d"]},{d[nx][ny][next_num][piece]["c"]}) , np:({np["d"]},{np["c"]})')
                    if d[nx][ny][next_num][piece]["d"] == -1 or compare_dict(d[nx][ny][next_num][piece], np)==-1: # mistake: d[nx][ny]...(O), d[x][y]...(X) in compare_dict
                        d[nx][ny][next_num][piece] = np
                        q.append((nx,ny,next_num,piece))
                        #print(f'rook: [{nx},{ny},{next_num},{piece}] = [{np["d"]}][{np["c"]}]')
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
                    np = {"d": d[x][y][num][piece]["d"] + 1, "c":d[x][y][num][piece]["c"]}
                    if d[nx][ny][next_num][piece]["d"] == -1 or compare_dict(d[nx][ny][next_num][piece], np)==-1:
                        d[nx][ny][next_num][piece] = np
                        q.append((nx,ny,next_num,piece))
                        #print(f'bishop: [{nx},{ny},{next_num},{piece}] = [{np["d"]}][{np["c"]}]')
                else:
                    break
                l += 1               
print(ans["d"], ans["c"])
                
                    
                             
