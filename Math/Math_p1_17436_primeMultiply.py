#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

"""
// N prime, M natural num
// 1 <= N <= 10
// 1 <= M <= 10^12
// 1 <= prime <= 100

// ex. n <= 100, n%2 == 0 and n%3 == 0
//     = |2's mul| + |3's mul| - |2*3's mul|
// ex. n <= 100, n%2 == 0 and n%3 == 0 and n%5 == 0
//     = |2's mul| + |3's mul| + |5's mul| 
//        - |2*3's mul| - |3*5's mul| - |2*5's mul|
//        + |2*3*5's mul|   
// cases = O(2^N-1)
"""

# You are given N prime numbers and a natural number M.
# Count the number of natural numbers less than or equal to M
# that are divisible by at least one of N primes
#                       --------
# > inclusion and exclusion principle

# n = 2, m = 100
# a[] = 2, 3

"""
n, m = map(int, input().split())
a = list(map(int,input().split()))
ans = 0
for i in range(1, (1<<n)): # bitmask 00,01,10,11
    cnt = 0
    p = 1
    for j in range(n): # 0, 1
        if (i&(1<<j)) > 0: 
            p *= a[j]      
            cnt += 1
    # i = 01, p = 2, cnt = 1, ans += 100//2
    # i = 10, p = 3, cnt = 1, ans += 100//3
    # i = 11, p = 2*3, cnt = 2, ans -= 100//6       
    if cnt % 2 == 0:       
        ans -= (m//p)
    else:
        ans += (m//p)
print(ans)
"""

def go(index, num):
    if (index >= n):
        return 0
    ans = 0
    if (num*a[index] > m):
        return 0
    ans += m//(num*a[index])
    # we choose whether to select cur index (O/X)
    ans += go(index+1, num); # - cur index
    ans -= go(index+1, num*a[index]) # + cur index : ==/-= change during recursive
    return ans

n, m = map(int, input().split())
a = list(map(int,input().split()))
ans = go(0, 1)
print(ans)
