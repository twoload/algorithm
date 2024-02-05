#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
using namespace std;

int main() {
    long long n,l,r,x;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=0; i<(1<<n); i++) {
        long long sum = 0;
        int mx = 0;
        int mn = 1000000;
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) {
                cnt += 1;
                sum += a[j];
                if (mx < a[j]) {
                    mx = a[j];
                }
                if (mn > a[j]) {
                    mn = a[j];
                }
            }
        }    
        if (cnt >= 2 && l<=sum && sum<=r && (mx-mn)>=x) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}