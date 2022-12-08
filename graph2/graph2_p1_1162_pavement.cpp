#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.

# my idea
# 1 -> N dijkstra : O(nLgn)
#   K ea can be correctted
#   choose K in N O(nCk)
#   = O(nLgn * nCk)
# DP : d[i][k] = shortest dist when k ea is corrected in i point

# pavement -> weight:0
# u -> v : pavement (O, X), k num limitation
# => num of pavement should be included in virtex definition
# (v, t) : num of pavement = t, when visit virtex v
# (u, t) -> (v, t)   : pavement X
#        -> (v, t+1) : pavement O (t<k)
#endif

#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[10001];
long long dist[10001][21]; //1<=N<=10000, 1<=M<=50000, 1<=K<=20
bool check[10001][21];
long long inf = 1'000'000'000LL*50'000LL;
int main() {
    int n,m,k;
    scanf("%d %d %d", &n,&m,&k);
    for (int i=0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d", &x,&y,&z);
        a[x].push_back(Edge(y,z)); //to,cost in each vertex
        a[y].push_back(Edge(x,z));
    }
    for (int i=1; i<=n; i++) { // 1~n
        for (int j=0; j<=k; j++) { // 0,1~k
            dist[i][j] = inf;
        }
    }
    // dist[n][k] : shortest path in n point with k ea pavement
    dist[1][0] = 0; 
    priority_queue<tuple<long long,int,int>> q;
    q.push(make_tuple(0,1,0));
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int x = get<1>(p);
        int step = get<2>(p);
        if (check[x][step]) { // already visited
            continue;
        }
        check[x][step] = true; // visit
        // about points connected a[x]
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i].to;
            // in case of pavement (O)
            if (step+1 <= k && dist[y][step+1] > dist[x][step]) {
                dist[y][step+1] = dist[x][step];
                q.push(make_tuple(-dist[y][step+1], y, step+1));
            }
            // in case of pavement (X)
            if (dist[y][step] > dist[x][step] + a[x][i].cost) {
                dist[y][step] = dist[x][step] + a[x][i].cost;
                q.push(make_tuple(-dist[y][step], y, step));
            }
        }
    }
    long long ans = inf;
    for (int i=1; i<=k; i++) {
        if (check[n][i] && ans > dist[n][i]) { // about visited points
            ans = dist[n][i];
        }
    }
    printf("%lld\n", ans);
}