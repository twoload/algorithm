#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// brute force: 2^(3N) : too big
// DP
//  size gets smaller
// d[n] = num of tiling at n column

// teacher
// d[i][j] : num of tining 3*i, i's status = j
// 0 1 0 1 0 1 0 1
// 0 0 1 1 0 0 1 1
// 0 0 0 0 1 1 1 1
// ----------------
// 0 1 2 3 4 5 6 7 (2^3 = 8 cases)

// tiling 3xi = 
//        column i can have empty
//        colume 1~(i-1) should not have empty (all occupied)
//               1~(i-2) empty X
//               1~(i-1) empty possible -> X by i

//[0] 1 0  0 1  1 0  1 0  1 1* (0 1)  1 0  1 0 (0 1) (0 1) 1 1* 0 1
//[1] 1 0  1 0  0 1  1 0  1 1* (0 1)  0 1  1 1  1 0  (0 1) 1 1* 1 1*
//[2] 1 0  1 0  1 0  0 1  1 0   1 0   0 1  1 1 (0 1) (0 1) 0 1  1 1*
//------------------------------------------------------------------
//    7 0  6 1  5 2  3 4  7 3   4 3   1 6  7 6  2 5   0 7  3 7  6 7

// d[i][s] = num of timing 3*i, colume i's status = s (1~i-1 all occuipied)
// d[i][0] = d[i-1][7]
// d[i][1] = d[i-1][6]
// d[i][2] = d[i-1][5]
// d[i][4] = d[i-1][3]
// d[i][3] = d[i-1][4] + d[i-1][7]
// d[i][6] = d[i-1][1] + d[i-1][6]
// d[i][5] = d[i-1][2]
// d[i][7] = d[i-1][0] + d[i-1][3] + d[i-1][6]

// d[0][7] = 1
// 0-th column
// 1
// 1
// 1
//----
// 7
// ans = d[n][7]

#include <iostream>
using namespace std;
long long D[31][8]; // 1<=n<=30, state:0~7
int main() {
    int n;
    cin >> n;
    D[0][7] = 1; // virtual 0-th column. not to put 1x2 out of range at column 1-th
    for (int i=1; i<=n; i++) {
        D[i][0] = D[i-1][7];
        D[i][1] = D[i-1][6];
        D[i][2] = D[i-1][5];
        D[i][4] = D[i-1][3];
        D[i][3] = D[i-1][4] + D[i-1][7];
        D[i][6] = D[i-1][1] + D[i-1][7];
        D[i][5] = D[i-1][2];
        D[i][7] = D[i-1][0] + D[i-1][3] + D[i-1][6];

    }
    cout << D[n][7] << '\n';
    return 0;
}