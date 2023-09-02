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

def go(index, start, n, m):
    if index == m:
        sys.stdout.write(' '.join(map(str,a))+'\n')
        return
    for i in range(n):
        if c[i]: 
            continue
        c[i] = True
        a[index] = num[i]
        go(index+1, start, n, m)
        c[i] = False
        
go(0,0,n,m)