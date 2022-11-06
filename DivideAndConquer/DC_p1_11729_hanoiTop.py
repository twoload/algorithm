# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 1<=n<=20
# output k : num of movement
# output : movement process

# solve(n,x,y) : move 1~n plate from x to y
# 1. move 1~n-1 from x to z
# 2. move n-th from x to y
# 3. move 1~n-1 from z to y
import sys

def solve(n,x,y):
    if n == 0:
        return
    # z = 6-x-y (1+2+3=6)
    solve(n-1, x, 6-x-y) # 1
    sys.stdout.write('%d %d\n' %(x,y)) # 2 
    solve(n-1, 6-x-y, y) # 3
    
n = int(input())
# d[n] = min movement num
# d[1] = 1
# d[n] = 2*d[n-1] + 1
# d[n]+1 = 2*(d[n-1]+1), e[n] = d[n]+1
# e[n] = 2*e[n-1]
# e[1] = 2
# e[n] = 2^n
# d[n] = 2^n - 1
print(2**n-1)
solve(n,1,3)