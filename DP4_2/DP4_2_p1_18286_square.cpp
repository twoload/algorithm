#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n*m
// 1<=n<=10^18
// 1<=m<=5

// dp
// d[n], case num of painting at n= 0~NM-1 : too big!!!
// d[n][s], at s=state, n row
// (* *) * *
// (* *) * *
//  * *  * *
// d[1][2^5] += d[0][s'],,, (about all s')
// matrix 2^5 x 2^5
// d[n-1][state] = matrix^n-1 * d[0][s']

// teacher
// d[row][state] : num of ways which row's state == state
// d[row][state] = sum(d[row-1][pstate])


#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;
using matrix = vector<vector<long long>>;
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
int isset(int state, int index) {
    if (state & (1 << index)) {
        return 1;
    } else {
        return 0;
    }
}
bool ok(int pstate, int state, int m) { // m: column
    for (int i=0; i<m-1; i++) {
        int color11 = isset(pstate, i);
        int color12 = isset(pstate, i+1);
        int color21 = isset(state, i);
        int color22 = isset(state, i+1);
        if (color11 == color12 && color12 == color21 && color21 == color22) {
            return false; //2x2: all same color
        }
    }
    return true;
}
int main() {
    long long n;
    int m;
    cin >> n >> m;
    int size = (1<<m); //max:2^5
    matrix ans(size, vector<long long>(size));
    matrix a(size, vector<long long>(size));
    for (int i=0; i<size; i++) { //0..2^5-1
        ans[i][i] = 1; // identity matrix
        for (int j=0; j<size; j++) { //0..2^5-1
            if (ok(i, j, m)) { //i: pstate, j:state
                a[i][j] = 1;   // pstate -> state : state = a*pstate
            }
        }
    }
    n -= 1; // 0~n-1 : n->n-1
    while (n > 0) { // pow of matrix
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }
    // O(m^3*logn)
    long long sum = 0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            sum += ans[i][j]; // state i->j (all cases)
            sum %= mod;
        }
    }
    cout << sum << '\n';
    return 0;
}
