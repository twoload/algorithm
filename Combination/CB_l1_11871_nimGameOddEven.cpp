#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// even : win
// odd : win
// d[x] = win
// d[x]^d[x+1],....

// teacher
// i  : 0 1 2 3 4 5 6 7 8 9 1011121314151617
//g(i): 0 1 0 2 1 3 2 4 3 5 4 6 5 7 6 8 7 9
//g(2k) = k-1
//g(2k-1) = k

//g(i): 0   0
//g(i):   1     (1:O)
//      \-/     0 -> 1
//g(i):       2 (1:X,2:O,3:O)    
//       \----/ 0
//         \--/ 1 -> 2
//g(i):         1 (1:X,2:O,3:X,4:X)
//           \--/ -> 1
//g(i):           3 (1:X,2:O,3:X,4:O,5:O)
//       \--------/ 0
//         \------/ 1
//             \--/ 2 -> 3
//g(i):             2 (1:X,2:O,3:X,4:O,5:X,6:X)
//               \--/ 1
//           \------/ 0 -> 2

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        //g(2k) = k-1 -> g(x) = x/2-1
        //g(2k-1) = k -> g(x) = (x+1)/2
        if (x % 2 == 0) {
            x = (x/2)-1;
        } else {
            x = (x+1)/2;
        }
        ans ^= x; // XOR
    }
    if (ans == 0) {
        cout << "cubelover\n";
    } else {
        cout << "koosaga\n";
    }
    return 0;
}