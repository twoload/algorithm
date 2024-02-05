#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    string b;
    cin >> b;
    reverse(b.begin(), b.end());
    stack<char> st;
    for (int i=0; i<s.size(); i++) {
        st.push(s[i]);

        stack<char> temp;
        int idx = 0;
        bool match = false;
        while (!st.empty() && st.top()==b[idx]) {
            temp.push(st.top());
            st.pop();
            idx++;
            if (idx >= b.size()) {
                match = true;
                break;
            }
        }
        if (match == false) {
            while (!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
        }
    }
    if (st.empty()) {
        cout << "FRULA" << '\n';
    } else {
        string r;
        while (!st.empty()) {
            r += st.top();
            st.pop();
        }
        reverse(r.begin(), r.end());
        cout << r << '\n';
    }
    return 0;
}
