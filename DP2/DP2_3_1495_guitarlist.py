# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[i] : max volume at i-th song
# BruteForce O(2^N) : N 50 -> too big
# volume range : 0 ~ M(1000) -> DP is possible
#    -> O(NM) : DP
# d[i][j] : i-th song, j volume -> True, False
# if d[i][j] is True,
#    d[i+1][j+v[i+1]], d[i+1][j-v[i+1]] will be True 

n, s, m = map(int, input().split())
v = [0]+list(map(int, input().split()))
d = [[False]*(m+1) for _ in range(n+1)]
d[0][s] = True
for i in range(n):
    for j in range(m+1):
        if d[i][j] == False:
            continue
        if j-v[i+1] >= 0:
            d[i+1][j-v[i+1]] = True
        if j+v[i+1] <= m:
            d[i+1][j+v[i+1]] = True    
ans = -1
for i in range(m+1):
    if d[n][i]:
        ans = i
print(ans)
            
    