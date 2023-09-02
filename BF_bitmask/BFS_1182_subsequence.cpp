//# I've attended the code.plus class (https://code.plus/)
//# And I've referred it's codes
//# And core parts can be come fully from the class.

// all cases
// 00000
// 00001
// 00010
// .....
// 11111

// sum = target check

// for (int i=0; i<(1<<n); i++)
// for (int i=1; i<(1<<n); i++)

#include <iostream>
using namespace std;
int a[20];
int main() {
    int n, s;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=1; i<(1<<n); i++) {
        int sum = 0;
        for (int k=0; k<n; k++) {
            if (i&(1<<k)) {
                sum += a[k];
            }
        }
        if (sum == s) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}