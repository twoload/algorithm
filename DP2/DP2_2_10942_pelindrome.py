# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# pelindrome
# n = 1 -> (O)
# n = 2 -> if two is the same -> (O)
# n = 3 -> if first and third are the same -> (O)
# p(s,e) = if first and end are the same, p(s+1, e-1)
import sys
sys.setrecursionlimit(100000) # default:1000
input = sys.stdin.readline # prevent timeout

n = int(input())
a = list(map(int, input().split()))
m = int(input())
d = [[-1]*n for _ in range(n)]
""" 
# topdown
def go(i, j):
    if i == j:
        return 1
    elif i + 1 == j:
        if a[i] == a[i+1]:
            return 1
    if d[i][j] >= 0:
        return d[i][j]
    if a[i] != a[j]:
        d[i][j] = 0
    else:
        d[i][j] = go(i+1, j-1)
    return d[i][j]

for _ in range(m):
    i, j = map(int, input().split())
    print(go(i-1,j-1)) # 0~i-1
"""
# bottom up
for i in range(n):
    d[i][i] = True
for i in range(n-1):
    if a[i] == a[i+1]:
        d[i][i+1] = True
for k in range(3, n+1):
    for i in range(0, n-k+1):
        j = i+k-1
        if a[i] == a[j] and d[i+1][j-1]:
            d[i][j] = True
for _ in range(m):
    s,e = map(int,sys.stdin.readline().split())
    print(1 if d[s-1][e-1] else 0)

