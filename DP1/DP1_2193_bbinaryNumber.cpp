#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[i][j] : num of bbinary = i, last number = j
//           d[i][0] = d[i-1][1] + d[i-1][0]
//           d[i][1] = d[i-1][0]

// init
// d[0][0] = 0
// d[1][0] = 1

#include <iostream>
using namespace std;
long long d[91][2];
int main() {
    int n;
    cin >> n;
    d[0][0] = 0;
    d[0][1] = 1;
    d[1][0] = 0;
    d[1][1] = 1;
    for (int i=2; i<=90; i++) {
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }
    cout << d[n][0] + d[n][1] << '\n';
}
// 1
// 10
// 100, 101
// 1000, 1001, 1010