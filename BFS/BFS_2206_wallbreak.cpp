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
using namespace std;

int a[1001][1001];
int dist[1001][1001][2];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void print(int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << "("<<dist[i][j][0]<<","<<dist[i][j][1]<<")";
        }
        cout << '\n';
    }
    cout << '\n';
}

int bfs(int n, int m) {
    memset(dist, -1, sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    dist[0][0][0] = 1;
    while (!q.empty()) {
        int x,y,wall;
        tie(x,y,wall) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (a[nx][ny]==0) {
                //0
                if (dist[nx][ny][wall]==-1) {
                    dist[nx][ny][wall]=dist[x][y][wall]+1;
                    q.push(make_tuple(nx,ny,wall));
                } 
            }
            else if (a[nx][ny]==1) {
                //1
                if (wall==0) {
                    if (dist[nx][ny][1]==-1) {
                        dist[nx][ny][1]=dist[x][y][0]+1;
                        q.push(make_tuple(nx,ny,1));
                    }
                } 
            } 
            //print(n,m);
        }
    }
    int ret = -1;
    int ret1 = dist[n-1][m-1][0];
    int ret2 = dist[n-1][m-1][1];
    if (ret1 == -1 && ret2 == -1) {
        ret = -1;
    } else if (ret1 != -1 && ret2 != -1) {
        ret = ret2;
        if (ret1 < ret2) {
            ret = ret1;
        }
    } else if (ret1 == -1 && ret2 != -1) {
        ret = ret2;
    } else if (ret1 != -1 && ret2 == -1) {
        ret = ret1;
    } else {
        ret = -1;
    }
    return ret;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        for (int j=0; j<m; j++) {
            a[i][j] = tmp[j]-'0';
        }
    }
    int ans = bfs(n,m);
    cout << ans << '\n';
    return 0;
}