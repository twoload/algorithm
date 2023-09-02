#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
import sys
n,m = map(int, input().split())
num = list(map(int, input().split()))
a = [0]*m
c = [False]*n
num.sort()

def go(index, selected, n, m):
    if selected == m:
        sys.stdout.write(' '.join(map(str,a))+'\n')
        return
    
    if index >= n:
        return
    # selected
    a[selected] = num[index]
    go(index+1, selected+1, n, m)
    # no select
    a[selected] = 0
    go(index+1, selected, n, m)
        
go(0,0,n,m)