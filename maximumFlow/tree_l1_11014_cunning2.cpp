#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
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
            fill(check.begin(),check.end(),false);
            if (dfs(i)) {
                ans += 1;
            }
        }
        return ans;
    }
};
int node(int x, int y, int m) {
    return x*m+y;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        MaximumFlow mf(n*m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 'x') continue;
                if (i > 0) {
                    if (j > 0) {
                        if (a[i-1][j-1] == '.') {
                            if (j%2 == 0) { // even column
                                mf.add_edge(node(i,j,m),node(i-1,j-1,m));
                            } else { // odd column
                                mf.add_edge(node(i-1,j-1,m),node(i,j,m));
                            }
                        }
                    }
                    if (j+1 < m) {
                        if (a[i-1][j+1] == '.') {
                            if (j%2 == 0) { // even column
                                mf.add_edge(node(i,j,m),node(i-1,j+1,m));
                            } else { // odd column
                                mf.add_edge(node(i-1,j+1,m),node(i,j,m));
                            }
                        }
                    }
                }
                if (j > 0) {
                    if (a[i][j-1] == '.') {
                        if (j%2 == 0) { // even column
                            mf.add_edge(node(i,j,m),node(i,j-1,m));
                        } else { // odd column
                            mf.add_edge(node(i,j-1,m),node(i,j,m));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '.') ans += 1;
            }
        }
        // mf.flow : min vertex cover
        // ans : all
        // maximum independent set = all - mf.flow
        printf("%d\n",ans-mf.flow());
    }
    return 0;
}