#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n x m (1<=n<=10, 1<=m<=25)
// dp
//  about row status
//  n*2^(2m) : too big
//  ->
//  about m+1 status
//  n*m*2^(m+1)
// dp[i][j] : max num , i pos, j status (i~i+m-1)
//   = dp[i+1][j>>1] + 1    (1x1)     
//        j & 1 == 0, 
//   = dp[i+1][j>>1] + 16   (2x2)
//        j & 1 == 0, j & 2 == 0
//        j & (1 << (m-1)) == 0 ,
//        j & (1 << (m)) == 0 // m+1  

// teacher
// 1<=n<=10, 1<=m<=25
// nm*2^m but m is big!!!
// n, m exchange!
// -> nm*2^n
// 4block
//   . (.* ? ? ? -> (state & 1==0, state & 2 == 0)
//   .) . ? ? ?  -> (a[i][j+1]== '.', a[i+1][j]=='.', a[i+1][j+1]=='.'])
// (index, state)
// index+2,
//   1 1 (* ? ?  -> state >> 2 | (1<<(m-1) | 1 << (m-2)) 
//   1 1) ? ? ? 


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int inf = 100'000'000;
int d[10*25][1<<10]; // 1<=n<=10, 1<=m<=25, state= 2^10 (smaller one between 10 and 25)
string a[25];
int n, m;
int go(int index, int state) {
    if (index == n*m) { // end
        if (state == 0) return 0; // finish
        else return -inf; // can't go
    }
    if (index > n*m) return -inf; // can't go
    int &ans = d[index][state]; // memoization
    if (ans != -1) return ans;
    int i = index/m; // row
    int j = index%m; // col
    if (a[i][j] == '1') { // block exist -> next
        ans = go(index+1, state >> 1) + 1;
        return ans;
    }
    ans = go(index+1, state>>1); // let it be empty
    if ((state & 1) == 0) { // fill 1
        ans = max(ans, go(index+1, state>>1) + 1);
    } 
    // fill 4
    // i!=n-1 && j!=m-1 (last one check : out of range)
    // state & 1 == 0 (empty: cur)
    // state & 2 == 0 (empty: next)
    // bottom, bottom right ? no consider (because empty)
    // but, need to check if there is 1 (already)
    // right, bottom, bottom right -> a[i][j+1], a[i+1][j], a[i+1][j+1]
    // index -> index + 2
    // state -> (state>>2 | (1<<(m-1) | (1<<(m-2))))
    if (i != n-1 && j != m-1 && (state & 1) == 0 && (state & 2) == 0) {
        if (a[i][j+1] == '.' && a[i+1][j] == '.' && a[i+1][j+1] == '.') {
            ans = max(ans, go(index+2, (state>>2) | (1<<(m-1)) | (1<<(m-2))) + 16);
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    vector<string> b(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    // n, m = 2, 11
    // b[0] = .....1..1..
    // b[1] = ..1.....1..

    // a[0] = b[0][0] + b[1][0]
    // a[1] = b[0][1] + b[1][1]
    // a[5] = b[0][5] + b[1][5]
    // a[0] = ..
    // a[1] = ..
    // a[6] = 1.
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            a[j] += b[i][j];
        }
    }
    swap(n, m);
    memset(d,-1,sizeof(d));
    cout << go(0, 0) << '\n';
    return 0;
}