#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[n] : max lis length of subsequence len n
//        max(d[i])+1

// d[i] = max(d[j])+1, j<i, A[j] < A[i]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1001];
int d[1001];
int v[1001]; // for backtracking
    
void go(int p) {
    // ? -> ? -> ... a[v[p]] -> a[p]
    // ---------------------
    //        go(v[p])
    if (p == -1)
        return;
    go(v[p]);
    cout << a[p] << ' ';
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        d[i] = 1;
        v[i] = -1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
                v[i] = j;
            }
        }
    }
    int ans = d[0];
    int p = 0;
    for(int i=0; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }
    cout << ans << '\n';
    go(p);
    cout << '\n';
    return 0;
}

