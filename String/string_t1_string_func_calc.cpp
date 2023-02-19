#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// find LCP
// but frequency is also important

// teacher
// LCP[i] = LCP(SA[i-1], SA[i])

// SA[i-1] \ LCP[i]     = k1
// SA[i]   / \ LCP[i+1] = k2
// SA[i+1]   /

//idx: 0 1 2 3 4 5 6 7 8 9
//s  : a b c d a b c a b b
//g  : 2 6 8 9 1 5 7 0 4 3
//sa : 7 4 0 9 8 5 1 6 2 3
//lcp: - 2 3 0 1 1 2 0 1 0

//       2: 2x2 = 4
//       2 3: min(2,3)x3=6
//         3: 3x2 = 6
//             1 1 2: min(1,1,2)x4=4 (9,8,5,1)
// lcp[i]-lcp[j], i<= j
// min = i-1:th sa ~ j:th sa
// 100,000
// all segments = O(n^2) = 100,000^2 = too big!!!
// = find the biggest square in the histogram

// 7: abb
// 4: abcabb
// 0: abcdabcabb
// 9: b
// 8: bb
// 5: bcabb
// 1: bcdabcabb
// 6: cabb
// 2: cdabcabb
// 3: dabcabb

#include <iostream>
#include <stack>
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

// same as finding the max square in histogram
long long largest(vector<int> &a) {
    int n = a.size();
    stack<long long> s;
    long long ans = 0;
    for (int i=1; i<n; i++) {
        int left = i;
        while(!s.empty() && a[s.top()] > a[i]) {
            long long height = a[s.top()];
            s.pop();
            long long width = i;
            if (!s.empty()) {
                width = (i - s.top() - 1);
            }
            width += 1; //lcp 1ea = string 2ea, lcp 2ea = string 3ea
            if (ans < width*height) {
                ans = width*height;
            }
        }
        s.push(i);
    }
    while(!s.empty()) {
        long long height = a[s.top()];
        s.pop();
        long long width = n;
        if (!s.empty()) {
            width = n-s.top()-1;
        }
        width += 1; //lcp 1ea = string 2ea, lcp 2ea = string 3ea
        if (ans < width*height) {
            ans = width*height;
        }
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
    } // SA + LCP 
    cout << largest(lcp) << '\n';
    return 0;
}
