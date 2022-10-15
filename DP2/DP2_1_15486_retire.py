# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.


# d[i]: max profit at i day

# i -> j
#   d[j] = max(d[j], d[i] + p[i]), i < j, j-i >= T[i]
#   d[i+j] = max(d[i+j], d[i]+p[i]), j >= T[i] 
#   1) d[i+1] = max(d[i+1], d[i])
#   2) d[i+t[i]] = max(d[i+t[i]], d[i]+p[i])

n = int(input())
t = [0]*n
p = [0]*n
d = [0]*(n+50) # prevent out of range
for i in range(n):
    t[i], p[i] = map(int, input().split())
    
for i in range(n):
    d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]) # yes consulting
    d[i+1] = max(d[i+1], d[i]) # no consulting
    
print(d[n])
