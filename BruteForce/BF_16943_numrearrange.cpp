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
string a, b;
int ans = -1;
bool check[10];    
void go(int idx, string s) {
    //printf("idx:%d, s:%s\n", idx, s.c_str());
    if (idx == n-1) {
        if (stoi(s) < stoi(b)) {
            if (stoi(s) > ans) {
                ans = stoi(s);
            }
        }
        return;
    }
    for (int i=0; i<n; i++) {
        if (check[i]) continue;
        check[i] = true;
        string j = string(1, a[i]);
        go(idx+1, s+j);
        check[i] = false;
    }
}

int main() {
    cin >> a >> b;
    n = a.length();
    if (a.length() > b.length()) {
        cout << -1 << '\n';
        return 0;
    }


    for (int i=0; i<a.length(); i++) {
        if (a.length() != 1) {
            if (a[i] == '0') continue;
        }
        memset(check, false, sizeof(check));
        check[i] = true;
        string j = string(1, a[i]);
        go(0, j);
        check[i] = false;
    }
    if (ans == -1) 
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}