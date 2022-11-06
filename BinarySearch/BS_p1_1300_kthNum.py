# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# N x N (N <= 10^5 = 10000)
# A[i][j] = ixj
# B[k] in ascending sort (k <= 10^9=1000 000 000)
#   1 2 3
# 1 1 2 3
# 2 2 4 6
# 3 3 6 9
# 1 2 2 3 3 4 6 6 9
#
# k-th location means that num under it is k

import sys
input = sys.stdin.readline

n = int(input())
k = int(input())
left = 1 # min index
right = n*n # max index
ans = 0
while left <= right:
    mid = (left+right) // 2 # mid:4(1,9,4)->5(2,9,5)
    #print(left, right, mid, '(l,r,m)')
    cnt = 0 
    for i in range(1,n+1): # 1<=i<=n
        # ex. l:1, r:9, mid:5
        # min(3, 5//1) = 3
        # min(3, 5//2) = 2
        # min(3, 5//3) = 1
        # cnt = 6 (l:1, r:9)
        #
        # l:mid+1=6,r:9, mid:7
        # min(3, 7//1) = 3
        # min(3, 7//2) = 3
        # min(3, 7//3) = 2
        # cnt = 8 (l:6, r:9)
        #
        # l:6, r:mid-1=6, mid:6
        # min(3, 6//1) = 3
        # min(3, 6//2) = 3
        # min(3, 6//3) = 2
        # cnt = 8 (l:6, r:6)
        cnt += min(n, mid//i)
    #print(cnt, k, '(cnt, k)')
    if cnt >= k:
        # 6 >= 7
        # 8 >= 7
        ans = mid
        right = mid-1
        #print(left,right,mid,'(l,r,m)')
    else:
        # 6 < 7
        # 6 < 7
        left = mid+1
        #print(left,right,mid,'(l,r,m)')
print(ans)
