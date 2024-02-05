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
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            q.push(x);
        } else {
            if (q.empty()) {
                cout << 0 << '\n';
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
    return 0;
}