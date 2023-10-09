#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define next _next

int next[101];
int dist[101];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=100;i++) {
        next[i] = i;
        dist[i] = -1;
    }
    while(n--) {
        int x,y;
        cin >> x >> y;
        next[x] = y;
    }
    while(m--) {
        int x,y;
        cin >> x >> y;
        next[x] = y;
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i=1; i<=6; i++) {
            int y = x+i;
            if (y>100) continue;
            y = next[y];
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}