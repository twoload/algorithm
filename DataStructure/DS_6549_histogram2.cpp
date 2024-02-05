#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// https://cocoon1787.tistory.com/315

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        long long ans = 0;
        long long n;
        cin >> n;
        if (n == 0) break;
        vector<long long> h(n+2);
        for (long long i=1; i<=n; i++) {
            cin >> h[i];
        }
        h[0] = 0;
        h[n+1] = 0;
        stack<long long> s;
        s.push(0);
        for (long long i=1; i<=n+1; i++) {
            while (!s.empty() && h[s.top()] > h[i]) {
                long long check = s.top();
                s.pop();
                ans = max(ans, h[check]*(i-s.top()-1));
            }
            s.push(i);
        }
        cout << ans << '\n';
    }
    return 0;
}
