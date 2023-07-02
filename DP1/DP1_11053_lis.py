#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


n = int(input())
a = list(map(int, input().split()))
d = [0]*n
for i in range(n):
    d[i] = 1
    for j in range(i):
        if a[j] < a[i] and d[j]+1 > d[i]:
            d[i] = d[j]+1
print(max(d))