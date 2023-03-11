#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 31245 : ok
// 3/12
// 1/2
// 312/4
// 3124/5

// 31425 : ng
// 3/12
// 31/4/2 : x

// brute force : n!
//   check the condition : n*n
//   O(n!*n^2) : too big!

// teacher
// way2
// 1. make all orders -> check the condition
// 2. meet the condition -> make orders (*)

//  (K) 1~k-1 (K)
//   v         v

// 1(1,1) -> 12(1,2) -> 123(1,3)
//                   -> 312(3,2)
// 1(1,1) -> 21(2,1) -> 213(2,3)
//                   -> 321(3,1)

// saving all orders are inefficient.
// Let's save first,end cities.

// d[l][r] = min cost when first city:l, last city:r
// n = max(l,r) : because we added the most left or right
// next = n+1 = max(l,r)+1
// 1. next, l, ..., r = A[next][l] + d[l][r]
// 2. l, ..., r, next = d[l][r] + A[r][next]

// recursive : becase it is not normal DP to add front or end
// d[l][r] = O(n^2) DP

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1500][1500]; // n<=1500 (0~1499)
int d[1500][1500];
int go(int l, int r) {
    if (d[l][r]) {
        return d[l][r]; // memoization
    }
    int next = max(l, r) + 1;
    if (next == n) { // exit
        return 0;
    }
    d[l][r] = min(a[next][l] + go(next, r), a[r][next] + go(l, next));
    return d[l][r];
}
int main () {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    cout << go(0, 0) << '\n'; //start=0,0
    return 0;
}




