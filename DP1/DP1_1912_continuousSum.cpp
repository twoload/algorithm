#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// d[n] : max sum until n
//        max(d[n], d[n-1] + a[n])

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n);
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    // O(n)
    for (int i=1; i<n; i++) {
        d[i] = max(d[i], d[i-1]+a[i]);
    }
    cout << *max_element(d.begin(), d.end()) << '\n';
    return 0;
}