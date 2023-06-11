#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// row group
// col group

// #.#.
// .###
// ###.
// ..#.

// row group
// 1 2
//  333
// 444
//   5

// col group
// 1 4
//  345
// 234
//   4


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
    cin >> n >> m; // row, col
    char b[100];
    vector<string> a(n); // string *.
    vector<vector<int>> r(n, vector<int>(m,0)); // row group
    vector<vector<int>> c(n, vector<int>(m,0)); // col group
    int rn=0;
    int cn=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '*') {
                if (j-1 < 0 || a[i][j-1] == '.') { // diff from before
                    r[i][j] = ++rn;
                } else if (a[i][j-1] == '*') { // same as before
                    r[i][j] = r[i][j-1];
                }
            }
        }
    }
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            if (a[i][j] == '*') {
                if (i-1 < 0 || a[i-1][j] == '.') {
                    c[i][j] = ++cn;
                } else if (a[i-1][j] == '*') {
                    c[i][j] = c[i-1][j];
                }
            }
        }
    }
    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d",r[i][j]);
        }
        puts("");
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d",c[i][j]);
        }
        puts("");
    }
    */
    MaximumFlow mf(max(rn,cn));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (r[i][j] > 0 && c[i][j] > 0) { // meaningful
                mf.add_edge(r[i][j]-1,c[i][j]-1); // create bipartie graph
            }
        }
    }
    printf("%d\n",mf.flow()); // maximum flow of bipartie graph = min virtex cover
    return 0;
}