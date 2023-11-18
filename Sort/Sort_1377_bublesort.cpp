
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    bool changed = false;
    for (int i=1; i<=n+1; i++) {
        changed = false;
        for (int j=1; j<=n-i; j++) {
            if (a[j] > a[j+1]) {
                changed = true;
                swap(a[j], a[j+1]);
            }
        }
        if (changed == false) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}