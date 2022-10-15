# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.


# BFS + dynamic

from collections import deque
MAX = 200000 # 0~100000 : any  number over 1000001
check = [False]*MAX
dist = [0]*MAX
cnt = [0]*MAX
# n : Subin, m : sister
n,m = map(int,input().split())
# n : start position
check[n] = True # visited
dist[n] = 0 # distance
cnt[n] = 1 # number of way
q = deque()
q.append(n)
while q:
    now = q.popleft() # start position
    for next in [now-1, now+1, now*2]: # next position
        if 0 <= next < MAX: # range check
            if not check[next]: # not visited
                q.append(next)
                check[next] = True
                dist[next] = dist[now] + 1
                cnt[next] = cnt[now] # same way
            elif dist[next] == dist[now] + 1: # same dist
                cnt[next] += cnt[now]
                
print(dist[m])
print(cnt[m])

            
        
        
    