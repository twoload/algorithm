#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool ok = false;
        // i*M + x
        for (int k=x; k<(n*m); k+=m) {
            if (k%n == y) {
                cout << k+1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
    }
}