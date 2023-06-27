#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

def gcd(x,y):
    if y == 0:
        return x
    else:
        return gcd(y, x%y)
t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    n = a[0]
    a = a[1:]
    ans = 0
    for i in range(0, n-1):
        for j in range(i+1, n):
            ans += gcd(a[i], a[j])
    print(ans)