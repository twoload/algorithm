//# I've attended the code.plus class (https://code.plus/)
//# And I've referred it's codes
//# And core parts can be come fully from the class.

// how to separate papers
// 1 <= N, M <= 4

// (0,0) -> (n-1,m-1) move
// select
// self, colum dir = 1,2,3,...m-1 
// self, row dir = 1,2,3,...n-1
// check <- bitmask
// remaining

// teacher
// (-), (|) 2 cases
// O(2^16) = 65536

// 2^NM state => bitmask

#include <iostream>
#include <cstdio>
using namespace std;
int a[4][4];
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &a[i][j]); // tip!!!
        }
    }
    int ans = 0;
    // 0: -, 1: |
    for (int s=0; s<(1<<(n*m)); s++) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            int cur = 0;
            for (int j=0; j<m; j++) {
                int k = i*m+j;
                if ((s&(1<<k)) == 0) {
                    cur = cur*10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for (int j=0; j<m; j++) {
            int cur = 0;
            for (int i=0; i<n; i++) {
                int k = i*m+j;
                if ((s&(1<<k)) != 0) { // tip!!! ==1 (wrong)
                    cur = cur*10 + a[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}



