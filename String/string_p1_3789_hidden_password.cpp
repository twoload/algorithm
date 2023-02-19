#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// abcd
// bcda
// cdab
// dabc

// abcd/abcd  : two strings addition
// ----
//  ----
//   ----
//    ----

// teacher
// abcd/abcd : length 4 sub strings

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
    int t;
    cin >> t;
    while (t--) {
        int m;
        string s;
        cin >> m >> s;
        s = s+s+"z"; // abcd+abcd : two strings
        // if "z" is not added, it's ok to put group[k+1][n] = n+1 instead of -1
        int n = s.length();
        vector<int> sa(n);
        vector<vector<int>> group(22, vector<int>(n+1));
        for (int i=0; i<n; i++) {
            sa[i] = i;
        }
        for (int i=0; i<n; i++) {
            group[0][i] = s[i]; // s!!!
        }
        // ex. 6 baabaa
        // if group[0][n] = n+1
        // 1: aabaabaabaa(Big) 
        // 4:    aabaabaa(Big)
        // 7:       aabaa(Big)
        // But if group[0][n] = -1,
        // 7:       aabaa(-1)
        // 4:    aabaabaa(-1)
        // 1: aabaabaabaa(-1)
        // what we want is 1-4-7. previous one.
        group[0][n] = -1;//n+1;//-1;//n+1; // ???
        int last = 0;
        for (int k=0, len=1; len/2 < n; len*=2, k++) {
            auto cmp = [&](int u, int v) {
                if (group[k][u] == group[k][v]) {
                    return group[k][u+len] < group[k][v+len];
                } else {
                    return group[k][u] < group[k][v];
                }
            };
            //printf("k=%d,l=%d > ", k, len);
            sort(sa.begin(), sa.end(), cmp); // sa: sorted
            //for(int i=0; i<sa.size(); i++) {
            //    printf("%d ", sa[i]);
            //}
            //printf("\n");
            group[k+1][sa[0]] = 0;
            group[k+1][n] = -1;//n+1;//-1;//n+1; // ???
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
        for (int i=0; i<n; i++) {
            if (sa[i] < m) { // ex.abcd : m = 4
                cout << sa[i] << '\n';
                break;
            }
        }
    }
    return 0;
}