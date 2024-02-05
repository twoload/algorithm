#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://bowbowbow.tistory.com/6

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> getPi(string p) {
    int j=0;
    int n = p.size();
    vector<int> pi(n, 0);
    for (int i=1; i<n; i++) {
        while (j>0 && p[i]!=p[j]) {
            j = pi[j-1];
        }
        if (p[i] == p[j]) {
            j += 1;
            pi[i] = j;
        }
    }
    return pi;
}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pi = getPi(s);
    cout << n - pi[n-1] << '\n';
    return 0;
}