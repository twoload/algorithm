// I've attmxed the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.


#include <iostream>
using namespace std;
int a[10000];
int p,n;
int main() {
    cin >> p >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    if (p <= n) {
        cout << p << '\n';
        return 0;
    }
    long long left = 0;
    long long right = 2000000000LL * 10000LL * 30LL;
    while (left <= right) {
        long long mid = (left+right)/2;
        long long begin = 0;
        long long end = n;
        for (int i=0; i<n; i++) {
            end += mid/a[i];
        }
        begin = end;
        for (int i=0; i<n; i++) {
            if (mid % a[i] == 0) {
                begin -= 1;
            }
        }
        begin += 1;
        if (p < begin) {
            right = mid-1;
        } else if (p > end) {
            left = mid+1;
        } else {
            for (int i=0; i<n; i++) {
                if (mid % a[i] == 0) {
                    if (p == begin) {
                        cout << i+1 << '\n';
                        return 0;
                    } else {
                        begin += 1;
                    }
                }
            }
        }
    }
    return 0;
}