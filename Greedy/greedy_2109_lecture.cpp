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
using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) {
        int p, d;
        cin >> p >> d;
        a[i] = make_pair(p,d);
    }
    sort(a.begin(), a.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i=0; i<n; i++) {
        pq.push(a[i].first);
        if (pq.size() > a[i].second) {
            pq.pop();
        }
    }
    
    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << '\n';
    return 0;
}