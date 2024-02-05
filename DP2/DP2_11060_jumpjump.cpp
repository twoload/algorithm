// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[1001];
int d[1001];
int n;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(d, -1, sizeof(d));
    d[0] = 0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (d[j] != -1 && i-j <= a[j]) {
                if (d[i] == -1 || d[i] > d[j]+1) {
                    d[i] = d[j]+1;
                }
            }
        }
    }
    cout << d[n-1] << '\n';
    return 0;
}