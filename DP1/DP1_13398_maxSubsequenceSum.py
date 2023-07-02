#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

n = int(input())
a = list(map(int, input().split()))
d = [0]*(n+1)
dr = [0]*(n+1)

for i in range(n):
    d[i] = a[i]
    dr[i] = a[i]

for i in range(n):
    if i-1 < 0:
        continue
    if d[i] < d[i-1]+a[i]:
        d[i] = d[i-1]+a[i]

for i in range(n-1, -1, -1):
    if i+1 > n-1:
        continue
    if dr[i] < dr[i+1]+a[i]:
        dr[i] = dr[i+1]+a[i]
        
ans = max(d)
for k in range(n):
    if k-1 < 0:
        continue
    if k+1 > n-1:
        continue
    if ans < d[k-1] + dr[k+1]:
        ans = d[k-1] + dr[k+1]
        
print(ans)