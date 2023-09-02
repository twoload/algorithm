#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

// d[n][k][s]
// = d[m][k-1][s-a[n]] + 1
//   0<= m < i

// teacher

// d[k][n] : case num which sum of k-ea numbers among 0~n is N
// = sum(d[k-1][n-l]) (0<=l<=n)
// = sum(d[k-1][n-l]) (0<=n-l<=n)
// = sum(d[k-1][l]) (0<=l<=n)

// d[k][n]
// = sum(d[k-1][l]) (0<=l<=n)
// = d[k-1][0]+ d[k-1][1]+ ... +d[k-1][n-1] +d[k-1][n]
//   ------------------------------------- 
// d[k][n-1]
// = d[k-1][0]+ d[k-1][1]+ ... +d[k-1][n-1]

// d[k][n] = d[k][n-1] + d[k-1][n]

# if 0
#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main() {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for (int i=1; i<=k; i++) {
        // O(KN^2) -> O(KN)
        // d[k][n] = d[k][n-1] + d[k-1][n]
        for (int j=0; j<=n; j++) {
            d[i][j] = d[i-1][j];
            if (j-1 >= 0) {
                d[i][j] += d[i][j-1];
            }
            d[i][j] %= mod;
        }
    }
    cout << d[k][n] << '\n';
    return 0;
}
# endif

// 2dim -> 1dim (time, space reduce)

// d[k][n] = d[k][n-1]+d[k-1][n]

// d2[n-2] = d2[n-3]+d2[n-2]
// d2[n-1] = d2[n-2]+d2[n-1]
// d2[n] = d2[n-1]+d2[n]

#include <iostream>
using namespace std;
long long d[201];
const long long mod = 1000000000;
int main() {
    int n, m;
    cin >> n >> m;
    d[0] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            d[j] += d[j-1];
            d[j] %= mod;
        }
    }
    cout << d[n] << '\n';
    return 0;
}