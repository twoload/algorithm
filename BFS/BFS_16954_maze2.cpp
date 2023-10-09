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
using namespace std;

bool check[8][8][9];
int dx[] = {0,0,1,-1,1,1,-1,-1,0};
int dy[] = {1,-1,0,0,1,-1,1,-1,0};

int main() {
    int n=8;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(7,0,0));
    check[7][0][0] = true;

    bool ans = false;
    while (!q.empty()) {
        int x,y,t;
        tie(x,y,t)=q.front(); q.pop();

        if (x==0 && y==7) ans = true;

        for (int k=0;k<9;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            int nt=min(t+1,8);
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if (nx-t>=0 && a[nx-t][ny]=='#') continue;
            if (nx-t-1>=0 && a[nx-t-1][ny]=='#') continue;
            if (check[nx][ny][nt]== false) {
                check[nx][ny][nt]=true;
                q.push(make_tuple(nx,ny,nt));
            }
        }
    }
    cout << ans ? 1 : 0 << '\n';
    return 0;
}