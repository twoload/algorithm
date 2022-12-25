#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n (1<= n <= 10^18)
// k (0<= k <= 10)

// 2 0
//   B C, C B, C C -> 3
// 2 1
//   A C, C A, C C, B C, C B -> 5

// brute force : 3^n
// DP
//  d[n][a][b][c]
//   d[n-1][a-1][b][c] +   // a solve
//   d[n-1][a][b-1][c] +   // b solve
//   d[n-1][a][b][c-1]     // c solve

// d[n][a][b][c]
//  n : problem numbers
//  a : problem nums of a % k 
//  b : 1 if n-1 solved, 0 if n-1 not solved
//  c : 0 if not solve, 1 if solve

#include <iostream>
#include <cstring>
using namespace std;
int n, k;
const long long mod = 1000000007;
// d[n][a][b][c]
//    a: 0~k-1
//    b: 0,1
//    c: 0,1
long long d[100000][10][2][2];
long long go(int index, int a, int b, int c) {
    // index : 0 ~ n-1
    // index : n (finish)
    if (index == n) {
        // a % k == 0, c solved at least 1
        if (a == 0 && c == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    long long &ans = d[index][a][b][c];
    if (ans != -1) return ans;
    ans = 0;
    if (k > 0) { // a
        ans += go(index+1, (a+1)%k, 0, c);
    }
    if (b == 0){ // b
        ans += go(index+1, a, 1, c);
    }
    // c
    ans += go(index+1, a, 0, 1);
    ans %= mod;
    return ans;
}
int main() {
    cin >> n >> k;
    memset(d,-1,sizeof(d));
    cout << go(0,0,0,0) << '\n';
    return 0;
}