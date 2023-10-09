#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int n;
int t[16];
int p[16];


int go(int index) {
    int ret = 0;
    if (index >= n) {
        return 0; 
    }
    int tmp = 0;
    // no select
    tmp = go(index+1);
    if (ret < tmp) {
        ret = tmp;
    }
    // select
    if (index+t[index] <= n) {
        tmp = go(index+t[index])+p[index];
        if (ret < tmp) {
            ret = tmp;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i] >> p[i];
    }
    cout << go(0) << '\n';
    return 0;
}
