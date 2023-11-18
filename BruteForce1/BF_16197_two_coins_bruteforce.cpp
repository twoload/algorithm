// bruteforce: my solution

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[21][21]; // empty:0, wall:1
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[21][21][21][21];
const int MAX = 987654321;

bool isIn(int x, int y) {
    if (0<= x && x < n && 0<=y && y<m) {
        return true;
    }
    else {
        return false;
    }
}
bool isOut(int x, int y) {
    return !isIn(x,y);
}

int go(int cnt, int x1, int y1, int x2, int y2) {
    //printf("[%d] (%d,%d), (%d,%d)\n", cnt, x1, y1, x2, y2);
    if (cnt >= 10) {
        return MAX;
    }

    int ret = MAX;
    for (int i=0; i<4; i++) {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];
        
        // check wall
        if (a[nx1][ny1] == 1) { // wall
            nx1 = x1;
            ny1 = y1;
        }
        if (a[nx2][ny2] == 1) { // wall
            nx2 = x2;
            ny2 = y2;
        }

        if (nx1 == x1 && nx2 == x2 && ny1 == y1 && ny2 == y2) {
            continue;
        }

        if ( isOut(nx1,ny1) && isOut(nx2,ny2) ) {
            continue;
        }
        bool ok1 = isOut(nx1,ny1) && isIn(nx2,ny2);
        bool ok2 = isIn(nx1,ny1) && isOut(nx2,ny2);
        if (ok1 || ok2) {
            if (ret > cnt+1) {
                ret = cnt+1;
            }
            continue;
        }
        // n1, n2 : both in
        if (!visited[nx1][ny1][nx2][ny2]) {
            visited[nx1][ny1][nx2][ny2] = true;
            int tmp = go(cnt+1, nx1, ny1, nx2, ny2);
            if (ret > tmp) {
                ret = tmp;
            }
            visited[nx1][ny1][nx2][ny2] = false;
        }
    }
    return ret;
} 

int main() {
    cin >> n >> m;
    vector<pair<int,int>> coins;
    memset(visited, 0, sizeof(visited));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'o' || ch == '.') {
                a[i][j] = 0;
                if (ch == 'o') {
                    coins.push_back(make_pair(i,j));
                }
            } else if (ch == '#') {
                a[i][j] = 1;
            }
        }
    }
    int ret = go(0, coins[0].first, coins[0].second, coins[1].first, coins[1].second);
    if (ret == MAX) {
        cout << "-1" << '\n';
    } else {
        cout << ret << '\n';
    }
    return 0;
}