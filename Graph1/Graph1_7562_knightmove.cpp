#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int d[301][301];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int l;
        scanf("%d", &l);
        int sx, sy;
        int tx, ty;
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &tx, &ty);
        memset(d, -1, sizeof(d));
        queue<pair<int,int>> q;
        q.push(make_pair(sx, sy));
        d[sx][sy] = 0;
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            if (cx == tx && cy == ty) {
                printf("%d\n", d[cx][cy]);
                break;
            }
            int nx, ny;
            for(int k=0; k<8; k++) {
                nx = cx + dx[k];
                ny = cy + dy[k];
                if (0<= nx && nx <l && 0<=ny && ny <l) {
                    if (d[nx][ny] == -1) {
                        q.push(make_pair(nx,ny));
                        d[nx][ny] = d[cx][cy] + 1;
                    }
                }
            }
        }
    }
    return 0;
}

#if 0
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int d[300][300];
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sx,sy;
        cin >> sx >> sy;
        int ex,ey;
        cin >> ex >> ey;
        memset(d,-1,sizeof(d));
        queue<pair<int,int>> q;
        q.push(make_pair(sx,sy));
        d[sx][sy] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k=0; k<8; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (d[nx][ny] == -1) {
                        d[nx][ny] = d[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        cout << d[ex][ey] << '\n';
    }
    return 0;
}
#endif