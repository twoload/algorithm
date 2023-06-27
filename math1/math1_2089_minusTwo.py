#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#!/usr/bi/python3
def go(n):
    if n == 0:
        return
    if n % 2 == 0:
        go(-(n//2))
        print(0,end='')
    else:
        if n > 0:
            go(-(n//2))
        else:
            go((-n+1)//2)
        print(1,end='')
n = int(input())
if n == 0:
    print(0)
else:
    go(n)
        