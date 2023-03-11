#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// loc    1 2 3 4 5 ...
// person 9 8 3 4 5 ...

// x : post office loc
// dist = (x-loc[i])*person[i] + ...
// min value of dist

// x: for one point
// dist = O(n)
// x: n point
// dist = O(n^2) = 10'000'000'000

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,long long>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second; // (position, person)
    }
    sort(a.begin(), a.end()); // sort by position
    for (int i=1; i<n; i++) {
        a[i].second += a[i-1].second;
    }
    //     a[i].second 
    // 1 3 3                       6<=3  (x)
    // 2 5 8                       6<=8  (o)
    // 3 3 11=total, mid=11+1/2=6  6<=11 (o)
    long long total = a[n-1].second;
    long long mid = (total+1)/2;
    int ans = -1;
    for (int i=0; i<n; i++) {
        if (mid <= a[i].second) {
            ans = a[i].first;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}