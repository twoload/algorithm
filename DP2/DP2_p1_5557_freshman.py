# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# O(2^N)
# limitation: mid sum (0 <= x <=20)

# d[i][j] = num of way to make j with 0~i numbers
# d[i][j] = d[i-1][j-A[i]] + d[i-1][j+A[i]] // +, -
# ex. n=5, 1 ? 2 = 3 
# # ? (1) 
# d[0][1=a[1]] = 1 // init value
# d[1][3] = d[0][3-2] + d[0][3+2]
# j = 10, 1 <= i <= n-2
#----------------------------------------

# O(2^N) or O(NM) // M : possible limit

n = int(input())-1
a = list(map(int, input().split())) # 0~n-1
goal = a[-1]
a = a[:-1]
d = [[0] * (20+1) for _ in range(n)]
d[0][a[0]] = 1 # init value
for i in range(1,n): # 1~n-1
    for j in range(21): # 0~20
        if j-a[i] >= 0:
                d[i][j] += d[i-1][j-a[i]];        
        if j+a[i] <= 20: 
                d[i][j] += d[i-1][j+a[i]]        
print(d[n-1][goal])


