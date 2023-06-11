#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// step1. how to put numbers over 0

// step2. make the biggest one is the minimum of candidates

/**
 * ()() 12
 * ()() 4
 * 6 10
 * 
 * source --(12)--> 1row -> 1col --(6)--> sink
 * ...
 * 
 */
// okay. i got it.

/**
 *   () ()<-() <--(12)--source
 *  / <----- 
 *  | () ()<-() <--(4 )--source
 *  | /<----- 
 *  | | |
 *   \ /
 *   sink
 */

// teacher : binary search!!!
// the maximum number limitation
// element
// -> vertex's capacity

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<int> check;
    vector<pair<int,int>> from;
    int step;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
    }
    int bfs() {
        queue<int> q;
        q.push(source);
        check[source] = step;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                if (graph[x][i]->capacity > 0 && check[graph[x][i]->to] != step) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = step;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if (check[sink] != step) {
            return 0;
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
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            step += 1;
            int f = bfs();
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};
// row major number : x*n+y
// Xin 
int in_node(int x, int y, int n) {
    return (x*n+y)*2;
}
// Xout
int out_node(int x, int y, int n) {
    return in_node(x,y,n)+1;
}
// row N개 2*N*N ~ 2*N*N + N-1      : sum of row
int row_node(int x, int n) {
    return 2*n*n + x;
}
// col N개 2*N*N + N ~ 2*N*N + 2N-1 : sum of col    
int col_node(int y, int n) {
    return row_node(y, n) + n;
}
int inf = 100000;
vector<vector<int>> make_board(int n, MaximumFlow &mf) {
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x = in_node(i, j, n); //Xin
            int y = out_node(i, j, n);//Xout
            for (auto &e : mf.graph[x]) { // mf.grph[Xin]
                if (e->to == y) {
                    ans[i][j] = e->rev->capacity; // because cap is changed after flow
                }
            }
        }
    }
    return ans;
}
pair<bool,vector<vector<int>>> check(int k, vector<int> &row, vector<int> &col) {
    int n = row.size();
    // 숫자판 N*N*2개 = 0 ~ 2*N*N-1      : vertex capacity => N*N*2(in,out)
    // row N개 2*N*N ~ 2*N*N + N-1      : sum of row
    // col N개 2*N*N + N ~ 2*N*N + 2N-1 : sum of col
    // source: 2*N*N + 2N
    // sink = 2*N*N + 2N+1
    MaximumFlow mf(2*n*n+2*n+2, 2*n*n+2*n, 2*n*n+2*n+1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // Vin --(k)--> Vout
            mf.add_edge(in_node(i,j,n),out_node(i,j,n),k);
        }
    }

/**
 *    () ()<-(row node) <--(12)--source
 *  / <----- 
 *  | () ()<-(row node) <--(4 )--source
 *  | /<-----
 *  | (col node) (col node)
 *  | | |
 *   \ /
 *   sink
 */

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // row_node --(inf)--> Vin
            mf.add_edge(row_node(i,n), in_node(i,j,n), inf); // k or inf
            // Vout --(inf)--> col_node
            mf.add_edge(out_node(i,j,n), col_node(j,n), inf);
        }
    }
    for (int i=0; i<n; i++) {
        // source --(row[i])--> row_node
        mf.add_edge_from_source(row_node(i,n), row[i]);
    }
    for (int j=0; j<n; j++) {
        // col_node --(col[i])--> sink
        mf.add_edge_to_sink(col_node(j,n), col[j]);
    }
    int total = accumulate(row.begin(), row.end(), 0); // total = sum of row_sum
    int ans = mf.flow();
    if (ans == total) { // total == maximum flow
        return make_pair(true, make_board(n, mf));
    } else {
        return make_pair(false, vector<vector<int>>());
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> row(n), col(n);
    for (int i=0; i<n; i++) {
        cin >> row[i]; // sum of row
    }
    for (int i=0; i<n; i++) {
        cin >> col[i]; // sum of col
    }
    int ans = 10000; // 0<= ans <= 10000
    int l = 0;
    int r = 10000;
    vector<vector<int>> board;
    // binary search
    while (l <= r) {
        int mid = (l+r)/2;
        auto p = check(mid, row, col);
        if (p.first) { // true/false
            r = mid-1;
            if (ans > mid) { // if mid is less than ans, update it
                ans = mid;
                board = p.second; // board
            }
        } else {
            l = mid+1;
        }
    }
    cout << ans << '\n';
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}


