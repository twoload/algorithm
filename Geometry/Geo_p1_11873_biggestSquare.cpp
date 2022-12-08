#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
// 1 <= N,M <= 1000
int d[1000][1000];

//       |
//    |  |  |
// |  |  |  |  |
// 1  2  3  2  1
//[0][1][2][3][4]
int largest(vector<int> &a) {
    int n = a.size();
    stack<int> s;
    int ans = 0;
    // s = 0 1 2
    for (int i=0; i<n; i++) {
        int left = i;
        // if a[i] is smaller, pop things bigger than a[i]
        //    get area size 
        //    push a[i]
        while(!s.empty() && a[s.top()] > a[i]) {
            int height = a[s.top()];
            s.pop();
            int width = i;
            if (!s.empty()) {
                width = (i - s.top() -1);
            }
            if (ans < width*height) {
                ans = width*height;
            }
        }
        s.push(i);
    }
    // small, .... big... 
    // get area size from the end
    while(!s.empty()) {
        int height = a[s.top()];
        s.pop();
        int width = n;
        if (!s.empty()) {
            width = n-s.top()-1;
        }
        if (ans < width*height) {
            ans = width*height;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (true) {
        cin >> n >> m; // row, col
        if (n == 0 && m == 0) break;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> d[i][j]; // input data
            }
        }
        int ans = 0;
        vector<int> a(m);
        // for 0-th row
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (d[i][j] == 0) {
                    a[j] = 0;
                } else {
                    a[j] += 1; // for each colume (high)
                }
            }
            int cur = largest(a);
            if (ans < cur) ans = cur;
        }
        cout << ans << '\n';
    }
    return 0;
}