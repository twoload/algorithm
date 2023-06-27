#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#!/usr/bin/python3
from collections import deque
n, m = map(int,input().split())
q = deque()
for i in range(1, n+1):
    q.append(i)
ans = []
for i in range(n-1):
    for j in range(m-1):
        q.append(q.popleft())
    ans += [q.popleft()]
    
ans += [q[0]]
print('<' + ', '.join(map(str,ans)) + '>')