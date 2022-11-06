# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# brute force
#   all cases : check if num is K (S[i] < S[j])
#               N! * O(N^2)

# DP
# d[i]  : num of K at len i, 
# d[i][j] : true/false if num == j at len i

# d[i][a][b][p] : true/false at (len i, num of A = a, num of B = b, num p of S[i]<S[j])
#      num of C = i - a - b
#      a<b, b<c, a<c
#      .....a : d[i+1][a+1][b][p]
#      .....b : d[i+1][a][b+1][p+a]
#      .....c : d[i+1][a][b][p+a+b]
#      where a >=0, b>=0, c>=0 (i-a-b >=0)

# 436 = 30*(30-1)/2 + 1
d = [[[[False]*436 for k in range(31)] for j in range(31)] for i in range(31)]
n,k = map(int, input().split())
ans = ''
def go(i,a,b,p):
    # exit condition
    if i == n:
        if p == k:
            return True 
        else:
            return False
        
    # True : when the function never is called, 
    # False : when the function ever is called
    if d[i][a][b][p]: 
        return False
    d[i][a][b][p] = True
    
    # declaration is needed
    global ans 
    temp = ans
    ans = temp + 'A'        
    if go(i+1, a+1, b, p):
        return True
    ans = temp + 'B'
    if go(i+1, a, b+1, p+a):
        return True
    ans = temp + 'C' # mistake temp = 'C' -> temp + 'C'
    if go(i+1, a, b, p+a+b):
        return True
    return False

if go(0,0,0,0):
    print(''.join(ans))
else:
    print(-1)
