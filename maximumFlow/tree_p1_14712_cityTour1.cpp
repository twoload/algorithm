#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// maximum flow

// 1: source, 2: sink

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
    vector<int> check;
    vector<pair<int,int>> from;
    int step;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
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
    int bfs() {
        queue<int> q;
        q.push(source);
        check[source] = step;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                if (graph[x][i]->capacity > 0 && check[graph[x][i]->to] != step) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = step;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if (check[sink] != step) {
            return 0;
        }
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        while (from[x].first != -1) {
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first != -1) {
            Edge *e = graph[from[x].first][from[x].second];
            e->capacity -= c;
            e->rev->capacity += c;
            x = from[x].first;
        }
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            step += 1;
            int f = bfs();
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};
int inf = 1000000;
int main() {
    int n,m;
    cin >> n >> m;
    MaximumFlow mf(n, 0, 1); // n, source:0, sink:1
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        mf.add_edge(x, y, 1); // make graph
    }
    cout << mf.flow() << '\n';
    return 0;
}