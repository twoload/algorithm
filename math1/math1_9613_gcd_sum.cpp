#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
using namespace std;
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x%y);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[111];
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        long long sum = 0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                sum += gcd(a[i], a[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}