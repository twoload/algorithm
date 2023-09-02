#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n : remaining day
// i : current day
// p : money
// go(n, i, p)
// end cond
//     i >= n
// next cond
// i(o) go(n, i+d(i), p+m(i))
// i(x) go(n, i+1, p)

// teacher
//   1 2 3 4 5
// T 3 1 2 2 100
// P 2 5 3 3 10000
// 
// 2^n = 2^15 = 32768

// 1) find answer
//    day == n+1
// 2) impossible
//    day > n+1
// 3) next 
//    i)  o: go(day+T[day], sum+[day]) 
//    ii) x: go(day+1, sum)


#include <iostream>
using namespace std;
const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum) {
    if (day == n+1) {
        if (ans < sum) ans = sum;
        return;
    }
    if (day > n+1) {
        return;
    }
    go(day+1, sum);
    go(day+t[day], sum+p[day]);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    go(1,0);
    cout << ans << '\n';
    return 0;
}