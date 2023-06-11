#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif


//teacher
// tofu: white - Black


// s -> W -> B -> t


// MCMF : Min Cost Max Flow => find Min Cost among Max Flow

// This problem doesn't require Max Flow.
// So Find Min Cost among Flow (not Max Flow)


// Max Value -> Cost x -1
// s->t : cost > 0 => answer can be small
// so, s->t : if cost > 0, break!!! we can find min cost.
// then x -1 => we can get MAX

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
    // N x M x Cost=10 = 25000 = inf
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
        // *****************************
        // if distance[] > 0, just break!!! so that we can get MAX
        if (distance[sink] > 0) { // added!!!
            return false;
        }
        // *****************************
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
int price_matrix[6][6] = {
    {10,8,7,5,0,1},
    {8,6,4,3,0,1},
    {7,4,3,2,0,1},
    {5,3,2,2,0,1},
    {0,0,0,0,0,0},
    {1,1,1,1,0,0}
};
// direction
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int price(char x, char y) {
    return price_matrix[x-'A'][y-'A']; // index
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    auto node = [&](int x, int y) {
        return x*m+y; // x: row, y: col => node order
    };
    // node num: n*m
    MCMF mcmf(n*m+2, n*m, n*m+1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // s -> w -> b -> t
            if ((i+j)%2 == 0) { // white
                for (int k=0; k<4; k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        mcmf.add_edge(node(i,j),node(x,y),1,-price(a[i][j],a[x][y]));
                        // (i,j) - (x,y)
                    }
                }
                mcmf.add_edge_from_source(node(i,j),1,0); // cap:1, cost:0
            } else { // black 
                mcmf.add_edge_to_sink(node(i,j),1,0); // cap:1, cost:0
            }
        }
    }
    cout << -mcmf.flow().second << '\n';
    return 0;
}
