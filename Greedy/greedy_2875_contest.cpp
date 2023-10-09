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
    
    int reserved = 0;
    int max_team = 0;
    if (n % 2 == 1) {
        reserved += 1;
        n -= 1;
    }
    if (n/2 < m) {
        reserved += m-n/2;
        max_team = n/2;
    } else if (n/2 == m) {
        max_team = m;
    } else {
        reserved += (n-2*m);
        max_team = m;
    }
    if (reserved >= k) {
        cout << max_team << '\n';
        return 0;
    } else {
        while (reserved < k) {
            if (n < 2) {
                cout << 0 << '\n';
                return 0;
            }
            n -= 2;
            max_team -= 1;
            reserved += 2;
            if (m < 1) {
                cout << 0 << '\n';
                return 0;
            }
            m -= 1;
            reserved += 1;
        }
        cout << max_team << '\n';
        return 0;
    }
    return 0;
}