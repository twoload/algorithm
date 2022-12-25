#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// N: Tree Height ( 1<= N <= 10 )
// R,B,G (0 <=  <= 100)

// Brute Force
//  n : h*(1+h)/2 = O(h^2)
//  R,G,B = O(3^(n=k^2)) <= O(3^100) : too big

// d[n][r][g][b], h = pre calcaulation, number n : h*(1+h)/2
// e[h][r][g][b] at height h

// r r g g = 4C2 * 2C2 = 6*1=6
// d[n][r][g][b] : size n tree, r,g,b number toys
// 1. use one color
//    red   : d[n-1][r-n][g][b]
//    green : d[n-1][r][g-n][b]
//    blue  : d[n-1][r][g][b-n]
// 2. use two colors (n shoule be even:2 multiplies)
//    red, green  : d[n-1][r-n/2][g-n/2][b] * nCn/2 (Comb[n][n/2])
//    green, blue : d[n-1][r][g-n/2][b-n/2] * nCn/2 (Comb[n][n/2])
//    red, blue   : d[n-1][r-n/2][g][b-n/2] * nCn/2 (Comb[n][n/2])
//    ,where Comb[n][r] = cases picking r among n
// 3. use three colors
//    r,g,b : d[n-1][r-n/3][g-n/3][b-n/3]*Comb[n][n/3]*Comb[n-n/3][n/3]

// bottom up -> top down (because parameter can be minus)

#include <iostream>
#include <cstring>
using namespace std;
long long d[11][101][101][101];
long long c[11][11];
long long go(int n, int r, int g, int b) {
    if (r < 0 || g < 0 || b < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (d[n][r][g][b] != -1) {
        return d[n][r][g][b];
    }
    d[n][r][g][b] = 0;
    // 1. use one color
    d[n][r][g][b] += go(n-1, r-n, g, b); 
    d[n][r][g][b] += go(n-1, r, g-n, b);
    d[n][r][g][b] += go(n-1, r, g, b-n);
    // 2. use two color
    if (n%2 == 0) {
        d[n][r][g][b] += go(n-1, r-n/2, g-n/2, b)*c[n][n/2];
        d[n][r][g][b] += go(n-1, r-n/2, g, b-n/2)*c[n][n/2];
        d[n][r][g][b] += go(n-1, r, g-n/2, b-n/2)*c[n][n/2];
    }
    // 3. use three color
    if (n%3 == 0) {
        d[n][r][g][b] += go(n-1, r-n/3, g-n/3, b-n/3)*c[n][n/3]*c[n-n/3][n/3];
    }
    return d[n][r][g][b];
}
int main() {
    int n, r, g, b;
    cin >> n >> r >> g >> b;
    c[0][0] = 1;
    for (int i=1; i<=10; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j=1; j<i; j++) {
            c[i][j] = c[i-1][j-1] + c[i-1][j]; // pascal's triangle
        }
    }
    memset(d,-1,sizeof(d));
    cout << go(n, r, g, b) << '\n';
    return 0;
}