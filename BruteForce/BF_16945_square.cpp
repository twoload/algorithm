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

int n = 3;

bool is_magic(vector<int>& d) {
    int magic = d[0*n+0] + d[0*n+1] + d[0*n+2];
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            sum += d[i*n+j];
        }
        if (magic != sum) return false;
    }
    for (int j=0; j<n; j++) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += d[i*n+j];
        }
        if (magic != sum) return false;
    }
    if (magic != d[0*n+0]+d[1*n+1]+d[2*n+2]) return false;
    if (magic != d[0*n+2]+d[1*n+1]+d[2*n+0]) return false;
    return true;
}

int diff(vector<int>& a, vector<int>& d) {
    int ans = 0;
    for (int i=0; i<n*n; i++) {
        int temp = a[i] - d[i];
        if (temp < 0) temp = -temp;
        ans += temp;
    }
    return ans;
}

int main() {
    vector<int> a(n*n);
    for (int i=0; i<n*n; i++) {
        cin >> a[i];
    }
    vector<int> d(n*n);
    for (int i=0; i<n*n; i++) {
        d[i] = i+1;
    }
    int ans = -1;
    do {
        if (is_magic(d)) {
            int cost = diff(a, d);
            if (ans == -1 || ans > cost) {
                ans = cost;
            }
        }
    } while (next_permutation(d.begin(), d.end()));
    cout << ans << '\n';
    return 0;
}