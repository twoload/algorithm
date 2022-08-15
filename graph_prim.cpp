/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/1922
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAX = 1001;

int n, m;
struct Edge{
    int to;
    int cost;
    bool operator< (const Edge& other) const{
        return cost > other.cost;
    }
};
vector<Edge> a[MAX];
bool c[MAX];

int main()
{
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; ++i){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c); 
        a[u].push_back(Edge({v,c}));
        a[v].push_back(Edge({u,c}));
    }
    c[1] = true; // add 1 into MST randomly
    priority_queue<Edge> q;
    for(Edge e : a[1]) // add all edges connected to 1
        q.push(e);
    
    int ans = 0;
    while (!q.empty()){
        Edge e = q.top();
        q.pop();
        if (c[e.to] == true) // ignore if it is already chosen
            continue;
        c[e.to] = true;
        ans += e.cost; // MST cost
        int x = e.to;
        for (Edge ee : a[x]){
            q.push(ee);
        }
    }
    printf("%d\n", ans);
    return 0;
}