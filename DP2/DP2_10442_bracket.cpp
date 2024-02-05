// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long mod = 1000000007LL; // LL
long long d[5001];

long long go(int n) {
    if (n %2 == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n == 0) {
        return 1;
    }
    long long& ans = d[n];
    if (ans != -1) return ans;
    ans = 0;
    for (int i=2; i<=n; i++) {
        ans = (ans + (go(i-2)*go(n-i))%mod)%mod;    
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(d, -1, sizeof(d));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << go(n) << '\n';
    }
    return 0;
}