#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[i][j][k] 
// i : row[i] num of cases
// j: col[0] lion o,x
// k: col[1] lion o,x

//d[i][1][0] = d[i-1][0][0] + d[i-1][0][1]
//d[i][0][1] = d[i-1][0][0] + d[i-1][1][0]
//d[i][0][0] = d[i-1][0][1] + [1][0] + [0][0]

// teacher
// 0: [x][x]
// 1: [x][O]
// 2: [O][x]
// 3: [O][O] (x)

//d[n][0] : n-th no 
//d[n][1] : n-th left
//d[n][2] : n-th right

#include <iostream>
#include <algorithm>
using namespace std;
int d[100001][3];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    d[0][0] = 1;
    for (int i=1; i<=n; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][1] = d[i-1][0] + d[i-1][2];
        d[i][2] = d[i-1][0] + d[i-1][1];
        for (int j=0; j<3; j++) {
            d[i][j] %= 9901;
        }
    }
    cout << (d[n][0] + d[n][1] + d[n][2]) % 9901 << '\n';
    return 0;
}



