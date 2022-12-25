#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n (1<= n <= 10^18) Too Big!!!
// k (0<= k <= 10)

// matrix multiply + DP ???

// a[n][m] 
// a[i][j] = b[i*m + j]  

// a[n][m][l]
// a[i][j][k] = b[i*ml + jl + k]


// d[n][a][b][c]
//     [a][b][c] = k x 2 x 2 [state]
// matrix multiply (logN)

// d[n][a][b][c]
// = d2[n][state_map[a][b][c]]

#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;
using matrix = vector<vector<long long>>;
// matrix multiply
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
int state_map[10][2][2];
int main() {
    long long n;
    int k;
    cin >> n >> k;
    int kk = max(k, 1); // if k==0, kk = 1, else k = kk
    int state_num = 0;
    // 3 dimension > 1 dimension
    for (int a=0; a<kk; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                state_map[a][b][c] = state_num++;
            }
        }
    }
    int size = kk * 2 * 2;
    matrix ans(size, vector<long long>(size));
    matrix mat(size, vector<long long>(size));
    // identity matrix
    for (int i=0; i<size; i++) {
        ans[i][i] = 1;
    }
    for (int a=0; a<kk; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                int state = state_map[a][b][c];
                if (k > 0) { // A solve
                    mat[state][state_map[(a+1)%k][0][c]] += 1;
                }
                if (b == 0) {// B solve
                    mat[state][state_map[a][1][c]] += 1;
                }
                // C solve
                mat[state][state_map[a][0][1]] += 1;
            }
        }
    }
    // matrix multiply
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * mat;
        }
        mat = mat*mat;
        n /= 2;
    }
    long long sum = ans[0][state_map[0][0][1]] + ans[0][state_map[0][1][1]];
    sum %= mod;
    cout << sum << '\n';
    return 0;
}
