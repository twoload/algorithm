#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

// d[i][j] : max sum at i-th len
//         : j = 0,1 
//               (0:no remove)
//               (1:removed before or now)

// d[i][0] : a[i] (init)

// d[i][0] = max(d[i-1][0] + a[i])
// d[i][1] = max(d[i-1][0],
//               d[i-1][1] + a[i])
// O(n)
// if O(n^2) : time over


// teacher
// d[i] : series sum which ending at i-th
// d2[i] : series sum which starting at i-th

// ....(k-1) (k:X) (k+1)....
//    d[k-1] + d2[k+1]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    vector<int> dr(n);
    for (int i=0; i<n; i++) {
        d[i] = a[i];
        if (i==0) continue;
        if (d[i] < d[i-1] + a[i]) {
            d[i] = d[i-1] + a[i];
        }
    }
    for (int i=n-1; i>=0; i--) {
        dr[i] = a[i];
        if (i==n-1) continue;
        if (dr[i] < dr[i+1] + a[i]) {
            dr[i] = dr[i+1] + a[i];
        }
    }
    int ans = d[0];
    for (int i=1; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i]; // series sum max
        }
    }
    for (int i=1; i<n-1; i++) { // i+1 <n
        if (ans < d[i-1]+dr[i+1]) {
            ans = d[i-1]+dr[i+1];
        }
    }
    cout << ans << '\n';
    return 0;
}
