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
enum {
    R = 0,
    L = 1,
    D = 2,
    U = 3
};
vector<tuple<int,int,int>> c; //type,x,y
int ans = 8*8;
int dx[] = {0,0,1,-1}; //R,L,D,U
int dy[] = {1,-1,0,0};
vector<vector<vector<int>>> dir = {
    {{R},{L},{D},{U}},
    {{R,L},{D,U}},
    {{U,R},{R,D},{L,D},{L,U}},
    {{L,U,R},{U,R,D},{L,D,R},{L,U,D}},
    {{L,R,D,U}}
};

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
    for (int i=0; i<dir[type-1].size(); i++) {
        for (int j=0; j<dir[type-1][i].size(); j++) {
            int k = dir[type-1][i][j];
            nx = x+dx[k];
            ny = y+dy[k];
            while (isValid(a,nx,ny)) {
                if (a[nx][ny]==0) {
                    a[nx][ny]=7;
                } 
                nx = nx+dx[k];
                ny = ny+dy[k];
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