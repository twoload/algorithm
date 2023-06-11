#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif



// capacity
// source -(1)-> i -(1)-> ... -(1)-> sink

// cost
// source -(0)-> i -(c)-> ... -(0)-> sink


// teacher
// 1->N->1

// 1->N  <=> N->1
// (1->N) x 2
//  1) min
//  2) don't share edge

// 1->N (min distance) => dijkstra
// 1->N x2  => MCMF

// s--(2)--> 1 -- ... -- N --(2)--> t
//                cap=1
//               cost=weight


#include <iostream>
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
    typedef pair<int,int> Vertex;
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance;
    vector<int> potential;
    vector<pair<int,int>> from;
    int inf = 20000000;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
        potential.resize(n);
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
        for (int i=0; i<n; i++) {
            potential[i] = distance[i];
        }
        return true;
    }
    bool dijkstra(int &total_flow, int &total_cost) {
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> q;
        fill(distance.begin(), distance.end(), inf);
        fill(check.begin(), check.end(), false);
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0;
        q.push(make_pair(0, source));
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (check[x]) {
                continue;
            }
            check[x] = true;
            if (x == sink) {
                continue;
            }
            for (int i=0; i<graph[x].size(); i++) {
                auto e = graph[x][i];
                int y = e->to;
                if (e->capacity > 0 && distance[y] > distance[x] + e->cost - potential[y] + potential[x]) {
                    distance[y] = distance[x] + e->cost - potential[y] + potential[x];
                    from[y] = make_pair(x,i);
                    q.push(make_pair(distance[y],y));
                }
            }
        }
        if (distance[sink] == inf) {
            return false;
        }
        for (int i=0; i<n; i++) {
            if (distance[i] != inf) {
                potential[i] += distance[i];
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
        total_flow += c;
        return true;
    }
    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        spfa();
        while (dijkstra(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    MCMF mcmf(n+2,0,n+1);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        mcmf.add_edge(x,y,1,z);
        mcmf.add_edge(y,x,1,z);
    }
    mcmf.add_edge_from_source(1,2,0);
    mcmf.add_edge_to_sink(n,2,0);
    printf("%d\n",mcmf.flow().second);
    return 0;
}