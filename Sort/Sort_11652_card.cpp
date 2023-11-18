
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool cmp(const pair<int, long long>& u, const pair<int, long long>& v) {
    return u.first < v.first;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    int n;
    cin >> n;
    vector<long long> a(n, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<int, long long>> b;
    int cnt = 1;
    long long pre = a[0];
    for (int i=1; i<n; i++) {
        if (pre == a[i]) {
            cnt += 1;
        } else {
            b.push_back(make_pair(cnt, pre));
            cnt = 1;
        }
        pre = a[i];
    }
    b.push_back(make_pair(cnt, pre));
    sort(b.begin(), b.end(), cmp);
    cout << b[0].second << '\n';
    return 0;
}