# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# problem: https://www.acmicpc.net/problem/17071

from collections import deque
"""
Subin can move the same position every 2 second (+1, -1)
if Subin arrives at a position at odd time, she can reach there at odd time
if Subin arrives at a position at even time, she can reach there at even time
"""
# dist[v][i] : the fastest time when Subin arrives at v 
#              (i=0, even time)
#              (i=1, odd time)
dist = [[-1]*2 for _ in range(500001)]
n, k = map(int,input().split())
q = deque()
q.append((n, 0)) 
dist[n][0] = 0 # Subin is at n, 0 odd time, fastest time is 0
while q:
    x, t = q.popleft() 
    # x -> y , t:odd/even
    # (x, t) -> (y, 1-t) : move one // 0 -> 1, 1 -> 0 (odd/even)
    for y in [x+1, x-1, 2*x]:  
        if 0 <= y <= 500000:
            if dist[y][1-t] == -1:
                dist[y][1-t] = dist[x][t] + 1 # the fastest time
                q.append((y, 1-t))
                
# at odd/even time, we found all fastest time of each position so far
ans = -1
t = 0
while True:
    k += t # brother's position after t seconds
    if k > 500000:
        break
    # if the fastest time when subin arrives at k position is less than t,
    if dist[k][t%2] <= t: # t%2 : odd/even, 
        ans = t
        break
    t += 1
print(ans)

# 500000 x 2 = 1000000 