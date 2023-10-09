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

int n, m;
int dist_water[51][51];
int dist[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void print(int a[51][51]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

int main() {
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    memset(dist_water, -1, sizeof(dist_water));
    vector<string> a(n);
    queue<pair<int,int>> q;
    queue<pair<int,int>> q_water;
    int ex, ey;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<m; j++) {
            if (a[i][j] == '*') {
                dist_water[i][j] = 0;
                q_water.push(make_pair(i,j));
            } else if (a[i][j] == 'S') {
                dist[i][j] = 0;
                q.push(make_pair(i,j));
            } else if (a[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }

    while (!q_water.empty()) {
        int x,y;
        tie(x,y) = q_water.front(); q_water.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (a[nx][ny]=='D' || a[nx][ny]=='S' || a[nx][ny]=='X') continue;
            if (dist_water[nx][ny] == -1) {
                dist_water[nx][ny]=dist_water[x][y]+1;
                q_water.push(make_pair(nx,ny));
            }
        }
    }
    //print(dist_water);

    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        //print(dist);
        int t = dist[x][y];
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (a[nx][ny]=='X') continue;
            if (dist_water[nx][ny]!=-1) {
                if (t+1 >= dist_water[nx][ny]) continue;
            }
            if (dist[nx][ny] == -1) {
                dist[nx][ny]=dist[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    if (dist[ex][ey]== -1) {
        cout << "KAKTUS" << '\n';
    } else {
        cout << dist[ex][ey] << '\n';
    }
    return 0;
}