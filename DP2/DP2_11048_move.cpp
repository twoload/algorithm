// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int m;
int a[1001][1001];
int d[1001][1001];
int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};
int go(int x, int y) {
    int& ret = d[x][y]; 
    if (d[x][y] != -1) {
        return d[x][y];
    }
    ret = a[x][y];
    if (x == n-1 && y == m-1) {
        return a[x][y];
    }
    int _max = 0;
    for (int k=0; k<3; k++) {
        int temp = 0;
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (nx<0 || nx>n || ny<0 || ny>m) {
           return 0;
        }
        temp = go(nx, ny);
        if (_max < temp) {
            _max = temp;
        }
    } 
    ret += _max;
    return ret;    
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(0,0) << "\n";
    return 0;
}