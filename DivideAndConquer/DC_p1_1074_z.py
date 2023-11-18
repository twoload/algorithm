# I've attended the code.plus class (https://code.plus/)
# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

def power2(k):
    return 2**k

# visit order number when I visit x,y
# 1  2
# 3  4
def go(n,x,y):
    if n==1: # 2x2
        return 2*x+y
    else:
        if x < power2(n-1):
            if y < power2(n-1): # area 1
                return go(n-1,x,y)
            else: # area 2
                return go(n-1,x,y-power2(n-1))+power2(2*n-2)
        else:    
            if y < power2(n-1): # area 3
                return go(n-1,x-power2(n-1),y)+power2(2*n-2)*2
            else: # area 4
                return go(n-1,x-power2(n-1),y-power2(n-1))+power2(2*n-2)*3
# example
# go(2,3,1)
#   if 3 > 2 in x
#   if 1 < 2 in y # area3
#      =go(1,3-2,1)+2^(2)*2
#      =go(1,1,1)+4*2

n,x,y = map(int,input().split())
print(go(n,x,y))