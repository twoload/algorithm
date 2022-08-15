/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/2252
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAX = 32001;

int n, m;
vector<int> a[MAX];
int ind[MAX];

void topology_sort()
{
    queue<int> q;
    for(int i=1; i<=n; ++i){
        if (ind[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            ind[y] -= 1;
            if (ind[y] == 0)
                q.push(y);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; ++i){
        int u, v;
        scanf("%d %d", &u, &v); // u->v
        a[u].push_back(v);
        ind[v]++;
    }
    topology_sort();
    return 0;
}