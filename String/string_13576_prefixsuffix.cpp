#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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
    string s;
    cin >> s;
    auto pi = getPi(s);
    int n = s.size();
    vector<int> a;
    int len = n-1;
    a.push_back(n);
    while(len>0) {
        a.push_back(pi[len]);
        len = pi[len]-1;
    }
    reverse(a.begin(), a.end());
    cout << a.size() << '\n';
    for (int i=0; i<a.size(); i++) {
        auto res = kmp(s, s.substr(0,a[i]));
        cout << a[i] << " " << res.size() << '\n';
    }
    return 0;
}
#endif
#include <bits/stdc++.h>
using namespace std;

vector<int> pre_processing(string &s){
    int s_len = s.length();
    vector<int> pi(s_len);
    pi[0] = 0;
    int j = 0;

    for(int i = 1; i < s_len; i++){
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]){
            pi[i] = j + 1;
            j++;
        }
        else{
            pi[i] = 0;
        }
    }
    return pi;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	
    string s;
    cin >> s;

    int s_len = s.length();
    vector<int> pi = pre_processing(s);
    vector<pair<int, int>> ans;
    vector<int> cnt(s_len+1, 0);

    for(int i = 0; i < s_len; i++){
        cnt[pi[i]] += 1;
    }
    for(int i = s_len; i > 0; i--){
        cnt[pi[i-1]] += cnt[i];
    }

    for(int i = s_len; i > 0; i = pi[i-1]){
        ans.push_back(make_pair(i, cnt[i]+1));
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto ch: ans){
        cout << ch.first << " " << ch.second << "\n";
    }

    
}