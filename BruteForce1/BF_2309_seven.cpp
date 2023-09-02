#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;

int main() {
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (sum - a[i] - a[j] == 100) {
                for (int k=0; k<n; k++) {
                    if (i == k || j == k) continue;
                    // print seven dwarfs except i, j
                    cout << a[k] << '\n';
                }
                return 0;
            }
        }
    }
    return 0;
}