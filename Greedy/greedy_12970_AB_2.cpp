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
    int n, k;
    cin >> n >> k;
    for (int a=0; a<=n; a++) {
        int b = n-a;
        if (k > a*b) continue;

        vector<int> cnt(b+1);
        for (int i=0; i<a; i++) {
            int x = min(b, k);
            k -= x;
            cnt[x] += 1;
        }
        for (int i=b; i>=0; i--) {
            for (int j=0; j<cnt[i]; j++) {
                cout << 'A';
            }
            if (i > 0) {
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}