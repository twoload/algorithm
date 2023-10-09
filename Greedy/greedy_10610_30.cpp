#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    priority_queue<int, vector<int>> pq;
    bool zero = false;
    int sum = 0;

    for (int i=0; i<n.size(); i++) {
        if (n[i] == '0') {
            zero = true;
        }
        sum += n[i]-'0';
        pq.push(n[i]);
    }
    if (zero && (sum % 3 == 0)) {
        string s;
        while (!pq.empty()) {
            char x = pq.top(); pq.pop();
            s += x;
        }
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}