#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// convex hull
// convex polygon covering all points
// graham scan
// 1. sort in angular order based on the bottom left point (CCW)
// 2. add counterclockwise points
// O(NlogN + N) = O(NlogN)
//   sort : NlogN
//   stack : N

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x, y; // 0<= x,y <= 40000
};
// Points num N (3<= N <= 100,000)
Point a[200000];
Point p;
int ccw(Point p1, Point p2, Point p3) {
    long long temp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    temp -= p2.x*p1.y + p3.x*p2.y +  p1.x*p3.y;
    if (temp > 0) return 1;
    if (temp < 0) return -1;
    return 0;
}

long long dist(Point p1, Point p2) {
    long long d1 = (long long)(p1.x - p2.x);
    long long d2 = (long long)(p1.y - p2.y);
    return d1*d1 + d2*d2;
}
// counterclockwise
//    V (0,2)
//      \
//       U (1,1)
//     /
//    P (0,0)
//    p.x u.x v.x p.x
//     0   1   0   0
//       \   \   \
//    p.y u.y v.y p.y
//     0   1   2   0
//    p.x u.x v.x p.x
//     0   1   0   0
//       /   /   /
//    p.y u.y v.y p.y
//     0   1   2   0
//    ccw(p,u,v) = 2  
//    +1 : counterclockwise
//    -1 : clockwise
//     0 : one line
bool cmp(const Point &u, const Point &v) {
    int temp = ccw(p,u,v);
    if (temp == 0) { // in one same line
        return dist(p,u) <= dist(p,v);
    } else { 
        return temp == 1; // counterclockwise
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    // step1. find bottom left
    p = a[0];
    for (int i=1; i<n; i++) {
        // bottom
        // if y is same, left
        if (a[i].y < p.y || (a[i].y == p.y && a[i].x < p.x)) {
            p = a[i];
        }
        sort(a, a+n, cmp); // sort in direction of counterclockwise
        vector<Point> s;
        for (int i=0; i<n; i++) {
            // if one line or clockwise, pop 
            while (s.size() >= 2 && ccw(s[s.size()-2], s[s.size()-1], a[i]) <= 0) {
                s.pop_back();
            }
            s.push_back(a[i]);
        }
        printf("%d\n", s.size());
        return 0;
    }
}