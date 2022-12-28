#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;
using matrix = vector<vector<long long>>;
matrix operator * (const matrix & a, const matrix &b) {
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
int main() {
    int n, m;
    cin >> n >> m;
    matrix ans(m, vector<long long>(m));
    matrix even(m, vector<long long>(m));
    matrix odd(m, vector<long long>(m));
    matrix a(m, vector<long long>(m));
    // 0 ~ m-1
    for (int i=0; i<m; i++) {
        ans[i][i] = 1; // identity matrix
        odd[i][i] = 1;        // odd
        if (i-1 >= 0) {
            odd[i][i-1] = 1;  // odd
            even[i][i-1] = 1;    // even
        }
        if (i+1 < m) {
            odd[i][i+1] = 1;  // odd
            even[i][i+1] = 1;    // even
        }
    }
    n -= 1; // 0 ~ n-1
    // first row (odd)
    //       / \ (even)
    //      /|\/|\ (odd)
    // a = even * odd
    a = even * odd;
    int p = n/2;
    // n =1 > 0 > p = 0 > 
    // n =2 > 1 > p = 0 > n%2 == 1 > even
    // n =3 > 2 > p = 1 > even*odd
    // n =4 > 3 > p = 1 > even*odd > n%2==1 > even
    // ...
    while (p > 0) {
        if (p % 2 == 1) {
            ans = ans *a;
        }
        a = a*a;
        p /= 2;
    }
    if (n % 2 == 1) {
        ans = ans * even;
    }
    long long sum = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            //printf("%d ", ans[i][j]);
            sum += ans[i][j];
            sum %= mod;
        }
        //printf("\n");
    }
    cout << sum << '\n';
#if 0
    cout << "odd" << '\n';
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", odd[i][j]);
        }
        printf("\n");
    }
    cout << "even" << '\n';
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", even[i][j]);
        }
        printf("\n");
    }
#endif
    return 0;
}