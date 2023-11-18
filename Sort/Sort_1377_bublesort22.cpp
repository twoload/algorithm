#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i=0; i<n; i++) {
        int d = a[i].second - i;
        if (ans < d) {
            ans = d;
        }
    }
    cout << ans+1 << '\n';
    return 0;
}