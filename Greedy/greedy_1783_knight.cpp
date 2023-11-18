#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool two = false;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    } else if (n == 2) {
        if (m <= 6) {
            cout << (m+1)/2 << '\n';
            return 0;
        } else {
            cout << 4 << '\n';
            return 0;
        }
    } else {
        if (m <= 3) {
            cout << m << '\n';
            return 0;
        } else if (4<= m && m <=6) {
            cout << 4 << '\n';
            return 0;
        } else {
            cout << 4 + (m-6) << '\n';
            return 0;
        }
    }
    return 0;
}