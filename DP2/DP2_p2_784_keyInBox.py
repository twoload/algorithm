# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# box: 1 2
# key: 1 2 : bom 1 -> key 1 -> can't open 2 (X)
# key: 2 1 : bom 1 -> key 2 -> can open 2 (O)
# box: 1,2,3,4,......n (n)
# key: ?,?,?,?,......? : num of bom (m)

# problem to find num of permutation of n length 
#    with num of cycle is not over m
# = Stirling numbers of the first kind
# d[i][j] = length i permutation(1~i)
#           cycle num: j

# d[i][j] = d[i-1][j-1] + d[i-1][j]*(i-1)
# 1 2 .... i-1 i
# 1) if i-th make cycle alone,
#    d[i-1][j-1]
# 2) if i-th is inluded in previous cycle,
#    d[i-1][j]*(i-1) // i-th comes in previous cycle

n, m = map(int, input().split())

def gcd(x,y):
    if y==0:
        return x
    else:
        return gcd(y,x%y)

d = [[0]*(n+1) for _ in range(n+1)]

d[1][1] = 1

for i in range(2,n+1): # 2~n
    for j in range(1,i+1): # 1~n
        d[i][j] = d[i-1][j-1] + (i-1)*d[i-1][j]

bunja = 0
for i in range(1,m+1): # 1~m (bom 1,2,3,...m)
    bunja += d[n][i]

bunmo = 1
for i in range(1,n+1):
    bunmo *= i # n!

g = gcd(bunja,bunmo)
bunja //= g
bunmo //= g
print(f'{bunja}/{bunmo}')

