#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 120
// 1~9     1 * 9
// 10~99   2 * (99-10+1)
// 100~120 3 * (120-100+1)

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int start=1, len=1; start<=n; start*=10, len++) {
        int end = start*10-1;
        // start:1, end:9, len:1
        // start:10, end:99, len:2
        // start:100, end:999, len:3 -> end=120
        if (end > n) {
            end = n;
        }
        ans += (long long)(end - start + 1)*len;
    }
    cout << ans << '\n';
    return 0;
}