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

int dist[201][201];
int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};


int main() {
    memset(dist, -1, sizeof(dist));
    int n;
    cin >> n;
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<int,int>> q;
    q.push(make_pair(r1,c1));
    dist[r1][c1] = 0;

    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); 
        q.pop();
        for (int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>n || ny<0 || ny>n) continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    cout << dist[r2][c2] << '\n';
    return 0;
}