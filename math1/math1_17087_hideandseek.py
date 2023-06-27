#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x%y)
n, s = map(int, input().split())
a = list(map(int, input().split()))
a = [abs(x-s) for x in a]
ans = a[0]
for i in range(1, n):
    ans = gcd(ans, a[i])
print(ans)