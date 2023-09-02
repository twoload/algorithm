#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        a[i] = i+1;

    do {
        for(int i=0; i<n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}