// I've attmxed the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <tuple>
using namespace std;

// 1(1:3) 2(2:2)
// 1(1:2) 2(2:1)
// 1(1:1) 2(3:2)
// 1(4:3) 2(3:1)
// 1(4:2) 2(5:2)
// 1(4:1) 2(5:1)
// 1(6:3) 2(7:2)

// 1(1:1) 2(2:2) 3(3:3) 4(4:4) 5(5:5)
// 1(6:1) 2(2:1) 3(3:2) 4(4:3) 5(5:4)
// 1(7:1) 2(8:2) 3(3:1) 4(4:2) 5(5:3)
// 1(9:1) 2(8:1) 3(10:3) 4(4:1) 5(5:2)
// 1(11:1) 2(12:2) 3(10:2) 4(13:4) 5(5:1)
// 1(14:1) 2(12:1) 3(10:1) 4(13:3) 5(15:5)
// 1(16:1) 2(17:2) 3(18:3) 4(13:2) 5(15:4)
// 1(19:1) 2(17:1) 3(18:2) 4(13:1) 5(15:3)
// 1(20:1) 2(21:1) 3(18:1) 4(22:4) 5(15:2)
// 9       5       3       3       2


int main() {
    long long p, n;
    cin >> p >> n;
    vector<long long> a(n);
    for (long long i=0; i<n; i++) {
        cin >> a[i];
    }
    if (p <= n) {
        printf("%d\n", p);
        return 0;
    }
    long long left = 0;
    long long right = 2000000000LL * 1000000LL;
    long long ans = 0;
    while (left <= right) {
        long long mid = (left+right)/2;
        long long begin, end;
        begin = end = 0;
        end = n;
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
                        printf("%d\n", i+1);
                        return 0;
                    }
                    begin += 1;
                }
            }
        }
    }
    return 0;
}