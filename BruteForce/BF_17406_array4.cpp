#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int n,m,k;
int a[51][51];
int b[51][51];
bool check[51];
vector<tuple<int,int,int>> ro;

void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void rotateClock(int r, int c, int s) {
    int x1 = r-s;
    int y1 = c-s;
    int x2 = r+s;
    int y2 = c+s;
    while (1) {
        int x1y1 = a[x1][y1];
        if (x1 >= x2 || y1 >= y2) break;
        for (int i=x1+1; i<=x2; i++) {
            a[i-1][y1] = a[i][y1];
        }
        for (int i=y1+1; i<=y2; i++) {
            a[x2][i-1] = a[x2][i];
        }
        for (int i=x2-1; i>=x1; i--) {
            a[i+1][y2] = a[i][y2]; 
        }
        for (int i=y2-1; i>=y1; i--) {
            a[x1][i+1] = a[x1][i];
        }
        a[x1][y1+1] = x1y1;

        x1 += 1;
        y1 += 1;
        x2 -= 1;
        y2 -= 1;
    }
}

void rotateClockwise(int r, int c, int s) {
    int x1 = r-s;
    int y1 = c-s;
    int x2 = r+s;
    int y2 = c+s;
    while (1) {
        int x2y2 = a[x2][y2];
        if (x1 >= x2 || y1 >= y2) break;
        for (int i=y2-1; i>=y1; i--) {
            a[x2][i+1] = a[x2][i];
        }
        for (int i=x2-1; i>=x1; i--) {
            a[i+1][y1] = a[i][y1]; 
        }
        for (int i=y1+1; i<=y2; i++) {
            a[x1][i-1] = a[x1][i];
        }
        for (int i=x1+1; i<=x2; i++) {
            a[i-1][y2] = a[i][y2];
        }
        a[x2-1][y2] = x2y2;

        x1 += 1;
        y1 += 1;
        x2 -= 1;
        y2 -= 1;
    }
}

int solve() {
    int ret = 987654321;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<m; j++) {
            sum += a[i][j];
        }
        if (ret > sum) {
            ret = sum;
        } 
    }
    return ret;
}

int main() {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> num(k);
    for (int i=0; i<k; i++) {
        int r,c,s;
        cin >> r >> c >> s;
        r -= 1;
        c -= 1;
        ro.push_back(make_tuple(r,c,s));
        num[i] = i;
    }
    //print();
    //rotateClock(2,3,2);
    //print();
    //rotateClockwise(2,3,2);
    //print();
    int ans = 987654321;
    do {
        memcpy(b, a, sizeof(b));
        for (int i=0; i<num.size(); i++) {
            int r,c,s;
            tie(r,c,s) = ro[num[i]];
            rotateClock(r,c,s);
        }
        int ret = solve();
        if (ans > ret) {
            ans = ret;
        }
        memcpy(a, b, sizeof(a));
    } while(next_permutation(num.begin(), num.end()));
    cout << ans << '\n';
    return 0;
}