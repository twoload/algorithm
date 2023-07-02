#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


n = int(input())
d = [0]*(n+1)
for i in range(1, n+1):
    d[i] = i
    j = 1
    while j*j <= i:
        if d[i] > d[i-j*j]+1:
            d[i] = d[i-j*j]+1
        j += 1
print(d[n])    
        