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
using namespace std;

int n, m;
int a[1000][1000];
int group[1000][1000];
int group_size[1000*1000];
int groupn = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int sx, int sy) {
    groupn += 1;
    queue<pair<int,int>> q;
    q.push(make_pair(sx, sy));
    group[sx][sy] = groupn;
    int cnt = 1;
    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0<=nx && nx<n && 0<=ny && ny<m) {
                if (a[nx][ny]==1 && group[nx][ny]==0) {
                    group[nx][ny] = groupn;
                    cnt += 1;
                    q.push(make_pair(nx,ny));
                } 
            }
        }
    }
    group_size[groupn] = cnt;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 1 && group[i][j] == 0) {
                bfs(i,j);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0) {
                vector<int> near;
                for (int k=0; k<4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (0<=nx && nx<n && 0<=ny && ny<m) {
                        if (a[nx][ny]==1) {
                            near.push_back(group[nx][ny]);
                        }
                    }
                }
                sort(near.begin(), near.end());
                near.erase(unique(near.begin(), near.end()), near.end());
                int sum = 1;
                for (int neighbor : near) {
                    sum += group_size[neighbor];
                }
                if (ans < sum) {
                    ans = sum;
                } 
            }
        }
    }
    cout << ans << '\n';
    return 0;
}