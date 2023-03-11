#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1<= n <= 1000
// d: street lamp's location
// w: power consumption

// ----------------------------------
//d    3         11  12  13  15  17
//w    2         10  18  19  15  19
//                            *
// (19+19+18+10+2) + (19+18+10+2)*2 + (18+10+2) + (10+2) + (2*8?)
//

// A3  A4  A5
// <--------
// <---<----
// any lamps = continous sections = l, r = Al~Ar
// person's location : Al or Ar
//
// d[i][j] : min costs of consuming power when turning off i~j lamps
// d[i][j][where] : where = 0 -> person is in i
//                  where = 1 -> person is in j
// (i,j,0) = Ai
//                                                                           i-1  i      j  j+1                                        
// 1) left  = i-1   > (i-1, j, 0) = d[i-1][j][0] = d[i][j][0] + (Ai - Ai-1)*(sum(w1~wi-1)+sum(wj+1~wn))
//
//            i-1  i      j  j+1                                                                           accumulated sum                
// 2) right = j+1   > (i, j+1, 1)
//    d[i][j+1][1] = d[i][j][0] + (Aj+1 - Ai)* (sum(w1~wi-1)+sum(wj+1~wn))

// where = 0 -> now = i
// where = 1 -> now = j
// in case of tuning off left lamp
//  go(left-1, right, 0) + (x[now]-x[left-1])*(s[n]-s[right]+s[left-1])
// in case of tuning off right lamp
//  go(left, right+1, 1) + (x[right+1]-x[now])*(s[n]-s[right]+s[left-1])
//                                              <-right+1~n-> <-1~left-1->


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int x[1001]; // 1<= n <= 1000
int s[1001];
int w[1001];
// d[i][j][where]  : min cost in range i~j, where = location (0:i, 1:j)
int d[1001][1001][2];
int go(int left, int right, int where) {
    if (left == 1 && right == n) { // finish 1~n
        return 0;
    }
    int &ans = d[left][right][where]; // memoization
    if (ans != -1) {
        return ans;
    }
    ans = 2147483647; // max
    int now = where ? right : left;
    if (left-1 >= 1) { // out of range check
        ans = min(ans, go(left-1, right, 0) + (x[now]-x[left-1])*(s[n]-s[right]+s[left-1]));
    }
    if (right+1 <= n) { // out of range check
        ans = min(ans, go(left, right+1, 1) + (x[right+1]-x[now])*(s[n]-s[right]+s[left-1]));
    }
    return ans;
}
int main() {
    scanf("%d\n%d\n",&n,&m); 
    for (int i=1; i<=n; i++) {
        scanf("%d %d",&x[i], &w[i]); // position, power consumption
        s[i] = s[i-1] + w[i]; // accumulated sum
    }
    memset(d,-1,sizeof(d));
    printf("%d\n",go(m,m,0)); // start position = m (m~m)
    return 0;
}