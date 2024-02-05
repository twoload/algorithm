#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

bool a[4001][4001];
int num[4001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        a[u][v] = true;
        a[v][u] = true;
        num[u] += 1;
        num[v] += 1;
    }

    int ans = 987654321;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j]) {
                for (int k=j+1; k<n; k++) {
                    if (a[i][k] && a[j][k]) {
                        int ret = (num[i]+num[j]+num[k]-6);
                        if (ans > ret) {
                            ans = ret;
                        }
                    }
                }
            }
        }
    }
    if (ans == 987654321) {
        ans = -1;
    }
    cout << ans << '\n';
    return 0;
}