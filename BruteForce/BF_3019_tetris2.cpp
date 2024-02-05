#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    switch (p) {
        case 1:
            ans += n;
            for (int i=0; i<n-3; i++) {
                if (a[i]==a[i+1] && a[i+1]==a[i+2] && a[i+2]==a[i+3]) {
                    ans += 1;
                }
            }
            break;
        case 2:
            for (int i=0; i<n-1; i++) {
                if (a[i]==a[i+1]) {
                    ans += 1;
                }
            }
            break;
        case 3:
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1] && a[i+1]+1==a[i+2]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i]==a[i+1]+1) {
                    ans += 1;
                }
            }
            break;
        case 4:
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1]+1 && a[i+1]==a[i+2]) {
                    ans += 1;
                }
            }       
            for (int i=0; i<n-1; i++) {
                if (a[i]+1==a[i+1]) {
                    ans += 1;
                }
            }
            break;
        case 5:
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1] && a[i+1]==a[i+2]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i]+1 == a[i+1]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1]+1 && a[i+1]+1==a[i+2]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i]==a[i+1]+1) {
                    ans += 1;
                }
            }
            break;
        case 6:
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1] && a[i+1]==a[i+2]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i] == a[i+1]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-2; i++) {
                if (a[i]+1==a[i+1] && a[i+1]==a[i+2]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i]==a[i+1]+2) {
                    ans += 1;
                }
            }
            break;
        case 7:
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1] && a[i+1]==a[i+2]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i]+2 == a[i+1]) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-2; i++) {
                if (a[i]==a[i+1] && a[i+1]==a[i+2]+1) {
                    ans += 1;
                }
            }
            for (int i=0; i<n-1; i++) {
                if (a[i]==a[i+1]) {
                    ans += 1;
                }
            }
            break;
    }
    cout << ans << '\n';
    return 0;
}