#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 4 0
// (((( 0000
// 4 4
// (((( 0000
// ((() 0001
// (()( 0010
// (()) 0011 x
// ()(( 0100
// ()()      x
// ())(
// if num of '(' is the same as num of ')', x

// select (, )
// select 0, 1
// d[n][m] : number at len n, num '(=0' is m
// 0 select : d[n-1][m-1]
// 1 select : d[n-1][m]

// teacher
// answer = all string - bracket string
//             2^N
// d[n][l] : num at len n, no match bracket l
//   1st string is open  '(' : d[n-1][l+1]
//   1st string is close ')' : d[n-1][l-1]
// d[n][l] = d[n-1][l+1] + d[n-1][l-1]

#include <iostream>
using namespace std;
// d[n][l] : num at len n, no match bracket l
long long d[50][50];
long long two(int x) { //2^x
    return (1LL << x);
}
int main() {
    int n;
    long long k;
    cin >> n >> k;
    d[0][0] = 1; //init
    for (int i=1; i<=n; i++) {
        d[0][i] = 0; //init
    }
    for (int i=1; i<=n; i++) {
        // init
        d[i][0] = d[i-1][1];
        //  all match  <-  no match=1
        // d[n][l] = d[n-1][l+1] + d[n-1][l-1]
        for (int j=1; j<=n; j++) {
            d[i][j] = d[i-1][j-1];
            if (j+1 <= n) { // out of range
                d[i][j] += d[i-1][j+1];
            }
        }
    }
    long long total = two(n) - d[n][0]; // no match string
    if (k >= total) { // impossible (0<=k<=50), order=total-1
        cout << -1 << '\n';
        return 0;
    }
    // find k-th number
    // '(' = order (0~left-1) = num of '(' = left
    //    ( + left
    // ')' = order (left~)
    //
    // if k < left
    //    k -> k
    // if k >= left
    //    k -> k-left (range=0~k-left)
    int open = 0;
    for (int len=n; len>=1; len--) {
        // [][][][] len:4
        //   <----> left: 2^3 - d[len-1][open+1]
        //   <----> left: 2^3 (when open < 0 : already ㄴㄴ string)
        long long left = two(len-1); // important: update every time
        if (open >= 0) {
            // left = 2^(len-1) - d[len-1][open+1]
            left -= d[len-1][open+1]; // bracket ㄴㄴ string
        }
        if (k < left) {
            cout << '(';
            open += 1;
        } else {
            k -= left;
            cout << ')';
            open -= 1;
            if (open < 0) {
                open = -1000000;
            }
        }
    }
    cout << '\n';
    return 0;
}
