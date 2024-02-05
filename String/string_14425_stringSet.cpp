#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://jaimemin.tistory.com/629

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string,int> mp;
    for (int i=0; i<n; i++) {
        string key;
        cin >> key;
        mp[key] = 1;
    }
    int ans = 0;
    for (int i=0; i<m; i++) {
        string key;
        cin >> key;
        if (mp.find(key) != mp.end()) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}