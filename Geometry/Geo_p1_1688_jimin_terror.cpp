#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// Polygon Inside, Outside
// odd: in
// even: out
// set one point outside not to match polygon's sides

#include <iostream>
#include <vector>
using namespace std;
using Point = pair<long long, long long>; // Point
using Line = pair<Point, Point>; // Line
int ccw(Point p1, Point p2, Point p3) {
    long long temp = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second;
    temp -= p2.first*p1.second + p3.first*p2.second +  p1.first*p3.second;
    if (temp > 0) return 1;
    if (temp < 0) return -1;
    return 0;
}
// includes 3 points can be in one line at the same time
// l1: p1---p2
// l2: p3---p4
bool cross(Line l1, Line l2) {
    // CCW(p1,p2,p3) x CCW(p1,p2,p4) < 0
    int l1l2 = ccw(l1.first,l1.second,l2.first) * ccw(l1.first,l1.second,l2.second);
    // CCW(p3,p4,p1) x CCW(p3,p4,p2) < 0
    int l2l1 = ccw(l2.first,l2.second,l1.first) * ccw(l2.first,l2.second,l1.second);
    
    return l1l2 < 0 && l2l1 < 0;
}

// p1 : person
// n : polygon's point's number
// a : polygon's point vector
int go(Point &p1, int n, vector<Point> &a) {
    for (int i=0; i<n; i++) {
        int t1 = ccw(a[i], a[i+1], p1);
        // 3 points are in one line
        // a[i], a[i+1] -> minx,miny,maxx,maxy
        // minx <= p1.x <= maxx  and  miny <= p1.y <= maxy 
        if (t1 == 0) { 
            auto minx = min(a[i].first, a[i+1].first);
            auto maxx = max(a[i].first, a[i+1].first);
            auto miny = min(a[i].second, a[i+1].second);
            auto maxy = max(a[i].second, a[i+1].second);
            if (minx <= p1.first && p1.first <= maxx) {
                if (miny <= p1.second && p1.second <= maxy) {
                    // can protect
                    return 1;
                }
            }
        }
    }
    Point p0 = {1, 2147483647}; //2^31-1 : no match point outside
    int cnt = 0;
    for (int i=0; i<n; i++) {
        Line l = {p0, p1}; // connect two points in line
        // check if two lines are cross in all lines : count
        cnt += cross(l, Line({a[i], a[i+1]})); 
    }
    // odd : inside   : can protect
    // even : outside : can not protect
    return cnt%2;
} 

int main() {
    int n;
    cin >> n; // Polygon's point's num
    vector<Point> a(n); //Polygon's points
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back(a[0]); //put first one one more. a[0],a[1],a[2],a[0]
    int m = 3;
    while (m--) {
        Point p1;
        cin >> p1.first >> p1.second; // people to protect
        cout << go(p1, n, a) << '\n';
    }
    return 0;
}