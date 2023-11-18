// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

// https://blog.naver.com/codersit/221465205466
// https://sujeng97.tistory.com/13

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}

int main() {
    double ax,ay,az,bx,by,bz,cx,cy,cz;
    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
    double ans = 50000;
    while (1) {
        double mx = (ax+bx)/2;
        double my = (ay+by)/2;
        double mz = (az+bz)/2;
        double l = dist(ax,ay,az,cx,cy,cz);
        double r = dist(bx,by,bz,cx,cy,cz);
        double h = dist(mx,my,mz,cx,cy,cz);
        if (abs(ans-h) <= 1e-6) {
            break;
        }
        if (ans > h) {
            ans = h;
        }
        if (l > r) {
            ax = mx;
            ay = my;
            az = mz;
        } else {
            bx = mx;
            by = my;
            bz = mz;
        }
    }
    cout << fixed;
    cout.precision(13);
    cout << ans << '\n';
    return 0;
}