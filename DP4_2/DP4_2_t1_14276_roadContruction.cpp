#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : num of houses  (1<= n <=30)
// m : num of roads   (1<= m <=30)
// k : road range  (1<= k <=8)
// all houses 

// brute force
// 1 road: (n*n)
// m road: (n*n)^m (+min road distance check)
//       = 900^30


// d[n][m] = case num at n houses, m roads 
//           s = road connection state
//               ???

// teacher
// all houses should be adjacent to even roads
//     even: 0
//     odd : 1
//     -> bitmask
//        2^30 : too big!!!
//        k
//        2^(k+1) : 0<|A-B|<=k only important
//
//   i-k...   i-2   i-1    i
//                   \----/
//             \----------/ 
//   <-------state-------->
//
// d[i][j][state] : we connect the house from the upper
//     we're trying to connect i-th house
//     (until i-1 th all roads are connected)
//     now j roads are connected
//     i-th house ~ k houses road connection state = state (0:even,1:odd)
// but, 1 2 3
//      2-3 > 1-3
//      1-3 > 2-3 should be differentiated but d[i][j][state] cannot differentiate



#include <iostream>
#include <cstring>
using namespace std;
const long long mod = 1000000007;
// d[i][j][cur][state]
//     we're trying to connect i-th house
//     (until i-1 th all roads are connected)
//     now num of j roads are connected
//     now I'm considering the connection i and (i-(cur+1)).
//     i-th house ~ k houses road connection state = state (0:even,1:odd)
// d[i][j][cur][state]
//      now I'm considering the connection i and (i-(cur+1)).
//      1 2 3 4 (k=3)
//          \-/
//        \---/
//      \-----/
// cur: 2 1 0
// 1<=n<=30, 0<=m<=30, 1<=k<=8
long long d[30][31][9][1<<9]; 
int n, m, k;
// 0,0,0,0 -> 0-th house, num of road:0, cur:0, state:0
long long go(int i, int j, int cur, int state) {
    if (i == n) { // finished (n-th houses)
        // num of road == m
        // state == 000000000(even) : i-k+1 ~ i houses have even neightbors.
        // cur == 0 (because we can go next only when cur==0)
        if (j == m && cur == 0 && state == 0/*even*/) return 1; //ok
        else return 0; //ng
    }
    // finished (cur) if k==3, cur=0,1,2 (3==finished)
    // state
    if (cur == k) {
        //    (1 2 3 4)
        //cur: 2 1 0
        //k  : 3
        //     1(2 3 4 5)
        //check if 1's neighbors are even
        if ((state & (1<<k)) == 0) { 
            return go(i+1, j, 0, (state<<1)); //next cur = 0
            //        1 2 3 4
            // state: 0 0 1 1     0011(2)
            //          2 3 4 5
            // state:   0 1 1 0   0110(2) = 0011(2)<<1
        } else {
            return 0; // ng
        }
    }
    long long &ans = d[i][j][cur][state]; //memoization
    if (ans != -1) return ans;
    ans = go(i, j, cur+1, state); // until cur==k-1 (only cur will change)

    // i:              1 2 3 4  i=4
    // cur:            2 1 0    k=3
    // i-(cur+1)             0  (possible at n==4)
    // i:              1
    // i-(cur+1) : <0 = out of range (impossible at n==1)
    if (i-(cur+1) >= 0 && j+1 <= m/*num of roads*/) { //out of range of i, j
        // connect between i and cur
        // j -> j+1
        //        1 2 3 4
        // state: 1 0 0 0     1000(2) j
        // next : 1 1 0 1     1101(2) j+1
        // cur  : 2 1 0
        //          -
        //        1000 -> 1101
        //                 - -
        //      (1<<(cur+1)) (1<<0)  _
        ans += go(i, j+1, cur, (state^(1<<0)^(1<<(cur+1)))); //^ = XOR (0->1, 1->0)
    }
    ans %= mod;
    return ans;
}
int main() {
    cin >> n >> m >> k;
    memset(d,-1,sizeof(d));
    cout << go(0, 0, 0, 0) << '\n';
}
