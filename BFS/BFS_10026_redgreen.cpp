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
vector<string> a(101);
//bool check[101][101];
int group[101][101];
vector<int> group_size;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int sx, int sy) {
    if (group[sx][sy] != -1) return;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    if (group_size.empty()) {
        group[sx][sy] = 0;
    } else {
        group[sx][sy] = group_size.back();
    } 
    int cnt = 1; 
    while (!q.empty()) {
        int x,y;
        char c;
        tie(x,y) = q.front(); q.pop();
        c = a[x][y];
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            int nc = a[nx][ny];
            if (group[nx][ny] == -1) {
                if (a[x][y] == a[nx][ny]) {
                    cnt += 1;
                    group[nx][ny] = group[x][y];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    group_size.push_back(cnt);
}

int group2[101][101];
vector<int> group_size2;
void bfs2(int sx, int sy) {
    if (group2[sx][sy] != -1) return;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    if (group_size2.empty()) {
        group2[sx][sy] = 0;
    } else {
        group2[sx][sy] = group_size2.back();
    } 
    int cnt = 1; 
    while (!q.empty()) {
        int x,y;
        char c;
        tie(x,y) = q.front(); q.pop();
        c = a[x][y];
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            int nc = a[nx][ny];
            if (group2[nx][ny] == -1) {
                if ((a[x][y] == a[nx][ny]) ||
                    (a[x][y] == 'R' && a[nx][ny] == 'G') ||
                    (a[x][y] == 'G' && a[nx][ny] == 'R'))
                {
                    cnt += 1;
                    group2[nx][ny] = group2[x][y];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    group_size2.push_back(cnt);
}

int main() {
    cin >> n;
    memset(group, -1, sizeof(group));
    memset(group2, -1, sizeof(group2));
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bfs(i,j);
            bfs2(i,j);
        }
    }   
    cout << group_size.size() << ' ' << group_size2.size() << '\n';
    return 0;
}