#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : 2<= n <=16 (num of cities)
// W[i][j] : cost (0<= <= 1'000'000, 0: can't go)
// graph, dijkstra, but come back ...???
// can't visit where I visited
// brute force : n! (too big!) -> n! x n 
//              if n <= 10, it's possible!
// graph : dfs, bfs (n^2)

// d[s][i] : current position = i, status which I visited cities = s
//           minimum value
// starting position = 1
//  1->2->3->1 (1->2, 2->3, 3->1)
//  2->3->1->2 (1->2, 2->3, 3->1)
//  -------
// 1. visited cities (should be same)
// 2. last visited city (should be same)
// 1,2 infos are important

// visited cities  status -> bitmask
// 0 ~ n-1
// d[s][i] : current position = i, status which I visited cities = s
//           minimum value

// 0 -> ... -> ...->  ?  -> i -->  d[s][i] (case1. s includes i : s & (1<<i) != 0) 
// \----------------------/ s            (case2. s also include j : s & (1<<j) != 0)
// 0 -> ... -> ...->  ?  -> i -->
// 0 -> ... -> ...->  j  -> i --> 
// \---------------/ s' = s - i --> min(d[s-(1<<i)][j] + w[j][i])
//                                        s & ~(1<<i)

// d[s][i] = d[s2][j] + w[j][i] : (2^n*n)*n = O(2^n*n^2) , n<=16
//                                  s  i  j
// ans = min(d[1<<n-1][i] + a[i][0])

// way2 (method2)
// 0 -> ... -> ...-> i
// \----------------/ s
// 0 -> ... -> ...-> i -> j
// \---------------------/ s | (1<<j)
// d[s|(1<<j)][j] = min(d[s][i] + w[i][j])

#include <iostream>
#include <algorithm>
using namespace std;
int d[1<<20][20]; // n<=16 , d[s][i] : s = 2^16-1
int a[20][20];
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j]; // w : cost
        }
    }
    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            d[i][j] = 100'000'000; // max <- 1'000'000 * 16+1 
        }
    }

    // d[s][i] : init position = 0, status = 2^0 = 1
    d[1][0] = 0; //cost = 0
    // d[i][j] = min(d[i][j],d[i-(1<<j)][k]+a[k][j])
    //   i : 000...00 ~ 111...11
    //   j : 0,1,...,n-1
    for (int i=0; i<(1<<n); i++) { 
        for (int j=1; j<n; j++) { // all j (1,2,...,n-1)
            if (i&(1<<j)) { // case1. j in i(s)
                for (int k=0; k<n; k++) {
                    if (k!=j && (i&(1<<k)) && a[k][j]) { // case2. k in i(s), k->j
                        d[i][j] = min(d[i][j],d[i-(1<<j)][k]+a[k][j]);
                    }   
                }
            }
        }
    }
    int ans=1'000'000'000;
    for (int i=1; i<n; i++) {
        if (a[i][0]) {
            ans = min(ans,d[(1<<n)-1][i]+a[i][0]); //start:0, last:1,...,n-1
        }
    }
    cout << ans << '\n';
    return 0;
}