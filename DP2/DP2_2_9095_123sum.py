# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
import sys
input = sys.stdin.readline # prevent timeout

#d[i] = number of way which n is sum of 1,2,3
#d[i] = d[i-1] + d[i-2] + d[i-3]

limit = 10000#11
d = [0]*(limit+1)
d[0] = 1
for i in range(1, limit+1):
    if i-1 >= 0:
        d[i] += d[i-1]
for i in range(1, limit+1):
    if i-2 >= 0:
        d[i] += d[i-2]
for i in range(1, limit+1):
    if i-3 >= 0:
        d[i] += d[i-3]
t = int(input())
for _ in range(t):
    n = int(input())
    print(d[n])

    
    
