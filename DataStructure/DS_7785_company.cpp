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
    
    int n;
    cin >> n;
    map<string, string> m;
    for (int i=0; i<n; i++) {
        string name, stat;
        cin >> name >> stat;
        m[name] = stat;
    }
    vector<string> a;
    for (auto mm : m) {
        if (mm.second == "enter") {
            a.push_back(mm.first);
        }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (auto aa : a) {
        cout << aa << '\n';
    }
    return 0;
}