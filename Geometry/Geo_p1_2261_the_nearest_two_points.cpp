#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// sort the points in increasing order of their x axis
// assume the nearest distance: d in (1th ~ M-1th points)
// add M-th point
// 1.cand can be points that x-axis dist is d or less from M-th point
//     dist = (x^2 + y^2)^0.5, if x == d, dist > d
// cand : p ~ M-1
//        ... check if dist is d or less from M-th point, 
// 2.answer can be points that y-axis dist is d or less in candidates.
// check all points in 1. and 2.
//
// sort candidates in y-axis -> O(lgN): find point which dist is d or less
//      lower bound - upper bound : O(lgN)
//      About N points
//      = O(NLgN)

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point { // sort in y-axis
    int x, y;
    bool operator < (const Point& v) const {
        if (y == v.y) {
            return x < v.x;
        } else {
            return y < v.y;
        }
    }
};
// sort in x-axis
bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end(), cmp); // sort in x-axis
    set<Point> candidate = {a[0], a[1]}; // BST (Binary Search Tree)
    int ans = dist(a[0], a[1]);
    int start = 0; // p's position
    
    for (int i=2; i<n; i++) { // about 2~n points
        // 1. x-axis
        // M-th point
        Point now = a[i];
        // compare 1~M-1 th points
        while (start < i) {
            auto p = a[start];
            int x = now.x - p.x; //dist
            if (x*x > ans) { // over d
                candidate.erase(p);
                start += 1;
            } else { // d or less
                break;
            }
        }
        // 2. y-axis
        int d = (int)sqrt((double)ans)+1; // sqrt:  decimal places are discarded
        // 2 <= n <= 100000
        auto lower_point = Point({-100000, now.y-d}); // first compare y axis
        auto upper_point = Point({100000, now.y+d});
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for (auto it = lower; it != upper; it++) {
            int d = dist(now, *it);
            if (d < ans) {
                ans = d;
            }
        }
        candidate.insert(now);
    }
    cout << ans << '\n';
    return 0;
}