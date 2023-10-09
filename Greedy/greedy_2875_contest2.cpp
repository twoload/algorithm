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
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    while (n >= 2 && m >= 1 && n+m >= 3+k) {
        ans += 1;
        n -= 2;
        m -= 1;
    }
    cout << ans << '\n';
    return 0;
}