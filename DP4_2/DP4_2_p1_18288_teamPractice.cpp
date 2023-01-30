#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n (1<= n <=10^5)
// brute force
//   3^n

// dp
// d[n] : num of cases to solve the problem (0~n)
// d[n][a] : a = (num which A solve the problem % k)
// d[n][a][c] : c = 0, 1
// d[n][a][b][c] : b = 0, 1 (b:0->1, 1->0 at n+1)
//   n -> n+1
//   a -> O:(a+1%k), X:a  , 0<=k<=10
//   b(0) -> 1
//   b(1) -> 0
//   c -> O:1, X:c
// d[0][0][0][0] -> d[n-1][a'][b'][c']
//                   a' % k == 0
//                   c' >= 1
//                   b' is handled during process
// O(n*k*2*2)


#include <iostream>
#include <cstring>
using namespace std;
int n, k;
const long long mod = 1000000007;
// d[n][a][b][c]
long long d[100000][10][2][2];
long long go(int index, int a, int b, int c) {
    if (index == n) { // finish
        if (a == 0 && c == 1) { // a%k==0, c==1 >=1
            return 1;
        } else {
            return 0;
        }
    }
    long long &ans = d[index][a][b][c]; // memoization
    if (ans != -1) return ans;
    ans = 0;
    // A solve
    if (k > 0) {
        ans += go(index+1, (a+1)%k, 0, c);
    }
    // B solve
    if (b == 0) {
        ans += go(index+1, a, 1, c);
    }
    // C solve
    ans += go(index+1, a, 0, 1);
    ans %= mod;
    return ans;
}
int main() {
    cin >> n >> k;
    memset(d,-1,sizeof(d)); // cache init
    cout << go(0, 0, 0, 0) << '\n';
    return 0;
}

