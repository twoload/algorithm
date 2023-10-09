#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int a[21][21];
bool visited[30];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
// bug: max!!! no overwrite!!!

bool check_range(int x, int y) {
    if (0<= x && x<n && 0<=y && y<m) {
        return true;
    } else {
        return false;
    }
}

int go(int x, int y) {
    int ret = 0;
    //cout << "( " << x << ", " << y << " ) " << '\n';
    //next
    for (int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!check_range(nx, ny)) continue;
        if (!visited[a[nx][ny]]) {
            visited[a[nx][ny]] = true;
            int tmp = go(nx, ny) + 1; // max!!!
            if (ret < tmp) {
                ret = tmp;
            }
            visited[a[nx][ny]] = false;
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            a[i][j] = s[j] - 'A';
        }
    }
    visited[a[0][0]] = true;
    cout << go(0,0) + 1 << '\n';
    return 0;
}