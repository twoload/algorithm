#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;

string cut(string s) {
    s.pop_back();
    return s;
}
string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}
bool can(string s, string t) {
    if (s == t) {
        return true;
    }
    if (t.length() > 0) {
        if (t.back()=='A' && can(s,cut(t))) {
            return true;
        }
        if (t[0]=='B' && can(s,cut(rev(t)))) {
            return true;
        }
    }
    return false; 
} 

int main() {
    string s, t;
    cin >> s >> t;
    cout << can(s, t) << '\n';
    return 0;
}