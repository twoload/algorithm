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
    int n,k;
    int source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    MaximumFlow(int n, int k) : n(n), k(k) {
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
        int cnt = 0;
        for (int i=0; i<n; i++) {
            fill(check.begin(),check.end(),false);
            if (dfs(i)) {
                ans += 1;
            }
        }
        for (int i=0; i<n; i++) {
            while (true) {
                fill(check.begin(),check.end(),false);
                if (dfs(i)) {
                    ans += 1;
                    cnt += 1;
                } else {
                    break;
                }
                if (cnt == k) break;
            }
            if (cnt == k) break;
        }
        return ans;
    }
};

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    MaximumFlow mf(max(n,m),k);
    for (int i=0; i<n; i++) {
        int cnt;
        scanf("%d",&cnt);
        for (int j=0; j<cnt; j++) {
            int job;
            scanf("%d",&job);
            mf.add_edge(i,job-1);
        }
    }
    printf("%d\n",mf.flow());
    return 0;
}