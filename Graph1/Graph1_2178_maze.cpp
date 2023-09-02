#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int a[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) { 
        for (int j=0; j<m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check[0][0] = true;
    dist[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                /* important check!!! */
                if (check[nx][ny] == false && a[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
    printf("%d\n", dist[n-1][m-1]);
    return 0;
}

#if 0 // timeover
int n;
int m;
int a[101][101];
int d[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    int cnt = 0;
    d[i][j] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0<= nx && nx < n && 0<= ny && ny < m) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    if (d[nx][ny] == 0 || (d[nx][ny] > d[x][y]+1))
                        d[nx][ny] = d[x][y]+1;
                }
            } 
        } 
    }
}
int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%1d", &a[i][j]);
            }
        }
        int cnt = 0;
        bfs(0,0);
        printf("%d\n", d[n-1][m-1]);
    }
    return 0;
}
#endif