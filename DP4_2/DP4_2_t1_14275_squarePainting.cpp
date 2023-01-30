#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n x m
// (1<= n <=100)
// (1<= m <= 8)

// d[n][s] : n = row, s = state
//      = sum(d[n-1][ps]) , ps = pstate
// check
//      cur position : (i,j)
//      left:  (i,j-1)
//      right: (i,j+1)
//      up  :  (i-1,j)
//      down:  (i+1,j)
// O(n*2^m*m)

// teacher
// 0: color, num of colored adj : even
// 1: color, num of colored adj : odd
// 2: no color
// O(nm*3^m) : all nxm, state: 3^m

#include <iostream>
#include <cstring>
using namespace std;
int n, m;
long long d[100*8][19683]; //3^9 = 19683
const long long mod = 1000000007;
long long pow3[9];
// 0: colored(even), 1: colored(odd), 2: empty
long long go(int num, int state) {
    if (num == n*m) { // finish
        while (state > 0) {
            if (state % 3 == 1) return 0; // ng (odd)
            state /= 3;
        }
        return 1; // (ok empty or colored) 
    }
    long long &ans = d[num][state]; // memoization
    if (ans != -1) return ans;
    ans = 0;
    int up = (state/pow3[m-1]) % 3; 
    int left = (state/pow3[0]) % 3; // state%3
    int cleft = 2; // left + colored
    if (left == 0) {
        cleft = 1;
    } else if (left == 1) {
        cleft = 0;
    }
    int cur = 0;
    if (left != 2) {
        cur = 1;
    }
    if (num%m == 0) { // left-most
        cleft = left;
        cur = 0;
    }
    // [m-1] [m-2] ... [1] [0]
    // up                  left
    // next
    // 0     [m-2] ... [1] 0
    // <<3
    // [m-2] [m-3] ... 0   cur
    // [m-2] [m-3] ... update cur
    int nstate = (state-up*pow3[m-1] - left*pow3[0]) * 3;
    if (up == 2) { // up: empty
        // cur: empty
        ans += go(num+1, nstate + left*pow3[1] + 2);
        // cur: colored
        ans += go(num+1, nstate + cleft*pow3[1] + cur);
    } else { // up: colored
        cur = 1-cur; // if left exists, cur =0, if no left, cur = 1
        if (up == 0) { // up: even
            // cur: empty
            ans += go(num+1, nstate + left*pow3[1] + 2);
        } else { // up: odd
            // cur: colored
            ans += go(num+1, nstate + cleft*pow3[1] + cur);
        }
    }
    ans %= mod;
    return ans;
}
int main() {
    cin >> n >> m;
    pow3[0] = 1;
    for (int i=1; i<=m; i++) {
        pow3[i] = pow3[i-1] * 3;
        pow3[i] %= mod;
    }
    int state = 0;
    for (int i=0; i<m; i++) {
        state = state * 3 + 2;
    }
    // 2222...2 =all empty (3) 1111...1 (2)
    memset(d,-1,sizeof(d));
    cout << go(0, state) << '\n';
    return 0;
}
