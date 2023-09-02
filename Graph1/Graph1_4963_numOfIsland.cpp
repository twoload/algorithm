#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int m;
int a[51][51];
int d[51][51];
int ans[51*51];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs(int i, int j, int cnt) {
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    d[i][j] = cnt;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0<= nx && nx < n && 0<= ny && ny < m) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = cnt;
                }
            }
        } 
    }
}
int main() {
    while (1) {
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0) {
            break;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%1d", &a[i][j]);
                d[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 1 && d[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}