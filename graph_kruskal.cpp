/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/1197
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAX = 10001;

int n, m;
struct Edge{
    int from; // created!!!
    int to;
    int cost;
    bool operator< (const Edge& other) const{
        return cost < other.cost; // Be careful!!! > : NG, < : OK
    }
};
int p[MAX];
int Find(int x)
{
    if (x == p[x]) // root if my parent is the same as mine.
        return x;
    else
        return p[x] = Find(p[x]); // update x's parent to reduce time 
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    p[y] = x; // make x into the parent of y : it is our own rule
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) // Union Find
        p[i] = i;
    
    vector<Edge> a(m); // resize
    for (int i=0; i<m; ++i){
        scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost); 
    }
    
    sort(a.begin(), a.end()); // vector<Edge> a :OK, vector<Edge> a[] : NG
    int ans = 0;
    for(int i=0; i<m; i++){
        Edge e = a[i];
        int x = Find(e.from);
        int y = Find(e.to);
        if (x != y){ // if each is in different area, merge
            Union(e.from, e.to);
            ans += e.cost;
        }
    }
    printf("%d\n", ans);
    return 0;
}