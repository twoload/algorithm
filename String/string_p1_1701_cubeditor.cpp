#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// max len in substrings which show over twice
// num of string : <= 5000

// abcdababca
// abc(3)

// all substrings = suffix's prefix

// max of all LCP (longest common prefix)


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
        if (ans < lcp[i]) {
            ans = lcp[i];
        }
    }
    cout << ans << '\n';
    return 0;
}