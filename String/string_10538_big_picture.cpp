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
#include <map>
using namespace std;

long long mod = 2147483647;
int base = 2; // o,x
long long h(vector<int>& a, int begin, int end) {
    long long ans = 0;
    for (int i=begin; i<end; i++) {
        ans = (ans*base + a[i]) % mod; 
    }
    return ans;
}
vector<int> convert(string &s) {
    int m = s.length();
    vector<int> ans(m, 0);
    for (int i=0; i<m; i++) {
        if (s[i] == 'o') {
            ans[i] = 1;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int rs, cs, rb, cb; // row_small, col_small, row_big, col_big;
    cin >> rs >> cs >> rb >> cb;
    vector<vector<int>> small(rs);
    vector<vector<int>> big(rb);
    for (int i=0; i<rs; i++) {
        string temp;
        cin >> temp;
        small[i] = convert(temp);
    }
    for (int i=0; i<rb; i++) {
        string temp;
        cin >> temp;
        big[i] = convert(temp);
    }
    long long pow_col = 1;
    for (int i=0; i<cs-1; i++) {
        pow_col = (pow_col * base) % mod;
    }
    long long base_row = (pow_col * base) % mod;
    long long pow_row = 1;
    for (int i=0; i<rs-1; i++) {
        pow_row = (pow_row * base_row) % mod;
    }
    long long hash_small = 0;
    for (int i=0; i<rs; i++) {
        hash_small = (hash_small * base_row + h(small[i], 0, cs)) % mod;
    }
    vector<vector<long long>> hash_col(rb, vector<long long>(cb));
    {
        auto &d = hash_col;
        for (int i=0; i<rb; i++) {
            d[i][0] = h(big[i], 0, cs);
            for (int j=1; j<=cb-cs; j++) {
                d[i][j] = d[i][j-1] - (big[i][j-1]*pow_col) % mod;
                d[i][j] = (d[i][j] + mod) % mod;
                d[i][j] = ((d[i][j] * base) % mod + big[i][j+cs-1]) % mod;
            }
        }
    }
    vector<vector<long long>> hash_rect(rb, vector<long long>(cb));
    {
        auto &d = hash_rect;
        for (int j=0; j<=cb-cs; j++) {
            d[0][j] = 0;
            for (int i=0; i<rs; i++) {
                d[0][j] = (d[0][j] * base_row + hash_col[i][j]) % mod;
            }
            for (int i=1; i<=rb-rs; i++) {
                d[i][j] = d[i-1][j] - (hash_col[i-1][j]*pow_row) % mod;
                d[i][j] = (d[i][j] + mod) % mod;
                d[i][j] = ((d[i][j] * base_row) % mod + hash_col[i+rs-1][j]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i=0; i<=rb-rs; i++) {
        for (int j=0; j<=cb-cs; j++) {
            if (hash_small == hash_rect[i][j]) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}