#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> a(101, vector<int>());
bool check[101];
int ans = 0;

void go(int start) {
    ans += 1;
    //cout << "start: " << start << '\n';
    check[start] = true;
    for (int next : a[start]) {
        if (check[next] == false) {
            check[next] = true;
            go(next);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    go(1);
    cout << ans -1 << '\n';
    return 0;
}