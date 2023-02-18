#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 3 <= n <= 1000
// divide into half....

// 1 2 3 4 5 6 7 8
// *       *
//   * *     * *

// teacher
// draw one line
// -> create two new games

// if connect 1 and i, 
// two games i and N-2-i
// g(n) = min integer which isn't 
//            included in g(i) XOR g(n-2-i)
// 1,2,3,4,5,6,7,8,9,10,11, n=11
// 1---7 (i=7)
// 2,3,4,5,6  (i-2 = 5)
// 8,9,10,11  (n-i = 4)

// 1,2,3,4,5,6,7,8,9,10,11, n=11
// if connect 1 and 7
// 1---7 
// 2,3,4,5,6  (i=5)
// 8,9,10,11  (n-2-i = 4)
// 1---2
// 0          (i=0)
// 3,4,5,6,7,8,9,10,11 (n-2-i=9)
// g(n) = g(i) XOR g(n-2-i)

#include <iostream>
#include <set>
using namespace std;
int g[1001]; // grundy number
int main() {
    int n;
    cin >> n;
    for (int i=0; i<=n; i++) {
        set<int> s; // check array
        // n=2  (*---*)  g(0)
        // n=3  (*---*)  g(0)^g(1), g(1)^g(0)
        //        \ /
        //         *
        // n=4  (*---*)  g(0)^g(2), g(2)^g(0)
        //       |   |
        //       *---*
        //      (*---*   g(1)^g(1)
        //       |   |
        //       *---*)

        for (int j=0; j<=i-2; j++) {
            s.insert(g[j] ^ g[i-2-j]);
            printf("s.insert(g[%d]^g[%d])\n", j, i-2-j);
        }
        for (int j=0;; j++) {
            if (s.count(j) == 0) {
                g[i] = j;
                printf("g[%d] = %d\n", i, j);
                break;
            }
        }
    }
    if (g[n] > 0) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
    return 0;
}