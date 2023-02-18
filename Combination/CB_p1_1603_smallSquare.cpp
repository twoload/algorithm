#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// 1<= n,m <= 10
// nm = 100
// 2^100

//  2*m
//  ...
//  2*m (n/2)
//  2^2m = 2^20


#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int d[1<<20]; // grundy number
int one[20]; // 1x1
int two[10]; // 2x2
bool already[100];
int main() {
    int t = 3;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        // position
        // *O O* OO OO
        // OO OO *O O*
        for (int i=0; i<2*m; i++) {
            one[i] = (1<<i);
        }
        // position
        // **OO O**O OO**
        // **OO O**O OO**
        for (int i=0; i<m-1; i++) {
            two[i] = (1<<i) | (1<<(i+1)) | (1<<(i+m)) | (1<<(i+m+1));
        }
        memset(d,0,sizeof(d));
        d[(1<<(2*m))-1] = 0; // all selected = d[1111....1111] = 0
        for (int i=((1<<(2*m))-2); i>=0; i--) {
            memset(already,false,sizeof(already));
            for (int k=0; k<2*m; k++) {
                if ((i&one[k]) == 0) {
                    already[d[i|one[k]]] = true;
                }
            }
            for (int k=0; k<m-1; k++) {
                if ((i&two[k]) == 0) {
                    already[d[i|two[k]]] = true;
                }
            }
            for (int k=0; k<100; k++) { 
                if (already[k] == false) { 
                    d[i] = k; // grundy number
                    break;
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i+=2) { //2xm
            int state = 0;
            for (int j=0; j<m; j++) {
                if (a[i][j] == '#') {
                    state |= (1<<j); // already 1
                }
                // n=4
                // i=0 OOOO
                // i=1 OOOO <- a[i+1][j]
                // i=2 OOOO
                // i=3 OOOO 
                //
                // n=3
                // i=0 OOOO
                // i=1 OOOO
                // i=2 OOOO <- i==n-1
                // i=3 ####    (we decide it is filled)
                if (i == n-1 || a[i+1][j] == '#') {
                    state |= (1<<(j+m));
                }
            }
            ans ^= d[state]; // XOR
        }
        cout << (ans == 0 ? "M" : "Y") << '\n';
    }
    return 0;
}
