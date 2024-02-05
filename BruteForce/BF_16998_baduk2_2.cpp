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
// n*m*n*m*(n*m)
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};    
int a[21][21];
bool check[21][21];
int bfs() {
    int sum = 0;
    memset(check, false, sizeof(check));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            queue<pair<int,int>> q;
            if (a[i][j]==2 && check[i][j]==false) {
                
                bool dead = true;
                check[i][j] = true;
                q.push(make_pair(i,j));
                int ret = 0;
                while (!q.empty()) {
                    int x, y;
                    tie(x,y) = q.front(); q.pop();
                    ret += 1;
                    for (int k=0; k<4; k++) {
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if (0<=nx && nx<n && 0<=ny && ny<m) {
                            if (a[nx][ny] == 0) {
                                dead = false;
                            } else if (a[nx][ny]==2 && check[nx][ny]==false){
                                check[nx][ny] = true;
                                q.push(make_pair(nx,ny));
                            }  
                        }
                    }
                }
                if (dead) {
                    sum += ret;
                }
            }
        }
    }
    return sum;
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
            if (a[x1][y1] != 0) continue;
            for (int x2=0; x2<n; x2++) {
                for (int y2=0; y2<m; y2++) {
                    if (x1==x2 && y1==y2) continue;
                    if (a[x2][y2] != 0) continue;
                    a[x1][y1] = 1;
                    a[x2][y2] = 1;
                    int cur = bfs();
                    if (ans < cur) ans = cur;    
                    a[x1][y1] = 0;
                    a[x2][y2] = 0;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}