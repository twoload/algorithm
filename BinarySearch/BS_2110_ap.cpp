// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// ref:https://jaimemin.tistory.com/966


int main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    long long start=0, mid, end;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (end < a[i]) {
            end = a[i];
        }
    }
    int ans = 0;
    sort(a.begin(), a.end());
    while (start <= end) {
        mid = (start+end)/2;
        int cnt = 1;
        int prev = a[0];
        for (int i=1; i<n; i++) {
            if (a[i]-prev >= mid) {
                cnt += 1;
                prev = a[i];
            }
        }
        if (cnt < c) {
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}