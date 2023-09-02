#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif 

#include <iostream>
using namespace std;
int d[100001];
int s[100001];
int main() {
    int n;
    cin >> n;
    d[0] = 1;
    s[0] = 1; 
    d[1] = 2; // x0, 0x
    s[1] = d[0] + d[1];
    for (int i=2; i<=n; i++) {
        d[i] = d[i-1] + 2*s[i-2];
        // s[i-1] = d[i-2] + d[i-3] + ... + d[1] + d[0]
        s[i] = s[i-1] + d[i];
        d[i] = d[i] % 9901;
        s[i] = s[i] % 9901;
    }
    cout << s[n] << '\n';
    return 0;
}