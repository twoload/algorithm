#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
# ref. https://xy-plane.tistory.com/14
#endif

// N : num of people (2<= N <= 200)
// K : K-th (1<= K <= 1'000'000)
// M : a, b = start a, end b is possible ? or not ?

// a -> b path's length is k or less ?

// A[i][j] : i->j num of edges 
// A^k[k][j] : i->j pass num k edges

// matrix power

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<bool>> matrix;
matrix operator *(const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<bool>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (a[i][k] && b[k][j])
                    c[i][j] = true; // count -> T/F (possible)
            }
        }
    }
    return c;
}
matrix pow(matrix a, int m) {
    int n = a.size();
    matrix ans(n, vector<bool>(n)); // 2 dimensional vector
    for (int i=0; i<n; i++) ans[i][i] = true; // identity matrix
    while (m > 0) {
        if (m % 2 == 1) {
            ans = ans * a;
        }
        a = a*a;
        m /= 2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    matrix a(n, vector<bool>(n));
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[i][x-1] = true; // index start:0~  [x-1]
        a[i][y-1] = true; // index start:0~  [y-1]
    }
    matrix ans = pow(a, k);
    while (m--) { // num of testcases
        int x, y;
        cin >> x >> y;
        if (ans[x-1][y-1]) {
            cout << "death" << '\n';
        } else {
            cout << "life" << '\n';
        }
    }
    return 0;
}