# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# n : num of push-up (1~5000)
# m : kind of score (1~10)
# Si in m lines (1~20)

# d[i][j] : True/False at pushUp: i, score: j
#    new score : k
#     -> score : j+k
#     -> pushUp : i+j+k
# d[i+j+k][j+k], where k : score kind
# d[0][0] = 1

# 20 + (20+20) + (20+20+20) + (20+20+20+20)...
# 20*1 + 20*2 + 20*3 + 20*4 ...
# (1+x)x/2 * 20 <= 5001
# x^2 <= 10000
# x <= 101

max_m_size = 101

def go(i, j):
    if i > n:
        return
    if j >= max_m_size: # prevent runtime error (indexError)
        return
    if d[i][j]: 
        return
    d[i][j] = True
    for k in range(m): # with all score kind
        go(i+j+a[k], j+a[k])
    

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    d = [[False]*max_m_size for _ in range(5001)]
    
    go(0,0)
    ans = -1
    for i in range(1,max_m_size): # find max score (1<=m<=10)
        if d[n][i]:
            ans = i
    print(ans)
    
    

