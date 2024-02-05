#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque> // push_front, push_back
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,-1,0,0,1,2,2,1,-1,-2,-2,-1};
int cost[] = {0,0,0,0,1,1,1,1,1,1,1,1};
int a[200][200];
int d[200][200][31];
int main() {
    int l;
    cin >> l;
    int n, m;
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    queue<tuple<int,int,int>> q;
    d[0][0][0] = 0;
    q.push(make_tuple(0,0,0));
    while (!q.empty()) {
        int x,y,c;
        tie(x,y,c) = q.front(); q.pop();
        for (int k=0; k<12; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nc = c+cost[k];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if(a[nx][ny] == 1) continue;
                if(nc <= l) {
                    if (d[nx][ny][nc] == -1) {
                        d[nx][ny][nc] = d[x][y][c] + 1;
                        q.push(make_tuple(nx,ny,nc));
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i=0; i<=l; i++) {
        if (d[n-1][m-1][i] == -1) continue;
        if (ans == -1 || d[n-1][m-1][i] < ans) {
            ans = d[n-1][m-1][i];
        }
    }
    cout << ans << '\n';
    return 0;
}