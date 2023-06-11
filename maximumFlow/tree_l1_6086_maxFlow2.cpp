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
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int bfs() {
        vector<bool> check(n, false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                // x-> can go -> go!!!
                if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = make_pair(x,i); // for back tracking : x->y i-th
                }
            }
        }
        if (!check[sink]) { // if we can't go sink, can't go
            return 0;
        }
        int x = sink;
        // min value : back tracking (while back tracking, find min value)
        int c = graph[from[x].first][from[x].second]->capacity;
        while (from[x].first != -1) { // -1: source
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity; // find min value
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first != -1) {
            Edge *e = graph[from[x].first][from[x].second];
            e->capacity -= c; // --> -c
            e->rev->capacity += c; // <-- +c
            x = from[x].first;
        }
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            int f = bfs();
            if (f == 0) break; // until we can't find
            ans += f;
        }
        return ans;
    }
};
int node(string s) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
        return s[0] - 'A';
    } else {
        return s[0] - 'a' + 26;
    }
}
int main() {
    int m;
    cin >> m;
    MaximumFlow mf(52, 0, 'Z'-'A');
    for (int i=0; i<m; i++) {
        string us, vs;
        int f;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        mf.add_edge(u,v,f);
        mf.add_edge(v,u,f);
    }
    cout << mf.flow() << '\n';
    return 0;
}