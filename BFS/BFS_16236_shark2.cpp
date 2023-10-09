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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

tuple<int,int,int> bfs(vector<vector<int>> &a, int x, int y, int size) {
    int n = a.size();
    vector<tuple<int,int,int>> ans;
    vector<vector<int>> d(n, vector<int>(n, -1));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 0;
    while (!q.empty()) {
        tie(x,y) = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0<=nx && nx<n && 0<=ny && ny<n && d[nx][ny]== -1) {
                bool ok = false;
                bool eat = false;
                if (a[nx][ny] == 0) {
                    ok = true;
                } else if (a[nx][ny] < size) {
                    ok = eat = true;
                } else if (a[nx][ny] == size) {
                    ok = true;
                }
                if (ok) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                    if (eat) {
                        ans.push_back(make_tuple(d[nx][ny],nx,ny));
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        return make_tuple(-1,-1,-1);
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n,0));
    int x,y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                tie(x,y) = make_pair(i,j);
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while (true) {
        int nx, ny, dist;
        tie(dist,nx,ny) = bfs(a,x,y,size);
        if (dist == -1) break;
        a[nx][ny]=0;
        ans+=dist;
        exp+=1;
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        tie(x,y) = make_pair(nx,ny);
    }
    cout << ans << '\n';
    return 0;
}


#if 0
int n;
int fish_array[21][21];
int sx, sy;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[21][21];

void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}

bool compare(pair<int,int> i, pair<int,int> j) {
    int x,y, nx,ny;
    tie(x,y) = i;
    tie(nx,ny) = j;
    if (dist[x][y] < dist[nx][ny]) {
        return true;
    } else if (dist[x][y] == dist[nx][ny]) {
        if (x < nx) {
            return true;
        } else if (x == nx) {
            if (y < ny) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> n;
    vector<tuple<int,int,int,int>> fish;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 9) {
                sx = i;
                sy = j;
            } else if (tmp != 0) {
                fish.push_back(make_tuple(i,j,tmp,0));
                fish_array[i][j] = tmp;
            } 
        }
    }

    int t = 0;
    int size = 2;
    int eat = 0;
    int numOffish = fish.size();
    for (int i=0; i<numOffish; i++) {
        queue<tuple<int,int>> q;
        memset(dist, -1, sizeof(dist));
        q.push(make_tuple(sx,sy));
        dist[sx][sy]=0;
        while (!q.empty()) {
            int x,y;
            tie(x,y) = q.front(); q.pop();
            //print();
            for (int k=0; k<4; k++) {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if (nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if (fish_array[nx][ny] > size) continue;   
                if (dist[nx][ny]== -1) {
                    dist[nx][ny]=dist[x][y]+1;
                    q.push(make_tuple(nx,ny));
                }
            }
        }
        //print();
        int ok = false;
        vector<pair<int,int>> cand;
        for (int j=0; j<fish.size(); j++) {
            int x,y,s,d;
            tie(x,y,s,d) = fish[j];
            if (dist[x][y] != -1) {
                if (fish_array[x][y] < size) {
                    ok = true;
                    cand.push_back(make_pair(x,y));
                }
            }
        }
        if (ok == false) {
            break;
        }
        sort(cand.begin(), cand.end(), compare);
        sx = cand[0].first;
        sy = cand[0].second;
        t += dist[sx][sy];
        eat += 1;
        if (size == eat) {
            size += 1;
            eat = 0;
        }
        int idx = 0;
        for (idx=0; idx<fish.size(); idx++) {
            if (sx == get<0>(fish[idx]) && sy == get<1>(fish[idx])) {
                break;
            }
        }
        fish.erase(fish.begin()+idx);
    }

    cout << t << '\n';
    return 0;
}
#endif