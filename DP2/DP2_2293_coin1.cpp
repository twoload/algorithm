// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <vector>
using namespace std;
int n;
int k;
int go(int n) {
    int ret = 0;
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    
}

int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    go(k)

    return 0;
}