#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
# ref. https://blog.solarmagic.dev/algorithm/boj/2020/08/26/16880/
#endif

// find grundy number and xor
// but time over
// find rules

#include <iostream>
#include <algorithm>
using namespace std;
int palace(int x, int y) { // we found the rules in 16879
    return (x+y)%3 + ((x/3)^(y/3))*3;
}
//
// 0 1 0 1
// 1 2 3 2
// 0 3 0 1
// 1 2 1 2
int king(int x, int y) {
    int u = min(x, y);
    int v = max(x, y) - u;
    if (u % 2 == 0) {
        if (v % 2 == 0) {
            return 0; // x:even, y:even
        } else {
            return 1;
        }
    } else {
        if (v%2 == 0) { 
            return 2; // x:even, y:odd
        } else {
            return 3;
        }
    }
}
// 0 0 0 0
// 0 1 1 1
// 0 1 2 2
// 0 1 2 3
int bishop(int x, int y) {
    return min(x, y);
}
//0 0 0 0 0 0 0 0 0 0
//0 0 1 1 1 1 1 1 1 1
//0 1 1 1 2 2 2 2 2 2
//0 1 1 0 0 0 0 0 0 0
//0 1 2 0 0 1 1 1 1 1
//0 1 2 0 1 1 1 2 2 2
//0 1 2 0 1 1 0 0 0 0
//0 1 2 0 1 2 0 0 1 1
//0 1 2 0 1 2 0 1 1 1
//0 1 2 0 1 2 0 1 1 0
int knight(int x, int y) {
    int u = min(x, y);
    int v = max(x, y) - u;
    if (u%3 == 0) {
        return 0;
    } else if (u%3 == 1) {
        if (v > 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (v > 1) {
            return 2;
        } else {
            return 1;
        }
    }
}
int rook(int x, int y) {
    // (0,1) -> 1
    // (1,0) -> 1
    // (1,1) -> 0
    return x^y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x, y;
        char ch;
        cin >> x >> y >> ch;
        if (ch == 'R') {
            ans ^= rook(x,y);
        } else if (ch == 'P') {
            ans ^= palace(x,y);
        } else if (ch == 'B') {
            ans ^= bishop(x,y);
        } else if (ch == 'K') {
            ans ^= king(x,y);
        } else if (ch == 'N') {
            ans ^= knight(x,y);
        }
    }
    if (ans > 0) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}
