// I've attended the code.plus class (https://code.plus/)
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
int d[101][101];
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

void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}
#if 0
5
5 5 5 0 0
5 0 5 0 0
5 0 4 0 0
5 0 5 5 8
5 5 7 0 5
3
#endif
bool go(int mid) {
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0,0,a[0][0],a[0][0]));
    d[0][0] = 0;
    
    while (!q.empty()) {
        int x,y,mmin,mmax;
        tie(x,y,mmin,mmax) = q.front(); q.pop();
        printf("(%d, %d) [%d]\n", x, y, mmax-mmin);
        print();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int n_mmin = mmin;
            int n_mmax = mmax;
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if (n_mmin > a[nx][ny]) {
                n_mmin = a[nx][ny];
            }
            if (n_mmax < a[nx][ny]) {
                n_mmax = a[nx][ny];
            }
            if (d[nx][ny] == -1 || (d[nx][ny] > n_mmax-n_mmin)) {
                d[nx][ny] = n_mmax-n_mmin;
                q.push(make_tuple(nx,ny,n_mmin, n_mmax));
            }
        } 
    }
    if (d[n-1][n-1] != -1 && d[n-1][n-1] <= mid) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n;
    int left = 0;
    int right = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (right < a[i][j]) {
                right = a[i][j];
            }
        }
    }
    int ans = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        memset(d, -1, sizeof(d));
        if (go(mid)) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}