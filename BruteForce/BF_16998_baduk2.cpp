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

int n,m;
// n*m*n*m*(n*m) = 20^6
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};    
int a[21][21];
bool check[21][21];
void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j] << "(" << check[i][j] << ")" << ' ';
        }
        cout << '\n';
    }
}
int go(int x, int y) {
    if (a[x][y] != 2) return 0;
    print();
    int ret = 1;
    bool ok = true;
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0<=nx && nx<n && 0<=ny && ny<m) {
            if (a[nx][ny] == 0) {
                ok = false;
                break;
            }
            if (a[nx][ny]==2) {
                if (check[nx][ny]) continue;
                check[nx][ny] = true;
                int tmp = 1 + go(nx,ny);
                ret = max(tmp, ret);
                //check[nx][ny] = false;
            }
        }
    }
    if (ok == false) {
        ret = 0;
    }
    return ret;
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int x1=0; x1<n; x1++) {
        for (int y1=0; y1<m; y1++) {
            if (a[x1][y1] == 1 || a[x1][y1]==2) continue;
            a[x1][y1] = 1;
            for (int x2=0; x2<n; x2++) {
                for (int y2=0; y2<m; y2++) {
                    if (a[x2][y2] == 1 || a[x2][y2] == 2) continue;
                    a[x2][y2] = 1;
                    print();
                    memset(check, false, sizeof(check));
                    int sum = 0;
                    for (int xx=0; xx<n; xx++) {
                        for (int yy=0; yy<m; yy++) {
                            if (check[xx][yy]) continue;
                            check[xx][yy] = true;
                            int ret = go(xx, yy);
                            sum += ret;
                            //check[xx][yy] = false;
                        }
                    }
                    if (ans < sum) ans = sum;    
                    a[x2][y2] = 0;
                }
            }
            a[x1][y1] = 0;
        }
    }
    cout << ans << '\n';
}