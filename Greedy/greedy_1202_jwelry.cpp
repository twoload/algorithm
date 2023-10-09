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

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    vector<int> b(m);
    for (int i=0; i<n; i++) {
        int w, c;
        cin >> w >> c;
        a[i] = make_pair(w, c);
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    priority_queue<int> pq;
    
    int j=0;
    for (int i=0; i<m; i++) {
        while (j<n && a[j].first <= b[i]) {
            pq.push(a[j].second);
            j += 1;
        }
        if (!pq.empty()) {
            sum += pq.top(); pq.pop();
        }
    }
    cout << sum << '\n';
    return 0;
}
#if 0
bool comp_jewel(pair<int,int>& a, pair<int,int>& b) {
    // value big -> small
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        // weight small -> big
        if (a.first < b.first) {
            return true;
        } 
    }
    return false;
} 

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    multiset<int> b;
    for (int i=0; i<n; i++) {
        int w, c;
        cin >> w >> c;
        a[i] = make_pair(w,c);
    }
    for (int i=0; i<m; i++) {
        int w;
        cin >> w
        b.a;
    }
    sort(a.begin(), a.end(), comp_jewel);
    sort(b.begin(), b.end());

    long long sum = 0;
    for (int i=0; i<a.size(); i++) {
        auto low = lower_bound(b.begin(), b.end(), a[i].first);
        if (low == b.end()) {
            continue;
        }
        sum += a[i].second;
        b.erase(b.begin()+(low - b.begin()));
    }
    cout << sum << '\n';
    return 0;
}
#endif