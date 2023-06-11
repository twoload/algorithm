#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

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
            for (int j=0; j<2; j++) { // source ->(2)->left
                fill(check.begin(),check.end(),false);
                if (dfs(i)) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    scanf("%d",&n);
    MaximumFlow mf(n);
    vector<int> a(n),b(n),c(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    }
    // make graph
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            if (a[i]==a[j] && b[i]==b[j] && c[i]==c[j]) {
                if (i<j) { // our condition
                    mf.add_edge(i,j);
                }
            } else if (a[i]>=a[j] && b[i]>=b[j] && c[i]>=c[j]) {
                mf.add_edge(i,j);
            }
        }
    }
    printf("%d\n",n-mf.flow());
    return 0;
}