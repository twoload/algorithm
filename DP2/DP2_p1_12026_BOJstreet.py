# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# 1 -> N (1000)
# B, O, J (index)
# energy consume k*k when jumping k
# d[i][j] : i = location (0 <= i <= n-1)
#           j = B(0), O(1), J(2)
#           min energy consumed
# d[i][j] = min(d[i-k][(3+(j-1))%3] + k*k), where 1<=k<=i

# d[n] = min energy to reach n
# i ---> n
# d[n] = min(d[i] + (n-i)^2)
# a[i] = J, a[n] = B
# a[i] = B, a[n] = O
# a[i] = O, a[n] = J

n = int(input())
a = str(input())
d = [-1]*1001

def get_prev(x):
    if x == 'B':
        return 'J'
    elif x == 'O':
        return 'B'
    elif x == 'J':
        return 'O'

d[0] = 0 # energy 0 at start point

# prev (j) ---> now (i)
for i in range(1,n): # 1~n-1
    now = a[i]
    prev = get_prev(now)
    for j in range(0,i): # 0~i
        if d[j] == -1: # we should've visited j
            continue
        if a[j] != prev:
            continue
        cost = d[j] + (i-j)*(i-j)
        if d[i] == -1 or d[i] > cost:
            d[i] = cost
print(d[n-1])