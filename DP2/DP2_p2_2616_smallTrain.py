# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# n : total
# m : num subs that small train leads (1 < m < n/3)
# small train : 3 num 
#    leading continous subs (m)
# 1.........n
# d[a][b][c] : max num of customers to be able to carry
#    a : start pos of A
#    b : start pos of B
#    c : start pos of C
#    b >= a+m
#    c >= b+m
#    n >= c+m

# d[i][j] : when comes i-th person, 
#           max customer num to carry with j small train
# .........i  , j-th small train
#      <-k->
# 1) j-th small train carries i
#    d[i-k][j-1] + sum of a[i](i-k+1 ~ i)
# 2) j-th small train doesn't carry i
#    d[i-1][j]
# max of 1) and 2)
# d[i][j] = max(d[i-1][j], d[i-m][j-1] + sum(a[i-m+1:i]))

n = int(input())
a = [0] + list(map(int, input().split()))
m = int(input())
d = [[0]*(4) for _ in range(n+1)]

def sum(x,y):
    return s[y] - s[x-1] # x~y

s = [0] * (n+1)
for i in range(1,n+1):
    s[i] = s[i-1] + a[i]

for j in range(1,3+1): # 1~3
    for i in range(m*j, n+1): # because train carry min m 
        d[i][j] = d[i-1][j]
        d[i][j] = max(d[i][j], d[i-m][j-1] + sum(i-m+1, i))
print(d[n][3])        