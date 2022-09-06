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
int p[MAX][17]; // added
int tin[MAX]; // tin[i]: visiting number of i with dfs
int tout[MAX];// tout[i]: leaving number of i with dfs
int timer;
int l;

void dfs(int v, int parent) {
    tin[v] = ++timer; // added
    p[v][0] = parent;
    for (int i=1; i<=l; i++) // be careful: from 1, not from 0
        p[v][i] = p[p[v][i-1]][i-1]; // DP

    for (int to : a[v])
        if (to != parent)
            dfs(to, v);
        
    tout[v] = ++timer; // added
}

bool upper(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (upper(u, v)) return u; //exception handling
    if (upper(v, u)) return v; //exception handling
    //<- parent - child relation

    for( int i=l; i>=0; i--) {
        if (!upper(p[u][i], v)) { // p[u]'s 2^i ancestor
            u = p[u][i]; // the biggest point right before LCA 
        }
    }
    
    return p[u][0];
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
    for (l=1; (1<<l) <= n; l++);
    l-=1;
    dfs(1, 1);
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }    
    return 0;
}