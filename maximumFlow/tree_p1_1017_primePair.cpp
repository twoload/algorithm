#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// all number match ??? -> two parties matching

// 2,   3,5,....
// even odd...
// odd = odd + even
// num: 1~1000  , not duplicate

// odd   even
// 

// ex. 1,4,7,10,11,12
// 1 --- 4
//    X
// 7 --- 10
//    \\
// 11--- 12

// 2/N   2/N

// 1. can we match all numbers?

// 2. which one do we have to match ?
//    1st ------ n/2 match  (n=50 : match=25)
//     x
//    matching

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
    int n;
    int source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1);
    };
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    bool dfs(int x) {
        if (x == -1) return true;
        for (int next : graph[x]) {
            if (check[next]) continue;
            check[next] = true;
            if (dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    int flow() {
        int ans = 0;
        for (int i=0; i<n; i++) {
            fill(check.begin(),check.end(),false);
            if (dfs(i)) {
                ans += 1;
            }
        }
        return ans;
    }
};
bool prime(int n) {
    if (n < 2) return true;
    for (int i=2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n,m;
    scanf("%d",&n);
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    vector<int> ans;
    for (int k=1; k<n; k++) {
        if (!prime(a[0]+a[k])) continue;
        vector<int> even;
        vector<int> odd;
        for (int i=1; i<n; i++) {
            if (i==k) continue;
            if (a[i]%2==0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }
        if (even.size() != odd.size()) continue;
        int m = even.size();
        MaximumFlow mf(m);
        // all cases : m (< n/2-1 = 50/2-1) : O(m^2) : not too big!
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                if (prime(odd[i]+even[j])) {
                    mf.add_edge(i,j);
                }
            }
        }
        if (mf.flow() == m) { // all match
            ans.push_back(a[k]);
        }
    }
    if (ans.empty()) {
        printf("-1\n");
    } else {
        sort(ans.begin(),ans.end()); // sort
        for (int x : ans) {
            printf("%d ",x);
        }
        puts("");
    }
    return 0;
}



