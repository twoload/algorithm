#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int ans = 0;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += p[i];
        ans += sum;
    }
    cout << ans << '\n';
    return 0;
}