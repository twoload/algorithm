#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// way 1: from the outside, fill
// way 2: 1xk, kx1 fill

// teacher
// 1<=n,m<=10

// | | ------
// | | 
// connect...

// row i-1 : pstate  
// row i   : state
// 0 : horizontal (-)
// 1 : vertical (|)

// d[i][state] : minimum num of tile at row i'state
// d[i][state] = d[i-1][pstate] + num of additional tile
//             = row 1~i-1 all filled (*)
//               because we need to fill all

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
// 0 : -, 1: |
int d[11][1<<10]; // 1<=n,m<=10
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    memset(d,-1,sizeof(d));
    d[0][0] = 0; // row 0, state 0(------), num of tile = 0
    for (int i=1; i<=n; i++) {
        for (int prev=0; prev<(1<<m); prev++) {
            if (d[i-1][prev] == -1) continue; // i-1 == 0, prev != 0
            for (int cur=0; cur<(1<<m); cur++) {
                int cnt = 0;
                int last = -100;
                // 0 : -, 1: |
                for (int k=0; k<m; k++) {
                    if (a[i][k] == '#') { // pole
                        continue;
                    }
                    if (cur & (1<<k)) { // 1 = |
                        if (i-1 == 0) cnt++; // first (new)
                        else if ((prev & (1<<k)) == 0) cnt++; // prev 0(---) (renew)
                        else if (a[i-1][k] == '#') cnt++; // pole (renew)
                    } else { // 0 = ---
                        if (last+1 != k) { // ---(last) k
                            cnt++;
                        }
                        last = k;
                    }
                }
                if (d[i][cur] == -1 || d[i][cur] > d[i-1][prev]+cnt) {
                    d[i][cur] = d[i-1][prev]+cnt;
                }
            }
        }
    }
    int ans = -1;
    for (int i=0; i<(1<<m); i++) {
        if (d[n][i] == -1) continue;
        if (ans == -1 || ans > d[n][i]) { // minimum num of tile at row n (at last row)
            ans = d[n][i];
        }
    }
    cout << ans << '\n';
    return 0;
}