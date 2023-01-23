#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n, m (1<=n,m<=10)
// brute force : 2^100 (./x) (0:no, 1:yes)
// dp
// d[i] : max num of students at i position
// status: map (n*m)
// status: map (n*2) update map as we move
// d[i][s]
//  n*m*2^2n

// teacher
// d[i][j] : num of students when row i's status = j

//         /-----------\ k
// i-1:    ? ? ? ? ? ? ?
// i:      1 0 1 0 1 0 0
//         \-----------/ status: j

// d[i][j] = max (d[i-1][k]) + num of students at status j



#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char a[22][22]; // 1<=n,m<=10
// d[i][j] : num of students when row i's status = j
int d[10][1<<10]; // 1<=n,m<=10
bool isset(int state, int i) { // if i in in state ?
    return (state & (1 << i)) > 0;
}

bool check(int row, int state) { // about row only (validation check)
    if (row < 0) return true;
    for (int j=0; j<m-1; j++) {
        if (isset(state, j) && isset(state, j+1)) { //. . -> false
            return false;
        }
    }
    for (int j=0; j<m; j++) {
        if (a[row][j] == 'x' && isset(state, j)) { //if . in x pos -> false
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> a[i]; //char a[22][22]; 
        }
        memset(d,0,sizeof(d));
        int ans = 0;
        for (int row=0; row<n; row++) { // row: 0~n-1
            for (int state=0; state<(1<<m); state++) {//00...0 ~ 11...1
                if (!check(row, state)) continue;
                // row, state
                // row-1, pstate
                for (int pstate=0; pstate<(1<<m); pstate++) {
                    if (!check(row-1, pstate)) continue;
                    int cnt = 0;
                    bool ok = true;
                    for (int j=0; j<m; j++) { // j: 0~ m-1 (all columns)
                        if (isset(state, j)) {// j: .
                            cnt += 1;
                            if (j-1 >= 0 && isset(pstate, j-1)) ok = false; // \ (upper left)
                            if (j+1 < m && isset(pstate, j+1)) ok = false;  // / (upper right)
                        }
                    }
                    if (ok) {
                        if (row == 0) {
                            d[row][state] = max(d[row][state], cnt);
                        } else {
                            d[row][state] = max(d[row][state], d[row-1][pstate]+cnt);
                        }
                    }
                }
            }
        }
        for (int state=0; state<(1<<m); state++) { // for all state
            if (ans < d[n-1][state]) {
                ans = d[n-1][state];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
// d[i][j]
// O(n*2^m*2^m) = O(n*2^2m) = 10*2^20
//  row cur pre
