#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
using namespace std;

int n;

int go(int sum) {
    if (sum == n) {
        return 1;
    }
    else if (sum > n) {
        return 0;
    }
    int ret = 0;
    ret += go(sum + 1);
    ret += go(sum + 2);
    ret += go(sum + 3);
    return ret;
}
#if 0
int go(int sum, int goal) {
    if (sum > goal) return 0;
    if (sum == goal) return 1;
    int now = 0;
    for (int i=1; i<=3; i++) {
        now += go(sum+i, goal);
    }
    return now;
}
#endif

int main()
{
    int t = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << go(0) << '\n';
    }
    return 0;
}
