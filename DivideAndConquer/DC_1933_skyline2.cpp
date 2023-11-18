// I've attended the code.plus class (https://code.plus/)
// And I've referred it's codes
// And core parts can be come fully from the class.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using Result = vector<pair<int,int>>;
struct Building {
    int left, height, right;
};

void append(Result& a, pair<int,int> p) {
    int n = a.size();
    if (n > 0) {
        if (a[n-1].second == p.second) {
            return;
        }
        if (a[n-1].first == p.first) {
            a[n-1].second = p.second;
            return;
        }
    }
    a.push_back(p);
}

Result merge(Result& l, Result& r) {
    Result ans;
    int u = 0;
    int v = 0;
    int h1 = 0;
    int h2 = 0;
    int i=0;
    int j=0;
    while (i < l.size() && j < r.size()) {
        if (l[i].first < r[j].first) {
            int x = l[i].first;
            h1 = l[i].second;
            int h = max(h1, h2);
            append(ans, make_pair(x,h));
            i+=1;
        } else {
            int x = r[j].first;
            h2 = r[j].second;
            int h = max(h1,h2);
            append(ans, make_pair(x,h));
            j+=1;
        }
    }
    while (i<l.size()) {
        append(ans, l[i]);
        i+=1;
    }
    while (j<r.size()) {
        append(ans, r[j]);
        j+=1;
    }
    return ans;
}

Result go(vector<Building>& a, int start, int end) {
    if (start == end) {
        Result ans = {
            {a[start].left, a[start].height},
            {a[start].right, 0}
        };
        return ans;
    }
    int mid = (start+end)/2;
    auto l = go(a, start, mid);
    auto r = go(a, mid+1, end);
    return merge(l,r);
}

int main() {
    int n;
    cin >> n;
    vector<Building> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i].left >> a[i].height >> a[i].right;
    }
    sort(a.begin(), a.end(), [](auto &u, auto&v) {
        return make_tuple(u.left, u.height, u.right) < make_tuple(v.left, v.height, v.right);
    });
    Result ans = go(a, 0, n-1);
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << ' ';
    }
    cout << '\n';
    return 0;
}
