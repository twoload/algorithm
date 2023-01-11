#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n x m square coloring
// brute force : 2^(n*m) , n=1~100, m=1~8
// 0,1 -> bitmask

// if any point is colored, m points are affected ???
// state
// 0 : colored, adjacent points are even
// 1 : colored, adjacent points are odd
// 2 : not colored (empty)

#include <iostream>
#include <cstring>
using namespace std;
int n, m;
// d[num][state]
//   num = n*m = 100*8, state=3^8
long long d[100*8][19683]; // 19683 ? =3^9
const long long mod = 1000000007;
long long pow3[9]; // 0~8
// 0: colored(even), 1: colored(odd), 2: empty
long long go(int num, int state) {
    //   -------
    //   |  |  | 
    //   -------
    //   |  |  |  state should not have 1 (odd), 
    //   -------        but 0(even),2(empty) are ok
    //   |v |     when end at ending point v,
    //   ----
    if (num == n*m) {
        while (state > 0) {
            if (state % 3 == 1) return 0;
            state /= 3;
        }
        return 1;
    }
    long long &ans = d[num][state]; // memoization
    if (ans != -1) return ans;
    ans = 0;

    //   -------
    //   |  | U| 
    //   -------
    //   |L | V|  state = U(0,1,2) L(0,1,2)   
    //   -------    U = (state/2^(m-1))%3
    //              L = (state/2^0)%3
    int up = (state/pow3[m-1]) % 3;
    int left = (state/pow3[0]) % 3;
    int cleft = 2; // left + colored
    if (left == 0) { // even
        cleft = 1;   // -> odd
    } else if (left == 1) { // odd
        cleft = 0;   // -> even
    }
    int cur = 0;
    if (left != 2) { // not empty
        cur = 1;     // odd
    }
    if (num%m == 0) { // left-most
        cleft = left; // not change
        cur = 0; // even
    }
    // nstate : (state - up - left)*3 // *3 == <<1 
    //   -------------
    //   |  |  |U |?'|
    //   -------------
    //   |? |L |V |  |  
    //   -------------    
    //   state    = U(0,1,2) ? ? L(0,1,2)
    //   -------------
    //   |  |  |? |?'|
    //   -------------
    //   |? |CL|cur|V |  
    //   -------------  
    //   nstate   = 0(0,1,2) ?' ? 0(0,1,2)
    //   nstate*3 = ?' ? 0(0,1,2) 0
    //   nstate*3+CL+cur = ?' ?  CL cur       

    int nstate = (state-up*pow3[m-1] - left*pow3[0]) * 3;
    if (up == 2) { // up: empty
        // cur: empty
        ans += go(num+1, nstate + left*pow3[1] + 2/*cur=empty*/);
        // cur: colored
        ans += go(num+1, nstate + cleft*pow3[1]/*left change*/ + cur);
    } else { // up: colored
        // 0(even)->1(odd), 1(odd)->0(even)
        // because up is colored
        cur = 1-cur; 
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
        // pow3[0]=1, [1]=3, [2]=9, [3]=27, [4]=81, 
        // [5] = 243, [6] = 729, [7] = 2187 [8]=6561
        pow3[i] = pow3[i-1] * 3;
        pow3[i] %= mod;
    }
    int state = 0;
    for (int i=0; i<m; i++) {
        // [0] 2 (3-1), [1] 8 (3^2-1), [2] 26 (3^3-1), [3] 80 (3^4-1)
        // [4] 242, [5] 728, [6] 2186 [7] 6560 
        state = state * 3 + 2;
    }
    memset(d, -1, sizeof(d));
    // ex. 2 2
    //
    //   (2 |2 ) state = 22(3) (2 means empty)
    //                 = 2*3 + 2
    //                 = init state of empty 
    //   -------
    //   |v |  | when start at starting point v,
    //   -------
    //   |  |  |
    //   -------
    cout << go(0, state) << '\n';
    return 0;
}