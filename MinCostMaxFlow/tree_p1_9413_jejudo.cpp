#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// teacher

// intersection = vertex
// road = one way edge
// graph cycle x 
// => DAG

// S1 ----> T1
// S2 ----> T2

// Don't share the intersection(vertex)
//    vertex => Vin --(1)--> Vout
//                    ---
//                    cap=1
//                    cost= -1 (MAX)

// normal road 
//   cap = 1
//   cost = 0

//  SS --(2)-->  s -->  G --> t --(2)--> TT
//                 -->    -->
//                 -->    -->

#include <iostream>
#include <numeric>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost;
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance;
    vector<pair<int,int>> from;
    int inf = 10000000;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
    };
    void add_edge(int u, int v, int cap, int cost) {
        Edge *ori = new Edge(v,cap,cost);
        Edge *rev = new Edge(u,0,-cost);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap, int cost) {
        add_edge(source, v, cap, cost);
    }
    void add_edge_to_sink(int u, int cap, int cost) {
        add_edge(u, sink, cap, cost);
    }
    bool spfa(int &total_flow, int &total_cost) {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), inf);
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            check[x] = false;
            for (int i=0; i<graph[x].size(); i++) {
                auto e = graph[x][i];
                int y = e->to;
                if (e->capacity > 0 && distance[x] + e->cost < distance[y]) {
                    distance[y] = distance[x] + e->cost;
                    from[y] = make_pair(x,i);
                    if (!check[y]) {
                        q.push(y);
                        check[y] = true;
                    }
                }
            }
        }
        if (distance[sink] == inf) {
            return false;
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
        total_flow += c;
        total_cost += c*distance[sink];
        return true;
    }
    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        while (spfa(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};
int in_node(int x) {
    return 2*x;
}
int out_node(int x) {
    return 2*x+1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        MCMF mcmf(2*n+4, 2*n, 2*n+1); // super source, super sink
        // super_source: 2*n
        // super_sink: 2*n+1
        // super_source -> source (2*n+2)
        // sink (2*n+3) -> super_sink
        for (int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            // normal road
            mcmf.add_edge(out_node(x), in_node(y), 1, 0);
        }
        for (int i=0; i<n; i++) {
            // vertex (intersection)
            mcmf.add_edge(in_node(i), out_node(i), 1, -1);
            mcmf.add_edge(2*n+2, in_node(i), 1, 0);
            mcmf.add_edge(out_node(i), 2*n+3, 1, 0);
        }
        mcmf.add_edge_from_source(2*n+2, 2, 0); // limit to 2
        mcmf.add_edge_to_sink(2*n+3, 2, 0); // limit to 2
        cout << -mcmf.flow().second << '\n'; // MAX
    }
    return 0;
}
