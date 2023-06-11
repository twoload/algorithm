#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// max num of book to buy : maximum flow

// min of sum of delivery cost : MCMF

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost; // add
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance; // add
    vector<pair<int,int>> from;
    // delivery fee: 1,000/1 book
    //    Ai x N x 1,000(cost)
    //    100 x 100 x 1000
    //    10,000,000
    int inf = 10000000; // add
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
    };
    void add_edge(int u, int v, int cap, int cost) {
        Edge *ori = new Edge(v,cap,cost);
        Edge *rev = new Edge(u,0,-cost); // add: cost
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
    // total_flow
    // total_cost
    bool spfa(int &total_flow, int &total_cost) {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), inf);
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0; // source...
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
                        check[y] = true;
                        q.push(y);
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
int t1[111][111];
int t2[111][111];
int main() {
    int n,m;
    cin >> n >> m;
    MCMF mcmf(n+m+2, n+m, n+m+1);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        mcmf.add_edge_to_sink(m+i,x,0);
    }
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        mcmf.add_edge_from_source(i,x,0);
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> t1[i][j]; // cap
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> t2[i][j]; // cost
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (t1[i][j])
            mcmf.add_edge(i,j+m,t1[i][j],t2[i][j]);
        }
    }
    auto ans = mcmf.flow();
    cout << ans.first << '\n';
    cout << ans.second << '\n';
    return 0;
}
