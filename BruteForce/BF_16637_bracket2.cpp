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

int ans = 0;

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

void go(int idx, bool choose, vector<int>& bracket) {
    if (idx == m) {
        // calc
        for (int i=0; i<bracket.size(); i++) {
            cout << bracket[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (choose) {
        go(idx+1, false, bracket);
    } else {
        go(idx+1, false, bracket);
        bracket.push_back(idx+1);
        go(idx+1, true, bracket)
        bracket.pop_back;
    }
}
int n;
string s;
int ans = 0;    
void go(int idx, int sum, char op) {
    if (idx >= n) {
        if (ans < sum) {
            ans = sum;
        }
        return;
    }
    if (idx == n-1) {
        int res = calc(sum, s[idx]-'0', op);
        if (ans < sum) {
            ans = sum;
        }
        return;
    }
    // bracket
    int tmp = calc(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
    int res = calc(sum, tmp, op);
    go(idx+4, res, s[idx+3]);
    // no bracket
    res = calc(sum, s[idx]-'0',op);
    go(idx+2, res, s[idx+1]);
}
int main() {
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << s[0]-'0' << '\n'
    } else if (n == 3) {
        cout << calc(s[0]-'0',s[2]-'0',s[1]) << '\n'
    } else {
        // bracket
        int res = calc(s[0]-'0',s[2]-'0',s[1]);
        go(idx+4, res, s[3]);
        res = s[0]-'0';
        // no bracket
        go(idx+2, res, s[1]);
    }
    return 0;
}