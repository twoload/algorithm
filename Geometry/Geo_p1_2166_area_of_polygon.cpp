#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// CCW
// P1(x1,y1), P2(x2,y2), P3(x3,y3)
// P1 ->  P2 -> P3
// 1: counterclockwise
// 0: straight line
// -1: clockwise
// == vector product = cross product
// x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1
// x1 x2 x3 x1   x1 x2 x3 x1
//   /  /  /   -   \  \  \ 
// y1 y2 y3 y1   y1 y2 y3 y1
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    x.push_back(x[0]); y.push_back(y[0]); // push first one at the end
    
    // calc cross-product 
    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += x[i] * y[i+1];
        ans -= y[i] * x[i+1];
    }
    if (ans < 0) ans = -ans;
    // ans : square > ans/2 = triangle
    cout << ans/2 << '.'; // 100.0 (round to 2 decimal places)
    if (ans%2 == 0) {
        cout << '0'; // 10/2 = 5
    } else {
        cout << '5'; // 11/2 = 5.5
    }
    cout << '\n';
    return 0;
}
