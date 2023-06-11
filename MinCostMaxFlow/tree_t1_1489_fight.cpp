#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif


// s --(cap:1)-->A1 --(cap:1)--> B1 --(cap:1)--> t
//     (cost:0)       (cost:2,1)
//                     -1


#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MCMF {
    struct Edge {
        int to;
        int capacity;
        long long cost;
        Edge *rev;
        Edge(int to, int capacity, long long cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<long long> distance;
    vector<pair<int,int>> from;
    long long inf = 100'000'000'000LL;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
    };
    void add_edge(int u, int v, int cap, long long cost) {
        Edge *ori = new Edge(v,cap,cost);
        Edge *rev = new Edge(u,0,-cost);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap, long long cost) {
        add_edge(source, v, cap, cost);
    }
    void add_edge_to_sink(int u, int cap, long long cost) {
        add_edge(u, sink, cap, cost);
    }
    bool spfa(int &total_flow, long long &total_cost) {
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
        total_cost += (long long)c*distance[sink];
        return true;
    }
    pair<int,long long> flow() {
        int total_flow = 0;
        long long total_cost = 0;
        while (spfa(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};

int in_node(int x) {
    return x*2;
}
int out_node(int x) {
    return x*2+1;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    MCMF mcmf(2*n+2, 2*n, 2*n+1);
    // 0 ≤ i < n: a_i
    // n ≤ i < 2n: b_{i-n}
    for (int i=0; i<n; i++) {
        mcmf.add_edge_from_source(i, 1, 0); // s -> a_i
        mcmf.add_edge_to_sink(n+i, 1, 0); // b_i -> t
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i] > b[j]) {
                mcmf.add_edge(i, n+j, 1, -2);
            } else if (a[i] == b[j]) {
                mcmf.add_edge(i, n+j, 1, -1);
            } else {
                mcmf.add_edge(i, n+j, 1, 0);
            }
        }
    }
    cout << -mcmf.flow().second << '\n';
    return 0;
}

