#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
# https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-using-binary-exponentiation
#endif

// 1 <= s <= 1'000'000
// d[s][a][b][c] : num of ways at s songs, a,b,c num of people
//   = d[s-1][a-1][b][c]
//    +d[s-1][a][b-1][c]
//    +d[s-1][a][b][c-1]

// teacher
// d[s][a][b][c]
// O(s^4) : impossible
// -> inclusion-exclusion principle : O(n)
// cond1: num of songs which 3 people sing = a,b,c
// cond2: at least one person must join every songs

// C(n,k) : num of way to choose k from n
// cond1: C(S,a) * C(s,b) * C(s,c)

// all: set of album satisfying cond1
// valid: set of album satisfying cond1 and cond2
// invalid: set of album satisfying cond1 and not satisfying cond2
// valid = all - invalid
// all - |there is no people who sings song1 U
//        there is no people who sings song2 U
//        ...
//        there is no people who sings song s|

//        there is no people who sings song1 +
//        there is no people who sings song2 +
//        ...
//        there is no people who sings song s
//       -there is no people who sings song 1,2
//       -...
//       +(-1)^(s+1)|there is no people who sings 1~s songs|
//  U
//  <=>  1 + 2 ...+ S - (1,2) - (1,3) - (s-1,s)
//       + (1,2,3), ...
//       - (1,2,3,4), ...
// n(A U B) = n(A) + n(B) - n(A n B)

// there is no people who sings song 1
// = there is no people who sings song 2
// = ...
// C(S-1, a) * C(S-1, b) * C(S-1, c)    xC(s,1): any song?

// there is no people who sings song 1,2
// = there is no people who sings song 1,3
// = ...
// C(S-2, a) * C(S-2, b) * C(S-2, c)    xC(s,2): choose 2 songs

// valid = all - sum(-1)^(i+1)*C(s,i)*C(s-i,a)*C(s-i,b)*C(s-i,c) (1<=i<=s)
// = C(s,a)*C(s,b)*C(s,c) + sum(-1)^i *C(s,i)*C(s-i,a)*C(s-i,b)*C(s-i,c) (1<=i<=s)
// = sum(-1)^i * C(s,i)*C(s-i,a)*C(s-i,b)*C(s-i,c) (0<=i<=s)

#include <iostream>
using namespace std;
const int mod = 1000000007;
long long fact[1000001]; // 1<= s <= 1,000,000
long long inv[1000001];
long long fact_inv[1000001];
// nCr =    n! 
//       --------
//       r!(n-r)!
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long ans = fact[n];
    ans = (ans * fact_inv[k]) % mod; // 1/k!
    ans = (ans * fact_inv[n-k]) % mod; //1/(n-k)!
    return ans;
}
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    fact[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = (fact[i-1] * i) % mod; // calc fact in advance 
    }
//https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-using-binary-exponentiation
// a^(m-2) = a^-1 mod m
//    <- a^m - a = m * x  : %m each side ...
// m > i
// m = k*i + r
//   (k = m/i, r = m%i)
//   0 = k*i + r    mod m
//   r = -k*i       mod m
//   r*i^-1 = -k    mod m
//   i^-1 = -k*r^-1 mod m
//        =  m - m/i*inv(m%i)%m
    inv[1] = 1;
    for (int i=2; i<=n; i++) {
        //inv[i] = (inv[mod%i] * (mod - mod/i)) % mod; 
        inv[i] = mod - mod/i * inv[mod%i] % mod; 
    }
    fact_inv[0] = 1;
    for (int i=1; i<=n; i++) {
        fact_inv[i] = (fact_inv[i-1] * inv[i]) % mod;
    }
    long long ans = 0;
    long long sign = 1;
    // = sum(-1)^i * C(s,i)*C(s-i,a)*C(s-i,b)*C(s-i,c) (0<=i<=s)
    for (int i=0; i<=n; i++) {
        long long temp = (comb(n,i) * comb(n-i,a)) % mod;
        temp = (temp * comb(n-i,b)) % mod;
        temp = (temp * comb(n-i,c)) % mod;
        ans += sign*temp;
        ans %= mod;
        ans = (ans + mod) % mod; // to prevent to become minus
        sign = -sign;
    }
    cout << ans << '\n';
    return 0;
}