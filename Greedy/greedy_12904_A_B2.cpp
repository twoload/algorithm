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
    string s, t;
    cin >> s >> t;
    while (s.length() != t.length()) {
        if (t.back() == 'A') {
            t.pop_back();
        } else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (s == t) {
        cout << '1' << '\n';
    } else {
        cout << '0' << '\n';
    }
    return 0;
}