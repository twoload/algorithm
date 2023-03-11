#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// teacher
// idea: big number goes much smaller if it is divided
//       small number goes less smaller if it is divided
// so, in only small ranges, we use memoization

#include <iostream>
using namespace std;
const int MAX = 5000001; // we only use memoization in this range
long long d[MAX];
long long p,q,x,y;
long long go(long long i) {
    if (i <= 0) {
        return 1;
    }
    if (i < MAX && d[i] != 0) { // memoization
        return d[i];
    }
    long long ans = go(i/p-x) + go(i/q-y); 
    if (i < MAX) {
        d[i] = ans; // update
    }
    return ans;
}
int main() {
    long long n;
    cin >> n >> p >> q >> x >> y;
    cout << go(n) << '\n';
    return 0;
}