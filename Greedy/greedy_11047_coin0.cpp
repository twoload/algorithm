#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (k == 0) break;
        int p = k / a[i];
        if (p >= 1) {
            ans += p;
            k -= p*a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}