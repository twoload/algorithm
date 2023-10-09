#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

#if 0
int binary_search(vector<int>& a, int start, int end, int val) {
    int mid = (start + end)/2;
    if (start == end) {
        return start;
    }
    if (val <= a[mid]) {
        return binary_search(a, start, mid, val);
    } else {
        return binary_search(a, mid+1, end, val);
    }
}
#endif

int binary_search(vector<int>& a, int key) {
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
        int mid = (l+r)/2;
        if (key <= a[mid]) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    b.push_back(a[0]);
    for (int i=1; i<n; i++) {
        if (b[b.size()-1] < a[i]) {
            b.push_back(a[i]);
        } else {
            int j = binary_search(b, a[i]);
            b[j] = a[i];
        }
    }
    cout << b.size() << '\n';
    return 0;
}