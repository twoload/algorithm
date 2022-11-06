# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# n <=100,000 : num of building
# 1<=l,r<=1000 000 000
# 1<=h <= 1000 000 000

import sys
from collections import namedtuple
input = sys.stdin.readline
Building = namedtuple('Building',['left','height','right'])
Pair = namedtuple('Pair',['x','height'])

def append(ans: [Pair], p: Pair):
    if ans:
        if ans[-1].height == p.height: # no add if height is the same
            return
        # ans (1,11,5) // left,height,right
        # p (5,3,7)
        #   output : 1 11 5 3 7 0
        # p (5,20,7)
        #   output : 1 11 5 20 7 0
        if ans[-1].x == p.x: 
            ans[-1] = Pair(ans[-1].x, p.height)
            return
    ans += [p]
    
def merge(l: [Pair], r: [Pair]):
    ans = []
    h1 = 0 # skyline height of left
    h2 = 0 # skyline height of right 
    i = 0 # left index
    j = 0 # right index
    while i < len(l) and j < len(r):
        u = l[i]
        v = r[j]
        if u.x < v.x:
            x = u.x
            h1 = u.height
            h = max(h1,h2)
            append(ans, Pair(x,h))
            i += 1
        else:
            x = v.x
            h2 = v.height
            h = max(h1,h2)
            append(ans, Pair(x,h))
            j += 1
    
    # remaining cases        
    while i < len(l):
        append(ans, l[i])
        i += 1
        
    while j < len(r):
        append(ans, r[j])
        j += 1
        
    return ans

def go(a: [Building], start, end):
    if start == end: # building 1 ea
        return [
            Pair(a[start].left, a[start].height),
            Pair(a[start].right, 0)
        ]
    
    mid = (start + end) // 2
    l = go(a, start, mid)
    r = go(a, mid+1, end)
    
    return merge(l,r)

n = int(input())
a = [Building(*map(int,input().split())) for _ in range(n)]
a.sort()
ans = go(a,0,n-1)
for x, height in ans:
    sys.stdout.write('%d %d ' % (x, height))
sys.stdout.write('\n')
    