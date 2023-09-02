#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


# each turn : O(2^n) for changing candies
# find the maximum length O(n^2)

# 2^50 : too big    

# teacher
# num of way = O(n^2)   not O(2^n)
#            = 4*n^2 for all elements (up,down,left,right)
#           -> 2*n^2 (because, up/left already considered)

# select series row/col : O(n^2) --> O(3n) also possible

# total = O(n^2) * O(n^2) = O(n^4)

# 50^4 = 2500^2 : not too big

def check(a):
    n = len(a)
    ans = 1
    for i in range(n):
        cnt = 1
        for j in range(1, n): #1,2,....n-1
            if a[i][j] == a[i][j-1]:
                cnt += 1
            else:
                cnt = 1
            if ans < cnt:
                ans = cnt
        cnt = 1
        cnt = 1
        for j in range(1, n): #1,2,....n-1
            if a[j][i] == a[j-1][i]:
                cnt += 1
            else:
                cnt = 1
            if ans < cnt:
                ans = cnt
    return ans

n = int(input())
a = [list(input()) for _ in range(n)]
ans = 0
for i in range(n):
    for j in range(n):
        if j+1 < n:
            a[i][j],a[i][j+1] = a[i][j+1],a[i][j] #swap
            temp = check(a)
            if ans < temp:
                ans = temp
            a[i][j],a[i][j+1] = a[i][j+1],a[i][j] #swap
        if i+1 < n:
            a[i][j],a[i+1][j] = a[i+1][j],a[i][j] #swap
            temp = check(a)
            if ans < temp:
                ans = temp
            a[i][j],a[i+1][j] = a[i+1][j],a[i][j] #swap
print(ans)            
        





