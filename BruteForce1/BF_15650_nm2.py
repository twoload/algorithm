#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

import sys
n, m = map(int, input().split())
c = [False]*(n+1)
a = [0]*m

# O(n!)

def go(index, start, n, m):
    if index == m:
        sys.stdout.write(' '.join(map(str,a))+'\n')
    for i in range(start, n+1):
        if c[i]:
            continue
        c[i] = True
        a[index] = i
        go(index+1, i+1, n, m)
        c[i] = False
        
go(0,1,n,m)

# select: O, X
# O(2^n)
"""
import sys
n, m = map(int, input().split())
a = [0]*m
def go(index, selected, n, m):
    if selected == m:
        sys.stdout.write(' '.join(map(str,a))+'\n')
        return
    if index > n:
        return
    a[selected] = index
    go(index+1, selected+1, n, m) #selected:o
    a[selected] = 0
    go(index+1, selected, n, m) #selected:x
    
go(1,0,n,m)
"""