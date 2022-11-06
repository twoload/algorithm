# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# d[i][j] : max cheer-up numbers at i~j
#     d[i+1][j] : no match
#     d[i+1][k-1] + d[k+1][j] + 1 where i<k<=j, a[i] == a[k]
n = int(input())
a = list(map(int, input().split()))
d = [[-1]*1001 for _ in range(1001)]

def go(i,j):
    if i>=j:
        return 0
    ans = d[i][j]
    if ans != -1:
        return ans
    ans = go(i+1,j)
    d[i][j] = ans
    for k in range(i+1, j+1):
        cur = 0
        if a[i] == a[k]:
            cur = go(i+1,k-1) + go(k+1,j) + 1
        if ans < cur:
            ans = cur
            d[i][j] = ans
    return ans
        
print(go(0,n-1))
            
    
