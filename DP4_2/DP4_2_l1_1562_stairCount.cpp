#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n (1<= n <=100)
// brute force: 10^100
//               2^100 (+1,-1)
// dp
//   dp[n] : len n, max stair number
//           status: s (0,1,2,3,...,9) : 2^10
//   dp[s][n][k] : len n, status s, last k, max stair number
//     = dp[s - (1<<n-1)][n-1][k-1] + dp[s - (1<<n-1)][n-1][k+1]
//       (0 <= k-1, k+1 <=9)        

// teacher : 0~9 show O, X
// d[n] : len n stairNum
//         L -> L+1/L-1
// \-------/ N
// d[N][L] : len n, last L
// = d[N+1][L+1], d[N+1][L-1]
// + show O,X condition add
// d[i][j] = d[i-1][j-1] + d[i-1][j+1]
// d[N][L][S] : len n, last L, status: S
//           = d[N+1][L+1][S | (1<<(L+1))]
//           = d[N+1][L-1][S | (1<<(L-1))]
// O(n*10*2^10) = O(nm2^m)

#include <cstdio>
long long d[101][10][1<<10]; // 1<=n<=100, s:0,1,...,9
long long mod = 1'000'000'000LL;
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=9; i++) {
        d[1][i][1<<i] = 1LL; //len=1, last=i, status=2^i, num = 1
    }
    // d[N][L][S] : len n, last L, status: S
    //           = d[N+1][L+1][S | (1<<(L+1))]
    //           = d[N+1][L-1][S | (1<<(L-1))]
    for (int i=1; i<=n-1; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<(1<<10); k++) { // 000,..., 2^10-1
                if (d[i][j][k] == 0) {
                    continue;
                }
                if ((k&(1<<j)) == 0) { // k should have j (last)
                    continue;
                }
                if (j+1 <= 9) { // check range
                    d[i+1][j+1][k | (1<<(j+1))] += d[i][j][k];
                    d[i+1][j+1][k | (1<<(j+1))] %= mod;
                }
                if (j-1 >= 0) { // check range
                    d[i+1][j-1][k | (1<<(j-1))] += d[i][j][k];
                    d[i+1][j-1][k | (1<<(j-1))] %= mod;
                }
            }
        }
    }

    long long ans = 0;
    for (int i=0; i<=9; i++) {
        ans += d[n][i][(1<<10)-1];
        //      len last  status = 11..11 (all show)
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}