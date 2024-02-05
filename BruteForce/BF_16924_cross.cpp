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
using namespace std;
// 1 -> 3x3
// 2 -> 5x5
// 3 -> 7x7
// 4 -> 9x9

int n, m;
string a[101];

void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
vector<tuple<int,int,int>> ans;

void go(int r, int c, int k) {
    int len = 2*k+1;
    for (int i=0; i<len; i++) {
        if (a[r+k][c+i] == '.') {
            return;
        }
    }
    for (int i=0; i<len; i++) {
        if (a[r+i][c+k] == '.') {
            return;
        }
    }
    for (int i=0; i<len; i++) {
        a[r+k][c+i] = '#';
        a[r+i][c+k] = '#';
    }
    //print();
    //printf("> %d %d %d\n", r+k+1, c+k+1, k);
    ans.push_back(make_tuple(r+k+1, c+k+1, k));
    return;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for(int k=1; j+2*k+1<=m && i+2*k+1<=n; k++) {
                //printf("i,j,k= %d %d %d\n", i,j,k);
                go(i,j,k);
            }
        }
    }
    //print();
    bool ok = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '*') {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << ans.size() << '\n';
        for (int i=0; i<ans.size(); i++) {
            cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}