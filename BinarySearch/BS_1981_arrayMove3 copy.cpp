// I've attmxed the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <tuple>
using namespace std;

int n;
int a[101][101];
bool check[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

#if 0
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1
2
#endif


#if 0
5
5 5 5 0 0
5 0 5 0 0
5 0 4 0 0
5 0 5 5 8
5 5 7 0 5
3
#endif
bool bfs(int mn, int mx) {
    if (a[0][0] < mn || mx < a[0][0]) {
        return false;
    }
    memset(check, false, sizeof(check));
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check[0][0] = true;
    
    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if (a[nx][ny] < mn || mx < a[nx][ny]) continue;
            if (check[nx][ny] == false) {
                check[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        } 
    }
    return check[n-1][n-1];
}

bool go(int diff) {
    for (int mn = 0; mn+diff <=200; mn++) {
        if (bfs(mn, mn+diff)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    int left = 0;
    int right = 200;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 200;
    while (left <= right) {
        int mid = (left+right)/2;
        if (go(mid)) {
            ans = min(mid,ans);
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}