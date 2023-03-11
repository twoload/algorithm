#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1<= n <= 100'000
// sum of all serial numbers % M = 0
// max of possible guitar number

// 1
// 3 5
// 1 8 6 -> 3

// 1
// 6 9
// 8 6 4 1 2 3 -> 5

// O(2^n)
// d[n] : max num at 1~n satisfying %m == 0
//        d[n-1] + (S[n]-S[n-1]% m == 1 : 0)

// teacher
// d[i][j] : max size at guitar num i, sum j
// in case without i-th guitar
//    d[i+1][j] = max(d[i+1][j], d[i][j])
// in case with i-th guitar
//    d[i+1][(j+A[i])%M] = max(d[i+1][(j+A[i])%M], d[i][j]+1)
// n<=500, m<=100'000
// need capacity : 500x100'000 int = 4byte = 200MByte > 128MByte

// d[n][m] => d[2][m]
// i:0 -> 1 -> 2 -> 3 -> 4
//   0 -> 1 -> 0 -> 1 
// 

// d[i]   -> d[cur]  so, previous status isn't interested. only two status are important.
// d[i+1] -> d[next]

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// d[i][j] : max size at guitar num i, sum j
//   2 
int d[2][100000];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i] %= m; // serial number : we're only interested in %m 
        }
        memset(d,-1,sizeof(d));
        // d[i][j] : max size at guitar num i, sum j
        // d[n][m] => d[2][m] : 1/25 : 
        // i:0 -> 1 -> 2 -> 3 -> 4
        //   0 -> 1 -> 0 -> 1 

        // d[i]   -> d[cur]
        // d[i+1] -> d[next]
        d[0][0] = 0;
        for (int i=0; i<n; i++) {
            int cur = i%2;     //0
            int nxt = (i+1)%2; //1
            for (int j=0; j<m; j++) { //next init
                d[nxt][j] = -1;
            }
// in case without i-th guitar
//    d[i+1][j] = max(d[i+1][j], d[i][j])
// in case with i-th guitar
//    d[i+1][(j+A[i])%M] = max(d[i+1][(j+A[i])%M], d[i][j]+1)
            for (int j=0; j<m; j++) {
                if (d[cur][j] == -1) continue;
                if (d[nxt][j] == -1 || d[nxt][j] < d[cur][j]) {
                    d[nxt][j] = d[cur][j];
                }
                int k = (j+a[i])%m;
                if (d[nxt][k] == -1 || d[nxt][k] < d[cur][j] + 1) {
                    d[nxt][k] = d[cur][j] + 1;
                }
            }
        }
        // n, 0(%m==0)
        cout << d[n%2][0] << '\n';
    }
    return 0;
}
