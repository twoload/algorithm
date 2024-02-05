#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//https://justicehui.github.io/coi/2018/11/06/BOJ3015/

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    stack<pair<long long, long long>> st;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i=0; i<n; i++) {
        int num = 1;
        while (!st.empty() && st.top().first <= a[i]) {
            if (st.top().first == a[i]) {
                ans += st.top().second;
                num = st.top().second + 1;
                st.pop();
            } else {
                ans += st.top().second;
                st.pop();
                num = 1;
            }
        }
        if (!st.empty()) ans += 1;
        st.push(make_pair(a[i], num));
    }
    cout << ans << '\n';
    return 0;
}
