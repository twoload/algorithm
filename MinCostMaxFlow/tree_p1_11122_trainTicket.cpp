#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// teacher

/**       ------ S ----\
 *       /       |      \
 *      /        |       \
 *    1->4      2->4 --------\   
 *     1->3       2->3     3->4
 *      1->2     /    \    /   \
 *     /    \   /      \  /     \
 *    1--()--> 2 --()--> 3 --()-->4
 *      \       \       /       /
 *       \------- T ------------
 */


#if 0

1      T:1
3 4    N:3, P:4
6 7    Cij (0->1) (0->2)
3      Cij (1->2)
4 1    Dij (0->1) (0->2)
1      Dij (1->2)
2 1    Oij (0->1) (0->2)
0      Oij (1->2)


#endif

#include <iostream>
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
// same as 11410 problem
int ticket(int x, int y, int n) {
    return n + (n-1)*n/2 - (n-x-1)*(n-x)/2 + (y-x-1);
}
int a[100][100];
int b[100][100];
int o[100][100];
int arrived[100];
int officer[100];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
#if 0
        1      T:1
3 4    N:3, P:4
6 7    Cij (0->1) (0->2)
3      Cij (1->2)
4 1    Dij (0->1) (0->2)
1      Dij (1->2)
2 1    Oij (0->1) (0->2)
0      Oij (1->2)
#endif
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                cin >> b[i][j];
            }
        }
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i=0; i<n; i++) officer[i] = 0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                cin >> o[i][j]; // add
                for (int k=i; k<j; k++) {
                    officer[k] += o[i][j]; // officer should board
                }
            }
        }
        int total = n + (n-1)*n/2 + 2;
        MCMF mcmf(total, total-2, total-1);
        for (int i=0; i<n-1; i++) {
            mcmf.add_edge(i, i+1, p-officer[i], 0); // diff
        }
        for (int i=0; i<n; i++) arrived[i] = 0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                mcmf.add_edge_from_source(ticket(i,j,n),a[i][j],0);
                mcmf.add_edge(ticket(i,j,n),i,a[i][j],-b[i][j]);
                mcmf.add_edge(ticket(i,j,n),j,a[i][j],0);
                arrived[j] += a[i][j];
            }
        }
        for (int i=1; i<n; i++) {
            mcmf.add_edge_to_sink(i, arrived[i], 0);
        }
        cout << -mcmf.flow().second << '\n';
    }
    return 0;
}
