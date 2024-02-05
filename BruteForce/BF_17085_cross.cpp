#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int n, m;
bool isPossible(int x, int y, int crossSize) {

}

void putCross(int x, int y, int crossSize)

void go(int idx, int x, int y) {
    if (idx == 2) return;
    int crossMax = min(n,m)/2;
    for (int i=0; i<=crossMax; i++) {

    }

}

int main() {
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            go(0,i,j);
        }
    }
    return 0;
}