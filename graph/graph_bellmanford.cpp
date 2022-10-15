/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/11657
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAX = 501;
constexpr int inf = 987654321;

int n, m;
struct Edge{
    int from; // created!!!
    int to;
    int cost;
    bool operator< (const Edge& other) const{
        return cost < other.cost; // Be careful!!! > : NG, < : OK
    }
};
int dist[MAX];

int main()
{
    scanf("%d %d", &n, &m);
    
    vector<Edge> a(m); // resize
    for (int i=0; i<m; ++i){
        scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost); 
    }
    
    for(int i=1; i<=n; ++i)
        dist[i] = inf;

    dist[1] = 0;
    bool negative_cycle = false;
    for(int i=1; i<=n; i++){  // repetition cycle: n-1 > n
        for(int j=0; j<m; j++){ // edges
            int x = a[j].from; // x -(z)-> y
            int y = a[j].to;
            int z = a[j].cost;
            if (dist[x] != inf && dist[y] > dist[x] + z){ // 1번 도시에서 다른 번호 도시로 가는 최소값 찾는다. 
                dist[y] = dist[x] + z;
                if (i == n)
                    negative_cycle = true;
            }
        }
    }  
    if (negative_cycle){  
        printf("%d\n", -1);
    }
    else{
        for (int i=2; i<=n; i++){
            if (dist[i] == inf) dist[i] = -1;
            printf("%d\n", dist[i]);
        }
    }
    return 0;
}