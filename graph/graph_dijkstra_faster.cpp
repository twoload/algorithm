/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/1753
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAX = 20001;
constexpr int inf = 987654321;

int n, m;
struct Edge{
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<Edge> a[MAX];
int dist[MAX];
bool check[MAX];

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    int start;
    scanf("%d", &start);
    
    for (int i=0; i<m; ++i){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(Edge(y,z)); 
    }
    
    for(int i=1; i<=n; ++i)
        dist[i] = inf;

    dist[start] = 0;
    priority_queue<pair<int,int>> q; // (dist, vertex)
    q.push(make_pair(0, start));
    while (!q.empty()){
        auto p = q.top();
        q.pop();
        int x = p.second;

        if (check[x]) // if already checked, skip
            continue;
        
        check[x] = true;
        for(int i=0; i<a[x].size(); i++){ // all vertexs connected to x
            int y = a[x][i].to;
            if (dist[y] > dist[x] + a[x][i].cost){
                dist[y] = dist[x] + a[x][i].cost;
                q.push(make_pair(-dist[y], y));
            }
        }
    }  
    for(int i=1; i<=n; i++){
        if (dist[i] == inf)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    return 0;
}