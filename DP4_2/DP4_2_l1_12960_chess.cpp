#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1<=r<=4, 1<=c<=47
// dp : about row
//  r*c*2^2c
//  row <-> col : swap
//  r*c*2^2r
//  tile's max number
//  d[i][j][k] : at pos i, row's status: j, next row's status k
//  *-  |    |  -*    
//  |   *-  -*   |
//  1   2    3   4
//  1. block1
//     j status update from already X
//     1) j & 1 == 0, j & 2 == 0
//     j / c = r, j % c = c
//     2) a[r+1][c] == 0
//     check black
//        i%2 == 0 -> black, 1 -> white
//        i%2 should be 0
//           d[i+2][j | 1 | 2][k | 1]
//  2. block2
//     j & 1 == 0

// teacher : similar
//    status : m
//    like 4block problem

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 100'000'000;
string a[47]; // in column
int n, m;
int d[4*47][1<<4]; // 1<=r<=4, 1<=c<=47
//    pos   status
int go(int index, int state) {
    if (index == n*m) { // end
        if (state == 0) return 0;
        else return -inf;
    }
    if (index > n*m) return -inf; // out of range
    int &ans = d[index][state]; // memoization
    if (ans != -1) return ans;
    int i = index/m; // row
    int j = index%m; // col
    if (a[i][j] == 'X') { // fill
        return ans = go(index+1, state>>1);
    }
    ans = go(index+1, state>>1); // empty : let it be
    if ((state&1) == 0) { 
        if ((i+j)%2==0) { // Black
            // BW
            // W.
            if (j+1 < m && i+1 < n) {
                if ((state&2) == 0 && a[i][j+1] == '.' && a[i+1][j] == '.') {
                    ans = max(ans, go(index+2, (state>>2) | (1<<(m-2))) + 1);
                }
            }
        } else { // White
            // WB
            // .W
            if (j+1 < m && i+1 < n) {
                if ((state&2) == 0 && a[i][j+1] == '.' && a[i+1][j+1] == '.') {
                    ans = max(ans, go(index+2, (state>>2) | (1<<(m-1))) + 1);
                }
            }
            // .W
            // WB
            if (j-1 >= 0 && i+1 < n) {
                if ((state&(1<<(m-1))) == 0 && a[i+1][j-1] == '.' && a[i+1][j] == '.') {
                    ans = max(ans, go(index+1, (state>>1) | (1<<(m-1)) | (1<<(m-2))) + 1);
                }
            }
            // W.
            // BW
            if (i+1 < n && j+1 < m) {
                if (a[i+1][j] == '.' && a[i+1][j+1] == '.') {
                    ans = max(ans, go(index+2, (state>>2) | (1<<(m-1)) | (1<<(m-2))) + 1);
                }
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    vector<string> b(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            a[j] += b[i][j]; // change direction (row, col)
        }
    }
    swap(n,m); // to make 2^m small (m:47 -> 4) 
    memset(d,-1,sizeof(d));
    cout << go(0, 0) << '\n';
    return 0;
}
