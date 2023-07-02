#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// d[i] : num of way which representing i with 1,2,3
//      += d[i-1] + 1
//      += d[i-2] + 1
//      += d[i-3] + 1

#include <iostream>
using namespace std;
long long d[1000001];
const long long mod = 1000000009LL;
int main() {
    d[0] = 1;
    for (int i=1; i<=1000000; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
        d[i] %= mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}
