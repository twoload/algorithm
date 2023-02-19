#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// penlindrome
// -> 
// <-
// same

// teacher
// S  = banana
// S' = ananab
// S+'#'+S' = banana#ananab
//             ----- ----- LCP max

// 6 #ananab
// 5 a#ananab (LCP = 0)
// 11 ab (LCP=1)
// 3 ana#ananab (LCP=1)
// 9 anab (LCP=3)
// 1 anana#ananab (LCP=3)
// 7 ananab (LCP=5)
// 12 b (LCP=0)
// 0 banana#ananab (LCP=1)
// 4 na#ananab (LCP=0)
// 10 nab (LCP=2)
// 2 nana#ananab (LCP=2)
// 8 nanab (LCP=4)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
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
    string t;
    cin >> t;
    string tr = t;
    reverse(tr.begin(), tr.end()); // reverse
    int m = t.length();
    string s;
    s = t + "#" + tr; // combine , insert "#" to differentiate
    int n = s.length();
    vector<int> sa(n);
    vector<vector<int>> group(22, vector<int>(n+1));
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) {
        group[0][i] = s[i];
    }
    group[0][n] = -1;
    int last = 0;
    for (int k=0, len=1; len/2 < n; len*=2, k++) {
        auto cmp = [&](int u, int v) {
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
    }
    vector<int> lcp(n);
    lcp[0] = -1;
    for (int i=1; i<n; i++) {
        lcp[i] = calc(n, group, last, sa[i-1], sa[i]);
    }
    int ans = 0;
    for (int i=1; i<n; i++) {
        if ((sa[i-1] > m && sa[i] < m) || (sa[i-1] < m && sa[i] > m)) {
            if (ans < lcp[i]) {
                ans = lcp[i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
