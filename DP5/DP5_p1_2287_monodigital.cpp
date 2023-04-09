#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// n = 1000  
// K is given
// len : 1, 2, 3, 4, .... 8
// len 1
// len 2 : k+k, k-k, k*k, k/k : 4
// len 3 : k (?) k (?) k : 2^4
// ...
// len 8 : 7^4
// O(1000) * (4+2^4+...7^4) = O(2'550'000)

// teacher
// d[i] : all numbers with K-expression, len:i
//
//      d[i]
//     /     \
//   /         \
// d[j] (+-*/) d[k]
// j+k = i

//    i
//   / \
//  j  i-j=k
// (x) (y)


#include <iostream>
#include <set>
using namespace std;
int main() {
    int k;
    cin >> k;
    set<int> s[9];
    int num = 0;
    for (int i=1; i<=8; i++) {
        num = num * 10 + k;
        s[i].insert(num); //init: 5, 55, 555, 5555, ...
    }
    //    i
    //   / \
    //  j  i-j=k
    // (x) (y)
    for (int i=2; i<=8; i++) {
        for (int j=1; j<i; j++) {
            int k = i-j;
            for (int x : s[j]) { // all nums in j : x
                for (int y : s[k]) { // all nums in k : y
                    s[i].insert(x+y);// all possible: added to i
                    s[i].insert(x-y);
                    s[i].insert(x*y);
                    if (y != 0) {
                        s[i].insert(x/y);
                    }
                }
            }
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x; // any number
        bool ok = false;
        for (int i=1; i<=8; i++) {
            if (s[i].count(x) > 0) { // if exists,
                cout << i << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
        }
    }
    return 0;
}


