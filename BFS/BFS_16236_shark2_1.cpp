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

int n;
int a[21][21];
int d[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
tuple<int,int,int> bfs(int x, int y, int size) {
    vector<tuple<int,int,int>> ans;
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 0;
    while (!q.empty()) {
        tie(x,y) = q.front(); q.pop();
        for (int k=0;k<4;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if (0<=nx && nx<n && 0<=ny && ny<n && d[nx][ny]==-1) {
                bool ok = false;
                bool eat = false;
                if (a[nx][ny] == 0) {
                    ok = true;
                } else if (a[nx][ny] < size) {
                    ok = true;
                    eat = true;
                } else if (a[nx][ny] == size) {
                    ok = true;
                }
                if (ok) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny]=d[x][y]+1;
                    if (eat) {
                        ans.push_back(make_tuple(d[nx][ny],nx,ny));
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        return make_tuple(-1,-1,-1);
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main() {
    cin >> n;
    int x,y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                tie(x,y) = make_pair(i,j);
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while (true) {
        int dist, nx, ny;
        tie(dist,nx,ny) = bfs(x,y,size);
        if (dist == -1) {
            break;
        }
        ans += dist;
        exp += 1;
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        tie(x,y) = make_pair(nx,ny);
        a[nx][ny]=0;
    }
    cout << ans << '\n';
    return 0;
}