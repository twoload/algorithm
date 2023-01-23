#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// N x M
// 2x1 
// max cost 

//2x1, 1x2
// brute force
// 2^NM
// 1<=N,M<=14

// dp
// d[i][j] : max cost at row i, state j
// k = 0~13
// i -> i-1
// 1x2 + a[i][k] + a[i][k+1]
// 2x1 d[i-1][j | (1<<k)] + a[i][k]
// 
// O(n*2^m*k)

// teacher
// + way not to put tile (*)
// m state

#include <iostream>
#include <cstring>
using namespace std;
char a[20][20]; // 1<=n,m<=14
// d[num][state]
int d[14*14][1<<14];
int n,m;
int score[6][6] = {
    {10,8,7,5,0,1},
    {8,6,4,3,0,1},
    {7,4,3,2,0,1},
    {5,3,2,2,0,1},
    {0,0,0,0,0,0},
    {1,1,1,1,0,0}
};
int calc(char x, char y) {
    return score[x-'A'][y-'A'];
}
int go(int num, int state) {
    if (num >= n*m) { // finish
        return 0; // init value = 0
    }
    if (d[num][state] >= 0) { // memoization
        return d[num][state];
    }
    int &ans = d[num][state];
    ans = 0;
    int x = num/m; // row
    int y = num%m; // col
    ans = go(num+1, (state >> 1)); // pass (not to put)
    if ((state & 1) == 0) { // empty
        if (x != n-1) {
            // 2x1
            int temp = go(num+1, (state >> 1) | (1 << (m-1)));
            temp += calc(a[x][y], a[x+1][y]);
            ans = max(ans, temp);
        }
        // check right end
        // 1x2
        if (y != m-1 && (state & 2) == 0) {
            int temp = go(num+2, (state >> 2));
            temp += calc(a[x][y], a[x][y+1]);
            ans = max(ans, temp);
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(d,-1,sizeof(d));
    cout << go(0, 0) << '\n';
    return 0;
}
