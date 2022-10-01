# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# problem: https://www.acmicpc.net/problem/8111

from collections import deque
# (A+B) % C = ((A%C) + (B%C)) %C
# (A*B) % C = ((A%C) * (B%C)) %C
t = int(input())
for _ in range(t):
    n = int(input())
    
    if n == 1:
        print(1)
        continue
    
    via = [-1]*(n+1) # x -> y : via[y] = x
    how = [-1]*(n+1) # 0, 1
    dist = [-1]*(n+1) # length of number
    q = deque()

    q.append(1) # put 1 into q
    dist[1] = 1
    how[1] = 1
    """
    q.append(1%n)  # 1%n : includes n=1 case
    dist[1%n] = 1
    how[1%n] = 1
    """
    while q:
        now = q.popleft()
        for i in [0,1]:
            next = (now*10+i)%n
            if dist[next] == -1:
                dist[next] = dist[now] + 1
                via[next] = now
                how[next] = i
                q.append(next)
    if dist[0] == -1: # remainder = 0
        print('BRAK')
    else:
        ans = ''
        i = 0
        while i != -1:
            ans += str(how[i])
            i = via[i]
        print(ans[::-1])
    
    

