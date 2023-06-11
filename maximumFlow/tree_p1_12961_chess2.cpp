#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// tile
// w  wb bw  w
// bw  w w  wb

// 4 group > two partie
// ????


// 1: white element in odd row
// 2: black element
// 3: white element in even row

/**
 * 2 3 2 3 2 3 2 3 2 3 2 3
 * 1 2 1 2 1 2 1 2 1 2 1 2
 * 2 3 2 3 2 3 2 3 2 3 2 3
 * 1 2 1 2 1 2 1 2 1 2 1 2
 * 2 3 2 3 2 3 2 3 2 3 2 3
 * 1 2 1 2 1 2 1 2 1 2 1 2
 * 
 * 
 */

// 1->2->3 : L shape tile
// s->1 (cap=1)
// 1->2 (cap=1)
// 2->3 (cap=1)
// 3->t (cap=1)

// vertex capacity = 1 (don't overlap)

// 1in --(1)--> 1out
// 2in --(1)--> 2out
// 3in --(1)--> 3out

// (r,c) -> r*m + c
//         2*(r*m + c)   : in
//         2*(r*m + c)+1 : out


#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
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
const int inf = 100; 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    // vertex : in / out
    auto in_node = [&](int x, int y) {
        return 2*(x*m+y);
    };
    auto out_node = [&](int x, int y) {
        return in_node(x,y)+1;
    };
    // 1: white element in odd row
    // 2: black element
    // 3: white element in even row
    auto type = [&](int x, int y) {
        if ((x+y)%2 == 0) return 2;
        if (x % 2 == 0) return 3; // white in even row
        return 1; 
    };
    // vertex capacity
    // source: n*m*2
    // sink : n*m*2 + 1
    MaximumFlow mf(n*m*2+2, n*m*2, n*m*2+1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '.') {
                // Vin --(1)--> Vout
                mf.add_edge(in_node(i,j), out_node(i,j), 1);
                int t = type(i, j);
                // 1: white element in odd row
                // 2: black element
                // 3: white element in even row

                // 1->2->3 : L shape tile
                // s->1 (cap=1)
                // 1->2 (cap=1)
                // 2->3 (cap=1)
                // 3->t (cap=1)
                if (t == 1) {
                    mf.add_edge_from_source(in_node(i,j),1);
                }
                if (t == 3) {
                    mf.add_edge_to_sink(out_node(i,j),1);
                }
                for (int k=0; k<4; k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    // out of range
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        if (a[x][y] == '.') {
                            if (type(i,j)+1 == type(x,y)) {
                                // 1->2 (cap=1)
                                // 2->3 (cap=1)
                                mf.add_edge(out_node(i,j), in_node(x,y),1);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << mf.flow() << '\n';
    return 0;
}




 