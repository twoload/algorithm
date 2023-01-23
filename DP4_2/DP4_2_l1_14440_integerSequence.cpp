#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// brute force
// one by one : O(n) : n = 10^8 : too big
// -> O(logn) with matrix

// (An) = (x y)^n-1 * (A1)
// (An-1)=(1 0)     * (A0)

// O(8logN) = O(logN)

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;
const int mod = 100;

matrix operator *(const matrix& a, const matrix& b) {
    int n = a.size();
    matrix c = matrix(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j]; // my mistake: = -> +=
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int n) {
    matrix ans = {{1,0},{0,1}};
    while (n > 0) {
        if (n % 2 == 1) {
            ans = a * ans;
        }
        a = a*a;
        n = n/2;
    }
    return ans;
}

void print(int x) {
    if (x < 10)
        cout << 0;

    cout << x << '\n';
}

int main() {
    int x, y, a0, a1, n;
    cin >> x >> y >> a0 >> a1 >> n;
    if (n == 0) {
        print(a0);
    } else if (n == 1) {
        print(a1);
    } else {
        // (An) = (x y)^n-1 * (A1)
        // (An-1)=(1 0)     * (A0)
        matrix m = {{x,y},{1,0}};
        m = pow(m, n-1);
        int ans = m[0][0]*a1 + m[0][1]*a0;
        print(ans%mod);
    }
    return 0;
}