#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

// k-th num 
// use binary search 

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
const int MAX = 100000;
vector<int> primes;
// inclusion-exclusion principle
// N set intersection
//   += N set size
//   -= 2 set intersection
//   += 3 set intersection
//   -= 4 set intersection
//   ... 
int calc(int index, long long num, long long m) {
    if (index >= primes.size()) return 0;
    int ans = 0;
    if (num*primes[index] > m) return 0;
    ans += m/(num*primes[index]);
    ans += calc(index+1, num, m);
    ans -= calc(index+1, num*primes[index], m);
    return ans;
}
// (1<=K<=1,000,000,000)
bool c[MAX+1]; // why ? MAX = 100,000 ? 
int main() {
    // Sieve of Eratosthenes (0~100,000 prime find!)
    for (int i=2; i<=MAX; i++) {
        if (c[i]) continue;
        primes.push_back(i*i);
        for (int j=i+i; j<=MAX; j+=i) { // remove not prime
            c[j] = true;
        }
    }
    int n;
    cin >> n;
    long long left = 0;
    long long right = 2147483647; //2^31-1 = Mersenne prime
    long long ans = right;
    // binary search
    while (left <= right) {
        long long mid = (left + right) / 2;
        // count the number not prime square numbers in less than or equal to mid
        int cnt = mid - calc(0,1,mid);
        if (cnt >= n) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}