#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// brute force
// 1: O(1)
// 2: O(N^2)
// O(MN^2)

// (L) the biggest one (R)
// L : find again 
// R : find again

// segment tree: save location instead of value
//  MlogN

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct SegmentTree {
    vector<int> tree;
    vector<int> a;
    int n;
    SegmentTree(vector<int> _a) {
        a = _a;
        n = a.size();
        int h = (int)ceil(log2(n+1));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
        init(1, 0, n-1);
    }
    void init(int node, int start, int end) {
        if (start == end) {
            tree[node] = start; // position
            return;
        }
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        // max = bigger
        if (a[tree[node*2]] > a[tree[node*2+1]]) {
            tree[node] = tree[node*2];
        } else {
            tree[node] = tree[node*2+1];
        }
    }
    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }
    void update(int node, int start, int end, int index, int val) {
        if (index < start || end < index) {
            return;
        }
        if (start == end) {
            a[index] = val;
            tree[node] = start;
            return;
        }
        int mid = (start+end)/2;
        update(node*2, start, mid, index, val);
        update(node*2+1, mid+1, end, index, val);
        if (a[tree[node*2]] > a[tree[node*2+1]]) {
            tree[node] = tree[node*2];
        } else {
            tree[node] = tree[node*2+1];
        }
    }
    int query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }
    int query(int node, int start, int end, int i, int j) {
        if (end < i || j < start) return -1;
        if (i <= start && end <= j) {
            return tree[node];
        }
        int mid = (start+end)/2;
        int m1 = query(node*2, start, mid, i, j);
        int m2 = query(node*2+1, mid+1, end, i, j);
        if (m1 == -1) {
            return m2;
        } else if (m2 == -1) {
            return m1;
        } else {
            if (a[m1] > a[m2]) {
                return m1;
            } else {
                return m2;
            }
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    SegmentTree tree(a);
    int m;
    cin >> m;
    while (m--) {
        int w;
        cin >> w;
        if (w == 1) {
            int index, val;
            cin >> index >> val;
            index -= 1;
            a[index] = val;
            tree.update(index, val);
        } else {
            int l, r;
            cin >> l >> r;
            l -= 1; r -= 1;
            int ans = 0;
            int p = tree.query(l, r);
            // L [l,p-1]
            if (p-1 >= l) {
                int p2 = tree.query(l, p-1);
                ans = max(ans, a[p] + a[p2]);
            }
            // R [p+1,r]
            if (p+1 <= r) {
                int p2 = tree.query(p+1, r);
                ans = max(ans, a[p] + a[p2]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
} 