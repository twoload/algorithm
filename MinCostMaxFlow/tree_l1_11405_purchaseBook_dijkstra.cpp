#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif


#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost; // added
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    typedef pair<int,int> Vertex;
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance;  // added
    vector<int> potential; // added
    vector<pair<int,int>> from;
    int inf = 10'000'000;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n); // added
        potential.resize(n); // added
    };
    void add_edge(int u, int v, int cap, int cost) {
        Edge *ori = new Edge(v,cap,cost); // added
        Edge *rev = new Edge(u,0,-cost); // added
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap, int cost) {
        add_edge(source, v, cap, cost); // added
    }
    void add_edge_to_sink(int u, int cap, int cost) {
        add_edge(u, sink, cap, cost); // added
    }
    bool spfa() {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), inf);
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
                // if cost is less,
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
        // not to make minus
        for (int i=0; i<n; i++) {
            potential[i] = distance[i]; // distance from source (min distance)
        }
        return true;
    }
    bool dijkstra(int &total_flow, int &total_cost) {
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> q;
        fill(distance.begin(), distance.end(), inf);
        fill(check.begin(), check.end(), false);
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0;
        q.push(make_pair(0, source)); // from source : 0
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (check[x]) { // visited -> continue
                continue;
            }
            check[x] = true;
            if (x == sink) { // because it is destination,
                continue;
            }
            for (int i=0; i<graph[x].size(); i++) {
                auto e = graph[x][i];
                int y = e->to;
                // p[to] : d (source -> to)
                //
                // x -----(cost)-----> y
                // d[x]               d[y]
                // +p[x]              -p[y] 
                //
                // distance[y] > distance[x] + e->cost (- potential[y] + potential[x])
                //                                        min            min
                if (e->capacity > 0 && distance[y] > distance[x] + e->cost - potential[y] + potential[x]) {
                    distance[y] = distance[x] + e->cost - potential[y] + potential[x];
                    from[y] = make_pair(x,i);
                    q.push(make_pair(distance[y],y));
                }
            }
        }
        if (distance[sink] == inf) { // if we can't go to sink,
            return false;
        }
        // not to make minus number
        for (int i=0; i<n; i++) {
            if (distance[i] != inf) {
                potential[i] += distance[i]; // potential update
            }
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
            total_cost += e->cost * c;
            x = from[x].first;
        }
        total_flow += c; // total_flow
        return true;
    }
    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        spfa(); // one time
        while (dijkstra(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};
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
            int x;
            cin >> x;
            mcmf.add_edge(i,j+m,100,x);
        }
    }
    auto ans = mcmf.flow();
    cout << ans.second << '\n';
    return 0;
}