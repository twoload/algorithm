#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <deque>
using namespace std;

int main() {
    string a, t;
    cin >> a >> t;
  
    deque<char> left;
    deque<char> right;

    int l = 0;
    int r = t.size()-1;
    int turn = 0;

    while (l <= r) {
        if (turn % 2 == 0) {
            left.push_back(t[l]);
            l += 1;
            if (left.size() >= a.length()) {
                bool same = true;
                for (int i=0; i<a.length(); i++) {
                    if (a[a.length()-1-i] != left[left.size()-1-i]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    for (int i=0; i<a.length(); i++) {
                        left.pop_back();
                    }
                    turn += 1;
                }
            }
        } else {
            right.push_front(t[r]);
            r -= 1;
            if (right.size() >= a.length()) {
                bool same = true;
                for (int i=0; i<a.length(); i++) {
                    if (a[i] != right[i]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    for (int i=0; i<a.length(); i++) {
                        right.pop_front();
                    }
                    turn += 1;
                }
            }
        }
    }
    string ans;
    for (int i=0; i<left.size(); i++) {
        ans.push_back(left[i]);
    }
    for (int i=0; i<right.size(); i++) {
        ans.push_back(right[i]);
    }
    while (ans.find(a) != std::string::npos) {
        ans.erase(ans.find(a), a.size());
    }
    cout << ans << '\n';
    return 0;
}