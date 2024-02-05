#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
using namespace std;


int main() {
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    int ans = -1;
    do {
        if (a.front() == '0') continue;
        if (stoi(a) < stoi(b)) {
            if (stoi(a) > ans) {
                ans = stoi(a);
            }
        } 
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
    return 0;
}