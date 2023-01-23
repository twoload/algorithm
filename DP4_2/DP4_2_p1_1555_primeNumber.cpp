#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// prime number : min/max
// aristotenes
//   1~n
//   %2 == 0 -> remove
//   %3 == 0 -> remove
//   ...
//   until k*k < n

// +, -, *, /
// n : (1<=n<=6)
// brute force : 4^6 = 2^12
// aristotenes : for : min/max
// O(2^12 * n)

// dp
//  d[s]
// s: O, X -> 0,1,2,3

// teacher
// numbers use: O, X -> 2^6 = 64
// set<int> d[1<<6] 
//  d[i] = all cases at state: i

#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> d[1<<6]; // duplicate isn't allowed
bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i=2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
// mask : first input = 11111...1111
//        numbers I've used
// first & second == 0
// first | second == mask
set<int> solve(vector<int> &a, int mask) {
    set<int> &ans = d[mask]; // memoization
    if (ans.size() > 0) { 
        return ans;
    }
    if (mask == 0) { // end condition
        return ans;
    }
    int n = a.size();
    for (int i=0; i<(1<<n); i++) { // all states
        int first = i & mask; // not to overrap
        int second = (~first) & mask;
        if (first == 0 || second == 0) {
            continue;
        }
        // divide and conquer
        solve(a, first);
        solve(a, second);

        //  d[i] = all cases at state: i
        for (int x : d[first]) {
            for (int y : d[second]) {
                if (x != 0) {
                    ans.insert(y/x);
                }
                if (y != 0) {
                    ans.insert(x/y);
                }
                ans.insert(x+y);
                ans.insert(x-y);
                ans.insert(y-x);
                ans.insert(x*y);
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        d[1<<i].insert(a[i]);
        // example, n = 3 , 1,2,3
        // d[1] = 1, d[2] = 2, d[4] = 3 (init value)
    }

    // ans has all possible calculation's answers
    auto ans = solve(a, (1<<n)-1);
    
    int ans_min=-1;
    int ans_max=-1;
    
    for (auto &x : ans) {
        if (is_prime(x)) {
            if (ans_min == -1) {
                ans_min = x;
            }
            ans_max = x;
        }
    }
    
    if (ans_min == -1) {
        cout << -1 << '\n';
    } else {
        cout << ans_min << '\n';
        cout << ans_max << '\n';
    }
    return 0;
}
