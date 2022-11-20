# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N, K
# S: len(S) = N, is composed of A,B
# 0<=i<j<N, s[i]=='A' && s[j]=='B' (i,j) pair num = K
# N (2~50), K (0 ~ N*(N-1)/2)

# 5 3
# BABBB
#
# a   : 0,1,2,3,4,5
# b   : 5,4,3,2,1,0
# axb : 0,4,6,6,4,0
# k=3 : x,o,o,o,o,x
#
# a=1,b=4,k=3
#   x=3
#   cnt[3]=1
#   k=0
#
# i=4, cnt[4]=0
#   B 
# i=3, cnt[3]=1
#   BAB
# i=2, cnt[2]=0
#   BABB
# i=1, cnt[1]=0
#   BABBB
# i=0
#
# 5 5
# ABABB
# a   : 0,1,2,3,4,5
# b   : 5,4,3,2,1,0
# k=5 : x,x,o,o,x,x
#
# a=2,b=3,k=5
# x=3
# cnt[3]=1
# k=5-3=2
# x=2
# cnt[2]=1
# k=0
#
# i=3, cnt[3]=1 // A BBB
#   AB
# i=2, cnt[2]=1 // A BBB, A BB
#   ABAB
# i=1, cnt[1]=0 
#   ABABB    
n, k = map(int, input().split())
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
        if i > 0: # skip if num of b is 0
            print('B', end='')
    print()
    exit()
print(-1)
    