#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[n] = num of way that represents n with 1,2,3
//        same number should not be used in series

// d[i][j] = i number, last number: j
//     d[i][1] = d[i-1][2] + d[i-1][3]
//     d[i][2] = d[i-2][1] + d[i-2][3]
//     d[i][3] = d[i-3][1] + d[i-3][2]

#include <stdio.h>
long long d[1000001][4];
const long long mod = 1000000009LL;
const int limit = 100000;
int main() {
    for (int i=1; i<=limit; i++) {
        if (i-1 >= 0) {
            d[i][1] = d[i-1][2] + d[i-1][3];
            if (i == 1) {
                d[i][1] = 1;
            }
        }
        if (i-2 >= 0) {
            d[i][2] = d[i-2][1] + d[i-2][3];
            if (i == 2) {
                d[i][2] = 1;
            }
        }
        if (i-3 >= 0) {
            d[i][3] = d[i-3][1] + d[i-3][2];
            if (i == 3) {
                d[i][3] = 1;
            }
        }
        d[i][1] %= mod;
        d[i][2] %= mod;
        d[i][3] %= mod;
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n",(d[n][1] + d[n][2] + d[n][3])%mod);
    }
}