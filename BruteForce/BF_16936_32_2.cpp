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
long long a[101];
bool check[101];

void go(int idx, vector<long long>& ans) {
    if (idx == n) {
        for (int i=0; i<n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    long long now = ans[ans.size()-1];
    for (int i=0; i<n; i++) {
        if (check[i]) continue;
        if (a[i] == now*2) {
            check[i] = true;
            ans.push_back(a[i]);
            go(idx+1, ans);
            check[i] = false;
            ans.pop_back();
        } else if ((now%3==0) && (now/3==a[i])) {
            check[i] = true;
            ans.push_back(a[i]);
            go(idx+1, ans);
            check[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i]; 
    }
    for (int i=0; i<n; i++) {
        memset(check, false, sizeof(check));
        vector<long long> ans;
        ans.push_back(a[i]);
        check[i] = true;
        go(1, ans);
        check[i] = false;
        ans.pop_back();
    }

    return 0;
}