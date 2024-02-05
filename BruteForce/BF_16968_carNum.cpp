#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    char pre = s[0];
    int sum = (pre == 'd' ? 10 : 26);
    for (int i=1; i<s.size(); i++) {
        char now = s[i];
        int num = (now == 'd' ? 10 : 26);
        if (pre == now) {
            sum *= num-1;
        } else {
            sum *= num;
        }
        pre = now;
    }
    cout << sum <<'\n';
    return 0;
}