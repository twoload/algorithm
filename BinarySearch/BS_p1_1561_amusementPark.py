# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# n : num of children
#     ride at min order of empty rides
# m : num of rides
#     operating time
# 3 5
# 1(7) 2(8) 3(9) 4(7) 5(8)
# 1,2,3
#
# 7 2
# 1(3) 2(2)
# 1,2
#  
#
#   1
# 2
#
#   
#   1
# 2 1
# output : num of rides which last child will ride

import sys
input = sys.stdin.readline

# p: person <= 2 000 000 000 
# n : rides <= 10 000
# a : wait time <= 30
p, n = map(int, input().split())
a = list(map(int, input().split()))

# at 0 min
#    can ride without wait (at 0 min)
#    all can ride
if p <= n:
    print(p)
    sys.exit(0)


# time (min ~ max)
left = 0 # min time :0 min
# max time: person * rides * wait time
#       > 2000000000 * 100000 * 30
right = 2000000000 * 1000000  

# input: 17 5
#        1 2 3 4 5
# output: 2
#
# (time)    1      2      3      4      5 (rides)
# 0 (L1)    1      2      3      4      5
# 1         6
# 2         7      8
# 3         9             10
# 4 (M1)    11(B1) 12           13(E1)
# 5 (L2)    14                         15
# 6 (M2)    16(B1) 17(*)  18(E1)
# 7         19
# 8 (R1)    20     21           22
#
# output: num of rides which last person would ride
while left <= right:
    mid = (left + right) // 2 
    begin = 0 # person order [begin, end] at mid min
    end = n # at time(0)
    for i in range(n): # n: num of rides
        end += mid // a[i] # total person's num until n min
    begin = end # 15
    for i in range(n): # 0,1,2,3,4
        if mid % a[i] == 0:
            begin -= 1 # moving begin forward
    begin += 1
    if p < begin:
        right = mid - 1 # forward
    elif p > end:
        left = mid + 1 # backward
    else:
        for i in range(n):
            if mid % a[i] == 0:
                if p == begin:
                    print(i+1)
                    sys.exit(0)
                begin += 1 # by increasing mid