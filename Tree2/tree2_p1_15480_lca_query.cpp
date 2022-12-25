/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100111;
vector<int> a[MAX]; // graph = tree
int d[MAX];
int p[MAX][18];
int tin[MAX];
int tout[MAX];
int timer;
int l;
void dfs(int v, int parent) {
    tin[v] = ++timer; // in order
    p[v][0] = parent;
    for (int i=1; i<=l; i++) {
        p[v][i] = p[p[v][i-1]][i-1]; // DP
    }
    for (int to : a[v]) {
        if (to != parent) {
            d[to] = d[v] + 1;
            dfs(to,v);
        }
    }
    tout[v] = ++timer;
}
bool upper(int u, int v) {
    // first in, last out -> upper
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int lca(int u, int v) {
    if (upper(u, v)) return u;
    if (upper(v, u)) return v;
    for (int i=l; i>=0; i--) {
        if (!upper(p[u][i], v)) {
            u = p[u][i];
        }
    }
    return p[u][0];
}
int dist(int u, int v) { //dist
    int x = lca(u, v);
    return d[u] + d[v] - 2*d[x];
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    // find height
    // 1--2--3--4--5
    // > l = 3-1 = 2
    // 1--2--3--4
    // > l = 3-1 = 2
    // 1--2--3
    // > l = 2-1 = 1
    for (l=1; (1<<l) <= n; l++); 
    l-=1;
    dfs(1,1);
    int m;
    scanf("%d", &m);
    while (m--) {
        int r, u, v;
        scanf("%d %d %d", &r, &u, &v);
        vector<pair<int,int>> t(6);
        t[0].second = r;
        t[1].second = u;
        t[2].second = v;
        t[3].second = lca(r,u);
        t[4].second = lca(r,v);
        t[5].second = lca(u,v);
        for (int i=0; i<6; i++) {
            int x = t[i].second;
            t[i].first = dist(x,r) + dist(x,u) + dist(x,v);
        }
        sort(t.begin(), t.end()); // sort by dist
        printf("%d\n", t[0].second);
    }
    return 0;
}