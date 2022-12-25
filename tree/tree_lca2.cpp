/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/11438
 */

#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> a[MAX]; 
int parent[MAX];
bool check[MAX];
int depth[MAX];
int p[MAX][17]; // added 
// p[i][j] = node i's 2^j's ancestor
// p[i][0] = node i's 2^0(=1)'s ancestor = parent

int lca(int u, int v) {
    if (depth[u] < depth[v]) { // assume u is deeper
        swap(u, v);
    } 
    int log = 1;
    // root(1)'s depth = 0
    // if u's depth == 4, 0-1-2-3-4, log = 3-1 = 2 (O)
    //    because log becomes 3 by log++ when exiting for loop
    //            need to minus 1
    for (log = 1; (1<<log) <= depth[u]; log++); // max height
    log-=1;
    for (int i=log; i>=0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) { // not to over v's depth
            u = p[u][i]; // by already found p[u][i]
        }
    }
    if (u == v) { // if v is parent of u, exit
        return u;
    } else {
        for (int i=log; i>=0; i--) {
            // p[u][i] == 0 > no ancestor
            if (p[u][i] != 0 && p[u][i] != p[v][i]) { // until no same
                u = p[u][i];
                v = p[v][i];
            }
        }
        return parent[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++){
        int u, v; 
        cin >> u >> v;
        a[u].push_back(v); // tree
        a[v].push_back(u);
    }
    depth[1] = 0; //root is 1
    check[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) { // BFS
        int x = q.front();
        q.pop();
        for (int y : a[x]) {
            if (!check[y]) {
                depth[y] = depth[x] + 1; // depth
                check[y] = true;
                parent[y] = x; // parent
                q.push(y);
            }
        }
    }
    // init
    for (int i=1; i<=n; i++) {
        p[i][0] = parent[i]; // node i's 2^0(=1) ancestor = parent 
    }
    // 1--2--3--4--5
    // > j = 1~2 
    // > p[1][1] = p[p[1][0]][0] = 0 (p[1][0]=0)
    // > p[2][1] = p[p[2][0]][0] = 0 (p[2][0]=1)
    // ...
    // > p[5][1] = p[p[5][0]][0] = 3 (p[5][0]=4)
    // > p[1][2] = 0
    // ...
    // > p[5][2] = 1
    // 1--2--3--4
    // > j = 1
    // > p[1][1] = 0
    // > p[2][1] = 0
    // > p[3][1] = 1
    // > p[4][1] = 2
    // why (1<<j) < n ? <=> (1<<j) <= n-1
    //     because it includes start point 1
    //     because to jump from 1, calculation is needed except start point
    //     ex. 1-2-3-4-5 : 1->3->5 (2) : (5-1)>>2 (O)
    //     ex. 1-2-3-4   : 1->3 (1) : (4-1)>>2 (x), (4-1)>>1 (O)  
    for (int j=1; (1<<j) < n; j++) { // it's ok even if (1<<j) <= n because it will be 0
        for (int i=1; i<=n; i++) { // 1~n
            // it is to prevent meaningless work
            // even if removing 'p[i][j-1] != 0', it is ok
            // because if p[i][j-1] == 0, p[i][j] = 0
            if (p[i][j-1] != 0) { //until root 1, parent[1] = 0
                p[i][j] = p[p[i][j-1]][j-1]; // 2^i = 2^(i-1) + 2^(i-1) = 2^(i-1)'s ancestor's 2^(i-1)'s ancestor
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }    
    return 0;
}