# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

dx = [0,0,1,-1]
dy = [1,-1,0,0]
n,m = map(int, input().split())
a = [input() for _ in range(n)]
ok = True
for i in range(n):
    for j in range(m):
        # if 'S' is adjacent to 'W', False
        if a[i][j] == 'S':
            for k in range(4):
                x,y = i+dx[k], j+dy[k]
                if 0<=x<n and 0<=y<m:
                    if a[x][y] == 'W':
                        ok = False
if not ok:
    print(0)
else:
    print(1)
    for i in range(n):
        for j in range(m):
            # all '.' -> 'D' change
            if a[i][j] == '.':
                print('D',end='')
            else:
                print(a[i][j],end='')
        print()