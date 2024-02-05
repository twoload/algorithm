#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
vector<int> getPi(string s) {
    int n = s.size(), j=0;
    vector<int> pi(n, 0);
    for (int i=1; i<n; i++) {
        while (j>0 && s[i]!=s[j]) {
            j = pi[j-1];
        }
        if (s[i]==s[j]) {
            j += 1;
            pi[i]=j;
        }
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    auto pi = getPi(s);
    int n = s.size();
    int len = pi[n-1];
    while (len>0) {
        for (int i=1; i<n-1; i++) {
            if (pi[i] == len) {
                cout << s.substr(0,len) << endl;
                return 0;
            }
        }
        len = pi[len-1]; //process to find next fail
    }
    cout << -1 << endl;
    return 0;
}