#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1 <= T <= 1000
// case num < 2^32
// O(T*2^32) : too big
// matrix
//   O(T*log(2^32))
// d[i][j] : num of cases at 4*i matrix, j state
//           4*(i-1) all filled with 1x2, 2x1
// j = 0000
//     0001
//     0010
//     0011
//     ...
// pre  cur
//  15   0
//  14   1
//  13   2
//  ...
// matrix
// d[i][j|(1<<k)] = a(matrix)*d[i-1][k]
//     j & (1<<k) == 0

// teacher
// 1    0    1    0
// 1    1    1    0
// 1    1    0    1
// 1    0    0    1
// f[n] g[n] h[n] h[n]
// f[n] = num of cases to fill 4xn
// g[n], h[n]

// f[n]
// 1 1^    <1 1>   <1 1>      1^   1 <1 1>
// 1 1v    <1 1>      1^      1v   1 <1 1>
// 1 1^       1^      1v   <1 1>   1 <1 1>
// 1 1v       1v   <1 1>   <1 1>   1 <1 1>
// f[n-1]  h[n-1]  g[n-1]  h[n-1]  f[n-2]
// f[n] = f[n-1] + h[n-1]*2 + g[n-1] + f[n-2]

// g[n]
// 1       <1 1>
// 1 1^     1 <1 1>
// 1 1v     1 <1 1>
// 1       <1 1>
// f[n-1]   g[n-2]
// g[n] = f[n-1] + g[n-2]

// h[n]
// <1 1>    1 1^
// <1 1>    1 1v
//  1       1
//  1       1
// h[n-1]   f[n-1]
// h[n] = h[n-1] + f[n-1]

// f[0] 0 (4x0)
// f[1] 1 (4x1)
// g[0] 0
// g[1] 1
// h[0] 0
// h[1] 1


#include <iostream>
using namespace std;
long long f[101];
long long g[101];
long long h[101];
int main() {
    f[0] = 1;
    f[1] = 1;
    g[0] = 0;
    g[1] = 1;
    h[0] = 0;
    h[1] = 1;
    // why ? 100 ?
    // ex. it's similar to fibonacci
    // = about 2^n increase
    // = 2^32
    // = about i<=32 or 50 is enough
    for (int i=2; i<=100; i++) { 
        f[i] = f[i-1] + f[i-2] + g[i-1] + 2*h[i-1];
        g[i] = f[i-1] + g[i-2];
        h[i] = f[i-1] + h[i-1];
        if (f[i] >= 2147483647LL) break; // cut branch
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}