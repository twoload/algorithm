#if 0
// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  s1----e1
 *             s5----e5
 *   s2----e2
 *   s0---s0
 *   s3------------e3
 *          s5-e5
 *             s4----e4
 */

bool compare(pair<int,int>& a, pair<int,int>& b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second) {
        if (a.first < b.first){
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> meet(n);
    for (int i=0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        meet[i].first = s;
        meet[i].second = e;
    }
    sort(meet.begin(), meet.end(), compare);

    int cnt = 1;
    int start, end;
    start = meet[0].first;
    end = meet[0].second;
    for (int i=1; i<meet.size(); i++) {
        int s, e;
        s = meet[i].first;
        e = meet[i].second;
        if (s < end) {
            continue;
        } else {
            start = meet[i].first;
            end = meet[i].second;
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}

