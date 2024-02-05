#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int dist[1000001];
bool check[1000001];
int main() {
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    queue<int> q;
    q.push(s);
    check[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now+u <= f && check[now+u]==false) {
            check[now+u] = true;
            q.push(now+u);
            dist[now+u] = 1 + dist[now];
        }
        if (now-d >= 1 && check[now-d]==false) {
            check[now-d] = true;
            q.push(now-d);
            dist[now-d] = 1 + dist[now];
        }
    }
    if (check[g]== false) {
        cout << "use the stairs" << '\n';
    } else {
        cout << dist[g] << '\n';
    }
    return 0;
}