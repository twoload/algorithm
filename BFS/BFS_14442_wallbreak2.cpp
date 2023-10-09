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
using namespace std;

int a[1001][1001];
int dist[1001][1001][11];
bool check[1001][1001][11];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, m, w;

void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << "(";
            for (int k=0; k<=w; k++) {
                cout << dist[i][j][k] << ",";
            }
            cout << ") ";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

void bfs(int sx,int sy) {
    queue<tuple<int,int,int>> q;
    dist[sx][sy][0] = 1;
    check[sx][sy][0] = true;
    q.push(make_tuple(sx,sy,0));
    while (!q.empty()) {
        //print();
        int x,y,z;
        tie(x,y,z) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (a[nx][ny]==0 && check[nx][ny][z]==false) {
                    dist[nx][ny][z]=dist[x][y][z]+1;
                    check[nx][ny][z]=true;
                    q.push(make_tuple(nx,ny,z));
                }
                if (a[nx][ny]==1) {
                    if (z+1 <= w) {
                        if (check[nx][ny][z+1]==false) {
                            dist[nx][ny][z+1]=dist[x][y][z]+1;
                            check[nx][ny][z+1]=true;
                            q.push(make_tuple(nx,ny,z+1));
                        }
                    }
                }
            }
        }
    }
}
int main() {
    
    cin >> n >> m >> w;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {    
            a[i][j] = s[j]-'0';
        }
    }
    memset(dist, -1, sizeof(dist));
    memset(check, 0, sizeof(check));
    bfs(0,0);
    int ans = -1;
    for (int k=0;k<=w;k++) {
        int ret = dist[n-1][m-1][k];
        if (ret != -1 && ans == -1) {
            ans = ret;
        } else if (ret != -1 && ans != -1) {
            if (ans > ret) {
                ans = ret;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}