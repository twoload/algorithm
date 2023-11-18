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
bool cmp(const Point&u, const Point&v) {
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}

int main() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    sort(a.begin(), a.end(), cmp);
    for (Point p: a) {
        cout << p.x << ' ' << p.y << '\n';
    }
    return 0;
}