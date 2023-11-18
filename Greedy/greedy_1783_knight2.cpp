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
    if (n == 1) {
        cout << 1 << '\n';
    } else if (n == 2) {
        cout << min(4, (m+1)/2) << '\n';
    } else {
        if (m < 7) {
            cout << min(4, m) << '\n';
        } else {
            cout << m-2 << '\n';
        }
    }
    return 0;
}