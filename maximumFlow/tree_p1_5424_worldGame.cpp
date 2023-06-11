#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

//         A vs B
// A win : 2    0  = 2
//       : 1    1  = 2
// A lose: 0    2  = 2

                
// --(2)--> (game) --(2)--> A
//                \
//                 --(2)--> B

// A win ?
// 1. A should win in all the remaining games
// 2. Remaining people should not gain score over A in all the remaining games

/**
 *          remaining game
 *     /--(2)--> A --------(2)---------> 1 -->(15)--> t 
 *    /            \-------(2)---------> 2 -->(25)--> t      
 *   / ---(2)--> B --------(2)---------> 1 
 *  s              \-------(2)---------> 3 -->(30)--> t
 *   ...
 * 
 */ 

// can 0 win?
// 0 : 75
// 1:  60
// 2:  50
// 3:  45

// max-flow : sum of remaining win scoress


#include <iostream>
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
vector<int> calculate_score(vector<string> &a) {
    int n = a.size();
    vector<int> score(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j] == '1') {  // win
                score[i] += 2;
            } else if (a[i][j] == '0') { // lose
                score[j] += 2;
            } else if (a[i][j] == 'd') { // tie
                score[i] += 1;
                score[j] += 1;
            }
        }
    }
    return score;
}
// game (between player x1 and player y1)
// game (between player x1 and player y2)
// ...
// game (between player x and player y)
// x*n + y
int game(int x, int y, int n) {
    return x*n+y;
}
// player 1,2,3,4,...  order after game
// n*n + x
int player(int x, int n) {
    return n*n+x;
}
// who: a person to win
// a: board info
bool can_win(int who, vector<string> a) {
    int n = a.size();
    for (int i=0; i<n; i++) { // winner should win all the remaining games
        if (a[who][i] == '.') {
            a[who][i] = '1'; // win
            a[i][who] = '0'; // lose of counterpart
        }
    }
    vector<int> score = calculate_score(a);
    for (int i=0; i<n; i++) {
        if (i == who) { // ignore to self
            continue;
        }
        // who expected score should be over
        // if not, return false
        if (score[i] > score[who]) { 
            return false;
        }
    }
    int points = 0;
    // source: n*n + n
    // sink:   n*n + n + 1
    // n     : n*n(game) + n(player)
    //       : n*n       + n        + 2(source + sink) 
    MaximumFlow mf(n*n+n+2, n*n+n, n*n+n+1);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j] == '.') { // didn't play yet
                // source --(2)--> game (between player i and player j)
                mf.add_edge_from_source(game(i,j,n), 2);
                // game[player i and player j] --(2)--> player i
                mf.add_edge(game(i,j,n), player(i,n), 2);
                // game[player i and player j] --(2)--> player j
                mf.add_edge(game(i,j,n), player(j,n), 2);
                // all remaining points : accumulate
                points += 2;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (who == i) {
            continue;
        }
        // player --()--> score
        mf.add_edge_to_sink(player(i,n), score[who] - score[i]);
    }
    int ans = mf.flow(); // max flow
    if (ans < points) {
        return false;
    } else { // all distribution is possible
        return true;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            if (can_win(i, a)) {
                cout << i+1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
