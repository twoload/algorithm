// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void solve(int n, int b, int r, int c) {
    int nn = n/2;
    if (n == 2) {
        if (r==0 && c==0) cout << b;
        else if (r==0 && c==1) cout << b+1;
        else if (r==1 && c==0) cout << b+2;
        else if (r==1 && c==1) cout << b+3;
        cout << '\n';
        return;
    }
    if (r < nn && c < nn) {
        solve(nn, b, r, c);
    }
    else if (r < nn && c >= nn) {
        solve(nn, b+nn*nn, r, c-nn);
    }
    else if (r >= nn && c < nn) {
        solve(nn, b+nn*nn*2, r-nn, c);
    }
    else if (r >= nn && c >= nn) {
        solve(nn, b+nn*nn*3, r-nn, c-nn);
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    solve(1<<n, 0, r, c);
    return 0;
}