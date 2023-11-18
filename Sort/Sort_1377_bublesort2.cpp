#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int ans = 0;    vector<pair<int,int>> a(n);

    for (int i=0; i<n; i++) {
        if (a[i].second - i > ans) {
            ans = a[i].second - i;
        }
    }
    return 0;
}