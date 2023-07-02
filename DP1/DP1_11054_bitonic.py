#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

# s1 < s2 < ... < sk-1 < sk > sk+1 > sk+2 > ... > sn

# ascending , descending

# 0~i,    i~n-1
# ascend  descend
# max

# teacher
# d[k] + d2[k] - 1
# d[i] = i-th end asending
# d2[i]= i-th start descending

n = int(input())
a = list(map(int, input().split()))
d1 = [0]*n
d2 = [0]*n
for i in range(n): # j , i (ascending)
    d1[i] = 1
    for j in range(i):
        if a[j] < a[i] and d1[j]+1 > d1[i]:
            d1[i] = d1[j]+1
for i in range(n-1, -1, -1): # i, j (descending)
    d2[i] = 1
    for j in range(i+1, n):
        if a[i] > a[j] and d2[j]+1 > d2[i]:
            d2[i] =  d2[j]+1
d = [d1[i]+d2[i]-1 for i in range(n)]
print(max(d))
