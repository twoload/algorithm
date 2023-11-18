// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

pair<long long, long long> go(string& a, int index, long long r, long long c, long long size) {
    if (size == 1) {
        return make_pair(r, c);
    }
    long long m = size/2;
    if (a[index]=='2') {
        return go(a, index+1, r, c, m);
    } else if (a[index]=='1') {
        return go(a, index+1, r, c+m, m);
    } else if (a[index]=='3') {
        return go(a, index+1, r+m, c, m);
    } else if (a[index]=='4') {
        return go(a, index+1, r+m, c+m, m);
    } 
    return make_pair(0,0);
}

string gogo(long long r, long long c, long long size, long long x, long long y) {
    if (size == 1) {
        return "";
    }
    long long m = size/2;
    if (x<r+m && y<c+m) {
        return "2"+gogo(r,c,m,x,y);
    } else if (x<r+m && y>=c+m) {
        return "1"+gogo(r,c+m, m,x,y);
    } else if (x>=r+m && y<c+m) {
        return "3"+gogo(r+m,c, m,x,y);
    } else {
        return "4"+gogo(r+m,c+m, m,x,y);
    }
}

int main() {
    int n;
    string a;
    cin >> n >> a;
    long long size = (1LL << n);
    auto p = go(a, 0, 0, 0, size);
    long long dr, dc;
    cin >> dc >> dr;
    dr = -dr;
    p.first += dr;
    p.second += dc;
    if (0<= p.first && p.first <size && 0<=p.second && p.second<size) {
        cout << gogo(0, 0, size, p.first, p.second) << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}