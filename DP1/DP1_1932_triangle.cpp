#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

// d[n] : max at n stairs
//        

// d[i][j] = max(d[i-1][j+1] + a[i][j],
//               d[i-1][j] + a[i][j])
// 0<= i-1, 0<= i< n, j+1 < n

// d[0][0] = 7
// max(d[n-1][0], [1], ....)


#include <iostream>
#include <algorithm>
using namespace std;
int a[500][500];
int d[500][500];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin >> a[i][j];
        }
    }
    d[0][0] = a[0][0];
    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            d[i][j] = d[i-1][j] + a[i][j];
            if (j-1 >=0 && d[i][j] < d[i-1][j-1] + a[i][j]) {
                d[i][j] = d[i-1][j-1] + a[i][j];
            }
        }
    }
    int ans = d[n-1][0];
    for (int i=0; i<n; i++) {
        if (ans < d[n-1][i]) {
            ans = d[n-1][i];
        }
    }
    cout << ans << '\n';
    return 0;
}