#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string eight[8] = 
{"000","001","010","011","100","101","110","111"};
int main() {
    string s;
    cin >> s;
    bool start = true;
    if (s.length() == 1 && s[0]-'0'==0) { // len:1
        cout << "0";
    }
    for (int i=0; i<s.length(); i++) {
        int n = s[i]-'0';
        if (start == true && n < 4) { // len:2
            if (n == 0) {
                continue;
            } else if (n == 1) {
                cout << "1";
            } else if (n == 2) {
                cout << "10";
            } else if (n == 3) {
                cout << "11";
            }
            start = false;
        } else { // len:3
            cout << eight[n];
            start = false;
        }
    }
    return 0;
}