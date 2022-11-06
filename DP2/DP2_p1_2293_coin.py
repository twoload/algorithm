# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

n,m = map(int,input().split())
a = [int(input()) for _ in range(n)]
    
#d[n] : case number of cost n 
#d[0] = 1
#d[i+a[j]] += d[i]
d = [0]*(m+1)
d[0]=1
for i in range(n):
    for j in range(m+1):
        if j-a[i] >= 0:
            d[j] += d[j-a[i]]
            
print(d[m])

