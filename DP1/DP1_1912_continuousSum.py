#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


n = int(input())
a = list(map(int, input().split()))
d = [0]*n
for i in range(n):
    d[i] = a[i]
    if i == 0:
        continue
    if d[i] < d[i-1] + a[i]:
        d[i] = d[i-1] + a[i]
print(max(d))