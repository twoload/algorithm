#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// brute orce
// 2^n : n = len(S)
// abcd = a,b,c,d,ab,bc,cd,abc,bcd,abcd = 10
// abab = a,b,a,b,ab,ba,ab,aba,bab,abab = 7

// all sub strings = suffix's prefix
// s -----|        |--------
//        <-----suffix----->
//        <-prefix->

// suffix array : sorted 
//   same sub strings are located nearby

// abcd (origin)
// abcd : 4 (a, ab, abc, abcd) 
// bcd : 3 (b, bc, bcd)
// cd : 2 (c, cd)
// d : 1 (d)
//     => 10

// abab (origin)
// ab : (a, ab) = 2
// abab : (a:x, ab:x, aba, abab) = 4-2 = 2
// b : (b) 1 = 1
// bab : (b:x, ba, bab) 3-1 = 2
//     => 7

// LCP : Longest Common Prefix

// suffix: nlog^2n = nlogn * logn
// lcp = n * (n-1) = O(n^2)
// => O(n^2)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int lcp(int n, vector<vector<int>> &group, int k, int i, int j) {
    int ans = 0;
    while (i < n && j < n && k >= 0) {
        if (group[k][i] == group[k][j]) {
            ans += (1 << k);
            i += (1 << k);
            j += (1 << k);
        }
        k -= 1;
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> sa(n);
    vector<vector<int>> group(22, vector<int>(n+1));
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) {
        group[0][i] = s[i];
    }
    group[0][n] = -1; // 0~n-1: n=earlier
    int last = 0;
    for (int k=0, len=1; len/2 < n; len*=2, k++) { // 1>>2>>4>>8...
        auto cmp = [&](int u, int v) { // for sort
            if (group[k][u] == group[k][v]) {
                return group[k][u+len] < group[k][v+len];
            } else {
                return group[k][u] < group[k][v];
            }
        };
        sort(sa.begin(), sa.end(), cmp);
        group[k+1][sa[0]] = 0;
        group[k+1][n] = -1;
        for (int i=1; i<n; i++) {
            if (cmp(sa[i-1], sa[i])) {
                group[k+1][sa[i]] = group[k+1][sa[i-1]]+1;
            } else {
                group[k+1][sa[i]] = group[k+1][sa[i-1]];
            }
        }
        last = k+1; 
        // k=0, last=1 : group[1][] : compared with len 2
        // k=1, last=2 : group[2][] : compared with len 4
        // k=2, last=3 : group[3][] : compared with len 8
    }
    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += (long long)(n-sa[i]);
        if (i > 0) {
            ans -= (long long)lcp(n, group, last, sa[i-1], sa[i]);
        }
    }
#if 0
    int lcp(int n, vector<vector<int>> &group, int k, int i, int j) {
        int ans = 0;
        // k=last=2, group[2][] : compared with len 4
        //   compare : group[2][i] == group[2][j]
        //   ans += (1 << k) : += 2^2 = 4
        // ...
        // k=last=3, group[3][] : compared with len 8
        //   if (group[3][i] != group[3][j])
        //   k -= 1 = 3-1 = 2
        // k=last=2, group[2][] : compared with len 4
        //   ans += (1 << k ) : += 2^2 = 4
        while (i < n && j < n && k >= 0) { 
            if (group[k][i] == group[k][j]) {
                ans += (1 << k);
                i += (1 << k);
                j += (1 << k);
            }
            k -= 1;
        }
        return ans;
    }
#endif
    cout << ans << '\n';
    return 0;
}
