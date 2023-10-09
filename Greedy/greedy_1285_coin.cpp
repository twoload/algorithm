#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string flip(string s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'T') {
            s[i] = 'H';
        } else {
            s[i] = 'T';
        }
    }
    return s;
}
char flip2(char c) {
    if (c == 'T') {
        c = 'H';
    } else {
        c = 'T';
    }
    return c;
}

void print(vector<string>& x) {
    int n = x.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << x[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}
vector<string> flip_in_column(vector<string>& x) {
    vector<string> y = x;
    int n = y.size();
    for (int i = 0; i < n; i++) {
        int num_t = 0;
        for (int j = 0; j < n; j++){
            if (y[j][i] == 'T') {
                num_t += 1;
            }
        }
        if (num_t > n/2) {
            for (int j = 0; j < n; j++) {
                y[j][i] = flip2(y[j][i]);    
            }
        }
    }
    return y;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 987654321;
    
    for (int i=0; i<(1<<n); i++) {        
        vector<string> b = a;
        // flip in row direction
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) {
                b[j] = flip(b[j]);
            }
        }
        // flip in col direction
        b = flip_in_column(b);
        
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (b[i][j] == 'T') {
                    cnt += 1;
                }
            }
        }
        if (ans > cnt) {
            ans = cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}