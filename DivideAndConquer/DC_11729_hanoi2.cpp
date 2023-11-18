// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

void solve(int n, int x, int y) {
    if (n==0) return;
    solve(n-1, x, 6-x-y);
    cout << x << ' ' << y << '\n';
    solve(n-1, 6-x-y, y);
}

int main() {
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n';
    solve(n, 1, 3);
    return 0;
}