# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

n = 9
# x,y = (0,0)
# nx,ny = x+dx,y+dy = (0,1), (1,0)
# x,y,nx,ny = (0,0)(0,1) or (0,0)(1,0)
dx = [0,1]
dy = [1,0]
# ex. 
# A1 -> (0,0)
# D3 -> (3,2)
def convert(s):
    return (ord(s[0])-ord('A'),ord(s[1])-ord('1'))
# square: 0,1,2,3,4,5,6,7,8
def square(x,y):
    return (x//3)*3+(y//3)
# not used num in row,col,square
def can(x,y,num):
    return not c[x][num] and not c2[y][num] and not c3[square(x,y)][num]
# what : True/False
#        update num in row, col, square 
def check(x, y, num, what):
    c[x][num] = what
    c2[y][num] = what
    c3[square(x,y)][num] = what
# check out of range
def check_range(x,y):
    return 0<=x<n and 0<=y<n
# go(0) -> go(81) : visit in order
def go(z):
    if z == 81:
        for i in range(n):
            print(''.join(map(str,a[i])))
        return True
    # find x,y axis value
    x = z//n # 0~8
    y = z%n # 0~8
    if a[x][y] != 0:
        return go(z+1)
    else:
        # domino = (x,y)(nx,ny)
        for k in range(2): # left-right, up-down
            nx,ny = x+dx[k],y+dy[k]
            if not check_range(nx,ny):
                continue
            if a[nx][ny] != 0:
                continue
            # consider all i,j cases (1,1),,,,,(9,9)
            for i in range(1, 10): # num: 1~9
                for j in range(1, 10): # num: 1~9
                    # domino' two numbers cannot be the same
                    if i == j:
                        continue
                    # already visit
                    if domino[i][j]:
                        continue
                    # (x,y) = i value ex.(A1)=(0,0)=8
                    # (nx,ny)=j value ex.(B1)=(1,0)=3
                    if can(x,y,i) and can(nx,ny,j):
                        check(x,y,i,True)
                        check(nx,ny,j,True)
                        domino[i][j] = domino[j][i] = True
                        a[x][y] = i
                        a[nx][ny] = j
                        if go(z+1):
                            return True
                        check(x,y,i,False)
                        check(nx,ny,j,False)
                        domino[i][j] = domino[j][i] = False
                        a[x][y] = 0
                        a[nx][ny] = 0
    return False

tc = 1
while True:
    c = [[False]*10 for _ in range(10)] #(1~9)(1~9) : 9x9
    c2 = [[False]*10 for _ in range(10)]
    c3 = [[False]*10 for _ in range(10)]
    domino = [[False]*10 for _ in range(10)]
    a = [[0]*9 for _ in range(9)] # (0~8)(0~8) : 9x9
    m = int(input())
    if m == 0:
        break
    # dominos
    for i in range(m):
        n1,s1,n2,s2 = input().split()
        n1 = int(n1)
        n2 = int(n2)
        x1,y1 = convert(s1)
        x2,y2 = convert(s2)
        a[x1][y1] = n1
        a[x2][y2] = n2
        domino[n1][n2] = domino[n2][n1] = True
        check(x1,y1,n1,True)
        check(x2,y2,n2,True)
    temp = input().split()
    # numbers
    for i in range(1,10): # 1,2,3,4,5,6,7,8,9
        s = temp[i-1]
        x,y = convert(s) # C5 = (2,4)
        a[x][y] = i
        check(x,y,i,True)
    print('Puzzle %d'%tc)
    go(0)
    tc += 1    
        
        
        
        