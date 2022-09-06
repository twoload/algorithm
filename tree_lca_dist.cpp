/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/1761
 */

#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 40001;
vector<pair<int,int>> a[MAX]; 
int parent[MAX];
bool check[MAX];
int depth[MAX];
int dist[MAX]; // dist

int lca(int u, int v) {
    if (depth[u] < depth[v]) { // assume u is deeper
        swap(u, v);
    }
    while (depth[u] != depth[v]) { // go up u until the same depth
        u = parent[u];
    }
    while (u != v) { // go up together
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++){
        int u, v, w; // w
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w)); // tree
        a[v].push_back(make_pair(u, w));
    }
    depth[1] = 0; //root is 1
    check[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) { // BFS
        int x = q.front();
        q.pop();
        for (auto &p : a[x]) {
            int y, cost;
            tie(y, cost) = p;
            if (!check[y]) {
                depth[y] = depth[x] + 1; // depth
                check[y] = true;
                dist[y] = dist[x] + cost;
                parent[y] = x; // parent
                q.push(y);
            }
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2*dist[lca(u, v)] << '\n'; // O(MN)
    }
    
    return 0;
}