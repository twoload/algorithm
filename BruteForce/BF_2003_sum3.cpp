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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int left=0;
    int right=0;
    int sum=a[0];
    int ans = 0;
    while (left < n && right < n) {
        if (sum < m) {
            right += 1;
            sum += a[right];
        } else if (sum == m) {
            right += 1;
            sum += a[right];
            ans += 1;
        } else if (sum > m) {
            sum -= a[left];
            left += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}