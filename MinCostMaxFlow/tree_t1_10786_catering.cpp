#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif


// teacher

// K team
// N resevation

// Company:1-th : all companies are in 1-th

// find min cost to handle all requests

// A[i][j] : cost which we move from i to j

// 2~N+1: the place that we've made a reservation


//=> Find num of K of path starting 1 ***

#if 0
3 2
40 30 40
50 10
50

n: 3(request), k: 2(team)

()() // company
1 --(40)-->    2
|  \     /     |
(40)\   /(10)  |(50)
| ---(30)---   |
V V          V V
4 <----(50)--- 3

Company:1, resevation:2,3,4
min cost: 
    1 -> 2 -> 4,
    1 -> 3
//  1 -> 2 = 40
//  1 -> 3 = 30
//  2 -> 4 = 10
//         = 80

1--> K path find!!!

each vertex should be included in one edge
=> vertex divide

each vertex should be connected to sink
<= because it can be stop in the middle of



    

#endif


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
    // cost = 1'000'000
    // k = 100
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
    int n,m;
    cin >> n >> m;
    // ex. n=3, m=2
    // vertex: 1,2,3,4 -> divide = 8
    // source(1), sink
    // total n' = 9
    MCMF mcmf(2*(n+1)+1, 0, 2*(n+1));
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        // 1 -> each node (2,3,4)
        mcmf.add_edge(out_node(0),in_node(i),1,x);
    }
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            int x;
            cin >> x;
            // connect each node except 1
            mcmf.add_edge(out_node(i), in_node(j), 1, x);
        }
    }
    // 1in ---(cap:m,cost:0)--->1out
    mcmf.add_edge(in_node(0), out_node(0), m, 0);
    for (int i=1; i<=n; i++) {
        // Iin ---(cap:m,cost:-inf)--->1out
        // prevent to make cost 0
        mcmf.add_edge(in_node(i), out_node(i), 1, -mcmf.inf);
        // Iout --(cap:1,cost:0)--> sink
        mcmf.add_edge_to_sink(out_node(i), 1, 0);
    }
    // 1out --(cap:m,cost:0)-->sink
    mcmf.add_edge_to_sink(out_node(0), m, 0);
    cout << mcmf.flow().second + mcmf.inf*(long long)n<< '\n';
    //                           --------------------- each vertex: one pass
    return 0;
}