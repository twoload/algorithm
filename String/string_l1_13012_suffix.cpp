#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> suffix_array(string s) {
    // s = baekjoon
    vector<pair<string,int>> a;
    reverse(s.begin(), s.end());
    // s = noojkeab
    string cur = "";
    for (int i=0; i<s.length(); i++) {
        cur = s[i] + cur; // front
        a.push_back({cur, s.length()-i-1}); // index
        // a[0] = {n, 7}
        // a[1] = {on, 6}
        // a[2] = {oon, 5}
        // ...
        // a[7] = {baekjoon, 0}
    }
    sort(a.begin(),a.end()); // sorted : 1,0,2,4,3,7,6,5
    vector<int> d;
    for (int i=0; i<a.size(); i++) {
        d.push_back(a[i].second);
    }
    return d; //{1,0,2,4,3,7,6,5}
}
int main() {
    string str;
    cin >> str;
    vector<int> sa = suffix_array(str);
    int n = str.length();
    vector<int> s(n+1); // order
    for (int i=0; i<n; i++) {
        s[sa[i]] = i;
    }
    s[n] = -1; // n-1:last, n:empty
    vector<char> ans(n);
    char cur = 'a';
    ans[sa[0]] = cur; // first one = a
    for (int i=0; i<n-1; i++) {
        // if i=0,   s[sa[0]+1] >= s[sa[1]+1]
        // if i=n-2, s[sa[n-2]+1] >= s[sa[n-1]+1] // n-1:last
        if (s[sa[i] + 1] >= s[sa[i+1]+1]) {
            cur += 1;
        }
        ans[sa[i+1]] = cur;
    }
    string ss = "";
    for (char c : ans) {
        ss += c;
    }
    if (ss < str) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}