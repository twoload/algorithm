# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# divide into m ea groups
# M bluray will have N lessons
# min bluray's size
# bluray's size should be the same
#   = lesson's sum in groups = group's sum
#   = max value of group's sum

# we need to find min of max value of group's sum
# min of max, max of min -> binary search

# 1. find min/max of bluray's size
#    min = max of lesson's size
#    max = lesson's sum

import sys
input = sys.stdin.readline

# m : bluray's total num
# size : bluray's size
def go(a, m, size):
    cnt = 1
    tot = 0
    for i in range(n): # lesson's num
        if tot + a[i] > size: # if it is bigger than bluray's size
            cnt += 1
            tot = a[i]
        else:
            tot += a[i]
    return cnt <= m

n, m = map(int, input().split())
a = list(map(int,input().split()))

left = max(a) # max of blueray's sizes
right = sum(a) # one blueray : sum of all bluray's sizes

ans = 0
while left <= right:
    mid = (left + right) // 2 # find bluray's size
    if go(a, m, mid): # possible to cover
        ans = mid
        right = mid - 1
    else:
        left = mid + 1
print(ans)