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
string s;
int ans = -987654321;    
int calc(int a, int b, char op) {
    if (op == '+') {
        return a+b;    
    } else if (op == '-') {
        return a-b;
    } else if (op == '*') {
        return a*b;
    } else {
        return a/b;
    }
}
void go(int idx, int sum) {
    if (idx >= n-1) {
        if (ans < sum) {
            ans = sum;
        }
        return;
    }
    if (idx+3 < n) {
        // bracket
        int tmp = calc(s[idx+1]-'0', s[idx+3]-'0', s[idx+2]);
        int res = calc(sum, tmp, s[idx]);
        go(idx+4, res);
    }
    if (idx+1 < n) {
        // no bracket
        int res = calc(sum, s[idx+1]-'0', s[idx]);
        go(idx+2, res);
    }
}
int main() {
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << s[0]-'0' << '\n';
    } else if (n == 3) {
        cout << calc(s[0]-'0',s[2]-'0',s[1]) << '\n';
    } else if (n > 3) {
        // bracket
        int res = calc(s[0]-'0',s[2]-'0',s[1]);
        go(3, res);
        // no bracket
        go(1, s[0]-'0');
        cout << ans << '\n';
    }
    return 0;
}