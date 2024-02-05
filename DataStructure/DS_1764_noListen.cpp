#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> mp;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n+m; i++) {
        string name;
        cin >> name;
        mp[name] += 1; 
    }
    vector<string> a;
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        if (it->second >= 2) {
            a.push_back(it->first);
        }
    }
    cout << a.size() << '\n';
    sort(a.begin(), a.end());
    for (int i=0; i<a.size(); i++) {
        cout << a[i] << '\n';
    }
    return 0;
}