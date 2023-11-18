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
        a[r+0][c+2] = '*';
        a[r+1][c+1] = a[r+1][c+3] = '*';
        for (int i=0; i<5; i++) {
            a[r+2][c+i] = '*';
        }
        return;
    }
    int m = n/2;
    go(a, m, r, c+m);
    go(a, m, r+m, c);
    go(a, m, r+m, c+n);
}


int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>((n/3)*6, ' '));
    go(a,n,0,0);
    for (int i=0; i<n; i++) {
        cout << string(a[i].begin(), a[i].end()) << '\n';
    }
    return 0;
}