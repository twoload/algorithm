#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

 // row group, col group

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
    vector<int> check;
    vector<int> matchR;
    vector<int> matchL;
    int step;
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        matchR.resize(n,-1);
        matchL.resize(n,-1);
    };
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    bool dfs(int x) {
        if (x == -1) return true;
        for (int next : graph[x]) {
            if (check[next] == step) continue;
            check[next] = step;
            if (dfs(matchR[next])) {
                matchR[next] = x;
                matchL[x] = next;
                return true;
            }
        }
        return false;
    }
    int flow() {
        int ans = 0;
        for (int i=0; i<n; i++) {
            step = i+1;
            if (dfs(i)) {
                ans += 1;
            }
        }
        return ans;
    }
};
/**
 * 
 * source --> row dir1 --> col dir1 --> sink
 *        --> row dir2 --> col dir2 -->
 *        --> row dir3 --> col dir3 -->
 * 
 * 
 * 
 */ 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> h(n), v(m);
        vector<string> hword(n), vword(m);
        MaximumFlow mf(max(n,m));
        for (int i=0; i<n; i++) {
            cin >> h[i].first >> h[i].second; // x,y
            cin >> hword[i];
        }
        for (int i=0; i<m; i++) {
            cin >> v[i].first >> v[i].second; // x,y
            cin >> vword[i];
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                // x dir (no overlap) 
                // v.x < h.x.begin
                if (v[j].first < h[i].first) continue;
                // x dir (no overlap)
                // h.x.end < v.x
                if (v[j].first >= h[i].first + hword[i].size()) continue;
                // y dir (no overlap)
                // h.y < v.y
                if (h[i].second < v[j].second) continue;
                // h.y >= v.y.end
                if (h[i].second >= v[j].second + vword[j].size()) continue;
                // if overlap and diff value, add edge
                // we need to cut (min cut)
                // max flow
                if (hword[i][v[j].first-h[i].first] != vword[j][h[i].second-v[j].second]) {
                    mf.add_edge(i,j);
                }
            }
        }
        cout << n+m-mf.flow() << '\n';
        //          --------- (min cut: overlap)
        //      all - min cut(overlap)
        //      = max number of words which doesn't overlap
    }
    return 0;
}
