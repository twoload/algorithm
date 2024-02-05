#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
using namespace std;

// n -> I,V,X,L
//      n,0,0,0
//      0,n,0,0
//      0,0,n,0
//      0,0,0,n

bool a[1001];

int main() {
    int n;
    cin >> n;
    int cnt =0;

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            for (int k=0; k<=n; k++) {
                for (int l=0; l<=n; l++) {
                    int len = i+j+k+l;
                    if (len == n) {
                        //cnt += 1;
                        a[i*1+j*5+k*10+l*50] = true;
                    }
                }
            }
        }
    }
    for (int i=0; i<1001; i++) {
        if (a[i]) {
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}