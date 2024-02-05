#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int mx = max(x,y);
    int cost = 5000*100000*3;
    for (int i=0; i<=2*mx; i+=2) {
        int now = c*i;
        if (x > i/2) {
            now += a*(x-i/2);
        }
        if (y > i/2) {
            now += b*(y-i/2);
        }
        if (cost > now) {
            cost = now;
        }
    }
    cout << cost << '\n';
    return 0;
}