#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif


// count : 1~ 15*28*19 = 7980
// for loop x 3


#include <iostream>
using namespace std;
int main() {
    int E, S, M;
    cin >> E >> S >> M;
    int e=1, s=1, m=1;
    for (int i=1;; i++) {
        if (e == E && s == S && m == M) {
            cout << i << '\n';
            break;
        }
        e += 1;
        s += 1;
        m += 1;
        if (e == 16) {
            e = 1;
        }
        if (s == 29) {
            s = 1;
        }
        if (m == 20) {
            m = 1;
        }
    }
    return 0;
}

// (e - 1) % 15 + 1 : 1,2,3,....,15
#if 0
#include <iostream>
using namespace std;
int main() {
    int e,s,m;
    cin >> e >> s >> m;
    e -= 1;
    s -= 1;
    m -= 1;
    for (int i=0;; i++) {
        if (i%15 == e && i %28 == s && i % 19 == m) {
            cout << i+1 << '\n';
            break;
        }
    }
}
