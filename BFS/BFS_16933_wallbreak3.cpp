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

int n, m, l;
int dist[1001][1001][11][2];
int a[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << "(";
            for (int k=0; k<=l; k++) {
                for (int p=0; p<2; p++) {
                    cout << dist[i][j][k][p] << ",";
                }
            }
            cout << ")";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}
void bfs() {
    dist[0][0][0][0] = 1;
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0,0,0,0));
    while (!q.empty()) {
        //print();
        int x,y,z,d;
        tie(x,y,z,d)=q.front();q.pop();
        for (int k=0; k<4; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            int nd=(d+1)%2;
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (a[nx][ny]==0 && dist[nx][ny][z][nd]== -1) {
                dist[nx][ny][z][nd]=dist[x][y][z][d]+1;
                q.push(make_tuple(nx,ny,z,nd));
            }
            if (a[nx][ny]==1) {
                if (d==0) {
                    if (z+1<=l) {
                        if (dist[nx][ny][z+1][nd]== -1) {
                            dist[nx][ny][z+1][nd]=dist[x][y][z][d]+1;
                            q.push(make_tuple(nx,ny,z+1,nd));
                        }
                    }
                } else if (d==1) {
                    if (dist[x][y][z][nd]== -1) {
                        dist[x][y][z][nd]=dist[x][y][z][d]+1;
                        q.push(make_tuple(x,y,z,nd));
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> l;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            a[i][j] = s[j]-'0';
        }
    }
    memset(dist, -1, sizeof(dist));
    bfs();
    int ans = -1;
    for (int i=0;i<=l;i++) {
        for (int j=0; j<2; j++) {
            int cnt = dist[n-1][m-1][i][j];
            if (ans == -1 && cnt != -1) {
                ans = cnt;
            } else if (ans != -1 && cnt != -1) {
                if (ans > cnt) {
                    ans = cnt;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}