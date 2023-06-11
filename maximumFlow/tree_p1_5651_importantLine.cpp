#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// very important edge 

// 1. find max flow : flow first
// 2. (u,v) check if there is an edge
//    if there is no edge, it is an important edge.


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
        int from;
        int to;
        int capacity;
        Edge *rev;
        Edge(int from, int to, int capacity) : from(from), to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<Edge *> edges;
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(u,v,cap);
        Edge *rev = new Edge(v,u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
        edges.push_back(ori);
    }
    int bfs() {
        fill(check.begin(), check.end(), false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if (!check[sink]) {
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
            int f = bfs();
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
    bool dfs(int x, int goal) {
        if (x == goal) {
            return true;
        }
        check[x] = true;
        for (int i=0; i<graph[x].size(); i++) {
            int next = graph[x][i]->to;
            if (!check[next] && graph[x][i]->capacity > 0) {
                if (dfs(next, goal)) {
                    return true;
                }
            }
        }
        return false;
    }
    int crucial() {
        flow();
        int ans = 0;
        for (auto e : edges) {
            fill(check.begin(), check.end(), false);
            if (!dfs(e->from, e->to)) {
                ans += 1;
            }
        }
        return ans;
    }
};
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d %d",&n,&m);
        MaximumFlow mf(n,0,n-1);
        for (int i=0; i<m; i++) {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            x-=1;
            y-=1;
            mf.add_edge(x,y,z);
        }
        printf("%d\n",mf.crucial());
    }
    return 0;
}