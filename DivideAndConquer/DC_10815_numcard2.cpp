// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool go(vector<int>& a, int left, int right, int value) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (value == a[mid]) {
            return true;
        }
        else if (value < a[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> m;
    int b;
    for (int i=0; i<m; i++) {
        cin >> b;
        cout << go(a, 0, a.size()-1, b) << ' ';
    }
    cout << '\n';
    return 0;
}