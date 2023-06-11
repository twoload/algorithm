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

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m,0)); // ㅁ[n][m]
    vector<vector<int>> r(n, vector<int>(m,0));
    vector<vector<int>> c(n, vector<int>(m,0));
    int rn=0;
    int cn=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] != 2) { // not wall
                if (j-1 < 0 || a[i][j-1] == 2) { // diff (because of wall or init)
                    r[i][j] = ++rn;
                } else if (a[i][j-1] != 2) { // same
                    r[i][j] = r[i][j-1];
                }
            }
        }
    }
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            if (a[i][j] != 2) {
                if (i-1 < 0 || a[i-1][j] == 2) {
                    c[i][j] = ++cn;
                } else if (a[i-1][j] != 2) {
                    c[i][j] = c[i-1][j];
                }
            }
        }
    }
    MaximumFlow mf(max(rn,cn));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (r[i][j] > 0 && c[i][j] > 0 && a[i][j] == 0) {
                mf.add_edge(r[i][j]-1,c[i][j]-1);
            }
        }
    }
    printf("%d\n",mf.flow());
    return 0;
}