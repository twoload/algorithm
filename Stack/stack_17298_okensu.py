#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

n = int(input())
a = list(map(int,input().split()))
ans = [0]*n
s = [0]
for i in range(1, n):
    if not s:
        s.append(i)
    while s and a[s[-1]] < a[i]:
        ans[s.pop()] = a[i]
    s.append(i)
while s:
    ans[s.pop()] = -1
print(' '.join(map(str,ans)))