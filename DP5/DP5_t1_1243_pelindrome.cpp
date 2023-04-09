#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : num of words      (1<= n <= 50)
// l : len of pelindrome (1<= l <= 30)
// a : len of word <= 15

// A, AA, BB, BC, CB

// A|A|A|A
// AA|A|A
// A|AA|A
// A|A|AA
// AA|AA
// A|BB|A
// BB|BB
// BC|CB
// CB|BC

// it's ok to use one word several times (duplicate)

// brute force: O(n^l)
// d[l][n] : num of way when n, l
// d[l][s] : num of way when s state

// teacher
// d[len][str][dir] 
//     length len is left.
//     str: string which is not penlindrome in the middle
//     dir: str's direction (0:left, 1:right)

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
string s[50];
map<string, int> h;
int d[31][1501][2]; // remain len, str index, direction
int n, l;
// check x[:len] == y[-len:]
bool check(string x, string y, int len) {
    int y_len = y.length();
    for (int i=0; i<len; i++) {
        if (x[i] != y[y_len-i-1]) return false;
    }
    return true;
}
// l, "", 0
int go(int len, string str, int dir) {
    int str_index = h[str]; // use string index instead of string
    int &ans = d[len][str_index][dir]; // memoization
    if (ans != -1) return ans;
    if (len == 0) { // end
        // check if str is penlindrome
        if (check(str, str, str.length())) {
            return ans = 1;
        } else {
            return ans = 0;
        }
    }
    // dir = 0
    ans = 0;
    if (dir == 0) {
        // ****str_______****
        for (int i=0; i<n; i++) {
            if (len < s[i].length()) { // we can put s[i] only when len is bigger than s[i].length
                continue;
            }
            // len to compare
            //  - str: already located in the mid
            //  - s[i]: string to put this time in the mid
            int mid_len = min(str.length(), s[i].length());
            if (check(str, s[i], mid_len)) {
                if (str.length() < s[i].length()) {
                    // ****str___sgnirts****
                    //            s[i]
                    string mid_str = s[i].substr(0, s[i].length()-mid_len);
                    ans += go(len-s[i].length(), mid_str, 1);
                } else {
                    // ****str____ts****
                    //           s[i]
                    string mid_str = str.substr(mid_len);
                    ans += go(len-s[i].length(), mid_str, 0);
                }
            }
        }
    } else {
        // ****_______rts****
        for (int i=0; i<n; i++) {
            if (len < s[i].length()) {
                continue;
            }
            int mid_len = min(str.length(), s[i].length());
            if (check(s[i], str, mid_len)) {
                if (str.length() < s[i].length()) {
                    // ****strings____rts****
                    //      s[i]
                    string mid_str = s[i].substr(mid_len);
                    ans += go(len-s[i].length(), mid_str, 0);
                } else {
                    // ****st____rts****
                    //    s[i]
                    string mid_str = str.substr(0, str.length()-mid_len);
                    ans += go(len-s[i].length(), mid_str, 1);
                }
            }
        }
    }
    return ans;
}
int main() {
    cin >> n;
    cin >> l;
    vector<string> words;
    for (int i=0; i<n; i++) {
        cin >> s[i];   // BC
        string t1 = "";
        string t2 = "";
        int m = s[i].length();
        for (int j=0; j<m; j++) {
            t1 = t1 + s[i][j];
            t2 = s[i][m-j-1] + t2;
            words.push_back(t1); // B, BC
            words.push_back(t2); // C, CB
        }
    }
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end()); // remove duplicate
    h[""] = 0;
    for (int i=0; i<words.size(); i++) {
        h[words[i]] = i+1;
    }
    memset(d,-1,sizeof(d));
    cout << go(l, "", 0) << '\n';
    return 0;
}
