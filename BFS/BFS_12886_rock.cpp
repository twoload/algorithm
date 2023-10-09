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

bool check[1501][1501];
int sum;
void go(int x, int y) {
    if (check[x][y]) return;
    check[x][y] = true;
    int a[3] = {x, y, sum-x-y};
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (a[i] < a[j]) {
                int b[3] = {x,y,sum-x-y};
                b[i] += a[i];
                b[j] -= a[i];
                go(b[0],b[1]);
            }
        }
    } 
}
int main() {
    int x,y,z;
    cin >> x >> y >> z;
    sum = x+y+z;
    if (sum %3 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    go (x,y);
    if (check[sum/3][sum/3]) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}


#if 0
bool check[1001][1001][1001];

int main() {
    int aa, bb, cc;
    cin >> aa >> bb >> cc;
    memset(check, false, sizeof(check));
    check[aa][bb][cc] = true;

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(aa,bb,cc));

    while (!q.empty()) {
        int x,y,z, xx, yy, zz;
        if (x == y && y == z && z == x) {
            cout << 1 << '\n';
            return 0;
        }
        tie(x,y,z) = q.front(); q.pop();
    //ab
        if (x == y) continue;
        if (x > y) swap(x,y);
        xx = x+x;
        yy = y-x;
        zz = z;
        if (check[xx][yy][zz]) continue;
        q.push(make_tuple(xx,yy,zz));
        check[xx][yy][zz] = true;
    //bc
        if (y == z) continue;
        if (y > z) swap(y,z);
        xx = x;
        yy = y + y;
        zz = z - y;
        if (check[xx][yy][zz]) continue;
        q.push(make_tuple(xx,yy,zz));
        check[xx][yy][zz] = true;
    //ca
        if (z == x) continue;
        if (z > x) swap(z,x);
        xx = x - z;
        yy = y;
        zz = z + z;
        if (check[xx][yy][zz]) continue;
        q.push(make_tuple(xx,yy,zz));
        check[xx][yy][zz] = true;
    // repeat
    }
    cout << 0 << '\n';
    return 0;
}
#endif