#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// previous problem : 3xn
// curr : nxm
// n state
// d[i][j] : num of ways which i position, next state j
//     d[i+1][j'] : i=O (2x1)
//            j'[0]=1
//     d[i+1][j'] : i=O (1x2)
//            j'[n-1]=1
//     d[i+1][j'] : i=x 

// teacher
// column i, i-1
// n*2^2m (like cunning problem) (1<=n,m<=14) too big!

// nm*2^m
// d[num][s] : case num of (fill num empty space. num ~ (num+m-1) status = s)
// row-major order

// row\col 0   1  2  3  4  5
// 0       0   1  2  3  4  5
// 1       6  (7*  8  9 10 11   : 7(cur), (7~12 : status)
// 2       12) 13 14 15 16 17
// ex. s = 4: 000100 -> 9(fill)
// ex. s = 5: 000101 -> 7,9(fill)

// i can't put block: 0-th bit (s&1)==1
//   num -> num+1
//   s -> s>>1
// i can put block (1x2)
//   s&1 == 0, s&2 == 0  (1x2 should be empty)
//   check if the righest block
//   num -> num+2
//   s -> s>>2
// i can put block (2x1)
//   s&1 == 0, 
//   num -> num+1
//    s -> (s >> 1) | (1<<(m-1))
//   in n*m, status should be 0 (if is not 0, incorrect)

// O(nm*2^m)

#include <iostream>
#include <cstring>
using namespace std;
int d[14*14][1<<14]; // 1<=n,m<=14
int n,m;
int go(int num, int state) {
    if (num == n*m && state == 0) { //last position
        return 1;
    }
    if (num >= n*m) {
        return 0;
    }
    if (d[num][state] >= 0) { //memoization
        return d[num][state];
    }
    int &ans = d[num][state];
    ans = 0;
    if (state & 1) { // occupied
        ans = go(num+1, (state >> 1));
    } else { // empty
        ans = go(num+1, (state >> 1) | (1 << (m-1))); // 2x1
        if ((num%m) != (m-1) && (state & 2) == 0) { // 1x2 (not right end, 1x2 empty)
            ans += go(num+2, (state >> 2));
        }
    }
    ans %= 9901;
    return ans;
}
int main() {
    cin >> n >> m;
    memset(d,-1,sizeof(d));
    cout << go(0, 0) << '\n';
    //         num state
    return 0;
}