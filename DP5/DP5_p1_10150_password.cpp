#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : password's length ( 5<= n <= 1'000'000)
// k : num of characters ( 3<= k <= 26)

// n: all cases -> k^n
// cases including pattern : n*n^2=n^3 for one
//                         : k^n * n^3

// nums which can be created with patterns
//    left + <pattern>
//    <pattern> + right
// d[n] : num of numbers creating with patterns at length n
//    d[n-1] + left/right(2*k)

// teacher
// 1. d[n][l1][l2][l3][l4][l5] -> nk^5 -> O(nk^6)
//  = sum(d[n-1][l0][l1][l2][l3][l4])
//  ABCBC, ABABC

// 2. A,B,C + remaining
// d[n][l1][l2][l3][l4][l5] : A,B,C,remaining(k-3) = 4 : O(n*4^6)

// 3. state
// start(0) -> A(1) -> AB(2) -> ABA(3) -> ABAB(4) -> ABABC
//                          \-> ABC(5) -> ABCB(6) -> ABCBC
// similar to ahocorasic : trie
// O(n)

#include <iostream>
using namespace std;
long long d[1000001][7];
const long long mod = 1000000009;
int main() {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1;
    for (int i=1; i<=n; i++) {
// start(0) -> A(1) -> AB(2) -> ABA(3) -> ABAB(4) -> ABABC
//                          \-> ABC(5) -> ABCB(6) -> ABCBC
        // start-> B,C,D,E,F,....(k-1), A->C,D,E,...(k-2),... 
        d[i][0] = d[i-1][0]*(k-1) + d[i-1][1]*(k-2) + d[i-1][2]*(k-2) + d[i-1][3]*(k-2) + d[i-1][4]*(k-2) + d[i-1][5]*(k-2) + d[i-1][6]*(k-2);
        // start-> A, AA->A, AABAA->A,....
        d[i][1] = d[i-1][0] + d[i-1][1] + d[i-1][3] + d[i-1][5] + d[i-1][6];
        d[i][2] = d[i-1][1]; // A -> AB
        d[i][3] = d[i-1][2] + d[i-1][4]; //AB->ABA, AB->ABC
        d[i][4] = d[i-1][3]; //ABA->ABAB
        d[i][5] = d[i-1][2]; //AB->ABC
        d[i][6] = d[i-1][5]; //ABC->ABCB
        for (int j=0; j<7; j++) {
            d[i][j] %= mod;
        }
    }
    long long ans = 0;
    for (int i=0; i<7; i++) {
        ans += d[n][i];
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}
