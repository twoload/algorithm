#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

# d[n] : max sum at len n
# d[i] = max(d[j] + a[i])
#        j < i
#        a[j] < a[i]
# d[0] = 0
# d[i] = a[i] 

n = int(input())
a = list(map(int, input().split()))
d = [0]*n
for i in range(n):
    d[i] = a[i]
    for j in range(i):
        if a[j] < a[i] and d[j]+a[i] > d[i]:
            d[i] = d[j]+a[i]
print(max(d))