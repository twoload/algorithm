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
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
    }
    int dfs(int x, int c) {
        if (check[x]) return 0;
        check[x] = true;
        if (x == sink) {
            return c;
        }
        for (int i=0; i<graph[x].size(); i++) {
            if (graph[x][i]->capacity > 0) {
                int nc = graph[x][i]->capacity;
                if (c != 0 && c < nc) {
                    nc = c;
                }
                int f = dfs(graph[x][i]->to, nc);
                if (f) {
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ans = 0;
        while (true) {
            fill(check.begin(),check.end(),false);
            int f = dfs(source, 0);
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    MaximumFlow mf(n+m+2,0,n+m+1);
    for (int i=1; i<=n; i++) {
        int cnt;
        scanf("%d",&cnt);
        for (int j=0; j<cnt; j++) {
            int job;
            scanf("%d",&job);
            mf.add_edge(i,n+job,1);
        }
    }
    for (int i=1; i<=n; i++) {
        mf.add_edge_from_source(i,1);
    }
    for (int i=1; i<=m; i++) {
        mf.add_edge_to_sink(n+i,1);
    }
    printf("%d\n",mf.flow());
    return 0;
}