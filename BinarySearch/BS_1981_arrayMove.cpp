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
using namespace std;

int n;
int a[101][101];
bool check[101][101][201][201]; //x,y,min,max
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

#if 1
bool go(int x, int y, int mid, int mmin, int mmax) {
    //printf("(%d,%d : %d) >\n", x,y,mmax-mmin);
    if (x==n-1 && y==n-1) {
        return ((mmax-mmin) <= mid);
    }
    bool ret = false;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int n_mmin = mmin;
        int n_mmax = mmax;
        if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if (check[nx][ny][mmin][mmax]) continue;
        if (n_mmin > a[nx][ny]) {
            n_mmin = a[nx][ny];
        }
        if (n_mmax < a[nx][ny]) {
            n_mmax = a[nx][ny];
        }
        if (n_mmax-n_mmin <= mid) {
            check[nx][ny][n_mmin][n_mmax] = true;
            ret |= go(nx,ny,mid,n_mmin,n_mmax);
            if (ret) {
                return true;
            }
        } else {
            //printf("over (%d, %d) %d > %d >\n", nx,ny,n_mmax-n_mmin,mid);
        }
    }
    return ret;
}
#endif
#if 0
bool go(int mid, int mmin, int mmax) {
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check[0][0]= true;
    
    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int n_mmin = mmin;
            int n_mmax = mmax;
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if (check[nx][ny]) continue;
            if (n_mmin > a[nx][ny]) {
                n_mmin = a[nx][ny];
            }
            if (n_mmax < a[nx][ny]) {
                n_mmax = a[nx][ny];
            }
            if (n_mmax-n_mmin <= mid) {
                check[nx][ny] = true;
                q.push(make_pair(nx,ny));
            } else {
                printf("over (%d, %d) %d > %d >\n", nx,ny,n_mmax-n_mmin,mid);
            }
        } 
    }
    
    return ret;
}
#endif

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
        //printf("\nmid: %d\n", mid);
        memset(check, 0, sizeof(check));
        int v = a[0][0];
        check[0][0][v][v] = true;
        if (go(0,0,mid,v,v)) {
            //printf("\nok\n");
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}