# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N, K
# S: len(S) = N, is composed of A,B
# 0<=i<j<N, s[i]=='A' && s[j]=='B' (i,j) pair num = K
# N (2~50), K (0 ~ N*(N-1)/2)

# 3 2
# ABB
#
# BBBB : b
# ABBBB -> 4(b)
# BABBB -> 3(b-1)
# BBBBA -> 0
# [0,axb] : max = a*b

#        B B B B
#      ^  ^ ^ ^ ^
# i: 4(b) 3 2 1 0
# cnt[i] = num when A is in i-th 
n, k = map(int, input().split())
# a : 0 ~ n
#
# ex. n = 4, k = 3 
#   B   B
# a = 0 , b = 4 (a*b=0 < 3 : x)
# a = 1 , b = 3 (3 < 3 : x)
# a = 2 , b = 2 (4 < 3 : O) --> (*) 
# a = 3 , b = 1 (x)
# a = 4 , b = 0 (x)
#
# i = 0, a = 2, b = 2 : x = min(2,3) = 2, cnt[2] += 1, k-=2 = 3-2=1
# i = 1, a = 2, b = 2 : x = 2, cnt[2] +=1, k-=2 = 1-2=-1


for a in range(0, n+1): # all cases because we don't know b (num of B)
    b = n - a
    if a*b < k: # 0<=k<=a*b
        continue
    cnt = [0]*(b+1)
    for i in range(a): # 0<=0<a
        x = min(b, k)
        cnt[x] += 1
        k -= x
    for i in range(b, -1, -1):
        for j in range(cnt[i]):
            print('A', end='')
        if i > 0:
            print('B', end='')
    print()
    exit()
print(-1)
    