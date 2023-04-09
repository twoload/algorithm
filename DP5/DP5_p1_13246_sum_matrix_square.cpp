#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// <- sum of square of matrix fast!!!
// s = a^1+a^2+a^3+...a^b
// a^(2q) = (a^q)^2
// a^(2q+1) = a^2q * a
// a^1+a^2+...+a^2q = (E+a^q)*(a^1+a^2+...+a^q)
// a^1+a^2+...+a^(2q+1) = (a^1+a^2+...a^2q)+a^(2q+1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using matrix = vector<vector<int>>;
const int mod = 1000;
// matrix multiply
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));
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
// sum of matrix
matrix operator + (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            c[i][j] %= mod;
        }
    }
    return c;
}
// identity marix
matrix init(int n) {
    matrix a(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        a[i][i] = 1;
    }
    return a;
}
matrix matrix_pow(matrix a, long long k) {
    if (k == 0) {
        return init(a.size()); // a^0 = identity
    } else if (k % 2 == 0) {
        return matrix_pow(a*a, k/2); // even: a^k = (a*a)^(k/2)
    } else {
        return a * matrix_pow(a, k-1); // odd: a^k = a*a^(k-1)
    }
}
// a^1+a^2+a^3+...+a^k
matrix matrix_sum(matrix a, long long k) {
    int n = a.size();
    if (k == 0) {
        matrix ans(n, vector<int>(n)); //0
        return ans;
    }
    // (E+a^(k/2))*(a^1+a^2+...+a^(k/2)) 
    else if (k % 2 == 0) { 
        return (init(n) + matrix_pow(a, k/2)) * matrix_sum(a, k/2);
    }
    // a^1+a^2+..+a^(k-1) + a^k
    // matrix_sum(a, k-1) + matrix_pow(a, k)
    else {
        return matrix_sum(a, k-1) + matrix_pow(a, k);
    }
}
void print(const matrix &a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    int n; long long k;
    cin >> n >> k;
    matrix a(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    // O(logk)
    matrix ans = matrix_sum(a, k);
    print(ans);
    return 0;
}
