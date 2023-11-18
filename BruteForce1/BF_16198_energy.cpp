// bruteforce: my solution

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> a;

int go(int n) {
    if (n <= 2) {
        return 0;
    }
    int ret = 0;
    for (int i=1; i<n-1; i++) {
        // erase
        vector<int> pre = a;
        int sum = a[i-1] * a[i+1];
        a.erase(a.begin()+i);
        sum = go(n-1) + sum;
        if (ret < sum) {
            ret = sum;
        }
        // insert
        a = pre;
    }
    return ret;
}

int main() {
    int n = 0;
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ret = go(n);
    cout << ret << '\n';
    return 0;
}