#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// exactly same as numGame
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