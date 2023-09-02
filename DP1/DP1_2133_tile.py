#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

# matrix ?
# last row
# d[n][7] = d[n-2][7] +
#           d[n-1][1] +  (100)
#           d[n-1][4]    (001)

# d[n] =[      ][ ] = [ ]
#
#
#
#
# teacher
# d[i] = num of cases at 3xi
# d[i] = 3*d[i-2] + 2*d[i-4] + 2*d[i-6] + ...

n = int(input())
d = [0]*(n+1)
d[0] = 1
for i in range(2,n+1,2): #2,4,6,...,n-2,n
    d[i] = d[i-2]*3
    for j in range(i-4, -1, -2): #i-4, i-6, ... 0
        d[i] += d[j] * 2
print(d[n])