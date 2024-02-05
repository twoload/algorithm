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
int a[33][33];
long long d[33][33][3];
long long ans = 0;
// type:0(row), 1(col), 2(diagonal)
long long go(int x, int y, int preType) {
    long long& ret = d[x][y][preType]; 
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    if (x==n-1 && y==n-1) {
        ret = 1;
        return 1;
    }
    int nextType = 0;
    int nx, ny;
    if (preType == 0 || preType == 2) {
        nextType = 0;
        nx = x;
        ny = y+1;
        if (0<=nx && nx<n && 0<=ny && ny<n) {
            if (a[nx][ny] == 0) {
                ret += go(nx, ny, nextType);
            }
        }
    }
    if (preType == 1 || preType == 2) {
        nextType = 1;
        nx = x+1;
        ny = y;
        if (0<=nx && nx<n && 0<=ny && ny<n) {
            if (a[nx][ny] == 0) {
                ret += go(nx, ny, nextType);
            }
        }
    }
    if (preType == 0 || preType == 1 || preType == 2) {
        nextType = 2;
        nx = x+1;
        ny = y+1;
        if (0<=nx && nx<n && 0<=ny && ny<n) {
            if (a[nx][ny]==0 && a[x][y+1]==0 && a[x+1][y]==0) {
                ret += go(nx, ny, nextType);
            }
        }
    }
    return ret;
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(0, 1, 0) << '\n';
    return 0;
}