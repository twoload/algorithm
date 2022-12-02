#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
"""
// (N K)
// N N-1 N-2 N-3 .... N-K+1 without ordering
// n!/(k!(n-k)!) = n(n-1)(n-2)...(n-k+1)/k!
// O(n)
// factorial = too big value
// 10! = 3628800 , 20! = ?

// Pascal's Triangle : O(n^2)
// c[n][k] : n-th row, k-th num
// c[n][1] = 1, c[n][n] = 1
// c[n][k] = c[n-1][k-1] + c[n-1][k] = (n k)
//           -> sel n-th   -> no sel n-th
""" 
n, m = map(int, input().split())
# d[n][k]
d = [[0]*(n+1) for _ in range(n+1)]
for i in range(n+1): # 0~n
    d[i][0] = d[i][i] = 1 # 0, n
    for j in range(1,i): # 1~n-1
        d[i][j] = (d[i-1][j-1] + d[i-1][j]) % 10007
# O(n^2)
print(d[n][m])