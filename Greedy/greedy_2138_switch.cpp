#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char flip(char c) {
    if (c == '1') {
        return '0';
    } else if (c == '0') {
        return '1';
    } 
    return c;
}
// 1st switch: O -> firstTurn: true
int go(bool firstTurn, const string& a, const string& b) {
    int n = a.size();
    string t = a;
    int cnt = 0;
    if (firstTurn) {
        t[0] = flip(t[0]);
        t[1] = flip(t[1]);
        cnt += 1;
    }
    if (n < 3) {
        if (t == b) {
            return cnt;
        } else {
            return -1;
        }
    }
    for (int i=1; i<n-1; i++) {
        if (t[i-1] != b[i-1]) {
            t[i-1] = flip(t[i-1]);
            t[i] = flip(t[i]);
            t[i+1] = flip(t[i+1]);
            cnt += 1;
        }
    }
    if (t[n-2] != b[n-2]) {
        t[n-2] = flip(t[n-2]);
        t[n-1] = flip(t[n-1]);
        cnt += 1;
    }
    if (t == b) {
        return cnt;
    } else {
        return -1;
    }
}

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ret1 = go(true, a,b);
    int ret2 = go(false, a,b);
    if (ret1 == -1 && ret2 == -1) {
        cout << -1 << '\n';
    } else if (ret1 != -1 && ret2 != -1) {
        cout << min(ret1, ret2) << '\n';
    } else if (ret1 == -1) {
        cout << ret2 << '\n';
    } else if (ret2 == -1) {
        cout << ret1 << '\n';
    }
    return 0;
}