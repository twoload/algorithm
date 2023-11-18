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
int closest(vector<Point>& a, int start, int end) {
    int n = end-start+1;
    if (n<=3) {
        return brute_force(a, start, end);
    }
    int mid = (start+end)/2;
    int left = closest(a, start, mid);
    int right = closest(a, mid+1, end);
    int ans = min(left, right);
    vector<Point> b;
    for (int i=start; i<=end; i++) {
        // compare x axis
        // it fails if you compare x,y axis both
        int d = (a[i].x-a[mid].x)*(a[i].x-a[mid].x);
        if (d < ans) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end(), cmp_y);
    int m = b.size();
    for (int i=0; i<m-1; i++) {
        for (int j=i+1; j<m; j++) {
            int d = (b[i].y-b[j].y)*(b[i].y-b[j].y);
            if (ans > d) {
                if (ans > dist(b[i], b[j])) {
                    ans = dist(b[i],b[j]);
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
    sort(a.begin(), a.end(), cmp_x);
    int ans = closest(a, 0, n-1);
    cout << ans << '\n';
    return 0;
}

