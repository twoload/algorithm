#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

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
 
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i=1; i<=n; i++) { // factorial
        ans *= i;
    }
    for (int i=1; i<=m; i++) {
        ans /= i;
    }
    for (int i=1; i<=n-m; i++) {
        ans /= i;
    }
    cout << ans << '\n';
    return 0;
}