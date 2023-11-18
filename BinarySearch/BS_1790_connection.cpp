// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//1-9 : 10-1                   1 (1)*(10^1-10^0)
//10-99 : (100-10)*2           2 (2)*(10^2-10^1)
//100-999 : (1000-100)*3       3 (3)*(10^3-10^2)
//1000-9999 : (10000-1000)*4   4
//10000-99999                  5
//100000-999999                6
//1,000,000-9,999,999          7
//10,000,000-99,999,999        8
//100,000,000-999,999,999      9


int main() {
    long long n, k;
    cin >> n >> k;
    long long p = 0;
    long long l = 0;
    long long nn = 0;
    nn = n;
    while (nn > 0) {
        p += 1;
        nn = nn / 10;
    }
    long long pp = p;
    l += pp*(n-pow(10,pp-1)+1);
    pp -= 1;
    while (pp > 0) {
        l += (pow(10,pp)-pow(10,pp-1));
        pp -= 1;
    }
    if (l < k) {
        cout << -1 << '\n';
        return 0;
    }

    string ans;
    long long ppp = 1;
    long long ll = 0;
    while (1) {
        long long ll = (pow(10,ppp) - pow(10,ppp-1))*ppp;
        if (k <= ll) {
            long long a = (k-1) / ppp;
            long long b = (k-1) % ppp;
            long long kk = pow(10,ppp-1)+a;
            ans = to_string(kk).substr(b,b+1);
            break;
        } else {
            k -= ll;
            ppp += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}