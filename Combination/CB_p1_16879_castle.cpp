#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 2       #
// 1     /
// 0 * /
//   0 1 2 3

// 3       #
// 2     /
// 1   /
// 0 * 
//   0 1 2 3

// m = 3000
#if 0
#include <iostream>
#include <unordered_set>
using namespace std;
const int m = 3000;
int d[m][m]; // 3000x3000 -> O(m^3) -> time over!!!
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    d[0][0] = 0;
    //
    // (0,0) (1,0) (2,0)
    // (0,1) (1,1) (2,1)
    // (0,2) (1,2) (2,2)
    //
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 && j == 0) continue;
            unordered_set<int> s; // faster than <set> when cases are many
            for (int k=0; k<i; k++) {
                s.insert(d[k][j]); // ^ (up : row direction)
            }                      // |
            for (int k=0; k<j; k++) {
                s.insert(d[i][k]); // <- (left: col direction)
            }                      // 
            if (i-1 >= 0 && j-1 >= 0) {  
                s.insert(d[i-1][j-1]);  //  \ (diagonal)
            }
            for (int k=0;; k++) {
                if (s.count(k) == 0) {
                    d[i][j] = k; // put the minimum value
                    break;       // grundy number
                }
            }
        }
    }
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        ans ^= d[x][y];
    }
    if (ans > 0) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}
#endif

// find rule!!!
// 0 1 2 3 4 5 6 7 8 9 10
// 1 2 0 4 5 3 7 8 6 10 11
// 2 0 1 5 3 4 8 6 7 11 9
// 3 4 5 0 1 2 9 10 11 6 7
// 4 5 3 1 2 0 10 11 9 7 8
// 5 3 4 2 0 1 11 9 10 8 6
// 6 7 8 9 10 11 0 1 2 3 4
// 7 8 6 10 11 9 1 2 0 4 5
// 8 6 7 11 9 10 2 0 1 5 3
// 9 10 11 6 7 8 3 4 5 0 1
// 10 11 9 7 8 6 4 5 3 1 2

// a[i][j] = the most left,upper in 3x3 of (i,j)-th
// a[i][j] = multiply of 3
// b[i][j] = a[i][j]/3
// b[i][j] = i^j 

#include <iostream>
using namespace std;
int palace(int x, int y) {
    return (x+y)%3 + ((x/3)^(y/3))*3;
}
// (0,1) -> 1 + 0 = 1
// (1,1) -> 2 + 0 = 2
// (1,2) -> 0 + 0 = 0
// (2,2) -> 1 + 0 = 1
// (1,3) -> 1 + 3 = 4
// 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        ans ^= palace(x,y);
    }
    if (ans > 0) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}
