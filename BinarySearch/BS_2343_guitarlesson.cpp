// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

// 1,000,000,000
#if 0
10 5

10000 10000 10000 10000 10000

10000 10000 10000 10000 10000
#endif

bool go(vector<int>& a, int size, int m) {
    int sum = 0;
    int cnt = 1;
    int n = a.size();
    for (int i=0; i<n; i++) {
        if (a[i] > size) {
            return false;
        }
        if (sum + a[i] > size) {
            cnt += 1;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    if (cnt > m) return false;
    else return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int left = 0;
    int right = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (left < a[i]) {
            left = a[i];
        }
        right += a[i];
    }
    int ans = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        if (go(a, mid, m) == false) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}