#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n <= 3'000
// location <= 10'000

// sort (nlogn)
// if I use helicopter, check if cost is lower
//    extend the range until cost is lower
//    stop if cost is not lower

// num of helicopter, loc of helicopter
// d[start][end][num of helicopter] : min value
// loc[n]: helicopter's location

// teacher

//     A2      A4 -> not efficient
//
// A1, A2, A3, A4

//     A2  A3  A4 -> efficient : series, continuous (helicopter)
//
// A1, A2, A3, A4

// sort
// A2~A4 delivery is more efficient than A2, A4 delivery

// sort
// d[n] = min value when deliver until 1~N
// 1.when deliver n-th product with truck
//   = d[n-1] + a[n]*T
// 2.when deliver n-th product with helicopter
//   = d[n-1] + 
// 3.when deliver n,n-1-th product with helicopter
//   = d[n-2] +
// 4.when deliver n,n-1,n-2-th product with helicopter
//   = d[n-3] + 
// 5. ...
// 6.when deliver n,n-1,n-2,...1-th product with helicopter

// 1. truck = d[n-1] + a[n]*T
// 2~6. helicopter : m~n helicopter = d[m-1](1~m-1) + H + (m~n sum from a[m+n/2]) 

// where I put helicopter ...?
//   = center
// location to put helicopter = X
// |X-A1| + |X-A2| + |X-A3| -> min when X = A2 (center)
//

// d[n] = min value to deliver 1~n products
// nth : truck = d[n-1] + a[n]*T
// m~nth : heli 
//       heli drop loc:x = a[(m+n)/2]
//       d[m-1] + H + (cost to deliver with truck from x)

// O(n) : total problem number
//      x (n+1) : truck 1, m~n : n
//      cost from x ??? : n  ----> we need to reduce
// O(n^3)
// we need to reduce time

// i   x   j
// i~j : heli, next truck
// heli drop loc : a[x] (x=(i+j)/2)
// (a[j]-a[x])*T    \
// (a[j-1]-a[x])*T  |
// ...              |
// (a[x+1]-a[x])*T  /
// (a[x]]-a[x])*T  ------> x
// (a[x]-a[x-1])*T  \
// ...              |
// (a[x]-a[i])*T    /

// accumulated sum -> O(n)
// -> O(n^2)


#include <iostream>
#include <algorithm>
using namespace std;
int a[3001]; // 1<=n<=3000
int d[3001];
int s[3001];
int n;
int t;
int h;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    cin >> t >> h;
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++) {
        s[i] = s[i-1] + a[i];  // calc accumulated sum in advance
    }
    for (int i=1; i<=n; i++) {
        d[i] = d[i-1] + a[i]*t; // truck
        // j..i
        for (int j=i; j>=1; j--) {
            int c = h;
            int x = (i+j)/2; // center
            // 10 20 30 40 50
            //  j     x     i
            //  2     4     6
            // (a[6]-a[4])
            // (a[5]-a[4])
            // (a[4]-a[4]) 
            //  = s[6]-s[3] - a[4]*(6-4+1)
            // (a[4]-a[3])
            // (a[4]-a[2])
            //  = a[4]*(4-2+1) -(s[4]-s[1])
            //  = a[4]*(4-2)-(s[3]-s[1]) 
            c += ((s[i]-s[x-1]) - a[x]*(i-x+1))*t;
            //c += (a[x]*(x-j+1) - (s[x]-s[j-1]))*t;
            c += (a[x]*(x-j) - (s[x-1]-s[j-1]))*t;
            // (2) x-1 ~ j
            // -(a[x-1]+...a[j])
            if (d[i] > d[j-1] + c) {
                d[i] = d[j-1] + c;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}

#if 0
#include <iostream>
#include <algorithm>
using namespace std;
int a[3001]; // 1<=n<=3000
int d[3001];
int n;
int t;
int h;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) { //starting 1
        cin >> a[i];
    }
    cin >> t >> h;
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++) {
        d[i] = d[i-1] + a[i]*t; // with truck
        for (int j=i; j>=1; j--) { //i~j
            int c = h;
            int x = a[(i+j)/2]; // center
            for (int k=j; k<=i; k++) { // cost from center x
                c += abs(x - a[k])*t;
            }
            if (d[i] > d[j-1] + c) {
                d[i] = d[j-1] + c;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
#endif

