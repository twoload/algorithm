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

long long n, l, r, x;
bool check[16];
long long a[16];
long long ans = 0;
void print(vector<long long>& input) {
    for (long long i=0; i<input.size(); i++) {
        cout << input[i] << ' ';
    }
    cout << '\n';
}

void go(long long idx, vector<long long>& p) {
    long long m = p.size();
    long long sum = 0;
    long long mx = 0;
    long long mn = 1000000000;
    for (long long i=0; i<m; i++) {
        sum += p[i];
        mx = max(mx, p[i]);
        mn = min(mn, p[i]);
    }
    if (idx == n) {
        if (l<=sum && sum<=r && (mx-mn)>=x) {
            //prlong long(p);
            ans += 1;
        }
        return;
    }
    if (m >= 2) {
        if (l<=sum && sum<=r && (mx-mn)>=x) {
            //prlong long(p);
            ans += 1;
        }
    }
    for (long long i=idx+1; i<n; i++) {
        if (check[i] == false) {
            p.push_back(a[i]);
            check[i] = true;
            go(idx+1, p);
            p.pop_back();
            check[i] = false;
        }
    }
}

long long main() {
    cin >> n >> l >> r >> x;
    for (long long i=0; i<n; i++) {
        cin >> a[i];
    }

    for (long long i=0; i<n; i++) {
        memset(check, false, sizeof(check));
        vector<long long> problems;
        problems.push_back(a[i]);
        check[i] = true;
        go(i, problems);
        problems.pop_back();
        check[i] = false;
    }
    cout << ans << '\n';
    return 0;
}