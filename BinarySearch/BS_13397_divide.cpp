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

int n, m;
bool go(vector<int>& a, int diff) {
    int mmin = a[0];
    int mmax = a[0];
    int cnt = 1;
    for (int i=1; i<n; i++) {
        if (a[i] < mmin) {
            mmin = a[i];
        } 
        if (a[i] > mmax) {
            mmax = a[i];
        }
        if (mmax - mmin > diff) {
            cnt += 1;
            mmin = a[i];
            mmax = a[i];
        }
    }
    if (cnt <= m) return true;
    else return false;
}

int main() {
    cin >> n >> m;
    vector<int> a(n);
    int left = 0;
    int right = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (right < a[i]) {
            right = a[i];
        }
    }
    
    int ans = 0;
    while (left <= right) {
        int mid = (left+right)/2;
        if (go(a, mid)) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}