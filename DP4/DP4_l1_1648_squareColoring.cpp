#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// brute force
//  2x1 kind : 2
//  2^(n*m) : too big

// D[num][s] : I'll color num-th point.
//             (from num-th ~) m numbers state : s
//             case numbers

// 0   1  2  3  4  5
// 6   7  8  9 10 11
// 12 13 14 15 16 17
// row-major order

// 0: empty
// 1: domino

// d[sum][s] : case num when M number's state is s from num 
// num=7, s=5 (000101)
// 0    1     2     3     4  5
// 6   <7(1)  8(0)  9(1) 10 11
// 12> 13    14    15    16 17

// in case that we cannot put block
//  = already block is put
//    ((s&1)==1)
//    num -> num + 1
//    s -> s >> 1

// in case that we can put block (1x2)
//    (s&1) == 0, (s&2) == 0
//    check if num is not the last column point
//    num -> num + 2
//    s -> s >> 2

// in case that we can put block (2x1)
//    (s&1) == 0
//    num -> num + 1
//    s -> (s >> 1) | (1 << (m-1))

// s should be 0 at n x m (18=3x6)
//   because we need to check out of range
// 0    1     2     3     4  5
// 6   <7(1)  8(0)  9(1) 10 11
// 12> 13    14    15    16 17
// 18 <- n*m

#include <iostream>
#include <cstring>
using namespace std;
// d[num][state] 
//  1<=n,m<=14, state:[13..0] (1<<14)
int d[14*14][1<<14];
int n,m; 
int go(int num, int state) {
    if (num == n*m && state == 0) {
        return 1;
    }
    if (num >= n*m) {
        return 0;
    }
    if (d[num][state] >= 0) {
        return d[num][state];
    }
    int &ans = d[num][state];
    ans = 0;
    if (state & 1) { // already put
        ans = go(num+1, (state >> 1));
    } else {
        // 2x1
        ans = go(num+1, (state >> 1) | (1 << (m-1)));
        // 1x2
        if ((num%m) != (m-1) /*not end*/ && (state & 2) == 0) {
            ans += go(num + 2, (state >> 2));
        }
    }
    ans %= 9901;
    return ans;
}
int main() {
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    cout << go(0,0) << '\n';
    return 0;
}