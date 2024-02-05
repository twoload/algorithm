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

int n;
int a[100001];
int ans = 987654321;
void go(int idx, int pre, int diff, int cnt) {
    if (idx >= n) {
        if (ans > cnt) {
            ans = cnt;
        }
        return;
    }
    int cur = a[idx];
    if (diff == -1) {
        go(idx+1, cur, pre-cur, cnt);
        go(idx+1, cur-1, pre-cur+1, cnt+1);
        go(idx+1, cur+1, pre-cur-1, cnt+1);
    } else {
        if (pre-cur == diff) {
            go(idx+1, cur, diff, cnt);
        } else if (pre-cur-1 == diff) {
            go(idx+1, cur+1, diff, cnt+1);
        } else if (pre-cur+1 == diff) {
            go(idx+1, cur-1, diff, cnt+1);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    go(1, a[0], -1, 0);
    go(1, a[0]+1, -1, 1);
    go(1, a[0]-1, -1, 1);
    if (ans == 987654321) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}