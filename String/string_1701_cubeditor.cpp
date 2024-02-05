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
using namespace std;

vector<int> getPi(string p) {
    int j = 0;
    int n = p.size();
    vector<int> pi(n, 0);
    for (int i=1; i<n; i++) {
        while (j>0 && p[i]!=p[j]) {
            j = pi[j-1];
        }
        if (p[i] == p[j]) {
            j += 1;
            pi[i] = j;
        }
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    string ss;
    int ans = 0;
    int n = s.size();
    for (int i=0; i<n; i++) {
        ss = s.substr(i);
        vector<int> pi = getPi(ss);
        sort(pi.begin(), pi.end());
        reverse(pi.begin(), pi.end());
        ans = max(ans, pi[0]);
    }
    cout << ans << '\n';
    return 0;
}