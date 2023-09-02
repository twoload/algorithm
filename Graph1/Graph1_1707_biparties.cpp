#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// cycle o, x ?

// teacher
// group1, 2
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> a[20001];
int color[20001];
void dfs(int node, int c) {
    color[node] = c;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            dfs(next, 3-c);
        }
    }
}

int main()
{
    int t;
    scanf("%d\n",&t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=1; i<=n; i++) {
            a[i].clear();
            color[i] = 0;
        }
        for (int i=0; i<m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i=1; i<=n; i++) {
            if (color[i] == 0) {
                dfs(i, 1);
            }
        }
        bool ok = true;
        for (int i=1; i<=n; i++) {
            for (int k=0; k<a[i].size(); k++) {
                int j = a[i][k];
                if (color[i] == color[j]) {
                    ok = false;
                }
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}