#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// vertex capacity
// ()   =>  -> Vin -> Vout ->


// 0 1 2
// 3 4 5
// 6 7 8

// in/out
// 0,1   2,3   4,5
// 6,7   8,9   10,11
// 12,13 14,15 16,17

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
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
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
};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int in_node(int x, int y, int m) {
    return 2*(x*m+y);
}
int out_node(int x, int y, int m) {
    return in_node(x,y,m)+1;
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int sx,sy; //start
    int ex,ey; //end
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'K') {
                sx=i; //start
                sy=j;
            } else if (a[i][j] == 'H') {
                ex=i; //end
                ey=j;
            }
        }
    }
    // in/out
    // 0,1   2,3   4,5
    // 6,7   8,9   10,11
    // 12,13 14,15 16,17
    int inf = 1000000;
    MaximumFlow mf(2*(n*m), out_node(sx,sy,m), in_node(ex,ey,m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '#') continue;
            mf.add_edge(in_node(i,j,m), out_node(i,j,m), 1); // in_node -(1)- out_node
            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) { // out of range
                    if (a[nx][ny] != '#') {
                        // to make cut only happen in between vertexs
                        mf.add_edge(out_node(i,j,m), in_node(nx,ny,m), inf); // out node -(inf)- in node
                    }
                }
            }
        }
    }
    int ans = mf.flow();
    if (ans >= inf) {
        ans = -1;
    }
    printf("%d\n",ans);
    return 0;
}