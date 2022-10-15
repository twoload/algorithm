# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.


# Sol1: DP[i][j] : max candy number at (i,j)
#       (1,1) start, (i,j) arrival
#       (1,1) ->...(*)-> (i, j)
n,m = map(int, input().split())
#a = [[0]*(m+1) for _ in range(n+1)]
a = [[0]*(m+1)] + [[0] + list(map(int, input().split())) for _ in range(n)]
d = [[0]*(m+1) for _ in range(n+1)]

#for i in range(n):
#    a[i+1][1:] = map(int, input().split())

#print(n, m)
#print(a)
# O(NM)
for i in range(1, n+1):
    for j in range(1, m+1):
       d[i][j] = max(d[i-1][j], d[i][j-1], d[i-1][j-1]) + a[i][j] 
       #print(f'dp({i},{j}) = {d[i][j]}')
       
print(d[n][m])
