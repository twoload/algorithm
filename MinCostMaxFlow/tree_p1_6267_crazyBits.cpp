#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// 23
// 010 011
// <-----  (1)

// 62
// 110 010


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
vector<int> convert(int num) {
    vector<int> a;
    for (int i=0; i<12; i++) { // 12bit > vector
        a.push_back(num&1);
        num >>= 1;
    }
    return a;
}
int dist(pair<int,int> p1, pair<int,int> p2) { // |p1-p2|
    int x1 = p1.first, y1 = p1.second;
    int x2 = p2.first, y2 = p2.second;
    int t1 = x1-x2;
    int t2 = y1-y2;
    if (t1 < 0) t1 = -t1;
    if (t2 < 0) t2 = -t2;
    return t1+t2;
}
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int inf = 1000000;
int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        // 2 dimensional vector
        vector<vector<int>> a(n), b(n); // a:in --> b:out
        for (int i=0; i<n; i++) {
            int num;
            cin >> num;
            a[i] = convert(num);
        }
        for (int i=0; i<n; i++) {
            int num;
            cin >> num;
            b[i] = convert(num);
        }
        vector<pair<int,int>> one1, one2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<12; j++) {
                if (a[i][j] == 1) {
                    one1.emplace_back(i,j); // one1 [i,j]
                }
                if (b[i][j] == 1) {
                    one2.emplace_back(i,j); // one2 [i,j]
                }
            }
        }
        if (one1.size() != one2.size()) {
            cout << "Impossible\n";
            continue;
        }
        int m = one1.size();
        // one1: m
        // one2: m
        // source: 2*m
        // sink : 2*m+1
        MCMF mcmf(2*m+2, 2*m, 2*m+1);
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                // cap = 1
                // cost = dist(one1[i],one2[j])
                mcmf.add_edge(i,m+j,1,dist(one1[i],one2[j]));
            }
            // cap: 1
            mcmf.add_edge_from_source(i,1,0);
            mcmf.add_edge_to_sink(m+i,1,0);
        }
        cout << mcmf.flow().second << '\n';
    }
    return 0;
}