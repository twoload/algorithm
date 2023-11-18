// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    int n;
    cin >> n;
    vector<int> a(10001, 0);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    for (int i=0; i<10001; i++) {
        for (int j=0; j<a[i]; j++) {
            cout << i << '\n';
        }
    }
    return 0;
}