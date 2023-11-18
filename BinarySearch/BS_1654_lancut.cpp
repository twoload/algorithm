// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


bool valid(vector<long long>&a, long long d, long long m) {
    long long cnt = 0;
    for (long long num : a) {
        cnt += (num / d);
    }
    if (cnt >= m) {
        return true;
    } else {
        return false;
    }
}

long long go(vector<long long>& a, long long m, long long start, long long end) {
    long long ret = 0;
    while (start <= end) {
        long long mid = (start+end)/2;
        if (valid(a, mid, m) == false) {
            end = mid - 1;
        } else {
            ret = mid;
            start = mid+1;
        }
    }
    return ret;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    long long max_num = 0;
    for (long long i=0; i<n; i++) {
        cin >> a[i];
        if (max_num < a[i]) {
            max_num = a[i];
        }
    }
    cout << go(a, m, 1, max_num);
    return 0;
}