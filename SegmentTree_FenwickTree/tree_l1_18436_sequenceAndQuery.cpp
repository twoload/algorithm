#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// n = 100'000
// m = 100'000
// O(nm) : too big

// segment tree
// edit: logN
// l<=i<=r, output num of even/odd : logN
// O(mlogN)
// myidea: segement tree, save 1(even),0(odd),1(self)
// [l,r] = we can know total length. so 1(even),0(odd) only needed
// => Fenwick tree (sum)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void update(vector<int> &tree, int i, int diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
int sum(vector<int> &tree, int l, int r) {
    if (l > r) return 0;
    return sum(tree, r) - sum(tree, l-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> tree(n+1);
    // O(nlogn)
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            update(tree, i, 1); //even->1
        }
    }
    int m; // query
    cin >> m;
    while (m--) {
        int w;
        cin >> w;
        if (w == 1) { //update
            int index, val;
            cin >> index >> val;
            if (a[index]%2 == 0 && val%2 == 1) {
                // even -> odd
                update(tree, index, -1); //1->0
            }
            if (a[index]%2 == 1 && val%2 == 0) {
                // odd -> even 
                update(tree, index, 1); //0->1
            }
            a[index] = val;
        } else { // 2,3
            int l, r;
            cin >> l >> r;
            int cnt = sum(tree, l, r); // num of even
            if (w == 3) { // num of odd
                cnt = (r-l+1) - cnt;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}