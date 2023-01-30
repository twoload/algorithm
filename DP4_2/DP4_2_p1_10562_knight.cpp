#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// T : T<=10
// M, N : board
// (1<=M<=4)
// (1<=N<=10^9)

// M<->N change
// dp
// d[n] = case num at row n
// d[n][state] at row n, state
//     =  d[n-1][pstate]
//       +d[n-2][ppstate]  
// row i, col j
//     (i-2, j+1), (i-2, j-1)
//     (i-1, j+2), (i-1, j-2)

// d[0][0000~1111] = 1 (all 1)
// d[1][0000~1111]
//     (i-1, j+2), (i-1, j-2) 
// d[2][0000~1111]
//     (i-2, j+1), (i-2, j-1)
//     (i-1, j+2), (i-1, j-2)
// state = a*pstate = a*b*ppstate
// state = (a*b)^k  sum of all
// state = (a*b)^k * b

// O(2^3logn)

// teacher
// d[n][s] : case num of (filled until n row and last two row's state = s)
//      1<<2M
// d[n][s] = sum (d[n-1][s'])
//           a = 2^2m * 2^2m
// d[n] = a*d[n-1]

#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000009LL;
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


int dx[] = {1, -1, 2, -2};
int dy[] = {0,  0, 1,  1};
//             ---------
// state:    |*| |*| | | (0,-1), (0, 1) 
//             ---------
//         |*| | | |*| | (1,-2), (1, 2)
//             ---------
// next :      |*| | | |
//             ---------
// n : 
matrix make(int n, int m) { 
    auto on = [&](int state, int row, int col) {
        return state & (1 << (row*m+col)); // isset 
    };
    auto possible = [&](int state, int next) {
        for (int i=0; i<m; i++) { 
            if (!on(next, 0, i)) { // check if next has i column 
                continue;
            }
            for (int k=0; k<4; k++) { 
                if (i+dx[k] < 0 || i+dx[k] >= m) 
                    continue; // out of range
                if (on(state, dy[k], i+dx[k])) {
                    return false; 
                }
            }
        }
        return true;
    };
//             cur state    next state
//             ---------
// state:      |0|1|2|3| 
//             ---------      ---------
//             |4|5|6|7|   -> |4|5|6|7|  
//             ---------      ---------
// next :      |8|9|10|11| -> |8|9|10|11|
//             ---------      ---------
// state: 76543210 >> 4 = 7  6  5  4
//                       [3][2][1][0]
// next : 111098 << 4    11 10  9  8
//                       [7][6][5][4]

// if example is m=1 n=2,
//    state  | | | | |
//           | | | | |
//    next   |*|*|*|*|
//    because state is empty, there is no problem
//    next state
//           | | | | |
//           |*|*|*|*|
//    next   |-|-|-|-|
//    next state
//           |*|*|*|*|
//           |-|-|-|-|
    int states = (1 << 2*m); 
    matrix adj = matrix(states, vector<long long>(states));
    for (int i=0; i<states; i++) { // all states
        for (int j=0; j<(1<<m); j++) { // next row
            if (possible(i, j)) {
                int k = (i >> m) | (j << m); // next states
                adj[i][k] = 1; //states -> next states
            }
        }
    }
    return adj;
}
matrix pow(matrix a, int n) {
    int m = a.size();
    matrix ans = matrix(m, vector<long long>(m));
    for (int i=0; i<m; i++) {
        ans[i][i] = 1; //identity matrix
    }
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n; // 1<= m <=4, 1<= n <= 10^9
        //      m = column (4) 
        //      ----
        // n    ||||
        // 10^9 ||||
        // row  |
        //      |
        //      |
        //      |

        matrix adj = make(n, m);
        print("adj", adj);
        matrix ans = pow(adj, n);
        print("ans", ans);
        long long sum = 0;
        for (int i=0; i<(1<<(2*m)); i++) {
            sum = (sum + ans[0][i]) % mod; //state:0 -> next_state: all
        }
        cout << sum << '\n';
    }
    return 0;
}


#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000009LL;
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
int dx[] = {-2,-1,1,2};
int dy[] = {1,0,0,1};
matrix make(int n, int m) {
    auto on = [&](int state, int col, int row) {
        return state & (1 << (col*n+row));
    };
    auto possible = [&](int state, int next) {
        for (int i=0; i<n; i++) {
            if (!on(next, 0, i)) continue;
            for (int k=0; k<4; k++) {
                if (i+dx[k] < 0 || i+dx[k] >= n) continue;
                if (on(state, dy[k], i+dx[k])) return false;
            }
        }
        return true;
    };
    int states = (1 << 2*n);
    matrix adj = vector<vector<long long>>(states, vector<long long>(states));
    for (int i=0; i<states; i++) {
        for (int j=0; j<(1<<n); j++) {
            if (possible(i, j)) {
                int k = (i >> n) | (j << n);
                adj[i][k] = 1;
            }
        }
    }
    return adj;
}
matrix pow(matrix a, int m) {
    int n = a.size();
    matrix ans = vector<vector<long long>>(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        ans[i][i] = 1;
    }
    while (m > 0) {
        if (m % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        m /= 2;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        matrix adj = make(n, m);
        matrix ans = pow(adj, m);
        long long sum = 0;
        for (int i=0; i<(1<<(2*n)); i++) {
            sum = (sum + ans[0][i]) % mod;
        }
        cout << sum << '\n';
    }
    return 0;
}
#endif