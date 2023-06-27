#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
bool check[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> primes;
    for (int i=2; i<=1000000; i++) {
        if (check[i] == false) {
            primes.push_back(i);
            for (int j=i+i; j<=1000000; j+=i) {
                check[j] = true;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i=0; i<primes.size(); i++) {
            //if (n-primes[i] >= 2 && primes[i] <= n-primes[i]) {
            if (primes[i] <= n-primes[i]) {            
                if (check[n-primes[i]] == false) {
                    ans += 1;
                }
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}