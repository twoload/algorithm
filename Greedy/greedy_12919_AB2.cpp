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
    string sa, sb;
    cin >> sa >> sb;

    if (sa.length() > sb.length()) {
        cout << 0 << '\n';
        return 0;
    }

    queue<string> cand;
    cand.push(sb);
    bool ans = false;
    while (!cand.empty()) {
        string now = cand.front(); cand.pop();
        if (sa.length() == now.length()) {
            if (sa == now) {
                ans = true;
                break;
            }
        }
        string next;
        if (now.back() == 'A') {
            next = now.substr(0, now.length()-1);
            cand.push(next);
        } 
        if (now.front() == 'B') {
            next = now.substr(1, now.length()-1);
            reverse(next.begin(), next.end());
            cand.push(next);
        }
    }
    if (ans) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}