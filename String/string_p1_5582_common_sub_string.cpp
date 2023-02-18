#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// each sa + lcp
// compare

// teacher
// dp
// d[i][j] = d[i-1][j-1] + 1 (a[i] == a[j]) else 0
// max value in d array

// sa
// find all suffix array in both strings
// LCP : O(n) for any two trings
// two sa : O(logn) ???
// step1. combine two strings 
// step2. find sa
// LCP : O(logn)

// LCP (SA[i], SA[i-1])
//       <-------> different strings should be
// abc, bcd
// abcbcd
// 012345
// index < A's len
// index >= A's len = B

// abcbcd 0
// bcbcd  1  0
// bcd    3  2
// cbcd   2  0
// cd     4  1
// d      5  0

// counter example
// A = AA
// B = AAA
// AAAAA

// A
// AA
// AAA  ->
// A/AAA -> LCP : 3
// AA/AAA

// S = A + '#' + B  (add the char which cannot be showed)
// AA # AAA
// A
// AA
// AAA
// AA#AAA -> LCP : 2
// A#AAA

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// LCP : O(logn)
int calc(int n, vector<vector<int>> &group, int k, int i, int j) {
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
    string a, b;
    cin >> a >> b;
    int na = a.length();
    int nb = b.length();
    string s = a+"#"+b; // remove counterexample : AA, AAA
    int n = s.length();
    vector<int> sa(n);
    vector<vector<int>> group(22, vector<int>(n+1)); // under 22
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) { // group 0
        group[0][i] = s[i];
    }
    group[0][n] = -1; // 0~n-1 : n = earliest
    int last = 0;
    for (int k=0, len=1; len/2 < n; len*=2, k++) { // len=1>2>4>8...
        auto cmp = [&](int u, int v) {
            // compare sa[u], sa[v]
            //         sa[u+t], sa[v+t], t=len
            if (group[k][u] == group[k][v]) {
                return group[k][u+len] < group[k][v+len];
            } else {
                return group[k][u] < group[k][v];
            }
        };
        sort(sa.begin(), sa.end(), cmp);
        // update group
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
    }
    vector<int> lcp(n);
    lcp[0] = -1;
    for (int i=1; i<n; i++) {
        // logest common prefix
        lcp[i] = calc(n, group, last, sa[i-1], sa[i]);
    }
    int ans = 0;
    for (int i=1; i<n; i++) {
        // sa[i-1] >= na && sa[i] < na : B && A
        // sa[i-1] < na && sa[i] >= na : A && B
        // LCP (SA[i], SA[i-1])
        //       <-------> different strings should be
        if ((sa[i-1] >= na && sa[i] < na) || (sa[i-1] < na && sa[i] >= na)) {
            if (ans < lcp[i]) {
                ans = lcp[i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
