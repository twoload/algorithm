# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

#d[n]: max num of A when n-pushing 
# print A : d[i] = d[i-1] + 1
# ctrl-A
# ctrl-C
# ctrl-v : push-i  , d[i] = d[i-(j+2)]*(j+1), 1<=j<=i-3 
n = int(input()) # 1<=n<=100

"""
d = [0]*(n+1)
for i in range(1,n+1):
    d[i] = max(d[i], d[i-1] + 1)
    for j in range(1,n+1):
        if j < 1 or j > n-3:
            continue
        d[i] = max(d[i], d[i-(j+2)]*(j+1))
        
print(d[n])
"""        
d = [0]*(n+1)
for i in range(1,n+1):
    d[i] = d[i-1] + 1
    for j in range(1,n-3+1):
        cur = d[i-(j+2)]*(j+1)
        if cur > d[i]:
            d[i] = cur
print(d[n])



