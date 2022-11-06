# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

#d[i][j] : num of way to reach the goal
#d[i][j] += d[i][k], j == k+a[i][k], 0<= k <j
#d[i][j] += d[k][j], i == k+a[k][j], 0<= k <i
n = int(input())
a = [list(map(int,input().split())) for _ in range(n)]
d = [[0]*n for _ in range(n)] 

d[0][0] = 1
for i in range(n):
    for j in range(n):
        if i == 0 and j == 0:
            continue
        for k in range(j):
            if k + a[i][k] == j:
                d[i][j] += d[i][k]
        for k in range(i):
            if k + a[k][j] == i:
                d[i][j] += d[k][j]
print(d[n-1][n-1])