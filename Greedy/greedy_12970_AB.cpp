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
    int n, k;
    cin >> n >> k;
    string s(n, 'B');
    int num_a = 0;
    for (int i=0; i<n; i++) {
        int possible = n-i-1-(num_a);
        if (k > possible) {
            s[i] = 'A';
            k -= possible;
            num_a += 1;
        } else if (k == possible) {
            s[i] = 'A';
            k -= possible;
            num_a += 1;
            break;
        } else {

        }
    }
    if (k == 0) {
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}