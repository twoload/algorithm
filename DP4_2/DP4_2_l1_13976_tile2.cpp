#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 3xn : 2x1, 1x2
// n = 1'000'000'000'000'000'000

// row, col change nx3 (m=3)
// dp
//  d[i][j] : num of case tiling at pos i, status j
//            j : status of i~i+m-1
//          i/m = r, r%m = c
//          2x1 ->
//              i&1 == 0
//              r+1 < n
//              d[i+1][j>>1 | 1<<(m-1)]
//          1x2 ->
//              i&1 == 0, i&2 == 0
//              c+1 < m
//              d[i+2][j>>2]
//  d[n*3][2^m-1]

// teacher
// 2133 tile : O(N) : d[i][j] = fill 3*i at i-state:j
// but N is too big!!!
// pibonacci
//   d[i] = d[i-1] + d[i-2]
//     d[0] = 1
//     d[1] = 1
//     d[i]   = (1 1)(d[i-1])
//     d[i-1]   (1 0)(d[i-2])

//     d[i-1] = (1 1)(d[i-2])
//     d[i-2]   (1 0)(d[i-3])

//     d[i]   = (1 1)(1 1)(d[i-2])... = (1 1)^i-1
//     d[i-1]   (1 0)(1 0)(d[i-3])      (1 0)
//     matrix : n*n ^k
//              n^3 log k

//   d[i][0] = [0 0 0 0 0 0 0 1] d[i-1][0]
//   d[i][1] = [0 0 0 0 0 0 1 0] d[i-1][1]
//   d[i][2] = [0 0 0 0 0 1 0 0] d[i-1][2]
//   d[i][3] = [0 0 0 0 1 0 0 1] d[i-1][3]
//   d[i][4] = [0 0 0 1 0 0 0 0] d[i-1][4]
//   d[i][5] = [0 0 1 0 0 0 0 0] d[i-1][5]
//   d[i][6] = [0 1 0 0 0 0 0 1] d[i-1][6]
//   d[i][7] = [1 0 0 1 0 0 1 0] d[i-1][7]


#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;
// matrix multiply
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

    if (n%2 == 1) { // because it's not even (1x2, 2x1)
        cout << 0 << '\n';
        return 0;
    }

    matrix ans = vector<vector<long long>>(8, vector<long long>(8));
    matrix a = vector<vector<long long>>(8, vector<long long>(8));

    for (int i=0; i<8; i++) { //2^3 = 8 (0,1,2,....7)
        ans[i][i] = 1; // identity matrix
    }

//d[i][j] = fill 3*i at i-state:j
//   d[i][0] = [0 0 0 0 0 0 0 1] d[i-1][0]
//   d[i][1] = [0 0 0 0 0 0 1 0] d[i-1][1]
//   d[i][2] = [0 0 0 0 0 1 0 0] d[i-1][2]
//   d[i][3] = [0 0 0 0 1 0 0 1] d[i-1][3]
//   d[i][4] = [0 0 0 1 0 0 0 0] d[i-1][4]
//   d[i][5] = [0 0 1 0 0 0 0 0] d[i-1][5]
//   d[i][6] = [0 1 0 0 0 0 0 1] d[i-1][6]
//   d[i][7] = [1 0 0 1 0 0 1 0] d[i-1][7]
    // matrix
    a[0][7] = 1;
    a[1][6] = 1;
    a[2][5] = 1;
    a[4][3] = 1;
    a[3][4] = a[3][7] = 1;
    a[6][1] = a[6][7] = 1;
    a[5][2] = 1;
    a[7][0] = a[7][3] = a[7][6] = 1;

    // n = 1 , ans = ans * a -> filter out upper
    // n = 2 , ans = ans * (a*a)
    // n = 3 , ans = ans * a -> filter out upper
    // n = 4 , ans = ans * (a*a*a*a)
    n = n-1; // modified
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
            if (n == 1)
                break;
        }
        a = a * a;
        n /= 2;
    }
#if 0
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%02d ", ans[i][j]);
        }
        printf("\n");
    }
#endif
    long long sum = 0;
    for (int i=0; i<7; i++) {
        //sum += ans[0][i]; // 
        sum += ans[7][i]; // 
    }

    sum %= mod;

    cout << sum << '\n';

    return 0;
}