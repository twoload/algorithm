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
#include <string>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if (num > 0) {
            plus.push_back(num);
        } else {
            minus.push_back(num);
        }
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    int ans = 0;
    int i = 0;
    for (i=0; i<plus.size(); i+=2) {
        if (i+1 > plus.size()-1) {
            ans += plus[i];
        } else {
            if (plus[i] == 1 || plus[i+1] == 1) {
                ans = ans + plus[i] + plus[i+1];
            } else {
                ans += (plus[i]*plus[i+1]);
            }
        }
    }
    for (i=0; i<minus.size(); i+=2) {
        if (i+1 > minus.size()-1) {
            ans += minus[i];
        } else {
            ans += (minus[i]*minus[i+1]);
        }
    }
    cout << ans << '\n';
    return 0;
}