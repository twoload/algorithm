# I've attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# '(' : 1st should be '('
# where is the counter of 'C' ?
# if the counter is i-th,
# '('.......i........L
#    <-----> <-------> both should be correct bracket
# d[L] : case num of n length correct bracket
#      = sigma(d[i-2]*d[L-i]), 2<=i<=L, i=multiply of 2
# O(L^2)
#-------------------------------------------------
# d[N][L] : N length bracket, L : open bracket num of no match
# ex) length N, correct bracket : d[n][0], L>=0
# -------------------')' : D[N-1][L+1] because '(' exists to match end ')'
# -------------------'(' : D[N-1][L-1]
# D[N][L] = D[N-1][L+1]+D[N-1][L-1]

mod = 1000000007
d = [[0]*5001 for _ in range(5001)]
d[0][0] = 1
for i in range(1, 5001):
    for j in range(i+1):
        if j+1 <= i: # out of range
            d[i][j] += d[i-1][j+1]
        if j-1 >= 0: # out of range
            d[i][j] += d[i-1][j-1]
        d[i][j] %= mod
t = int(input())
for _ in range(t):
    n = int(input())
    print(d[n][0])
