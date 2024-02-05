#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int a[51][51];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<int> d;

void print(vector<vector<int>>& a) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> n >> m;
    vector<pair<int,int>> h;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                h.push_back(make_pair(i,j));
            }
        }
    }
    vector<int> dist;
    vector<vector<int>> d(n, vector<int>(m,-1));
    for (int i=0; i<h.size(); i++) {
        queue<pair<int,int>> q;
        q.push(h[i]);
        d[h[i].first][h[i].second] = 0;
        int dd = 0;
        while (!q.empty()) {
            int x,y;
            tie(x,y) = q.front(); q.pop();
            for(int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (0<=nx && nx<n && 0<=ny && ny<n) {
                    if (d[nx][ny]== -1) {
                        q.push(make_pair(nx,ny));
                        d[nx][ny] = d[x][y] + 1;
                        print(d);
                    }
                    if (a[nx][ny]==2) {
                        dd = d[nx][ny];
                        break;
                    }
                }
            }
            if (dd != 0) {
                break;
            }

        }
        dist.push_back(dd);
    }
    sort(dist.begin(), dist.end());
    int sum = 0;
    for (int i=0; i<m; i++) {
        sum += dist[i];
    }
    cout << sum << '\n';
    return 0;
}