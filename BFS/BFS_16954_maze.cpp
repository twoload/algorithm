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
int dx[] = {0,0,1,-1,1,-1,1,-1,0};
int dy[] = {1,-1,0,0,1,1,-1,-1,0};
int main() {
    int n = 8;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    queue<tuple<int,int,int>> q;
    check[7][0][0] = true;
    q.push(make_tuple(7,0,0));
    bool ans = false;
    while (!q.empty()) {
        int x,y,t;
        tie(x,y,t)=q.front(); q.pop();
        if (x==0 && y==7) ans = true; // arrival
        for (int k=0; k<9; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            int nt=min(t+1,8);
            if (0<=nx && nx<n && 0<=ny && ny<n) {
                if (nx-t>=0 && a[nx-t][ny]=='#') continue;    
                if (nx-t-1>=0 && a[nx-t-1][ny]=='#') continue;
                if (check[nx][ny][nt]==false) {
                    check[nx][ny][nt] = true;
                    q.push(make_tuple(nx,ny,nt));
                }
            }
        }
    }
    cout << (ans ? 1 : 0) << '\n';
    return 0;
}

#if 0
int n = 8;
int a[9][9];
int dist[9][9][9];
int dx[]={0,0,1,-1,1,1,-1,-1,0};
int dy[]={1,-1,0,0,1,-1,1,-1,0};

void print() {
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << "(";
            for (int k=0; k<=8; k++) {
                cout << dist[i][j][k] << ",";
            }
            cout << ")";
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

void bfs(int sx, int sy) {
    queue<tuple<int,int,int>> q;
    dist[sx][sy][0]=0;
    q.push(make_tuple(sx,sy,0));
    while (!q.empty()) {
        print();
        int x,y,z;
        tie(x,y,z)=q.front(); q.pop();
        dist[x][y][z] = -1;
        for (int k=0;k<9;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            int d=dist[x][y][z]; //cur
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if (nx-d >=0 && nx-d < n) {
                if (a[nx-d][ny]==1) continue;
            }
            if (dist[nx][ny][z] == -1) {
                // check #
                d += 1; //move
                if (nx-d >=0 && nx-d < n) {
                    if (a[nx-d][ny] != 1) {
                        dist[nx][ny][z]=dist[x][y][z]+1;
                        q.push(make_tuple(nx,ny,z));
                        if (x==nx && y==ny && z+1 <= 8) {
                            dist[nx][ny][z+1]=dist[x][y][z]+1;
                            q.push(make_tuple(nx,ny,z+1));
                        }
                    }
                } else {
                    dist[nx][ny][z]=dist[x][y][z]+1;
                    q.push(make_tuple(nx,ny,z));
                }
            }
        }
    }
}

int main() {
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<n; j++) {
            if (s[j]=='.') {
                a[i][j] = 0;
            } else if (s[j]=='#') {
                a[i][j] = 1;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    bfs(n-1,0);
    int ans = 0;
    for (int i=0;i<=8;i++) {
        if (dist[0][n-1][i]== -1) {
        } else {
            ans = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
#endif
#if 0
int n = 8;
int a[9][9];
int dist[9][9];
int dx[]={0,0,1,-1,1,1,-1,-1,0};
int dy[]={1,-1,0,0,1,-1,1,-1,0};

void print() {
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dist[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

void bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    dist[sx][sy]=0;
    q.push(make_pair(sx,sy));
    while (!q.empty()) {
        print();
        int x,y;
        tie(x,y)=q.front(); q.pop();
        for (int k=0;k<9;k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            int d=dist[x][y]; //cur
            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if (nx-d >=0 && nx-d < n) {
                if (a[nx-d][ny]==1) continue;
            }
            if (dist[nx][ny] == -1) {
                // check #
                d += 1; //move
                if (nx-d >=0 && nx-d < n) {
                    if (a[nx-d][ny] != 1) {
                        dist[nx][ny]=dist[x][y]+1;
                        q.push(make_pair(nx,ny));
                    }
                } else {
                    dist[nx][ny]=dist[x][y]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main() {
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<n; j++) {
            if (s[j]=='.') {
                a[i][j] = 0;
            } else if (s[j]=='#') {
                a[i][j] = 1;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    bfs(n-1,0);
    if (dist[0][n-1]== -1) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
    return 0;
}
#endif