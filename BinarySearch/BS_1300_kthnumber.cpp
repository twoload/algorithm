// I've attmxed the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <tuple>
using namespace std;

#if 0
target: 6  4  
1 2 3 (3) (3)
2 4 6 (3) (2)
3 6 9 (2) (1)
1 2 2 3 3 4 6 6 9
#endif

int main() {
    long long n, k;
    cin >> n >> k;
    long long left = 0;
    long long right = n*n;
    long long ans = 0;
    while (left <= right) {
        long long mid = (left+right)/2;
        long long cnt = 0;
        for (long long i=1; i<=n; i++) {
            cnt += min(n, mid/i);
        }
        if (cnt >= k) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}