// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void go(vector<vector<char>>& a, int n, int r, int c) {
    if (n==3) {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i==1 && j==1) continue;
                a[r+i][c+j] = '*';
            }
        }
        return;
    }
    int m = n/3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i==1 && j==1) continue;
            go(a, m, r+m*i, c+m*j);
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n, ' '));
    go(a,n,0,0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}