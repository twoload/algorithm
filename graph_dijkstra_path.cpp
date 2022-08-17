/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/11779
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
constexpr int MAX = 1001;
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
int from[MAX];

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i=0; i<m; ++i){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(Edge(y,z)); 
    }
    int start, end;
    scanf("%d %d", &start, &end);
    
    for(int i=1; i<=n; ++i)
        dist[i] = inf;
    

    dist[start] = 0;
    from[start] = -1; // init!!!
    for(int k=0; k<n-1; k++){  // total: v-1
        int m = inf + 1;
        int x = -1;
        for(int i=1; i<=n; i++){
            if (check[i] == false && m > dist[i]){ // when dist[i] is the lowest,  
                m = dist[i]; // update m into the lowest value.
                x = i; // update the index at the lowest point
            }
        }
        check[x] = true;
        for(int i=0; i<a[x].size(); i++){ // all vertexs connected to x
            int y = a[x][i].to;
            if (dist[y] > dist[x] + a[x][i].cost){
                dist[y] = dist[x] + a[x][i].cost;
                from[y] = x; // x -> y : path update!!! 
            }
        }
    }  
    printf("%d\n", dist[end]);
    
    // find path
    stack<int> st;
    int x = end;
    while (x != -1){
        st.push(x);
        x = from[x];
    } 
    printf("%d\n", st.size());
    while (!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}