#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n = 10^18
// mod = 1000000007

// d[i][s] = way num that print 3*i 
//           i-th col state : s
//           i-1 col : all painted

/*
 * d[i][0] = d[i-1][7]
 * d[i][1] = d[i-1][6]
 * d[i][2] = d[i-1][5]
 * d[i][4] = d[i-1][3]
 * d[i][3] = d[i-1][4] + d[i-1][7]
 * d[i][6] = d[i-1][1] + d[i-1][7]
 * d[i][5] = d[i-1][2]
 * d[i][7] = d[i-1][0] + d[i-1][3] + d[i-1][6]
 * ans = d[n][7]
 * d[0][7] = 1 (way num : 1)
 */

/**
 * state: 0,   1,   2,   3,   4,   5,   6,   7
 *        000, 001, 010, 011, 100, 101, 110, 111
 * d[i][0]  [0 0 0 0 0 0 0 1][d[i-1][0]]
 * d[i][1]  [0 0 0 0 0 0 1 0][d[i-1][1]]
 * d[i][2]  [0 0 0 0 0 1 0 0][d[i-1][2]]
 * d[i][3]  [0 0 0 0 1 0 0 1][d[i-1][3]]
 * d[i][4] =[0 0 0 1 0 0 0 0][d[i-1][4]]
 * d[i][5]  [0 0 1 0 0 0 0 0][d[i-1][5]]
 * d[i][6]  [0 1 0 0 0 0 0 1][d[i-1][6]]
 * d[i][7]  [1 0 0 1 0 0 1 0][d[i-1][7]]
 * 
 * O(i^3logK)
 */

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
int main() {
    long long n;
    cin >> n;
    if (n%2 == 1) { // odd 3*odd = odd (can't print with 2x1 tile)
        cout << 0 << '\n';
        return 0;
    }

    matrix ans = vector<vector<long long>>(8, vector<long long>(8));
    matrix a = vector<vector<long long>>(8, vector<long long>(8));

    for (int i=0; i<8; i++) {
        ans[i][i] = 1; // identity matrix
    }
    // matrix
    a[0][7] = 1;
    a[1][6] = 1;
    a[2][5] = 1;
    a[4][3] = 1;
    a[3][4] = a[3][7] = 1;
    a[6][1] = a[6][7] = 1;
    a[5][2] = 1;
    a[7][0] = a[7][3] = a[7][6] = 1;

    // if n == 2,
    //    ans = a*a
    //    what I want was a*1
    //    so, sum of ans[0][i] is needed
    //    because ans[0] : all empty is needed
    // in another solution,
    //    if n == 2,
    //       if ans = a*1
    //       sum of ans[7][i] is needed
    //       because ans[7] : all occupied is needed 

    //n = n-1; // I've added 
    while (n > 0) {
        if (n % 2 == 1) {
            ans = a * ans;
        }
        a = a*a;
        n /= 2;
    }
    
    // d[i][0-7] = a^(n-1)*d[0][0-7]
    //           = ans[i][0-7]
    long long sum = 0;
    for (int i=0; i<7; i++) {
        sum += ans[0][i];  // answer ? 
        //sum += ans[7][i];  // I've added
    }
    sum %= mod;
    cout << sum << '\n';

#if 0
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
#endif


    return 0;
}
