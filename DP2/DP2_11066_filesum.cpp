// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[501][501];
int a[501];
int n;
int go(int i, int j) {
    if (i == j) {
        return 0;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    int &ans = d[i][j];
    int sum = 0;
    for (int k=i; k<=j; k++) {
        sum += a[k];
    }
    for (int k=i; k<=j-1; k++) {
        int temp = go(i,k) + go(k+1,j) + sum;
        if (ans == -1 || ans > temp) {
            ans = temp;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        cout << go(1,n) << '\n';
    }
    return 0;
}