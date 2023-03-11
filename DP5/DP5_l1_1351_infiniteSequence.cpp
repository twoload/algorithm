#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// DP
// N <= 10^12

// teacher
// we can't use memoization because N is too big
// d[1,000,000,000,000]

// TopDown
// N ---> N/2
//   \--/ it's ok even if we don't know betweens

// map

#include <iostream>
#include <map>
using namespace std;
map<long long, long long> d; // memoization
long long n,p,q;
long long go(long long i) {
    if (i == 0) {
        return 1;
    } else if (d.count(i) > 0) { // if exists, 
        return d[i];
    } else {
        return d[i] = go(i/p) + go(i/q);
    }
}
int main(){
    cin >> n >> p >> q;
    cout << go(n) << '\n';
    return 0;
}

