#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[101] = {0,};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n+m; i++) {
        int u, v;
        cin >> u >> v;
        a[u] = v;
    }
    vector<int> dist(101, 0);
    for (int i=1; i<=100; i++) {
        dist[i] = 100;
    }
    dist[1] = 0;
    queue<int> q;
    //for (int i=1; i<=6; i++) {
    //    q.push(i);
    //}
    q.push(1); //starting with 1
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (a[cur] != 0) {
            int next = a[cur];
            if (dist[next] > dist[cur]) {
                dist[next] = dist[cur];
                q.push(next);
            }
            continue; 
        }
        for (int i=1;i<=6;i++) {
            int next = cur+i;
            if (next <= 100) {
                if (dist[next] > dist[cur]+1) {
                    dist[next] = dist[cur]+1;
                    q.push(next);
                }
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}