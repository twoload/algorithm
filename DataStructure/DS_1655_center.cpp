#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2; 
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if (pq1.size() <= pq2.size()) {
            pq1.push(num);
        } else {
            pq2.push(num);
        }
        if (!pq1.empty() && !pq2.empty()) {
            if (pq1.top() >= pq2.top()) {
                int num1 = pq1.top();
                int num2 = pq2.top();
                pq1.pop(); pq2.pop();
                pq1.push(num2);
                pq2.push(num1);
            }
        }
        cout << pq1.top() << '\n';
    }
    return 0;
}