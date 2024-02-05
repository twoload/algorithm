// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[10001];
int n;
int m = 3;
int num[] = {1,2,3}; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    d[0] = 1;
    n = 10000;
    for (int j=0; j<m; j++) {
        for (int i=1; i<=n; i++) {
            if (i-num[j]>=0) {
                d[i] += d[i-num[j]];
            }
        }
    }
    while (t--) {
        int x;
        cin >> x;
        cout << d[x] << '\n';
    }
    return 0;
}