// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int d[61][61][61];
int a[3];
int n;

int go(int i, int j, int k) {
    if (i<0) return go(0,j,k);
    if (j<0) return go(i,0,k);
    if (k<0) return go(i,j,0);
    if (i==0 && j==0 && k==0) return 0;

    int &ans = d[i][j][k];
    if (ans != -1) return ans;
    ans = 10000000; 
    vector<int> p = {1,3,9};
    do {
        if (ans > go(i-p[0],j-p[1],k-p[2])) {
            ans = go(i-p[0],j-p[1],k-p[2]);
        }
    } while (next_permutation(p.begin(), p.end()));
    ans += 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    d[0][0][0] = 0;
    cout << go(a[0], a[1], a[2]) << '\n';   
    return 0;
}