# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# anta ... tica (a,n,t,i,c)
# students can read only word which has k characters 
# output: max numbers of words which students can read
#
# n <= 50
# k <= 26
# 8 <= words <= 15
#
# 3 6
# antarctica : antr ic
# antahellotica : anthelotic
# antacartica : antcri
#
# = a,n,t,i,c (5) should be learned
# = problem which selects k-5 numbers among 26-5

# ex. words = antarctica
#             if learn[] has a,n,t,r,c,i
#                cnt += 1
#     words = antahellotica
#             if learn[] has a,n,t,r,c,i but doesn't have e,l,o
#                ok = False
#                return cnt = 0
# return: numbers of words which students can read 
#
# O(num of words x len of each word)
#   -> O(num of words) with bitmask
#
def count(words):
    cnt = 0
    for word in words:
        ok = True
        for x in word:
            if not learn[ord(x)-ord('a')]:
                ok = False
                break
        if ok:            
            cnt += 1
    return cnt

# index = 26
# a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z = 26
# a: O, X
# b: O, X
# ...
# O(2^26)
def go(index, k, words):
    if k < 0:
        return 0
    if index == 26:
        return count(words)
    ans = 0
    learn[index] = True
    # case1: have
    t1 = go(index+1, k-1, words) 
    learn[index] = False
    if ans < t1:
        ans = t1
    # case2: no have, but a,n,t,i,c should always be have (case1)
    if index not in [ord('a')-ord('a'), ord('n')-ord('a'), ord('t')-ord('a'), ord('i')-ord('a'), ord('c')-ord('a')]:
        t2 = go(index+1, k, words)
        if ans < t2:
            ans = t2
    return ans

n, m = map(int,input().split())
words = [input() for _ in range(n)]
learn = [False] * 26
print(go(0,m,words))