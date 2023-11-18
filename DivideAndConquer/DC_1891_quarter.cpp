// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

long long power2(long long k) {
    return (1LL<<k);
}


pair<long long,long long> go(long long n, string num) {
    if (n==1) {
        string now = num;
        if (now == "1") {
            return make_pair(0, 1);
        } else if (now == "2") {
            return make_pair(0, 0);
        } else if (now == "3") {
            return make_pair(1, 0);
        } else if (now == "4") {
            return make_pair(1, 1);
        }
    }
    string now = num.substr(0,1);
    long long dx, dy, nx, ny;
    tie(dx, dy)=go(n-1, num.substr(1));
    if (now == "1") {
        nx = dx;
        ny = dy+power2(n-1);
    } else if (now == "2") {
        nx = dx;
        ny = dy;
    } else if (now == "3") {
        nx = dx+power2(n-1);
        ny = dy;
    } else if (now == "4") {
        nx = dx+power2(n-1);
        ny = dy+power2(n-1);
    }
    return make_pair(nx,ny);
}

string go2(long long n, long long x, long long y) {
    if (n==1) {
        if (x==0 && y==1) {
            return "1";
        } else if (x==0 && y==0) {
            return "2";
        } else if (x==1 && y==0) {
            return "3";
        } else if (x==1 && y==1) {
            return "4";
        }
    }
    if (x < power2(n-1)) {
        if (y < power2(n-1)) {
            return "2" + go2(n-1,x,y);
        } else {
            return "1" + go2(n-1,x,y-power2(n-1));
        }
    } else {
        if (y < power2(n-1)) {
            return "3" + go2(n-1,x-power2(n-1),y);
        } else {
            return "4" + go2(n-1,x-power2(n-1),y-power2(n-1));
        }
    }
}

#if 0
50 12341234123412341234123412341234123412341234123412
500000 3000000000

답: 12341234123412341221133113344344122332344143223412
#endif
long long n;
string num;
long long dx, dy, x, y, nx, ny;
int main() {
    
    cin >> n >> num;
    
    cin >> dy >> dx;
    dx = -dx;
    tie(x,y) = go(n, num);
    nx = x + dx;
    ny = y + dy;
    if (0<=nx && nx<power2(n) && 0<=ny && ny<power2(n)) {
        cout << go2(n, nx, ny) << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}