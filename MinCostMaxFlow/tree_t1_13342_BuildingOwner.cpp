#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif


// 0, 1, .... N-1 (Building number)
// C : num of Car
// M : need to get money from M buildings
// Ai : order to get money
//      A0->A1->A2->...AM-1
// Start Point : 0

// W : walk  (W x len of road)
// D : drive (D x len of road)

// min time to get all money

// N area = vertex
// bi-directional road = Edge

// N=4, C=1, M=3, W=5, D=1
// Car=[1]
// A=[2,3,0]

/**
 *   0           1
 *     \(1)     /(2)
 *      --------
 *     /        \
 *   3 ---(3)--- 2
 * 
 *  0->2: W
 *  2->3: W
 *  3->1: W
 *  Car ride
 *  -> 0: D
 * 
 *  5*1 + 5*3 + 5*2 + 1*2 + 1*3 + 1*1 = 36
 */

// each road should be moved by max one car
// one car should use max one road

// 1) Ai -> Ai+1 : W
// 2) if we drive, Ai->Car : W , Car->Ai+1: D

// MCMF
//  C: time
//  F: count

/**
 * s  -> ( 0->A0)              W        --(cap:inf,cost:0)--> t
 *    -> (A1->A2)              1th Car  --(cap:1,cost:0)---->
 *    -> ...                   ...
 *    -> (AM-2->AM-1)          Cth Car
 * 
 *    cap:1        cap:1
 *    cost:0       cost: 0->A0 time (W)
 *                 cost: 0->Car1(W) + 1->A0(D)
 */   

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
const int inf = 1000000;
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

int main() {
    int n, c, m, walk, drive;
    cin >> n >> c >> m >> walk >> drive;
    vector<int> car(c);
    for (int i=0; i<c; i++) {
        cin >> car[i]; // Car Position
    }
    vector<int> a(m);
    for (int i=0; i<m; i++) {
        cin >> a[i]; // order to get money
    }
    vector<vector<int>> d(n, vector<int>(n)); // road info
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> d[i][j];
            if (d[i][j] == 0) {
                d[i][j] = inf; // can't go
            }
        }
        d[i][i] = 0;
    }
    for (int k=0; k<n; k++) { // min road : Floyd
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    // i (0 ≤ i < m): ai-1 -> ai
    // m: walk
    // m+j+1 (0 ≤ j < c): car_j
    // m+c+1: source
    // m+c+2: sink
    MCMF mcmf(m+c+3, m+c+1, m+c+2);
    for (int i=0; i<m; i++) {
        // s -> (ai-1 -> ai)
        mcmf.add_edge_from_source(i, 1, 0);
        //1) Walk
        // (ai-1 -> ai) -> walk // 0->a0 at first, a0->a1 next
        int from = i == 0 ? 0 : a[i-1]; // Gango is in 0 at first.
        int to = a[i];
        mcmf.add_edge(i, m, 1, walk*d[from][to]); // min cost = d[from][to]
        //2) Drive(Car)
        // (ai-1 -> ai) -> car_j
        for (int j=0; j<c; j++) { //1-th car, 2-nd car, ... , n-th car
            mcmf.add_edge(i, m+j+1, 1, walk*d[from][car[j]] + drive*d[car[j]][to]);
        }
    }
    mcmf.add_edge_to_sink(m, inf, 0);
    for (int j=0; j<c; j++) {
        mcmf.add_edge_to_sink(m+j+1, 1, 0);
    }
    cout << mcmf.flow().second << '\n';
    return 0;
}
