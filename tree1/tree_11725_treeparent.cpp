/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/1761
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define left _left
#define right _right
using namespace std;
// exist -> parent
// no -> child

//struct Node {
//    int child;
//};
//Node a[100001];
const int MAX = 100111;
vector<int> a[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int dist[MAX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    depth[1] = 0;
    check[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : a[x]) {
            if (!check[y]) {
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for (int i=2; i<=n; i++) {
        printf("%d\n", parent[i]);
    }
    return 0;
}