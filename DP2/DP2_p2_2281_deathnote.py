# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# colume : m
# min sum of square of remaining right sides (except last row)
# i don't know how many names will put.

# when I write name,
# 1) I can write it in current row
# 2) I can write it in next row

# d[index][count] = sum of square of right remaining
#   I will write index
#   I wrote count numbers of characters
# 1) count ... a[index] 
# 2) count
#    a[index]

# assume: count includes blank(1)
# 1) count(has blank(1)) + a[index] + blank(1)
# go(index+1, count+a[index]+1) //+1 space
# 2) count(has blank(1)) + space(= m-count+1)
#    a[index]
# go(index+1, a[index]+1)+space*space

# n 1~1000
# m 1~1000

n, m = map(int, input().split())

a = []
for _ in range(n):
    a.append(int(input()))

d = [[-1]*1002 for _ in range(1002)] 

def go(index,cnt): # index: 0~n-1
    if index == n:
        return 0
    ans = d[index][cnt] 
    if ans != -1:
        return ans
    # case 2
    space = m - cnt + 1
    cost = space*space
    # a[index]+1, where 1<=index<=n-1 
    #    if index == 0, a[0]+1 is duplicate as init -> NG
    #    index should start from 1 not 0
    ans = go(index+1, a[index]+1) + cost  
    d[index][cnt] = ans
    # case 1
    if cnt + a[index] <= m: # 1~m 
        cur = go(index+1, cnt+a[index]+1)
        if ans > cur:
            ans = cur
            d[index][cnt] = ans
    return ans

print(go(1, a[0]+1))
