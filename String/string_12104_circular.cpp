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
// https://blog.naver.com/kks227/220917078260
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
vector<int> kmp(string s, string p, vector<int> pi) {
    vector<int> ans;
    //auto pi = getPi(p);
    int n = s.size(), m = p.size(), j=0;
    for (int i=0; i<n-1; i++) { // important: n-1
        while (j>0 && s[i]!=p[j]) {
            j = pi[j-1];
        }
        if (s[i]==p[j]) {
            if (j==m-1) {
                ans.push_back(i-m+1);
                j = pi[j];
            } else {
                j += 1;
            }
        }
    }
    return ans;
}
int main() {
    string a, b;
    cin >> a >> b;
    a = a+a;
    auto pi = getPi(b);
    auto res = kmp(a, b, pi);
    cout << res.size() << '\n';
    return 0;
}