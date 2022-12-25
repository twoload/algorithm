#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// N (1<= N <= 1'000'000)
// mod = 1'000'000'000

// brute force
//   (n-1)! = 1'000'000 !

// d[n] : num of ways which n people exchange presents


/*
 * case1
 * 
 *     -----
 *    v     |
 *    i     n
 *    |     ^
 *     -----
 *    d[n-2] * (n-1)  ,where i: 1~n-1
 * 
 * case2
 *     -----                ------------
 *    |     v              |            v
 * ?  i     o     n     ?  i      o     n     
 * ^        |           ^        | ^    |
 *  --------             ---------  ----
 *    d[n-1] * (n-1)  ,where i: 1~n-1
 * 
 */

#include <iostream>
using namespace std;
long long d[1000001];
const long long mod = 1000000000;
int main() {
    int n;
    cin >> n;
    d[1] = 0;
    d[2] = 1;
    for (int i=3; i<=n; i++) {
        d[i] = (i-1)*(d[i-1]+d[i-2]);
        d[i] %= mod;
    }
    cout << d[n] << '\n';
    return 0;
}
