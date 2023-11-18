// bruteforce: my solution

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n = 0;
int a[16] = {0,}; // save column index
    
bool possible(int row) {
    for (int i=0; i<row; i++) {
        if (a[i] == a[row]) {
            return false;
        } 
        if (abs(row-i) == abs(a[row]-a[i])) {
            return false;
        }
    }
    return true;
}
int go(int row) {
    if (row >= n) {
        return 1;
    }
    int ret = 0;
    for (int i=0; i<n; i++) {
        a[row] = i;
        if (possible(row)) {
            ret += go(row + 1);
        }        
    }
    return ret;
}

int main() {
    cin >> n;
    int ret = go(0);
    cout << ret << '\n';
    return 0;
}