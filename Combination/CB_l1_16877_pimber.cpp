#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// Grundy Number

// Sprague-Grundy Function
// g(x) = min(n>=0, n!=g(y) for y in F(x))
// g(x) : x's next position = y
//        min integer which isn't included in g(y) (not minus)

// x -> y1 0 1  
//   -> y2 1 2
//   -> y3 0 3
// g(y) = {0,1}
// g(x) = 2

// g(y) = {1,2,3}
// g(x) = 0

//  0 <- 1(*)
//-------------
//  1 <- 0(*)
//  2 <-
//-------------
//  0 <- 1(*) 
//  2 <-  
//-------------

// rock game
// i  : 0 1 2 3 4 5 6 7 8 9 10 
//g(i): 0 1 2 3 0 1 2 3 0 1 2 
//            \-/
//           \--/
//         \----/
//         g(y) = {1,2,3} > g(x) = 0 : g(4)=0
//g(i) = i mod 4

// if game is composed of severals,
//    XOR of each game = answer 

// nim game (assume that rock stack num = 1)
// i  : 0 1 2 3 4 5 6 7 8 9 10
//g(i): 0 1 2 3 4 5 6 7 8 9 10
//            \-/
//           \--/
//         \----/
//g(i) = i

// fimber
// num of removable rocks : fibonacci num

#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int limit = 3'000'000;
int main() {
    // make fibonacci numbers
    vector<int> fibo = {1, 1};
    for (int i=2;; i++) {
        int num = fibo[i-2] + fibo[i-1];
        if (num > limit) break;
        fibo.push_back(num);
    }
    // grundy number
    vector<int> d(limit+1);
    for (int i=1; i<=limit; i++) {
        vector<int> check(50); //F(50)=12'586'269'025
        for (int j : fibo) {
            if (i < j) break;
            // i-j >= 0
            check[d[i-j]] = 1;
        }
        for (int k=0;; k++) {
            if (check[k] == 0) {
                d[i] = k; // find grundy number = minimum value
                break;
            }
        }
    }
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        ans ^= d[x]; // XOR
    }
    if (ans == 0) {
        cout << "cubelover" << '\n';
    } else {
        cout << "koosaga" << '\n';
    }
    return 0;
}
