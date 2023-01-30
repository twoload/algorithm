#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// nxm 
//  1<= n <=10^9
//  1<= m <=30
// (i+j)%2 == 0 : black
// (i+j)%2 == 1 : white
// odd row : black -> black
// odd row : white -> white
// even row: black -> white, black
// even row: white -> white, black

// rule:
// odd: 1*1    1*2,.....1*2      1*1
// even 1*1*2  1*2*3    1*2*3    1*1*2
// odd: 

// 1~n -> 0~n-1
// d[i][j] : num of cases at row i, col j
// = d[i-1][j-1] + d[i-1][j+1]  //i-1: even, 0<= j-1, j+1 <=m-1 
// = d[i-1][j-1] + d[i-1][j] + d[i-1][j+1] //i-1: odd, 0<= j-1, j+1 <=m-1

// 1<=n<=10^9 : too big!!! -> matrix!!!
// d[i] = a*d[i-1]
// i: odd, even : two cases

// d[i] = even * d[i-1] // i:even  (all j)
// d[i] = odd  * d[i-1] // i: odd  (all j)

// d[i] = even * odd * d[i-2]
// d[i] = A * d[i-2]

// O(NM) -> O(M^3logN)

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
void print(const char* header, const matrix& a)
{
    printf("%s: \n", header);
    int n = a.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    int n, m;
    cin >> n >> m;
    matrix ans(m, vector<long long>(m));
    matrix even(m, vector<long long>(m));
    matrix odd(m, vector<long long>(m));
    matrix a(m, vector<long long>(m));
    for (int i=0; i<m; i++) {
        ans[i][i] = 1; // identity matrix : E
        odd[i][i] = 1;
        if (i-1 >= 0) {
            odd[i][i-1] = 1;
            even[i][i-1] = 1;
        }
        if (i+1 < m) {
            odd[i][i+1] = 1;
            even[i][i+1] = 1;
        }
    }
#if 0
    print("odd", odd);
    print("even", even);

    odd: 
    1 1 0 0 0 
    1 1 1 0 0 
    0 1 1 1 0 
    0 0 1 1 1 
    0 0 0 1 1 

    even: 
    0 1 0 0 0 
    1 0 1 0 0 
    0 1 0 1 0 
    0 0 1 0 1 
    0 0 0 1 0
#endif
    n -= 1;
    a = even * odd;
    int p = n/2;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = ans * a;
            if (p == 1)
                break;
        }
        a = a * a;
        //print("a", ans);
        p /= 2;
    }
    if (n % 2 == 1) {
        ans = ans * even;
    }
    //print("ans", ans);
#if 0
    3 5
    ans: 
    1 1 1 0 0 
    1 2 1 1 0 
    1 1 2 1 1 
    0 1 1 2 1 
    0 0 1 1 1
    each colume goes independently
#endif
    long long sum = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            sum += ans[i][j];
            sum %= mod;
        }
    }
    cout << sum << '\n';
    return 0;
}
