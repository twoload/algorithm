#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n (1<=n<=15) : num of numbers
// len : (1<=len<=50)
//   -> len of appended num : 15*50 = 750 : too big!
//   -> %k : save!!! *** (1~100)
// k : remaining (1<=k<=100)

// brute force
// n! arrange = 15! : too big!
// %k == 0 ? (O/X)
// O(n!) -> state

// dp
// dp[s] : percentage at s = 2^15

// teacher
// state: s -> create numbers -> order
//        number choose : O, X
//        remaining : m (including order)
// d[s][m] : num of cases at group s , remaining m
// s -> s | (1<<L) 
// L-th num: A[L]
// M A[L] 's remaining = ((M* 10^(Len(L))) + A[L])%K = next
// D[s|(1<<L)][next] += D[S][M]
// ans
//   total = sum(D[2^15-1][i]), 0<=i<100 = N!
//   %k==0 = sum(D[2^15-1][0])  

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// d[s][m] : s=state, m=remaining
long long d[1<<15][100];
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    else return gcd(y, x%y);
}
int main() {
    int n;
    cin >> n;
    vector<string> num(n);
    vector<int> a(n);
    vector<int> len(n);
    for (int i=0; i<n; i++) {
        cin >> num[i];
        len[i] = num[i].size();
    }
    int k;
    cin >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<len[i]; j++) {
            a[i] = a[i] * 10 + (num[i][j] - '0');
            a[i] %= k; // remaining
        }
    }
    vector<int> ten(51);
    ten[0] = 1;
    for (int i=1; i<=50; i++) {
        ten[i] = ten[i-1] * 10;
        ten[i] %= k; // remaining
    }
    // num of cases
    // d[0][0] = 1 (at s = 0, m(remaining) = 0)
    // init value should be 1
    // if it's 0, .... d[x][y] = 0 (it's problem)
    d[0][0] = 1; 
    for (int i=0; i<(1<<n); i++) { // all state
        for (int j=0; j<k; j++) { // all remaining
            for (int l=0; l<n; l++) { // l: new number
                if ((i&(1<<l)) == 0) { // l should not be in i
                    int next = j * ten[len[l]]; // already calculated
                    next %= k;
                    next += a[l];
                    next %= k;
                    d[i|(1<<l)][next] += d[i][j]; // update case nums
                }
            }
        }
    }
    long long t1 = d[(1<<n)-1][0]; // %k == 0 = numerator
    long long t2 = 1;
    for (int i=2; i<=n; i++) { // n! = denominator
        t2 *= (long long)i;
    }
    long long g = gcd(t1,t2); // greatest common divisor
    t1 /= g;
    t2 /= g;
    cout << t1 << '/' << t2 << '\n';
    return 0;
}