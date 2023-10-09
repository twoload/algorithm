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
#define index _index


int group[1001][1001];
vector<int> groupnum(1);
int a[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int index=0;

void bfs(int x, int y, int n, int m) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    index += 1;
    group[x][y] = index;
    int cnt = 1;
    while (!q.empty()) {
        int xx, yy;
        tie(xx,yy) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = xx + dx[k];
            int ny = yy + dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (a[nx][ny]==0 && group[nx][ny]==0) {
                group[nx][ny] = index;
                cnt += 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    groupnum.push_back(cnt);
}
int main() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        for (int j=0; j<m; j++) {
            a[i][j] = tmp[j]-'0';
        }
    }
    // group
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j]==0 && group[i][j]==0) {
                bfs(i,j, n, m);
            }
        }
    }
    // cnt
    int b[1001][1001];
    memset(b, 0, sizeof(b));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 1) {
                int cnt = 1;
                bool check[groupnum.size()+1];
                memset(check, 0, sizeof(check));
                for (int k=0; k<4; k++) {
                    int nx, ny;
                    nx = i+dx[k];
                    ny = j+dy[k];
                    if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    int num = group[nx][ny];
                    if (num == 0) continue;
                    if (check[num]) continue;
                    check[num] = true;
                    cnt+=groupnum[num];
                }
                b[i][j] = cnt % 10;
                //cout << cnt << '\n';
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << b[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}