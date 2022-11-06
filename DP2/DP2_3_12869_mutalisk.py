# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[i][j][k] : min attack number at i,j,k power
# (1,2,3) d[i-9][j-3][k-1]
# (1,3,2) d[i-9][j-1][k-3]
# ...
# (3,2,1) d[i-1][j-3][k-9]

n = int(input())
scv = list(map(int, input().split()))
while len(scv) < 3:
    scv += [0]
# power 1~60, minus~0: 0 -> 61 cases
d = [[[-1]*61 for j in range(61)] for i in range(61)]
def go(i,j,k): # advantage: param can be minus
    if i < 0:
        return go(0,j,k)
    if j < 0:
        return go(i,0,k)
    if k < 0:
        return go(i,j,0)
    if i==0 and j==0 and k==0: # mutalisk all destruction
        return 0
    ans = d[i][j][k] # memoization
    if ans != -1:
        return ans
    ans = 10000000 # max init
    # attack all orders
    #    find minimum attack number
    #    permutation can be used (from itertools import permutations)
    if ans > go(i-1,j-3,k-9):
        ans = go(i-1,j-3,k-9)
    if ans > go(i-1,j-9,k-3):
        ans = go(i-1,j-9,k-3)
    if ans > go(i-3,j-1,k-9):
        ans = go(i-3,j-1,k-9)
    if ans > go(i-3,j-9,k-1):
        ans = go(i-3,j-9,k-1)
    if ans > go(i-9,j-1,k-3):
        ans = go(i-9,j-1,k-3)
    if ans > go(i-9,j-3,k-1):
        ans = go(i-9,j-3,k-1)
    ans += 1 # this time fight
    # r = 1 + go(i-1,j-3,k-9)
    # ans = min(ans, r)
    d[i][j][k] = ans
    return d[i][j][k]

print(go(scv[0],scv[1],scv[2]))
        
