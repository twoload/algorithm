#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// -10~10 = 21
// ex. 4x4 : 4 numbers
// n <= 10
// 10! : ok brute (x)
// teacher => 21^10 : timer over!!!

// go(i) : index
// if ok:
//    i >= n
//    if check
//       return a
// if ng:
//    i > n
// if next:
// for(k=-10; k<=10; k++)
//    a[i] = k
//    go(i+1)

// sign[i][i] : i-th buho
// + : 1~10
// - : -10~-1
// 0 : 0

// => 10^10 : time over

#include <iostream>
#include <string>
using namespace std;
int n;
int sign[10][10];
int ans[10];
bool ok() {
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += ans[j];
            if (sign[i][j] == 0) {
                if (sum != 0) return false;
            } else if (sign[i][j] > 0) {
                if (sum <= 0) return false;
            } else if (sign[i][j] < 0) {
                if (sum >= 0) return false;
            }
        }
    }
    return true;
}
bool go(int index) {
    if (index == n) {
        return ok();
    }
    if (sign[index][index] == 0) {
        ans[index] = 0;
        return go(index+1);
    }
    for (int i=1; i<=10; i++) {
        ans[index] = sign[index][index]*i;
        if (go(index+1)) return true;
    }
    return false;
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (s[cnt] == '0') {
                sign[i][j] = 0;
            } else if (s[cnt] == '+') {
                sign[i][j] = 1;
            } else {
                sign[i][j] = -1;
            }
            cnt += 1;
        }
    }
    go(0);
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}