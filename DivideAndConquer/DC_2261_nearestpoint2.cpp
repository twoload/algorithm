// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
struct Point {
    int x;
    int y;
};
bool cmp_x(const Point& u, const Point& v) {
    return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}
bool cmp_xe(const Point& u, const Point& v) {
    return make_pair(u.x, u.y) <= make_pair(v.x, v.y);
}
bool cmp_y(const Point& u, const Point& v) {
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int brute_force(vector<Point>& a, int start, int end) {
    int ans = -1;
    for (int i=start; i<=end-1; i++) {
        for (int j=i+1; j<=end; j++) {
            int d = dist(a[i],a[j]);
            if (ans == -1 || ans > d) {
                ans = d;
            }
        }
    }
    return ans;
}
int closest(vector<Point>& ax, vector<Point>& ay, int start, int end) {
    int n = end-start+1;
    if (n<=3) {
        return brute_force(ax, start, end);
    }
    int mid = (start+end)/2;
    vector<Point> ayl, ayr;
    Point mid_p = ax[mid];
    for (Point p : ay){
        if (cmp_xe(p, mid_p)) {
            ayl.push_back(p);
        } else {
            ayr.push_back(p);
        }
    }
    int left = closest(ax, ayl, start, mid);
    int right = closest(ax, ayr, mid+1, end);
    int ans = min(left, right);
    vector<Point> b;
    for (Point p : ay) {
        int d = (p.x-mid_p.x);
        if (d*d < ans) {
            b.push_back(p);
        }
    }
    int m = b.size();
    for (int i=0; i<m-1; i++) {
        for (int j=i+1; j<m; j++) {
            int y = b[j].y-b[i].y;
            if (y*y < ans) {
                int d = dist(b[i],b[j]);
                if (ans > d) {
                    ans = d;
                }
            } else {
                break;
            }
        }
    }
    return ans;
}
#if 0
https://bingorithm.tistory.com/8
7
-5 0
-3 4
2 1
3 4
-1 1
8 8
1 7
#endif

int main() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    vector<Point> b = a;
    sort(a.begin(), a.end(), cmp_x);
    sort(b.begin(), b.end(), cmp_y);
    int ans = closest(a, b, 0, n-1);
    cout << ans << '\n';
    return 0;
}

