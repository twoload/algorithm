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

int n, m;
int a[10001];
int s[10001];

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            int temp = s[j]-s[i-1];
            if (temp == m) ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}