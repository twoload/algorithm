#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// d[i] : max money to buy i number cards
//      : when I buy j-th cards,
//        d[i-j] + A[j]
// d[i] = max(d[i-j] + A[j]), 1<= j <= N

// teacher
// d[i] = max(d[i-j] + A[j]), 1<= j <= i

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i]; // cost
    }
    vector<int> d(n+1);
    // n * O(n) = O(n^2)
    for (int i=1; i<=n; i++) { // 1~n : d[n]
        for (int j=1; j<=i; j++) { // each 
            d[i] = max(d[i], d[i-j]+a[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}

