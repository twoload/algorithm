// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a[3000][3000];
int cnt[3];

bool same(int x, int y, int n) {
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (a[x][y] != a[i][j]) {
                return false;
            }        
        }
    }
    return true;
}
void solve(int x, int y, int n) {
    if (same(x,y,n)) {
        cnt[a[x][y]+1] += 1;
        return;
    }
    int m = n/3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            solve(x+m*i,y+m*j,m);
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    solve(0, 0, n);
    for (int i=0; i<3; i++) {
        cout << cnt[i] << '\n';
    }
    return 0;
}