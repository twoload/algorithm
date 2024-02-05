#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> preprocessing(string p) {
    int m = p.size();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    for (int i=1; i<m; i++) {
        while (j>0 && p[i] != p[j]) {
            j = pi[j-1];
        }
        if (p[i] == p[j]) {
            pi[i] = j+1;
            j += 1;
        } else {
            pi[i] = 0;
        }
    }
    return pi;
}
int main() {
    string s;
    cin >> s;
    int n = s.length();
    auto pi = preprocessing(s);
    vector<int> cnt(n+1);
    for (int i=0; i<n-1; i++) {
        cnt[pi[i]] += 1;
    }
    for (int i=n; i!=0; i=pi[i-1]) {
        if (cnt[i] >= 1) {
            cout << s.substr(0,i) << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}