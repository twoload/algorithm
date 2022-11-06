# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# brute force : O(3^N)
# a, b, c
# d[a][b][c][p1][p2] : True/False
#     num of A,B,C = (a,b,c), 
#     person who worked last day = p1, 
#     person who worked last last day = p2
#  
#     p2,p1,?  ?
# 
# if A attends 
#     p2,p1,A  ?
#     d[a+1][b][c][a][p1]
# if B attends 
#     p2,p1,B  ?
#     d[a][b+1][c][b][p1] , where p1 != B
# if C attends 
#     p2,p1,C  ?
#     d[a][b][c+1][c][p1] , where p1 != C, p2 != C


s = input()
limit = [0,0,0] # num of a,b,c
n = len(s)
for ch in s:
    limit[ord(ch)-ord('A')] += 1
# 0 <= p1,p2 <= 2
# 0 <= a,b,c <= 50
d = [[[[[-1]*3 for l in range(3)] for k in range(51)] for j in range(51)] for i in range(51)]
def go(a,b,c,p1,p2):
    if a+b+c == n: # exit condition
        d[a][b][c][p1][p2] = 1
        return d[a][b][c][p1][p2]
    if d[a][b][c][p1][p2] != -1: # memoization
        return d[a][b][c][p1][p2]
    # 0 <= a <= limit[0]
    #   p1 <- a(0)
    #   p2 <- p1
    if a+1 <= limit[0] and go(a+1,b,c,0,p1) == 1: 
        d[a][b][c][p1][p2] = 1 # True
        return d[a][b][c][p1][p2]
    # 0 <= b <= limit[1]
    # p1 != b(1)
    #   p1 <- b(1)
    #   p2 <- p1
    if b+1 <= limit[1] and p1 != 1:
        if go(a,b+1,c,1,p1) == 1: 
            d[a][b][c][p1][p2] = 1
            return d[a][b][c][p1][p2]
    # 0 <= c <= limit[2]
    # p1 != c() && p1 != c(2)
    #    p1 <- c(2)
    #    p2 <- p1
    if c+1 <= limit[2] and p2 != 2 and p1 != 2:
        if go(a,b,c+1,2,p1) == 1:
            d[a][b][c][p1][p2] = 1
            return d[a][b][c][p1][p2]
    d[a][b][c][p1][p2] = 0
    return d[a][b][c][p1][p2]

# create string back
def back(a,b,c,p1,p2): 
    if a+b+c == n:
        return ''
    if a+1 <= limit[0] and go(a+1,b,c,0,p1) == 1:
        return 'A' + back(a+1,b,c,0,p1)
    if b+1 <= limit[1] and p1 != 1:
        if go(a,b+1,c,1,p1) == 1:
            return 'B' + back(a,b+1,c,1,p1)
    if c+1 <= limit[2] and p1 != 2 and p2 != 2:
        if go(a,b,c+1,2,p1) == 1:
            return 'C' + back(a,b,c+1,2,p1)
    return ''
    
ans = go(0,0,0,0,0)
if ans == 0:
    print(-1)
else:
    print(back(0,0,0,0,0))
    
        
    



