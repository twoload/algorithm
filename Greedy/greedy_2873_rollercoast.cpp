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

int a[1001][1001];
void append(string &s, char c, int cnt) {
    for (int i=0; i<cnt; i++) {
        s += c;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    // case1: row=odd
    if (n % 2 == 1) {
        int nn = n;
        while (nn > 0) {
            if (nn == 1) {
                for (int i=0; i<m-1; i++) {
                    cout << 'R';
                }
                nn -= 1;
            }
            else if (nn % 2 == 1){
                for (int i=0; i<m-1; i++) {
                    cout << 'R';
                }
                cout << 'D';
                nn -= 1;
            } else {
                for (int i=0; i<m-1; i++) {
                    cout << 'L';
                }
                cout << 'D';
                nn -= 1;
            }
        }
    }
    // case 2: colume = odd
    else if (m % 2 == 1) {
        int mm = m;
        while (mm > 0) {
            if (mm == 1) {
                for (int i=0; i<n-1; i++) {
                    cout << 'D';
                }
                mm -= 1;
            } else if (mm % 2 == 1){
                for (int i=0; i<n-1; i++) {
                    cout << 'D';
                }
                cout << 'R';
                mm -= 1;
            } else {
                for (int i=0; i<n-1; i++) {
                    cout << 'U';
                }
                cout << 'R';
                mm -= 1;
            }
        }        
    }
    // case 3. 
    else { // n%2==0, m%2==0
        int sx = 0, sy = 0;
        string str_s, str_e;
        int ex = n-1, ey = m-1;
        int x, y;
        int prev = 1001;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if ((i+j)%2 == 1) {
                    if (a[i][j] < prev) {
                        x = i;
                        y = j;
                        prev = a[i][j];
                    }
                }
            }
        }
         
        while (sx+1 < x) {
            append(str_s, 'R', m-1);
            append(str_s, 'D', 1);
            append(str_s, 'L', m-1);
            append(str_s, 'D', 1);
            sx += 2;
        }
        while (ex-1 > x) {
            append(str_e, 'R', m-1);
            append(str_e, 'D', 1);
            append(str_e, 'L', m-1);
            append(str_e, 'D', 1);
            ex -= 2;
        }
        while (sy+1 < y) {
            append(str_s, 'D', 1);
            append(str_s, 'R', 1);
            append(str_s, 'U', 1);
            append(str_s, 'R', 1);
            sy += 2;
        }
        while (ey-1 > y) {
            append(str_e, 'D', 1);
            append(str_e, 'R', 1);
            append(str_e, 'U', 1);
            append(str_e, 'R', 1);
            ey -= 2;
        }
        if (sx == x) {
            append(str_s, 'D', 1);
            append(str_s, 'R', 1);
        } else {
            append(str_s, 'R', 1);
            append(str_s, 'D', 1);
        }
        reverse(str_e.begin(), str_e.end());
        string s = str_s + str_e;
        cout << s << '\n';
    }
    return 0;
}