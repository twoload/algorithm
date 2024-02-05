#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans = 987654321;

void print(vector<string>& a) {
    cout << '\n';
    int n = a.size();
    for (int i=0; i<n; i++) {
        cout << a[i] << '\n';
    }
    cout << '\n';
}

bool visitedAll(vector<string>& a) {
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            if (a[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

void go(vector<string>& a, int x, int y, int cnt) {
    int n = a.size();
    int m = a[0].size();
    a[x][y] = '#';
    vector<string> b = a;
    //cout << "x,y = " << x << ", " << y << " (" << cnt << ")" <<'\n';
    //print(b);
    bool moved4dir = false;
    for (int k=0; k<4; k++) {
        int nx = x;
        int ny = y;
        bool moved = false;
        while (1) {
            if (nx+dx[k]<0 || nx+dx[k]>=n || ny+dy[k]<0 || ny+dy[k]>=m) break;
            if (a[nx+dx[k]][ny+dy[k]]=='*' || a[nx+dx[k]][ny+dy[k]]=='#') break;
            nx += dx[k];
            ny += dy[k];
            a[nx][ny] = '#';
            moved = true;
        }
        if (moved) {
            moved4dir = true;
            go(a, nx, ny, cnt+1);
        }
        a = b;
    }
    if (moved4dir == false) {
        if (visitedAll(a)) {
            if (ans > cnt) {
                ans = cnt;
            }
        }
    }
}

int main() {
    int t = 0;
    while (1) {
        t += 1;
        ans = 987654321;
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                vector<string> b = a;
                if (b[i][j] == '.') {
                    go(b,i,j,0);
                }
            }
        }
        if (ans == 987654321) {
            cout << "Case " << t << ": " << "-1" << '\n';    
        } else {
            cout << "Case " << t << ": " << ans << '\n';
        }
    }
    return 0;
}