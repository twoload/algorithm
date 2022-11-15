# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# [5,1,2] = 1,2,5,3(1+2),6(1+5),7(2+5),8(1+2+5)
#           1,2,3,(4:x),5,6,7,8 -> 4
#
# 1 <= n < = 20
# s <= 100,000
# O(2^n) x n = subsequence(O(2^n)) x n(sum)

n = int(input())
a = list(map(int,input().split()))
c = [False]*(n*100000+10)
# n = 3
# a = 5,1,2
# 2^3 subsequences
# 0 = 000 
# 1 = 001 = a[0] = 5
# 2 = 010 = a[1] = 1
# 3 = 011 = a[0]+a[1] = 6
# 4 = 100 = a[2] = 2
# 5 = 101 
# 6 = 110
# 7 = 111 = a[0]+a[1]+a[2] = 8
for i in range(1<<n):
    s = 0
    for j in range(n):
        if (i&(1<<j)):
            s += a[j]
            #print('s = %d (a[%d]=%d) (i,j)(%d,%d)' %(s,j,a[j],i,j))
    c[s] = True
    #print('c[%s] = True' %(s))
i = 1
while True:
    if c[i] == False:
        break
    i += 1
print(i)