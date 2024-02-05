// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[1500002];
int t[1500002];
int p[1500002];
int n;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        cin >> p[i];
    }
    memset(d, -1, sizeof(d));
    d[0] = 0;
    for (int i=0; i<n; i++) {
        if (d[i] != -1) {
            d[i+1] = max(d[i+1], d[i]);
            if (i+t[i] <= n) {
                d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
            } 
        }
    }
    cout << d[n] << '\n';
    return 0;
}