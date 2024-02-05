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

int n, m;
int a[50][50];
int d[50][50];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};


int go(int sx, int sy) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            d[i][j] = -1;
        }
    }
    d[sx][sy]=0;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<8; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == 1) {
                        return d[x][y] + 1;
                    } else {
                        d[nx][ny] = d[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0) {
                int dist = go(i,j);
                if (ans < dist) ans = dist; 
            }
        }
    }
    cout << ans << '\n';
    return 0;
}