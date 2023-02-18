#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// i  : 0 1 2 3 4 5 6 7 8 9 10
//g(i): 0 1 2 4
//g(4k+1) = 4k+1
//g(4k+2) = 4k+2
//g(4k+3) = 4k+4
//g(4k+4) = 4k+3
//2 -> 1 : g(1) = 1
//  -> 0 : g(0) = 0
//g(2):     2? No!
// 2-> (1,1) = g(1) XOR g(1) = 1^1 = 0
//g(2) = 2
//3 -> 2(get 1) : g(2)=2  
//  -> 1(get 2) : g(1)=1
//  -> 0(get 3) : g(0)=0
//  -> (1,2) : g(1) xor g(2) = 3
//g(3) = 4

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        //g(4k+1) = 4k+1
        //g(4k+2) = 4k+2
        //g(4k+3) = 4k+4
        //g(4k+4) = 4k+3
        if (x % 4 == 0) {
            x = x-1;
        } else if (x % 4 == 3) {
            x = x+1;
        }
        ans ^= x;
    }
    if (ans == 0) {
        cout << "cubelover" << '\n';
    } else {
        cout << "koosaga" << '\n';
    }
    return 0;
}