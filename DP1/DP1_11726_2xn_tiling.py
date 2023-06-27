#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

n = int(input())
d = [0]*1001
d[0] = 1
d[1] = 1
for i in range(2, n+1):
    d[i] = d[i-1] + d[i-2]
    d[i] %= 10007
print(d[n])