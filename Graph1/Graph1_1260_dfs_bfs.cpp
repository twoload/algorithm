#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
    //if (check[node]) return; 
    check[node] = true;
    printf("%d ", node);
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    memset(check,false,sizeof(check));
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (int i=0; i<a[cur].size(); i++) {
            int next = a[cur][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }    
    }
}

int main() {
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for (int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        sort(a[i].begin(), a[i].end()); // *important*
    }
    memset(check, 0, sizeof(check));
    dfs(start);
    //printf("\n");
    puts("");
    memset(check, 0, sizeof(check));
    bfs(start);
    puts("");
    //printf("\n");
    return 0;
}