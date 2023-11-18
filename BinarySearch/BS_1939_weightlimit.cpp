// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool bfs(vector<vector<pair<int,int>>> & a, long long start, long long end, int d) {
    bool found = false;
    int n = a.size();
    vector<bool> checked(n, false);
    
    queue<pair<int,int>> q;
    q.push(make_pair(start,0));
    checked[start] = true;
    while (!q.empty()) {
        int now = q.front().first; q.pop();
        if (now == end) {
            found = true;
            break;
        }
        for (int i=0; i<a[now].size(); i++) {
            int next = a[now][i].first;
            int cost = a[now][i].second;
            if (checked[next]) continue;
            if (cost < d) continue;
            checked[next] = true;
            q.push(make_pair(next, 0));
        }
    }
    return found;
}

int main() {
    int n, m;
    cin >> n >> m;
    long long start=1, mid, end=0;
    vector<vector<pair<int,int>>> a(n+1);
    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
        if (end < z) {
            end = z;
        }
    }
    int factory1, factory2;
    cin >> factory1 >> factory2;
    int ans = 0;
    while (start <= end) {
        mid = (start+end)/2;
        if (bfs(a, factory1, factory2, mid) == false) {
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}