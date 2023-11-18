// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long start=1, mid, end=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (end < a[i]) {
            end = a[i];
        }
    } 
    int ans = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        long long sum = 0;
        for (int l : a) {
            if (l < mid) continue;
            sum += (l-mid);
        }
        if (sum < m) {
            end = mid-1;
        } else {
            ans = mid;
            start = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}