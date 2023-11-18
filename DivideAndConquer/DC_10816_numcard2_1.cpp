// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        cout << upper_bound(a.begin(), a.end(), b)-lower_bound(a.begin(), a.end(),b) << ' ';
    }
    cout << '\n';
    return 0;
}