#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1<= n, m <=100
// group1 group2
// step1. remove one group
// step2. divide another group

// 1 1 -> cur person wins

//ex. 5 4
// 1. 2 2
// 2. 1 1 -> win
// 1. 2 3
// 2. 1 1 -> win

//ex. 1 2
// 1. 1 1 -> win 

//ex. 3 4
// 1. 1 2
// 2. 1 1 -> win
// 1. 2 2 
// 2. 1 1 -> win

// d[i][j] = who wins when one box has i, the other has j
// d[1][1] = false
// (i,j) -> (0,j)
//          (1,j-1) (2,j-2) ... (j-1,1)
// false    if all are true,
// true     if at least one is false,


#include <iostream>
using namespace std;
bool c[111][111];
bool d[111][111]; // int (-1,0,1) -> c array isn't needed because -1
bool go(int n, int m) {
    if (c[n][m]) { // memoization
        return d[n][m];
    }
    c[n][m] = true;
    d[n][m] = false;
// d[i][j] = who wins when one box has i, the other has j
// d[1][1] = false
// (i,j) -> (0,j)
//          (1,j-1) (2,j-2) ... (j-1,1)

    //[n][m] -> [0][m]
    for (int i=1; i<=m; i++) {
        // (1,m-1),(2,m-2),...,(m,0)
        if (go(i, m-i) == false) {
            d[n][m] = true;
        }
    }
    //[n][m] -> [n][0]
    for (int i=1; i<=n; i++) {
        // (1,n-1),(2,n-2),...,(n,0)
        if (go(i, n-i) == false) {
            d[n][m] = true;
        }
    }
    return d[n][m];
}
int main() {
    int n,m;
    cin >> n >> m;
    c[1][1] = true; // visited
    d[1][1] = false;
    bool ans = go(n, m);
    if (ans) {
        cout << "A\n";
    } else {
        cout << "B\n";
    }
    return 0;
}
