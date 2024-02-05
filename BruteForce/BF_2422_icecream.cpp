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

// 200*200*200*(200*200*200)
vector<vector<int>> a(201, vector<int>());


int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            bool ok = true;
            for (int aa=0; aa<a[i].size(); aa++) {
                if (a[i][aa] == j) {
                    ok = false;
                    break;
                }
            }
            if (ok == false) continue;
            //printf("%d %d \n", i, j);

            for (int k=j+1; k<=n; k++) {
                bool ok = true;
                for (int aa=0; aa<a[i].size(); aa++) {
                    if (a[i][aa] == k) {
                        ok = false;
                        break;
                    }
                }   
                if (ok == false) continue;
                //printf("%d %d %d\n", i, j, k);
                for (int bb=0; bb<a[j].size(); bb++) {
                    if (a[j][bb] == k) {
                        ok = false;
                        break;
                    }
                }   
                if (ok == false) continue;
                //printf("%d %d %d\n", i, j, k);
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}