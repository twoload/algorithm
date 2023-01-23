#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// brute force
// n^2*n!
// 1<= n <= 20
// d[state] : max percentage to succeed the mission
//   = min(d[pre-state] * a[j][k] / 100)
//                        bond work
// d[i | 1<<k] = min(d[i] * a[j][k] / 100)
//   1 <= j <= 20
//   1 & (1<<k) == 0

// teacher
// person : mission do (O, X) : 2^N
// mission : done (O, X) : 2^N (*)
// 2^N * 2^N = 2^2N <= 2^40
// -> remove useless condition
// -> 2^N
// d[s] : percentange to finish successfully at mission state = s, 
//   i : i-th person will do the mission j
//   (0 ~ i-1th) mission is done
// s & (1<<j) == 0
// s -> s | (1<<j)
// O(2^N*N^2) , state=2^N, mission j = N, person i = N
// O(2^N*N) : state=2^N, next mission j = N
//   because all people doesn't have a choice to select all mission
//     example, n-th person only can choose one option...

#include <iostream>
#include <iomanip>
using namespace std;
double a[20][20];
bool c[1<<20]; // memoization array because d is double type
double d[1<<20]; // double type
int n;
double go(int i, int s) {
    if (i == n) { // 100%
        return 1.0;
    }
    if (c[s]) { // memoization 
        return d[s];
    }
    c[s] = true;
    double &ans = d[s];
    for (int k=0; k<n; k++) {
        if ((s&(1<<k)) == 0) {
            double temp = a[i][k]*go(i+1, s|(1<<k));
            if (ans < temp) { // ans init val = 0
                ans = temp;   // max value
            }
        }
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            a[i][j] /= 100.0;
        }
    }
    cout << fixed << setprecision(10) << go(0, 0)*100.0 << '\n';
    return 0;
}
