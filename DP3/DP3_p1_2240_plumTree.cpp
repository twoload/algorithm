#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// T, W
// t : turn (1<=n<=1000)
// w : movement (1<=w<=30)

// brute force 
//  2^n (2^1000) : too big

// d[n][p][w] where, n: turn, p:cur pos = 0/1, w:movement count
//  bottom-up
//    move O : d[n+1][(p+1)%2][w+1]
//    move X : d[n+1][(p+1)%2][w]
//  top-down
//    move O : d[n-1][(p+1)%2][w-1]
//    move X : d[n-1][(p+1)%2][w]

// if you know w, you can know p
// 0 : tree 1
// 1 : tree 2
// ...
// d[sec][turn] : max plum num that you can get at sec with turn
//   cur pos = turn%2 + 1
// move x : (sec,turn) -> (sec+1, turn)
// move O : (sec,turn) -> (sec+1, turn+1)
// where = turn%2 + 1
// +1 a[sec] == where else +0

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10001];
int d[10001][31];
int n,m;
int go(int pos, int turn) {
    if(pos == n+1 && turn <= m) {
        return 0;
    }
    if (turn > m) {
        return 0;
    }
    if (d[pos][turn] != -1) { // memoization
        return d[pos][turn];
    }
    int where = turn % 2 + 1;
    int &ans = d[pos][turn];
    // max(turn o, turn x) + +1/+0(according to cur pos)
    ans = max(go(pos+1, turn), go(pos+1, turn+1)) + (where == a[pos] ? 1 : 0);
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    memset(d, -1, sizeof(d));
    printf("%d\n", max(go(1,0), go(1,1))); // 1sec+tree1, 1sec+tree2(mov)
    return 0;
}