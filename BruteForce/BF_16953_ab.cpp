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

long long a, b;
long long ans = -1;

void go(long long x, long long cnt) {
    if (x == b) {
        if (ans == -1 || ans > cnt) ans = cnt;
        return;
    } else if (x > b) {
        return;
    }
    go (2*x, cnt+1);
    go (10*x+1, cnt+1);
}

int main() {
    
    cin >> a >> b;
    go(a, 1);
    cout << ans << '\n';
    return 0;
}