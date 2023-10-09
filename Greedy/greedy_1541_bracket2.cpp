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


int main() {
    string s;
    cin >> s;
    vector<int> num;
    vector<int> sign;
    bool minus = false;
    int cur = 0;
    sign.push_back(1);
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+') {
                sign.push_back(1);
            } else {
                sign.push_back(-1);
            }
            num.push_back(cur);
            cur = 0;
        } else {
            cur = 10*cur + (s[i]-'0');
        }
    }
    num.push_back(cur);
    int ans = 0;
    minus = false;
    for (int i=0; i<num.size(); i++) {
        if (sign[i] == -1) {
            minus = true;
        }
        if (minus) {
            ans -= num[i];
        } else {
            ans += num[i];
        }
    }
    cout << ans << '\n';
    return 0;
}

#if 0
int main() {
    string s;
    cin >> s;
    string tmp = "";
    int sum = 0;
    bool minus = false;
    for (int i=0; i<s.size(); i++) {
         if ('0'<= s[i] && s[i] <= '9') {
             tmp += s[i];
         } else if (s[i] == '+' || s[i] == '-') {
             if (minus == false) {
                sum += stoi(tmp);
             } else {
                sum -= stoi(tmp);
             }
             tmp = "";
             if (s[i] == '-') {
                 minus = true;
             }
         } 
    }
    if (minus == false) {
        sum += stoi(tmp);
    } else {
        sum -= stoi(tmp);
    }
    cout << sum << '\n';
    return 0;
}
#endif