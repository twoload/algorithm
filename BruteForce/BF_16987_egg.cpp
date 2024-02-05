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
    
int ans = 0;

void go(vector<pair<int,int>>& egg, int idx) {
    int n = egg.size();
    if (idx == n) {
        int num = 0;
        for (int i=0; i<n; i++) {
            if (egg[i].first <= 0) {
                num += 1;
            }
        }
        if (ans < num) ans = num;
        return;
    }
    int& x1 = egg[idx].first;
    int& y1 = egg[idx].second;
    if (x1 <= 0) {
        go(egg, idx+1);
        return;
    }

    bool broke = false;
    for (int i=0; i<n; i++) {
        if (idx == i) continue;
        int& x2 = egg[i].first;
        int& y2 = egg[i].second;
        if (x2 <= 0) continue;
        broke = true;
        x1 -= y2;
        x2 -= y1;
        go(egg, idx+1);
        x1 += y2;
        x2 += y1;
    }
    if (broke == false) {
        go(egg, idx+1);
        return;
    }
}
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> egg;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        egg.push_back(make_pair(a,b));
    }

    go(egg, 0);
    cout << ans << '\n';
    return 0;
}