#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

"""
import sys
n,m = map(int, input().split())
c = [False] * (n+1)
a = [0]*n
def go(index, start, n, m):
    if index == m:
        for i in range(m):
            sys.stdout.write(str(a[i])+' ')
        sys.stdout.write('\n')
        return
    for i in range(start, n+1):
        c[i] = True
        a[index] = i
        go(index+1, i, n, m)
        c[i] = False
        
go(0,1,n,m)
"""

import sys
n,m = map(int, input().split())
cnt = [0]*(n+1)
def go(index, selected, n, m):
    if selected == m:
        for i in range(1, n+1):
            for j in range(cnt[i]):
                sys.stdout.write(str(i)+' ')
        sys.stdout.write('\n')
        return
    if index > n:
        return
    # select
    # 1111  : the smallest   
    # 111
    # 11
    # 1
    for i in range(m-selected, 0, -1):
        cnt[index] = i # how many included
        go(index+1, selected+i, n, m)
    # no select
    cnt[index] = 0
    go(index+1, selected, n, m)

go(1,0,n,m)    
        