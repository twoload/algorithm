#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
using namespace std;

int n,m;
vector<tuple<int,int,int>> c; //type,x,y
int ans = 8*8;

void print(vector<vector<int>>& a) {
    cout << '\n';
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isValid(vector<vector<int>>& a, int x, int y) {
    if (0<=x && x<n && 0<=y && y<m) {
        if (a[x][y] == 6) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

int getNumber0(vector<vector<int>>& a) {
    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0) {
                ret += 1;
            }
        }
    }
    return ret;
}

void go(vector<vector<int>>& a, int idx) {
    //print(a);
    vector<vector<int>> a_copy = a;
    if (idx >= c.size()) {
        int num = getNumber0(a);
        if (ans > num) {
            ans = num;
        }
        return;
    }
    int type,x,y,nx,ny;
    tie(type,x,y) = c[idx];
    if (type == 1) {
        // 0
        int dx0[] = {0};
        int dy0[] = {1};
        nx = x+dx0[0];
        ny = y+dy0[0];
        while (isValid(a,nx,ny)) {
            if (a[nx][ny]==0) {
                a[nx][ny]=7;
            } 
            nx = nx+dx0[0];
            ny = ny+dy0[0];
        }
        go(a, idx+1);
        a = a_copy;
        // 90
        int dx1[] = {-1};
        int dy1[] = {0};
        nx = x+dx1[0];
        ny = y+dy1[0];
        while (isValid(a,nx,ny)) {
            if (a[nx][ny]==0) {
                a[nx][ny]=7;
            } 
            nx = nx+dx1[0];
            ny = ny+dy1[0];
        }
        go(a, idx+1);
        a = a_copy;
        // 180
        int dx2[] = {0};
        int dy2[] = {-1};
        nx = x+dx2[0];
        ny = y+dy2[0];
        while (isValid(a,nx,ny)) {
            if (a[nx][ny]==0) {
                a[nx][ny]=7;
            } 
            nx = nx+dx2[0];
            ny = ny+dy2[0];
        }
        go(a, idx+1);
        a = a_copy;
        // 270
        int dx3[] = {1};
        int dy3[] = {0};
        nx = x+dx3[0];
        ny = y+dy3[0];
        while (isValid(a,nx,ny)) {
            if (a[nx][ny]==0) {
                a[nx][ny]=7;
            } 
            nx = nx+dx3[0];
            ny = ny+dy3[0];
        }
        go(a, idx+1);
        a = a_copy;
    } else if (type == 2) {
        //0
        int dx0[] = {0,0};
        int dy0[] = {1,-1};
        for (int k=0; k<2; k++) {
            nx = x+dx0[k];
            ny = y+dy0[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx0[k];
                ny = ny+dy0[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //90
        int dx1[] = {1,-1};
        int dy1[] = {0,0};
        for (int k=0; k<2; k++) {
            nx = x+dx1[k];
            ny = y+dy1[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx1[k];
                ny = ny+dy1[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
    } else if (type == 3) {
        //0
        int dx0[] = {-1,0};
        int dy0[] = {0,1};
        for (int k=0; k<2; k++) {
            nx = x+dx0[k];
            ny = y+dy0[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx0[k];
                ny = ny+dy0[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //90
        int dx1[] = {1,0};
        int dy1[] = {0,1};
        for (int k=0; k<2; k++) {
            nx = x+dx1[k];
            ny = y+dy1[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx1[k];
                ny = ny+dy1[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //180
        int dx2[] = {1,0};
        int dy2[] = {0,-1};
        for (int k=0; k<2; k++) {
            nx = x+dx2[k];
            ny = y+dy2[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx2[k];
                ny = ny+dy2[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //270
        int dx3[] = {-1,0};
        int dy3[] = {0,-1};
        for (int k=0; k<2; k++) {
            nx = x+dx3[k];
            ny = y+dy3[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx3[k];
                ny = ny+dy3[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
    } else if (type == 4) {
        //0
        int dx0[] = {-1,0,0};
        int dy0[] = {0,1,-1};
        for (int k=0; k<3; k++) {
            nx = x+dx0[k];
            ny = y+dy0[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx0[k];
                ny = ny+dy0[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //90
        int dx1[] = {1,-1,0};
        int dy1[] = {0,0,1};
        for (int k=0; k<3; k++) {
            nx = x+dx1[k];
            ny = y+dy1[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx1[k];
                ny = ny+dy1[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //180
        int dx2[] = {1,0, 0};
        int dy2[] = {0,-1,1};
        for (int k=0; k<3; k++) {
            nx = x+dx2[k];
            ny = y+dy2[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx2[k];
                ny = ny+dy2[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
        //270
        int dx3[] = {-1,1,0};
        int dy3[] = {0,0,-1};
        for (int k=0; k<3; k++) {
            nx = x+dx3[k];
            ny = y+dy3[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx3[k];
                ny = ny+dy3[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
    } else if (type == 5) {
        int dx0[] = {-1,1,0,0};
        int dy0[] = {0,0,-1,1};
        for (int k=0; k<4; k++) {
            nx = x+dx0[k];
            ny = y+dy0[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx0[k];
                ny = ny+dy0[k];
            }
        }
        go(a, idx+1);
        a = a_copy;
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int type;
            cin >> type;
            a[i][j] = type;
            if (1<= type && type <=5) {
                c.push_back(make_tuple(type, i, j));
            }
        }
    }
    go(a, 0);
    cout << ans << '\n';
    return 0;
}