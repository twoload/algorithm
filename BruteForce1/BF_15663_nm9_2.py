#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
import sys
n,m = map(int, input().split())
num = list(map(int, input().split()))
a = [0]*m
c = [False]*(n+1)
d = []
num.sort()

def go(index, n, m):
    if index == m:
        #sys.stdout.write(' '.join(map(str,a))+'\n')
        temp = [num[a[i]] for i in range(m)]
        d.append(tuple(temp))
        return
    for i in range(n):
        if c[i]: 
            continue
        c[i] = True
        a[index] = i
        go(index+1, n, m)
        c[i] = False
         
go(0,n,m)
d = list(set(d))
d.sort()
for v in d:
    print(' '.join(map(str,v)))