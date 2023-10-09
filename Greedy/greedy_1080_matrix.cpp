#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[51][51];
int b[51][51];
int n, m;


void flip(int sa, int sb) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int x=sa+i;
            int y=sb+j;
            a[x][y]= 1 - a[x][y];
        }
    }
}
void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m-2; j++) {
            cout << a[i][j] << a[i][j+1] << a[i][j+2] << " " << b[i][j] << b[i][j+1] << b[i][j+2];
        }
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            a[i][j] = s[j]-'0';
        }
    }
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            b[i][j] = s[j]-'0';
        }
    }

    
    if (n < 3 || m < 3) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] != b[i][j]) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
        cout << 0 << '\n';
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] == b[i][j]) {
                continue;
            }
            else {
                flip(i, j);
                cnt += 1;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}