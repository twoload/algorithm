#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
//int a[101][101];
vector<string> a(101);
int d[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << d[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

int main() {
    cin >> m >> n;
    int sx,sy,ex,ey;
    bool start = false;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<m; j++) {
            if (a[i][j]=='C') {
                if (start == false) {
                    sx = i;
                    sy = j;
                    start = true;
                } else {
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    d[sx][sy] = 0;
    //print();
    while (!q.empty()) {
        int x,y;
        tie(x,y) = q.front(); q.pop();
        int dist= d[x][y]+1;
        for (int k=0;k<4;k++) {
            int xx = x;
            int yy = y;
            while (true) { 
                //print();   
                int nx=xx+dx[k];
                int ny=yy+dy[k];
                if (nx<0 || nx>=n || ny<0 || ny>=m) break;
                if (a[nx][ny]=='*') break;
                if (d[nx][ny]== -1) {
                    d[nx][ny] = dist;
                    q.push(make_pair(nx,ny));
                }
                xx = nx;
                yy = ny;
            }
        }
    }
    cout << d[ex][ey]-1 << '\n';
    return 0;
}