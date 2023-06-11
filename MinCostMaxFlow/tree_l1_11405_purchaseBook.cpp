#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// maximum flow + cost = min cost max flow

// in MCMF
// if there is no limitation of capacity,
//    -> minimum distance 
// if all costs are 0,
//    -> maximum flow

/**
 * 
 *              bookstore  people
 *                     cap:inf
 *                     cost:delivery
 *  source --(5)--> 1 --(inf)-->  1--(3)--> sink
 *  source --(3)--> 2 --(inf)-->  2--(2)--> sink
 *  ...
 * 
 * 
 * 
 */
// max flow : s->t find path
// min cost max flow : s->t find min cost path
//                     bellmanford ** (minus weight)
//                         u->v : cost(u,v)
//                         v->u : -cost(u,v)
//                     dijkstra : X

// we can get an answer
//    only when graph doesn't include minus cycle
// in bellmanford

// Bellmanford, SPFA : O(VE)
// Dijkstra : O(ElogE)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int total_cost2 = 0;
struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost; // added
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
    // delivery fee: 1,000/1 book
    //    Ai x N x 1,000(cost)
    //    100 x 100 x 1000
    //    10,000,000
    int inf = 10'000'000;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
    };
    void add_edge(int u, int v, int cap, int cost) {
        Edge *ori = new Edge(v,cap,cost); // cost added
        Edge *rev = new Edge(u,0,-cost); // cost added
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap, int cost) {
        add_edge(source, v, cap, cost); // cost added
    }
    void add_edge_to_sink(int u, int cap, int cost) {
        add_edge(u, sink, cap, cost); // cost added
    }
    bool spfa(int &total_flow, int &total_cost) {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), inf); // distance : inf (init)
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            check[x] = false;
            for (int i=0; i<graph[x].size(); i++) {
                auto e = graph[x][i]; //edge
                int y = e->to;
                // if cost is less ? Let's go!
                // path is created according to lower cost
                if (e->capacity > 0 && distance[x] + e->cost < distance[y]) {
                    distance[y] = distance[x] + e->cost;
                    from[y] = make_pair(x,i);
                    // if not visited ? Let' put
                    if (!check[y]) {
                        check[y] = true;
                        q.push(y);
                    }
                }
            }
        }
        if (distance[sink] == inf) { // there is no way to go to sink
            return false;
        }
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        // until source,
        // find min capacity
        while (from[x].first != -1) {
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first != -1) {
            Edge *e = graph[from[x].first][from[x].second];
            e->capacity -= c; // update capacity
            e->rev->capacity += c;
            x = from[x].first;
            //total_cost2 += e->cost * c;
        }
        total_flow += c; // total flow
        total_cost += c*distance[sink]; // total cost
        //total_cost2 += c*(e->cost);
        //printf("total_cost: %d, total_cost2: %d\n", total_cost, total_cost2);
        return true;
    }
    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        while (spfa(total_flow, total_cost)); // until flow cannot be done
        return make_pair(total_flow, total_cost);
    }
};
int main() {
    int n,m;
    cin >> n >> m;
    // n : bookstore
    // m : people
    MCMF mcmf(n+m+2, n+m, n+m+1);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        mcmf.add_edge_to_sink(m+i,x,0); // people --(x)--> sink
    }
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        mcmf.add_edge_from_source(i,x,0); // source --(x)--> store
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            mcmf.add_edge(i,j+m,100,x); // delivery cost : x, cap: 100(max) 
        }
    }
    auto ans = mcmf.flow(); // [total_flow, total_cost]
    cout << ans.second << '\n'; // total_cost
    return 0;
}



