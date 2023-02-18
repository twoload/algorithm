#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// group : n (1<= n <= 100)
// num of rocks of each group : Pi
//     (1 <= Pi <= 10^9)

// 1. choose group (not 0) : O(n)
// 2. remove rocks (1 or more) : make it 0,1 : O(2)
// 3. repeat 1~2 : O(n*2)
// d[state][turn] = who wins at state: group+rocks, turn

// teacher
// 0 0 0 : L
// 0 0 x : W
// 0 0 1 : W
// 0 1 1 : L
// 0 1 X : W
// XOR = 0 -> L

// 5 7 8 = 101+111+1000 (XOR) = 1010 : W
// 5 7 2 = 101+111+010  (XOR) = 000 : L

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ans ^= x; //XOR
    }
    if (ans == 0) {
        cout << "cubelover\n";
    } else {
        cout << "koosaga\n";
    }
    return 0;
}