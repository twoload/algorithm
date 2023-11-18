// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool go(vector<int>& a, int start, int end, int value) {
    if (value < a[start] || a[end] < value) {
        return false;
    }
    if (start == end) {
        if (a[start] == value) {
            return true;
        } else {
            return false;
        }
    }
    int mid = (start + end)/2;
    if (value <= a[mid]) {
        return go(a, start, mid, value);
    } else {
        return go(a, mid+1, end, value);
    }
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