#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

//       p2
//       |
//  p3 ------ p4
//       |
//       p1
//  L1 = /p1p2, L2 = /p3p4
//  cross ? dir(p1p2p3) is opposite to dir(p1p2p4)
//
//  (counter example)
//  p3 ------ p4
//       p2
//       |
//       p1
//  cross ? dir(p1p2p3) is opposite to dir(p1p2p4)
//  cross ? dir(p3p4p1) is opposite to dir(p3p4p2)
//  CCW(p1,p2,p3) x CCW(p1,p2,p4) < 0
//  CCW(p3,p4,p1) x CCW(p3,p4,p2) < 0
//
//  if 3 points are in one line,,,
//
//  p1---p3---p2  ,  p1---p3,p2  ,   p1---p2   p3
//       |                  |                   |
//       p4                p4                  p4
//
//  CCW(p1,p2,p3) x CCW(p1,p2,p4) <= 0
//  CCW(p3,p4,p1) x CCW(p3,p4,p2) <= 0
//
//  (counter example)
//  p1---p2   p3---p4  (cross x)
//  p1---p3---p2---p4  (cross O)
//  CCW(p1,p2,p3) x CCW(p1,p2,p4) = 0
//  CCW(p3,p4,p1) x CCW(p3,p4,p2) = 0
//  + p3<=p2 and p1<=p4
//
#include <iostream>
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
    
    if (l1l2 == 0 && l2l1 == 0) {
        // p1---p3---p2---p4
        // sort (p1,p2)
        if (l1.first > l1.second) {
            swap(l1.first, l1.second);
        }
        // sort (p3,p4)
        if (l2.first > l2.second) {
            swap(l2.first, l2.second);
        }
        // p3 <= p2 and p1 <= p4
        return l2.first <= l1.second && l1.first <= l2.second;
    }
    return l1l2 < 0 && l2l1 < 0;
}

int main() {
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    Line l1 = {{x1,y1}, {x2,y2}};
    Line l2 = {{x3,y3}, {x4,y4}};
    cout << (cross(l1,l2) ? 1 : 0) << '\n';
    return 0;
}