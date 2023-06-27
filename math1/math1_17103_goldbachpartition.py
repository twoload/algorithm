#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


#!/usr/bin/python3
check = [False] * 1000001
primes = []
for i in range(2, 1000001):
    if check[i] == False:
        primes.append(i)
        j = i+i
        while j <= 1000000:
            check[j] = True
            j += i
t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    for p in primes:
        if n - p >= 2 and p <= n - p:
            if check[n-p] == False:
                ans += 1
        else:
            break
    print(ans)