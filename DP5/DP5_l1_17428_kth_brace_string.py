#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
'''
// n (2<= n <=50)

// d[n][l] : num of bracket string with len n
//      l : num of brackets which doesn't match 

// /-- n --\
//         (  : d[n-1][l-1] , l >=0

// /-- n --\
//         )  : d[n-1][l+1] , l >=0

//           ()())
// not match:1010-1 : minus = l >= 0

// k-th () string
// /-- n --\
// (          : d[n-1][l+1]
// d[n][l]: bracket string with len n,
//          num of bracket which doesn't match is l
// /-- n --\
// )          : d[n-1][l-1]
// if l == 0, ( open bracket
'''
               
n, k = map(int, input().split())
# d[n][l]
# d[n][l]: num of bracket string with len n
#      l : num of brackets which doesn't match 

d = [[0]*(n+1) for _ in range(n+1)]
# init
d[0][0] = 1
for i in range(1, n+1):
    d[0][i] = 0;
    
for i in range(1, n+1): #1,2,...,n
    # d[i][0]
    d[i][0] = d[i-1][1] # [0] ) -> match
    # d[i][1], d[i][2], ..., d[i][n]
    for j in range(1, n+1): #1,2,...,n
        # d[i][j] = d[i-1][j-1]+d[i-1][j+1]
        #           )           (
        d[i][j] = d[i-1][j-1]
        if j+1 <= n:
            d[i][j] += d[i-1][j+1]

if k >= d[n][0]: # wrong
    print(-1)
    exit()
    
#op = open (
op = 0
for i in range(n, 0, -1): #n,n-1,...,2,1
    if op == 0:
        print('(',end='') #( start...
        op += 1
    else:
        # d[i-1][op+1]: (
        if k < d[i-1][op+1]:
            print('(',end='')
            op += 1
        else: # )
            print(')',end='')
            k -= d[i-1][op+1] # () -> -d[i-1][op+1]
            op -= 1
print()