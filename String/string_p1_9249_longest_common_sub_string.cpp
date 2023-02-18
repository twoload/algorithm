#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// length + strings
// lcp[i] = lcp(sa[i-1], sa[i])

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calc(int n, vector<vector<int>> & group, int k, int i, int j) {
    int ans = 0;
    while (i < n && j < n && k >= 0) {
        if (group[k][i] == group[k][j]) {
            ans += (1 << k); // ex. k=3, 1<<3 = 8  
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
    string s = a+"#"+b;
    int n = s.length();
    vector<int> sa(n);
    vector<vector<int>> group(22, vector<int>(n+1));
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) {
        group[0][i] = s[i]; // sa:x, s:o (my mistake!!!)
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
        group[k+1][sa[0]] = 0; // init value
        group[k+1][n] = -1;
        for (int i=1; i<n; i++) {
            if (cmp(sa[i-1], sa[i])) {
                group[k+1][sa[i]] = group[k+1][sa[i-1]] + 1;
            } else { // same
                group[k+1][sa[i]] = group[k+1][sa[i-1]];
            }
        }
        last = k+1; // group[k+1] was updated
    }
    vector<int> lcp(n);
    lcp[0] = -1; // minimum value
    for (int i=1; i<n; i++) {
        lcp[i] = calc(n, group, last, sa[i-1], sa[i]);
    }
    int ans = 0;
    int p = 0;
    for (int i=1; i<n; i++) {
        // they should be different strings : A, B
        if ((sa[i-1] >= na && sa[i] < na) || (sa[i-1] < na && sa[i] >= na)) {
            if (ans < lcp[i]) {
                ans = lcp[i];
                p = i;
            }
        }
    }
    cout << ans << '\n'; // max length
    //cout << s.substr(sa[p-1], ans) << '\n'; // ok
    cout << s.substr(sa[p], ans) << '\n';     // ok
    return 0;
}