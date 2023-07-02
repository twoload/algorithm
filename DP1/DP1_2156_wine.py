#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

# d[n][m] : max amount of wine at n-th wine
#           m : num of series of wine

# d[n][3] x
# d[n][2] = max(d[n-1][2] , d[n-1][1] + A[n])
# d[n][1] = max(d[n-1][1], d[n-1][0]+A[n])
# d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2]) ***

# teacher solution#1
# d[n][3] x
# d[n][2] = d[n-1][1]+A[n]
# d[n][1] = d[n-1][0]+A[n])
# d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2]) ***

# teacher solution#2
# series:0 d[i] = d[i-1]
# series:1 d[i] = d[i-2] + a[i] #didn't drink a[i-1]
# series:2 d[i] = d[i-3] + a[i-1] + a[i] # didn't drink a[i-2] and drank a[i-1]
# d[1] = a[1]
# d[2] = a[1] + a[2]

n = int(input())
a = [0] + [int(input()) for _ in range(n)]
d = [0] * (n+1)
d[1] = a[1]
if n >= 2:
    d[2] = a[1]+a[2]
for i in range(3,n+1):
    d[i] = d[i-1]
    d[i] = max(d[i], d[i-2]+a[i])
    d[i] = max(d[i], d[i-3]+a[i]+a[i-1])
print(d[n])



