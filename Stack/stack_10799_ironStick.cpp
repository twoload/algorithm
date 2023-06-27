#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
using namespace std;

// () --> point
// (()) --> 2
// (()()) --> 3
// ((()())) --> 2*3
//...

// stack : push index (diff:1 = laser)

int main() {
    string a;
    cin >> a;
    int n = a.size();
    stack<int> s;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == '(') {
            s.push(i);
        } else {
            if (s.top()+1 == i) { // laser
                s.pop();
                ans += s.size();
            } else { // end of the stick
                s.pop();
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}