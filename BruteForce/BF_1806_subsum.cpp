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

long long a[100001];

int main() {
    long long n, s;
    cin >> n >> s;
    for (long long i=0; i<n; i++) {
        cin >> a[i];
    }
    long long left = 0;
    long long right = 0;
    long long sum = a[0];
    long long ans = -1;
    while (left < n && right < n) {
        if (sum < s) {
            right += 1;
            sum += a[right];
        } else if (sum == s) {
            long long len = right - left + 1;
            if (ans == -1 || ans > len) {
                ans = len;
            }
            right += 1;
            sum += a[right];
        } else if (sum > s) {
            long long len = right - left + 1;
            if (ans == -1 || ans > len) {
                ans = len;
            }
            sum -= a[left];
            left += 1;
        }
    }
    if (ans == -1) {
        cout << 0 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}