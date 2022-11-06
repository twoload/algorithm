# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 2 <= n < = 100 000
# brute force : O(n^2)

# 1.sort in x index
# 2. dl, dr : nearest distance in left, right
# 3. d = min(dl, dr)
# 4. center -d ~ center + d
#    y-d ~ y+d

# O(nLog^2n) = nlogn (1step) x logn

import sys
from collections import namedtuple
input = sys.stdin.readline
Point = namedtuple('Point', ['x','y'])

def dist(p1: Point, p2: Point):
    return (p1.x-p2.x)**2 + (p1.y-p2.y)**2

def brute_force(a, start, end):
    ans = -1
    for i in range(start, end):
        for j in range(i+1, end+1):
            d = dist(a[i],a[j])
            if ans == -1 or ans > d:
                ans = d
    return ans

def closest(a, start, end):
    n = end-start+1
    if n <= 3:
        return brute_force(a,start,end)
    
    mid = (start+end) // 2
    left = closest(a, start, mid)
    right = closest(a, mid+1, end)
    ans = min(left, right)
    b = []
    # b[] = center-d ~ center+d (in x axis)
    for i in range(start, end+1):
        d = a[i].x - a[mid].x
        if d*d < ans:
            b += [a[i]] # a[i] : Point type, [a[i]] : list type
    # sort by y axis first, sort by x axis next    
    b.sort(key=lambda p: (p.y, p.x))
    m = len(b)
    for i in range(m-1):
        for j in range(i+1, m):
            y = b[j].y - b[i].y # diff in y axis
            if y*y < ans:
                d = dist(b[i], b[j]) # dist between two points
                if d < ans:
                    ans = d
            else: 
                break # because of sorted 
    return ans

n = int(input())
a = [Point(*map(int,input().split())) for _ in range(n)]
a.sort()
print(closest(a, 0, n-1))
    
    
    
    