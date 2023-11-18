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
    int n = s.size();
    int m = t.size();
    bool dir = 0;
    int start = 0;
    int end = m-1;
    while (n != end-start+1) {
        if (dir == 0) {
            if (t[end] == 'A') {
                end -= 1;
            } else {
                dir = 1-dir;
                end -= 1;
            } 
        } else { // dir == 1
            if (t[start] == 'A') {
                start += 1;
            } else { // 'B'
                dir = 1-dir;
                start += 1;
            }
        }
    }
    string tt = t.substr(start, end-start+1);
    if (dir) {
        reverse(tt.begin(), tt.end());
    }
    bool ans = (s == tt);
    cout << ans << '\n';
    return 0;
}