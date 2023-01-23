#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// N x 3 board (1<=N<=1000)
// K Domino    (1<=K<=1000)

// brute force
// 2(2x1, 1x2)^board(N*3)
// 2^(K) * (N*3 C K)

// dp
// d[i] : max sum at i state 
//   = d[j] + sum(1x2)
//       i = j+ (1<<pos) + (1<<(pos+1))
//       check out of range
//
//   = d[j] + sum(2x1)
//       i = j+ (1<<pos) + (1<<(pos+3))
//
// 3xn : state -> too big! 2^(3*n)
// 1row : state
// d[i][s] : max sum at i-th row's state
// d[i+1][s'] : max sum at i+1-th row's state
//        (1) () ()
//        (1) () ()

//        ()  () ()
//        (1) (1) ()

// if 2x1, col=0, => d[i][0] should be 0
//    put, d[i][s | 1] =
//         d[i+1][s'|1] = max(d[i][s|1] + a[i+1][0])
//...
// O(2^3:state * n:row * 3(for))
// = O(mn*2m)

// teacher
// d[row][domino][state] : max sum at row, state, domino
//  it isn't needed to cover all. but k ea dominos.
//  -> so [domino] is needed

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001][3];
// d[row][domino][state]
long long d[1001][1001][1<<3];
const long long inf = 100'000'000'000'000'000LL;
// prev state, cur state, domino's number
int states[11][3] = {
    {0, 0, 0},
    {1, 1, 1},
    {2, 2, 1},
    {4, 4, 1},
    {0, 3, 1},
    {0, 6, 1},
    {1, 7, 2},
    {4, 7, 2},
    {3, 3, 2},
    {6, 6, 2},
    {5, 5, 2}
};
long long calc(int n, int cur) {
    long long ans = 0;
    if (n < 0 && cur != 0) return -inf; // check by calc(n-1, prev) when n==0
    if (cur & 1) ans += a[n][0];
    if (cur & 2) ans += a[n][1];
    if (cur & 4) ans += a[n][2];
    return ans;
}
long long go(int n, int k, int state) {
    if (n < 0) { // finish
        if (k == 0) return 0; // domino all used? ok
        else return -inf; // domino left ? ng
    }
    if (k == 0) return 0; // domino all used? ok
    if (k < 0) return -inf; // domino -1? ng
    long long &ans = d[n][k][state];
    if (ans != -inf) return ans;
    for (int i=0; i<11; i++) { // all cases
        int prev = states[i][0];
        int cur = states[i][1];
        int cost = states[i][2]; // domino's number
        if (cur & state) continue; // already occupied?
        ans = max(ans, calc(n, cur) + calc(n-1, prev) + go(n-1, k-cost, prev));
        // row: n-1 > n-2 > n-3 > ... > 2 > 1 > 0
    }
    return ans;
}
int main() {
    int n, m, k;
    cin >> n >> k;
    m = 3;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    // fill d[0][0][0] ~ d[1000][end][end]
    fill(&d[0][0][0], &d[1001][0][0], -inf);
    cout << go(n-1, k, 0) << '\n';
    return 0;
}

