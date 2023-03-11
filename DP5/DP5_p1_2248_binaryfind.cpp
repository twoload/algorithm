#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1<= n <= 31
// 1<= L <= n
// i-th binary find
// n=5, L=3, i=19

// ALL numbers
// L bits compare
// sort
// I <= L : just I converts to binary
// I > L :  (L+1) (L) .... (1)
//            *   ------------
// remaining num = I - 2^(L+1)*K ...
// I <= L : I converts to binrary

// answer = K :: I converts to binary

// teacher
// len > count numbers > 0, 1
// d[n][l] : number which only bits under l are '1' in n binarys
//   last one n-th : 0 -> d[n-1][l]
//   last one n-th : 1 -> d[n-1][l-1]
// d[n][l] = d[n-1][l] + d[n-1][l-1]
//   starting 0 : same
//   starting 1 : same
// d[n][l] = d[n-1][l] + d[n-1][l-1]
//
// d[i][j]
// 0 : d[i-1][j]
// 
// 1 : d[i-1][j-1]
//

#include <iostream>
using namespace std;
// d[n][l] : number which only bits under l are '1' in n binarys
long long d[32][32];
int main() {
    int n,l;
    long long k;
    cin >> n >> l >> k;
    for (int i=0; i<=31; i++) {
        d[0][i] = 1; // init
    }
    for (int i=1; i<=31; i++) {
        d[i][0] = d[i-1][0]; // 1: there is no '1' under l
        for (int j=1; j<=31; j++) {
            // starting 0: d[i-1][j]
            // starting 1: d[i-1][j-1]
            // d[1][1] = d[0][1] + d[0][0] = 1 + 1 = 2
            //  '1','0'
            d[i][j] = d[i-1][j] + d[i-1][j-1];
        }
    }
    // find k-th number
    while (n > 0) {
        if (k <= d[n-1][l]) { // '0'
            cout << 0;
            n--;
        } else {
            cout << 1; // '1'
            k -= d[n-1][l];
            n--;
            l--;
        }
    }
    cout << '\n';
    return 0;
}