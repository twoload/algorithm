#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// O(n^2logn)
//->O(nlog^2n) = sort:O(nlogn) x logn (repeat)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> sa(n); // suffix array
    vector<int> group(n+1); // group
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) { // one len : 1st ch check
        group[i] = s[i];
    }
    group[n] = -1; // n-1:last, n:empty
    // i: 0 1 2 3 4 5 6 7 8 9
    // S: a b c d a b c a b b 
    // G: 0 1 2 3 0 1 2 0 1 1 (one ch)
    //G0: 4: abcabb
    //    0: abcdabcabb
    //    7: abb
    //G1: 1: bcdabcabb
    //    8: bb
    //    5: bcabb
    //    9: b
    //G2: 2: cdabcabb
    //    6: cabb
    //G3: 3: dabcabb
    //important!!! = suffix's suffix = suffix
    //G0: 4: abcabb     G[4]=0 > G[5]=1
    //    0: abcdabcabb G[0]=0 > G[1]=1 => same
    //G0: 0: abcdabcabb G[0]=0
    //G1: 1: bcdabcabb  G[1]=1 => 0 is earlier than 1
    //G2: 2: cdabcabb   G[2]=2 > G[3]=3
    //    6: cabb       G[6]=2 > G[7]=0 => 6 is earlier than 2
    //G1: 8: bb
    //G1: 9: b => 9 is earlier than 8
    // i: 0 1 2 3 4 5 6 7 8 9
    // S: a b c d a b c a b b 
    // G: 0 3 5 6 0 3 4 0 2 1 (two ch)
    //G0  4: abcabb
    //    0: abcdabcabb
    //    7: abb
    //G1: 9: b
    //G2: 8: bb
    //G3: 1: bcdabcabb
    //    5: bcabb
    //G4: 6: cabb
    //G5: 2: cdabcabb
    //G6: 3: dabcabb
    // i: 0 1 2 3 4 5 6 7 8 9
    // S: a b c d a b c a b b 
    // G: 0 3 5 6 0 3 2 0 2 1 (four ch)
    //G': 2 6 8 9 1 5 7 0 4 3
    // 4: abcabb     G[4]=0 > G[6]=2
    // 0: abcdabcabb G[0]=0 > G[2]=5 => 4 is earlier than 0
    //G0: 7: abb /
    //G1: 4: abca/bb
    //G2: 0: abcd/abcabb
    //G3: 9: b   /
    //G4: 8: bb  /
    //G5: 5: bcab/b
    //G6: 1: bcda/bcabb
    //G7: 6: cabb/
    //G8: 2: cdab/cabb
    //G9: 3: dabc/abb
    // <---> <---------->
    //   t   <----> t : compare
    for (int len=1; len/2 < n; len*=2) { //1>2>4>8>...
        auto cmp = [&](int u, int v) {
            if (group[u] == group[v]) {
                // len:1>2>4>8...
                return group[u+len] < group[v+len]; // compare suffix
            } else {
                return group[u] < group[v];
            }
        };
        sort(sa.begin(), sa.end(), cmp); //sa:sort: suffix array
        // new group number
        vector<int> group2(n+1);
        group2[sa[0]] = 0; //init
        group2[n] = -1; //n-1:last, n:empty
        for (int i=1; i<n; i++) {
            // cmp(sa[0], sa[1])
            // ...
            // cmp(sa[n-2], sa[n-1])
            if (cmp(sa[i-1], sa[i])) {
                // diff
                group2[sa[i]] = group2[sa[i-1]]+1;
            } else {
                // same
                group2[sa[i]] = group2[sa[i-1]];
            }
        }
        group = group2; //update
    }
    for (int i=0; i<n; i++) {
        cout << sa[i] << '\n';
    }
    return 0;
}
#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> sa(n);
    // 100,000
    // log(100,000) < 20
    // group -> group[k]
    // group2 -> group[k+1]
    vector<vector<int>> group(20, vector<int>(n+1));
    for (int i=0; i<n; i++) {
        sa[i] = i;
    }
    for (int i=0; i<n; i++) {
        group[0][i] = s[i];
    }
    group[0][n] = -1;
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
    }
    for (int i=0; i<n; i++) {
        cout << sa[i] << '\n';
    }
    return 0;
}
#endif