#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://bowbowbow.tistory.com/6

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#if 0
ABAABAB : len(7)
i  substr  pi[i]
0  A       0
1  AB      0
2  ABA     1
3  ABAA    1
4  ABAAB   2
5  ABAABA  3
6  ABAABAB 2


#endif


vector<int> getPi(string p) {
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for (int i=1; i<m; i++) {
        while(j>0 && p[i]!=p[j]) {
            j = pi[j-1];
        }
        if (p[i]==p[j]) {
            j += 1;
            pi[i] = j;
        }
    }
    return pi;
}
vector<int> kmp(string s, string p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j=0;
    for (int i=0; i<n; i++) {
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
    string s, p;
    getline(cin, s);
    getline(cin, p);
    auto matched = kmp(s,p);
    cout << (int)matched.size() << '\n';
    for (auto i : matched) {
        cout << i+1 << ' ';
    }
    cout << '\n';
    return 0;
}