# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 1 <= N <= 40
# all subsequence's num : 2^N-1
# if N <= 20 : 1048576
# if N <= 40 : too big

n,s= map(int,input().split())
a = list(map(int,input().split()))
# divide a into two (time complexity)
m = n//2
n = n-m
# a = [1,2,1,3,2,1]
# up = [1,2,1]
# down = [3,2,1]
first = [0]*(1<<n) # 2^n
for i in range(1<<n): # n = 3 : 2^3 = 8
    for k in range(n): # 0,1,2
        if (i&(1<<k)) > 0: # each bit : contain, not contain
            # i = 0 -> x = 0
            # i = 1 -> (1<<k = 1,2,4) = +=a[k] = a[0]=1
            # i = 2 -> (1,2,4) = 2 +=a[1] = 2
            # i = 3 -> (1,2,4) = 1,2 = 3 +=a[0]+a[1]=3
            # i = 4 -> (1,2,4) = 4 +=a[2]=1
            # i = 5 -> (1,2,4) = 1,4 = a[0]+a[2]=2
            # i = 6 -> (1,2,4) = 2,4 = a[1]+a[2]=3
            # i = 7 -> (1,2,4) = 1,2,4 = a[0]+a[1]+a[2]=4
            first[i] += a[k]
second = [0]*(1<<m)
for i in range(1<<m):
    for k in range(m):
        if (i&(1<<k)) > 0:
            second[i] += a[k+n]
first.sort() # increasing
second.sort() 
second.reverse() # decreasing
n = (1<<n)
m = (1<<m)
i = 0
j = 0
ans = 0
while i<n and j<m:
    if first[i] + second[j] == s:
        c1 = 1
        c2 = 1
        i += 1
        j += 1
        while i<n and first[i] == first[i-1]: # move until diff
            c1 += 1
            i += 1
        while j<m and second[j] == second[j-1]: # move until diff
            c2 += 1
            j += 1
        ans += c1*c2
    elif first[i] + second[j] < s:
        i += 1
    else:
        j += 1
# first = [0,1,1,2,2,3,3,4]
# second = [0,1,2,3,3,4,5,6]
if s == 0: # first=0, second=0 -> impossible 
    ans -= 1
print(ans)