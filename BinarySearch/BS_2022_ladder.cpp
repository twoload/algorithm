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

int main() {
    double x, y, c;
    cin >> x >> y >> c;
    double start = 0.0;
    double end = max(x,y);
    double ans = 0;
    while (start+0.001 <= end) {
        double mid = (start+end)/2;
        //mid = 26.033;
        double h1 = sqrt(x*x-mid*mid);
        double h2 = sqrt(y*y-mid*mid);
        double c1 = (h1*h2) / (h1+h2);
        //cout << "c1: " << c1 << " mid: " << mid << "(" << start << ", " << end << ") " << '\n';
        if (c < c1) {
            ans = mid;
            start = mid;
        } else {
            end = mid;
        }
    }
    cout << ans << '\n';
    return 0;
}