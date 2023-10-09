#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int s[21];
bool c[2000001];

int main() {
    int n = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    for (int i=0; i<(1<<n); i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) {
                sum += s[j];
            }
        }
        c[sum] = true;
    }
    int ans = 0;
    for (int i=1; i<=2000001; i++) {
        if (c[i] == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}