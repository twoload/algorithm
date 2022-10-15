# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.


# D[i] : arrival of location(i) with min jump

n = int(input())
a = list(map(int, input().split()))
d = [-1]*(1101)
d[0] = 0
# i -> j
#   d[j] = min(d[j], d[i]+1), i<j, j-i <= a[i]
# i -> i + j
#   d[i+j] = min(d[i+j], d[i]+1), 1<j<= a[i]

for i in range(n): # 0 ~ n-1
    if d[i] == -1:
        continue
    for j in range(1,a[i]+1): # 1 <= j <= a[i]
        if i+j >= n: # out of range
            break
        if d[i+j] == -1 or d[i+j] > d[i] + 1:
            d[i+j] = d[i] + 1
            
print(d[n-1])