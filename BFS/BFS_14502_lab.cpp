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
using namespace std;

int a[9][9];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void print(int array[9][9], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << array[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

// 3 select 


int main() {
    
    int n, m;
    cin >> n >> m;
    
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            cin >> a[x][y];
        }
    }
    int num = n*m;
    int ans = 0;
    for (int i=0; i<n*m; i++) {
        for (int j=i+1; j<n*m; j++) {
            for (int k=j+1; k<n*m; k++) {
                queue<pair<int,int>> q; 
                bool check[9][9];  
                memset(check, false, sizeof(check));         
                int b[9][9];
                for (int x=0; x<n; x++) {
                    for (int y=0; y<m; y++) {
                        b[x][y] = a[x][y];    
                        if (a[x][y] == 2) {
                            q.push(make_pair(x,y));
                        }
                    }
                }
                //print(b,n,m);
                int x1 = i/m; int y1 = i%m;
                int x2 = j/m; int y2 = j%m;
                int x3 = k/m; int y3 = k%m;
                
                
                if (b[x1][y1]!=0 || b[x2][y2]!=0 || b[x3][y3]!=0) continue;
                b[x1][y1] = 1;
                b[x2][y2] = 1;
                b[x3][y3] = 1;
                //cout << "(" << x1 << "," << y1 <<") (" << x2 <<"," << y2 <<") ("<<x3<<","<<y3<<")" <<'\n';
                //print(b,n,m);
                while(!q.empty()) {
                    int x,y;
                    tie(x,y) = q.front(); q.pop(); 

                    for (int l=0; l<4; l++) {
                        int nx = x+dx[l];
                        int ny = y+dy[l];
                        if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        if (b[nx][ny] == 1) continue;
                        else if (b[nx][ny] == 0) {
                            if (check[nx][ny] == false) {
                                q.push(make_pair(nx,ny));
                                check[nx][ny] = true;
                                b[nx][ny]=2;
                            }
                        } 
                        //print(b,n,m);
                    }
                }
                int cnt = 0;
                for (int y=0; y<n; y++) {
                    for (int z=0; z<m; z++) {
                        if (b[y][z] == 0) {
                            cnt += 1;
                        }
                    }
                }
                if (ans < cnt) {
                    ans = cnt;
                }
                //cout << cnt << '\n';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}