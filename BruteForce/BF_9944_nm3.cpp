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

const int MAX = 1000000;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dotnum = 0;
int ans = MAX;
bool check[30][30];
int n, m;

void print(vector<string>& a) {
    cout << '\n';
    int n = a.size();
    for (int i=0; i<n; i++) {
        cout << a[i] << '\n';
    }
    cout << '\n';
}

bool visitedAll(vector<string>& a) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '.' && check[i][j] == false) {
                return false;
            }
        }
    }
    return true;
}

bool canMove(vector<string>& a, int x, int y) {
    if (0<=x && x<n && 0<=y && y<m) {
        if (a[x][y] == '.') {
            if (check[x][y] == false) {
                return true;
            }
        }
    }
    return false;
}

void go(vector<string>& a, int x, int y, int cnt) {
    if (cnt > dotnum) return;
    //cout << "x,y = " << x << ", " << y << " (" << cnt << ")" <<'\n';
    //print(b);
    bool finish = true;
    for (int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (canMove(a, nx, ny)) {
            finish = false;
            check[nx][ny] = true;
            while (1) {
                nx += dx[k];
                ny += dy[k];
                if (canMove(a, nx, ny)) {
                    check[nx][ny] = true;
                } else {
                    nx -= dx[k];
                    ny -= dy[k];
                    break;
                }
            }
            go(a, nx, ny, cnt+1);
            while (1) {
                if (nx == x && ny == y) break;
                check[nx][ny] = false;
                nx -= dx[k];
                ny -= dy[k];
            }
        }
    }
    if (finish == true) {
        if (visitedAll(a)) {
            if (ans > cnt) {
                ans = cnt;
            }
        }
    }
}

int main() {
    int t = 0;
    while (cin >> n >> m) {
        t += 1;
        ans = MAX;
        dotnum = 0;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            for (int j=0; j<a[i].size(); j++) {
                if (a[i][j] == '.') {
                    dotnum += 1;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '.') {
                    check[i][j] = true;
                    go(a,i,j,0);
                    check[i][j] = false;
                }
            }
        }
        if (ans == MAX) {
            ans = -1;
        }
        cout << "Case " << t << ": " << ans << '\n';
    }
    return 0;
}