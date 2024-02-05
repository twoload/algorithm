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
int n;
int a[17][17];
int ans = 0;
// type:0(row), 1(col), 2(diagonal)
void go(int x, int y, int preType) {
    if (x==n-1 && y==n-1) {
        ans += 1;
        return;
    }
    int nextType = 0;
    int nx, ny;
    if (preType == 0 || preType == 2) {
        nextType = 0;
        nx = x;
        ny = y+1;
        if (0<=nx && nx<n && 0<=ny && ny<n) {
            if (a[nx][ny] == 0) {
                go(nx, ny, nextType);
            }
        }
    }
    if (preType == 1 || preType == 2) {
        nextType = 1;
        nx = x+1;
        ny = y;
        if (0<=nx && nx<n && 0<=ny && ny<n) {
            if (a[nx][ny] == 0) {
                go(nx, ny, nextType);
            }
        }
    }
    if (preType == 0 || preType == 1 || preType == 2) {
        nextType = 2;
        nx = x+1;
        ny = y+1;
        if (0<=nx && nx<n && 0<=ny && ny<n) {
            if (a[nx][ny]==0 && a[x][y+1]==0 && a[x+1][y]==0) {
                go(nx, ny, nextType);
            }
        }
    }
}
int main() {
    
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    go(0, 1, 0);
    cout << ans << '\n';
    return 0;
}