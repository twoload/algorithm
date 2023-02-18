#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// Radix sort
//   suffix array : O(nlog^2n) -> O(nlogn)

// Radix sort
// 260,35,25,160,8,90,33,180,23,45,10,98
// Radix 1
// 0 : 260, 160, 90, 180, 10
// 1
// 2
// 3 : 33, 23
// 4
// 5 : 35, 25, 45
// 6
// 7
// 8 : 8, 98
// 9
// 260,160,90,180,10,33,23,35,25,45,8,98
// Radix 10
// 0 : 8
// 1 : 10
// 2 : 23,25
// 3 : 33
// 4 : 45
// 5 : 
// 6 : 260,160
// 7
// 8 : 180
// 9 : 90,98
// 8,10,23,25,33,45,260,160,180,90,98
// Radix 100
// 0 : 8,10,23,25,33,45,90,98
// 1 : 160,180
// 2 : 260
// 3 : 
// 4 : 
// 5 : 
// 6 : 
// 7
// 8 : 
// 9 : 
// 8,10,23,25,33,45,90,98,160,180,260

// O(dN) // N: number of numbers, d: radix (260->3)
#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct suffix {
    int index;
    int rank[2];
};
void radix_sort(int len, vector<int> &sa, vector<int> &group) {
    int n = sa.size();
    vector<suffix> a(n);
    for (int i=0; i<n; i++) {
        a[i].index = sa[i];
        a[i].rank[0] = group[sa[i]];
        if (sa[i]+len < n) {
            a[i].rank[1] = group[sa[i]+len];
        } else {
            a[i].rank[1] = -1;
        }
    }
    vector<suffix> temp(n);
    for (int p=1; p>=0; p--) {
        vector<int> cnt(n+1, 0);
        vector<int> sum(n+2, 0);
        for (int i=0; i<n; i++) {
            cnt[a[i].rank[p]+1] += 1;
        }
        for (int i=1; i<n+1; i++) {
            sum[i] = sum[i-1] + cnt[i-1];
        }
        for (int i=0; i<n; i++) {
            temp[sum[a[i].rank[p]+1]++] = a[i];
        }
        for (int i=0; i<n; i++) {
            a[i] = temp[i];
        }
    }
    for (int i=0; i<n; i++) {
        sa[i] = a[i].index;
    }
    group[a[0].index] = 0;
    for (int i=1; i<n; i++) {
        if (a[i].rank[0] == a[i-1].rank[0] && a[i].rank[1] == a[i-1].rank[1]) {
            group[a[i].index] = group[a[i-1].index];
        } else {
            group[a[i].index] = group[a[i-1].index] + 1;
        }
    }
}
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> sa(n);
    vector<int> group(n);
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) {
        group[i] = s[i] - 'a';
    }
    for (int len=1; len/2 < n; len*=2) {
        radix_sort(len, sa, group);
    }
    for (int i=0; i<n; i++) {
        cout << sa[i] << '\n';
    }
    return 0;
}
#endif
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
    for (int i=0; i<n; i++) {
        cout << sa[i]+1 << ' ';
    }
    cout << '\n';
    cout << 'x' << ' ';
    for (int i=1; i<n; i++) {
        cout << lcp[i] << ' ';
    }
    cout << '\n';


    return 0;
}