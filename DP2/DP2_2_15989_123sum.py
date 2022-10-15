# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
import sys
input = sys.stdin.readline # prevent timeout

#d[i] = number of way which n is sum of 1,2,3
#d[i] = d[i-1] + d[i-2] + d[i-3]

limit = 11
d = [0]*(limit+1)
d[0] = 0 # d = [1,2,4]
d[1] = 1
d[2] = 2
d[3] = 4
for i in range(4, limit+1):
    d[i] = d[i-1] + d[i-2] + d[i-3] # d.append(sum(d[-3:]))
t = int(input())
for _ in range(t):
    n = int(input())
    print(d[n])
