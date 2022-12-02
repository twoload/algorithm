#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// A^B
// % 1000
// c = nxm
//   = sum(a[i][k] * b[k][j])
//   N = max(n,r,m) > O(N^3) : N should <= 500

// size: NxN
// A^2B = A^B * A^B
// A^(2B+1) = A^B * A*2B
// > O(logB) : count of multiply
// * O(N^3)
// = O(N^3*logB)

#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));
    for (int i=0; i<n; i++) { 
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) { // O(N^3)
                c[i][j] += a[i][k] * b[k][j]; // multiply of matrix
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}
int main() {
    int n;
    long long b;
    cin >> n >> b;

    matrix ans(n, vector<int>(n));
    matrix a(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
        // unit matrix (1 0 / 0 1) > anss
        ans[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 == 1) {
            // only ans is updated here
            ans = ans * a; // operator *
        }
        // update a, b
        a = a*a;
        b /= 2;
    }

    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
